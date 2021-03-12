#ifndef CONO_H_INCLUDED
#define CONO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

class Cono : public ObjRevolucion{
    public :
        Cono ( const int num_vert_perfil = 2 ,
            const int num_instancias_perf = 20,
            const float altura = 1.0,
            const float radio = 1.0);
        Cono (std::vector<Tupla3f> vertices,int num_instancias, bool tapa_sup,bool tapa_inf);    
    private:
        float altura,radio;
} ;

#endif