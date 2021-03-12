#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

class Cilindro : public ObjRevolucion
{
    public :
        Cilindro ( const int num_vert_perfil =2 ,
            const int num_instancias_perf =20,
            const float altura =1.0,
            const float radio =1.0,
            bool tex=false);
        Cilindro (std::vector<Tupla3f> vertices,int num_instancias, bool tapa_sup,bool tapa_inf,bool tex);
    private:
        float altura,radio;
};

#endif