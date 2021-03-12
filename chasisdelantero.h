#ifndef CHASISDELANTERO_H_INCLUDED
#define CHASISDELANTERO_INCLUDED

#include "aux.h"
#include "cubo.h"
#include "malla.h"
#include "cilindro.h"
#include "esfera.h"

class ChasisDelantero : public Malla3D
{
private:
    Cubo *c1;
    Cilindro *rueda;
    Esfera *faro;
    Textura *chasis;
public:
   ChasisDelantero();
   void dibujar(bool solido,bool lineas,bool puntos,bool ajedrez);
   
} ;
#endif