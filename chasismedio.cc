#include "malla.h"
#include "aux.h"
#include "chasismedio.h"


ChasisMedio::ChasisMedio(){
    c1=new Cubo(1);
    c2=new Cubo(1);
    p1=new Puerta();
    p2=new Puerta();
    a=new Asiento();

    //Set Materiales
    Material c(Tupla4f(0.61424,0.04136,0.04136,1.0),Tupla4f(0.727811,0.626959,0.626959,1.0),Tupla4f(0.1745,0.01175,0.01175,0.0),0.6f);
    c1->setMaterial(c);
    c2->setMaterial(c);

    //Set Colores
    c1->setColores(Tupla3f(1,0,0));
    c2->setColores(Tupla3f(1,0,0));

    /*
    chasis=new Textura("texturas/coche-tex.jpg");
    c1->calcularTextura();
    c1->asignarTextura(chasis);
    c2->calcularTextura();
    c2->asignarTextura(chasis);
    */
}   

void ChasisMedio::dibujar(bool solido,bool lineas,bool puntos,bool ajedrez){
    glPushMatrix();
        glTranslatef(0,0,0.5);
        glRotatef(rotarPuerta1,0,1,0);
        p1->dibujar(solido,lineas,puntos,ajedrez);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0,-0.5);
        glRotatef(rotarPuerta2,0,1,0);
        p2->dibujar(solido,lineas,puntos,ajedrez);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5,1.5,0);
        glScalef(1,0.1,1);
        c1->draw(solido,lineas,puntos,ajedrez);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5,-0.5,0);
        glScalef(1,0.1,1);
        c1->draw(solido,lineas,puntos,ajedrez);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1,0.5,0);
        glScalef(0.1,2,1);
        c2->draw(solido,lineas,puntos,ajedrez);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.6,-0.2,0);
        a->dibujar(solido,lineas,puntos,ajedrez);
    glPopMatrix();

}

void ChasisMedio::abrirPuerta1(){
    rotarPuerta1+=aumentoAlfaPuertas;
    if(rotarPuerta1>90){
        rotarPuerta1=90;
    }    
    
}
void ChasisMedio::cerrarPuerta1(){
    rotarPuerta1-=aumentoAlfaPuertas;
    if(rotarPuerta1<0){
        rotarPuerta1=0;
    }
}
void ChasisMedio::abrirPuerta2(){
    rotarPuerta2-=aumentoAlfaPuertas;
    if(rotarPuerta2<270){
        rotarPuerta2=270;
    }
}
void ChasisMedio::cerrarPuerta2(){
    rotarPuerta2+=1;
    if(rotarPuerta2>360){
        rotarPuerta2=360;
    }
}

void ChasisMedio::abrirVentana1(){
    p1->abrirVentana();
}

void ChasisMedio::abrirVentana2(){
    p2->abrirVentana();
}

void ChasisMedio::cerrarVentana1(){
    p1->cerrarVentana();
}

void ChasisMedio::cerrarVentana2(){
    p2->cerrarVentana();
}

void ChasisMedio::animarPuertas(){
    if(abrirPuertas){
        abrirPuerta1();
        abrirPuerta2();
        if(rotarPuerta1==90){
            abrirPuertas=false;
        }
    }
    else{
        cerrarPuerta1();
        cerrarPuerta2();
        if(rotarPuerta1==0){
            abrirPuertas=true;
        }
    }
}

void ChasisMedio::animarVentanas(){
    p1->animarVentana();
    p2->animarVentana();
}

void ChasisMedio::aumentarVelocidadPuertas(){
    aumentoAlfaPuertas*=1.25;
}

void ChasisMedio::disminuirVelocidadPuertas(){
    aumentoAlfaPuertas/=1.25;
}

void ChasisMedio::aumentarVelocidadVentanas(){
    p1->aumentarVelocidadVentanas();
    p2->aumentarVelocidadVentanas();
}

void ChasisMedio::disminuirVelocidadVentanas(){
    p1->disminuirVelocidadVentanas();
    p2->disminuirVelocidadVentanas();
}