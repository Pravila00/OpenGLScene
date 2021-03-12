#ifndef COCHE_H_INCLUDED
#define COCHE_INCLUDED

#include "aux.h"
#include "malla.h"
#include "chasisdelantero.h"
#include "chasismedio.h"
#include "chasistrasero.h"

class Coche : public Malla3D
{
private:
    ChasisMedio *cm;
    ChasisDelantero *cd;
    ChasisTrasero *ct;

public:
    Coche();
    void dibujar(bool solido,bool lineas,bool puntos,bool ajedrez);

    void avanzarTronco();
    void retrocederTronco();

    void abrirPuerta1();
    void cerrarPuerta1();
    void abrirPuerta2();
    void cerrarPuerta2();
    
    void abrirVentana1();
    void cerrarVentana1();
    void abrirVentana2();
    void cerrarVentana2();

    void animarPuertas();
    void animarTronco();
    void animarVentanas();

    void animar();

    void aumentarVelocidadPuertas();
    void disminuirVelocidadPuertas();

    void aumentarVelocidadTronco();
    void disminuirVelocidadTronco();

    void aumentarVelocidadVentanas();
    void disminuirVelocidadVentanas();

    void aumentarVelocidadGeneral();
    void disminuirVelocidadGeneral();
} ;




#endif