#ifndef LUZ_H_INCLUDED
#define LUZ_H_INCLUDED

#include "aux.h"

class Luz{
    //Atributos
    protected:
        Tupla4f posicion;
        GLenum id;
        Tupla4f colorAmbiente;
        Tupla4f colorDifuso;
        Tupla4f colorEspecular;
        bool luzActivada=false;
    public:
        void activar();
        void desactivar();
        bool getLuzActivada();
};

#endif