#include "malla.h"
#include "aux.h"
#include "coche.h"

Coche::Coche(){
    cm=new ChasisMedio();
    ct=new ChasisTrasero();
    cd=new ChasisDelantero();
}

void Coche::dibujar(bool solido,bool lineas,bool puntos,bool ajedrez){
    glPushMatrix();
        glTranslatef(-2.4,0,0);
        ct->dibujar(solido,lineas,puntos,ajedrez);
    glPopMatrix();


    glPushMatrix();
        glTranslatef(0,0.05,0);
        glScalef(1.5,1,1);
        cm->dibujar(solido,lineas,puntos,ajedrez);
    glPopMatrix();


    glPushMatrix();
        glTranslatef(0.9,0,0);
        cd->dibujar(solido,lineas,puntos,ajedrez);
    glPopMatrix();
}
void Coche::avanzarTronco(){
    ct->avanzarTronco();
}

void Coche::retrocederTronco(){
    ct->retrocederTronco();
}

void Coche::cerrarPuerta1(){
    cm->cerrarPuerta1();
}

void Coche::abrirPuerta1(){
    cm->abrirPuerta1();
}

void Coche::cerrarPuerta2(){
    cm->cerrarPuerta2();
}

void Coche::abrirPuerta2(){
    cm->abrirPuerta2();
}

void Coche::abrirVentana1(){
    cm->abrirVentana1();
}

void Coche::abrirVentana2(){
    cm->abrirVentana2();
}

void Coche::cerrarVentana1(){
    cm->cerrarVentana1();
}

void Coche::cerrarVentana2(){
    cm->cerrarVentana2();
}

void Coche::animarPuertas(){
    cm->animarPuertas();
}

void Coche::animarTronco(){
    ct->animarTronco();
}

void Coche::animarVentanas(){
    cm->animarVentanas();
}

void Coche::animar(){
    animarPuertas();
    animarTronco();
    animarVentanas();
}

void Coche::aumentarVelocidadGeneral(){
    aumentarVelocidadPuertas();
    aumentarVelocidadTronco();
    aumentarVelocidadVentanas();
}

void Coche::disminuirVelocidadGeneral(){
    disminuirVelocidadPuertas();
    disminuirVelocidadTronco();
    disminuirVelocidadVentanas();
}

void Coche::aumentarVelocidadPuertas(){
    cm->aumentarVelocidadPuertas();
}

void Coche::disminuirVelocidadPuertas(){
    cm->disminuirVelocidadPuertas();
}

void Coche::aumentarVelocidadTronco(){
    ct->aumentarVelocidadTronco();
}

void Coche::disminuirVelocidadTronco(){
    ct->disminuirVelocidadTronco();
}

void Coche::aumentarVelocidadVentanas(){
    cm->aumentarVelocidadVentanas();
}

void Coche::disminuirVelocidadVentanas(){
    cm->disminuirVelocidadVentanas();
}