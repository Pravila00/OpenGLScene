#include "cono.h"

//Constructor de la clase cono
Cono::Cono( const int num_vert_perfil ,
            const int num_instancias_perf,
            const float altura ,
            const float radio ){
    this->altura=altura;
    this->radio=radio;
    std::vector<Tupla3f> vertices;
    Tupla3f poloSur(0.0,-altura/2.0,0.0);
    Tupla3f poloNorte(0.0,altura/2.0,0.0);
    Tupla3f vertice1(radio,-altura/2,0.0);
    vertices.push_back(poloSur);
    vertices.push_back(vertice1);
    vertices.push_back(poloNorte);

    Cono conoAux(vertices,num_instancias_perf,true,true);
    *this=conoAux;    
}

Cono::Cono(std::vector<Tupla3f> vertices,int num_instancias, bool tapa_sup,bool tapa_inf)
    : ObjRevolucion(vertices,num_instancias,tapa_sup,tapa_inf){}