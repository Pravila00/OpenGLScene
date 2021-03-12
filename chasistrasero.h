#ifndef CHASISTRASERO_H_INCLUDED
#define CHASISTRASERO_INCLUDED

#include "aux.h"
#include "cubo.h"
#include "malla.h"
#include "cilindro.h"

class ChasisTrasero : public Malla3D
{
private:
    Cubo *c1;
    Cilindro *rueda,*tronco;
    float alfaTronco,aumentoAlfa;
    bool avanzandoTronco=true;
    Textura *chasis;
public:
   ChasisTrasero();
   void dibujar(bool solido,bool lineas,bool puntos,bool ajedrez);
   void avanzarTronco();
   void retrocederTronco();
   void animarTronco();
   void aumentarVelocidadTronco();
   void disminuirVelocidadTronco();
} ;
#endif