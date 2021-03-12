#ifndef PUERTA_H_INCLUDED
#define PUERTA_H_INCLUDED

#include "aux.h"
#include "cubo.h"
#include "esfera.h"


class Puerta : public Malla3D
{
private:
    Cubo *c1,*c2;
    Esfera *esf;
    float alfa=1.0;
    bool abrirVentanaAnimacion=true;
    float aumentoAlfa=0.02;

   public:
   Puerta();
   void dibujar(bool solido,bool lineas,bool puntos,bool ajedrez);

   void abrirVentana();
   void cerrarVentana();

   void animarVentana();
   void aumentarVelocidadVentanas();
   void disminuirVelocidadVentanas();
   
} ;




#endif
