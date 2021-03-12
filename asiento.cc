#include "malla.h"
#include "aux.h"
#include "asiento.h"

Asiento::Asiento(){
    c1=new Cubo(1);
    c2=new Cubo(2);
    volante=new Esfera();

    //Set materiales
    Material c(Tupla4f(0.61424,0.04136,0.04136,1.0),Tupla4f(0.727811,0.626959,0.626959,1.0),Tupla4f(0.1745,0.01175,0.01175,0.0),0.6f);
    Material r(Tupla4f(0.01,0.01,0.01,1.0),Tupla4f(0.4,0.4,0.4,1.0),Tupla4f(0.02,0.02,0.02,1.0),0.78125f);
    c1->setMaterial(c);
    c2->setMaterial(c);
    volante->setMaterial(r);

    //Set colores
    c1->setColores(Tupla3f(0,0,0));
    c2->setColores(Tupla3f(0,0,0));
    volante->setColores(Tupla3f(0,0,0));
}

void Asiento::dibujar(bool solido,bool lineas,bool puntos,bool ajedrez){
    glPushMatrix();
        glTranslatef(-0.25,0.5,0);
        glScalef(0.05,1.5,0.5);
        c1->draw(solido,lineas,puntos,ajedrez);
    glPopMatrix();


    glPushMatrix();
        //glTranslatef();
        glScalef(0.25,0.3,0.25);
        c2->draw(solido,lineas,puntos,ajedrez);
    glPopMatrix();


    glPushMatrix();
        glTranslatef(0.5,0.6,0);
        glScalef(0.05,0.3,0.3);
        volante->drawObjRev(true,solido,lineas,puntos,ajedrez);
    glPopMatrix();
}
