#include "chasisdelantero.h"
#include "aux.h"
#include "malla.h"
#include "cilindro.h"

ChasisDelantero::ChasisDelantero(){
    c1=new Cubo(1);
    rueda=new Cilindro();
    faro=new Esfera();

    //Set materiales
    Material c(Tupla4f(0.61424,0.04136,0.04136,1.0),Tupla4f(0.727811,0.626959,0.626959,1.0),Tupla4f(0.1745,0.01175,0.01175,0.0),0.6f);
    Material r(Tupla4f(0.01,0.01,0.01,1.0),Tupla4f(0.4,0.4,0.4,1.0),Tupla4f(0.02,0.02,0.02,1.0),0.78125f);
    Material f(Tupla4f(0.5,0.5,0.5,1.0),Tupla4f(0.7,0.7,0.7,1.0),Tupla4f(0.05,0.05,0.05,1.0),0.78125f);

    c1->setMaterial(c);
    rueda->setMaterial(r);
    faro->setMaterial(f);

    //Set Colores
    c1->setColores(Tupla3f(1,0,0));
    rueda->setColores(Tupla3f(0,0,0));
    faro->setColores(Tupla3f(1,1,1));

    //chasis=new Textura("texturas/coche-tex.jpg");
    //c1->calcularTextura();
    //c1->asignarTextura(chasis);
}

void ChasisDelantero::dibujar(bool solido,bool lineas,bool puntos,bool ajedrez){
    //Cubo
    glPushMatrix();
        glScalef(1.8,1,1);
        c1->draw(solido,lineas,puntos,ajedrez);
    glPopMatrix();

    //Rueda1
    glPushMatrix();
        glTranslatef(0,-0.4,0.5);
        glScalef(0.4,0.4,0.4);
        glRotatef(90,1,0,0);
        rueda->drawObjRev(true,solido,lineas,puntos,ajedrez);
    glPopMatrix();

    //Rueda2
    glPushMatrix();
        glTranslatef(0,-0.4,-0.5);
        glRotatef(90,1,0,0);
        glScalef(0.4,0.4,0.4);
        rueda->drawObjRev(true,solido,lineas,puntos,ajedrez);
    glPopMatrix();

    //Faro1
    glPushMatrix();
        glTranslatef(0.9,-0.2,0.3);
        glScalef(0.1,0.1,0.1);
        faro->drawObjRev(true,solido,lineas,puntos,ajedrez);
    glPopMatrix();

    //Faro2
    glPushMatrix();
        glTranslatef(0.9,-0.2,-0.3);
        glScalef(0.1,0.1,0.1);
        faro->drawObjRev(true,solido,lineas,puntos,ajedrez);
    glPopMatrix();
}