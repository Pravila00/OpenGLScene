#ifndef CHASISMEDIO_H_INCLUDED
#define CHASISMEDIO_INCLUDED

#include "aux.h"
#include "cubo.h"
#include "esfera.h"
#include "puerta.h"
#include "malla.h"
#include "asiento.h"
#include "textura.h"

class ChasisMedio : public Malla3D
{
private:
    Cubo *c1,*c2;
    Puerta *p1,*p2;
    Asiento *a;
    float rotarPuerta1=0;
    float rotarPuerta2=360;
    bool abrirPuertas=true;
    float aumentoAlfaPuertas=1;
    Textura *chasis;

public:
    ChasisMedio();
    void dibujar(bool solido,bool lineas,bool puntos,bool ajedrez);
    void abrirPuerta1();
    void cerrarPuerta1();
    void abrirPuerta2();
    void cerrarPuerta2();

    void abrirVentana1();
    void cerrarVentana1();
    void abrirVentana2();
    void cerrarVentana2();

    void animarPuertas();
    void animarVentanas();
   
    void aumentarVelocidadVentanas();
    void disminuirVelocidadVentanas();

    void aumentarVelocidadPuertas();
    void disminuirVelocidadPuertas();
   
} ;




#endif