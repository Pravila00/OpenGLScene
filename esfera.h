#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

class Esfera : public ObjRevolucion
{
    public :
        Esfera ( const int num_vert_perfil =10,
            const int num_instancias_perf =20,
            const float radio = 1.0);
        Esfera (std::vector<Tupla3f> vertices,int num_instancias,bool tapa_sup,bool tapa_inf);
    private:
        float radio;
} ;

#endif