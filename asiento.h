#ifndef ASIENTO_H_INCLUDED
#define ASIENTO_INCLUDED

#include "aux.h"
#include "cubo.h"
#include "esfera.h"
#include "malla.h"

class Asiento : public Malla3D
{
private:
    Cubo *c1,*c2;
    Esfera *volante;

public:
   Asiento();
   void dibujar(bool solido,bool lineas,bool puntos,bool ajedrez);
   
} ;




#endif