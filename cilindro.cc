#include "cilindro.h"

Cilindro::Cilindro( const int num_vert_perfil ,
            const int num_instancias_perf ,
            const float h ,
            const float r ,bool tex)
{
   altura=h;
   radio=r;
   std::vector<Tupla3f> vertices;
   Tupla3f poloSur(0.0,-h/2.0,0.0);
   Tupla3f poloNorte(0.0,h/2.0,0.0);
   Tupla3f vertice1(r,-h/2.0,0.0);
   Tupla3f vertice2(r,h/2.0,0.0);
   vertices.push_back(poloSur);
   vertices.push_back(vertice1);
   vertices.push_back(vertice2);
   vertices.push_back(poloNorte);
   Cilindro cilindroAux(vertices,num_instancias_perf,true,true,tex);
   *this=cilindroAux;
   inicializarColores();
   calcular_normales();
}
Cilindro::Cilindro(std::vector<Tupla3f> vertices,int num_instancias, bool tapa_sup,bool tapa_inf,bool tex)
    : ObjRevolucion(vertices,num_instancias,tapa_sup,tapa_inf,1,tex){}
    
