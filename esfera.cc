#include "esfera.h"

Esfera::Esfera( const int num_vert_perfil ,
            const int num_instancias_perf ,
            const float radio )
{
    this->radio=radio;
    std::vector<Tupla3f> vertices;
    float anguloInicial=(3*PI)/2.0;
    float anguloActual=PI/num_vert_perfil;
    for(int i=0;i<num_vert_perfil;i++){
        Tupla3f vert(radio*cos(anguloInicial-anguloActual*i),radio*sin(anguloInicial-anguloActual*i),0.0);
        vertices.push_back(vert);
    }
    Esfera esferaAux(vertices,num_instancias_perf,true,true);
    *this=esferaAux;
}

Esfera::Esfera(std::vector<Tupla3f> vertices,int num_instancias,bool tapa_sup,bool tapa_inf)
    : ObjRevolucion(vertices,num_instancias,tapa_sup,tapa_inf){}