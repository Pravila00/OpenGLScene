#include "aux.h"
#include "malla.h"
#include "puerta.h"

Puerta::Puerta(){
    esf=new Esfera();
    c1=new Cubo(1);
    c2=new Cubo(1);

    //Set colores
    c1->setColores(Tupla3f(0.795,0.839,0.917));
    c2->setColores(Tupla3f(1,0,0));
    esf->setColores(Tupla3f(1,1,1));

    //Set Materiales
    Material c(Tupla4f(0.61424,0.04136,0.04136,1.0),Tupla4f(0.727811,0.626959,0.626959,1.0),Tupla4f(0.1745,0.01175,0.01175,0.0),0.6f);
    Material pomo(Tupla4f(0.01,0.01,0.01,1.0f),Tupla4f(0.5,0.5,0.5,1.0),Tupla4f(0.0,0.0,0.0,1.0),0.25f);
    Material v(Tupla4f(0.55,0.55,0.55,1.0),Tupla4f(0.7,0.7,0.7,1.0),Tupla4f(0.0,0.0,0.0,1.0),0.25f);
    c1->setMaterial(v);
    c2->setMaterial(c);
    esf->setMaterial(pomo);
}

void Puerta::dibujar(bool solido,bool lineas,bool puntos,bool ajedrez){
    glPushMatrix();
        glTranslatef(-0.5,0,0);
        glScalef(1,1,0.1);
        c2->draw(solido,lineas,puntos,ajedrez);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5,alfa,0);
        glScalef(1,1.0,0.05);
        c1->draw(solido,lineas,puntos,ajedrez);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-0.8,0,0);
        glScalef(0.1,0.1,0.1);
        esf->drawObjRev(true,solido,lineas,puntos,ajedrez);
    glPopMatrix();
}

void Puerta::abrirVentana(){
    alfa-=aumentoAlfa;
    if(alfa<0){
        alfa=0;
    }
}

void Puerta::cerrarVentana(){
    alfa+=aumentoAlfa;
    if(alfa>1){
        alfa=1;
    }
}

void Puerta::animarVentana(){
    if(abrirVentanaAnimacion){
        abrirVentana();
        if(alfa==0.0){
            abrirVentanaAnimacion=false;
        }
    }
    else{
        cerrarVentana();
        if(alfa==1.00){
            abrirVentanaAnimacion=true;
        }
    }
}

void Puerta::aumentarVelocidadVentanas(){
    alfa*=1.25;
}

void Puerta::disminuirVelocidadVentanas(){
    alfa/=1.25;
}