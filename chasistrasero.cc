#include "chasistrasero.h"
#include "aux.h"
#include "malla.h"
#include "cilindro.h"

ChasisTrasero::ChasisTrasero(){
    c1=new Cubo(1);
    rueda=new Cilindro();
    tronco=new Cilindro();

    //Set Colores
    c1->setColores(Tupla3f(1,0,0));
    rueda->setColores(Tupla3f(0,0,0));
    tronco->setColores(Tupla3f(0.445,0.359,0.257));

    //Set Materiales
    Material c(Tupla4f(0.61424,0.04136,0.04136,1.0),Tupla4f(0.727811,0.626959,0.626959,1.0),Tupla4f(0.1745,0.01175,0.01175,0.0),0.6f);
    Material r(Tupla4f(0.01,0.01,0.01,1.0),Tupla4f(0.4,0.4,0.4,1.0),Tupla4f(0.02,0.02,0.02,1.0),0.78125f);
    Material t(Tupla4f(0.445,0.359,0.257,0.0),Tupla4f(0.445,0.359,0.257,0.0),Tupla4f(0.2,0.2,0.2,0.2),1.0f);
    c1->setMaterial(c);
    rueda->setMaterial(r);
    tronco->setMaterial(t);

    //Inicializar grados de libertad
    alfaTronco=0.0;
    aumentoAlfa=0.025;

    //chasis=new Textura("texturas/coche-tex.jpg");
    //c1->calcularTextura();
    //c1->asignarTextura(chasis);
}

void ChasisTrasero::dibujar(bool solido,bool lineas,bool puntos,bool ajedrez){
    //Tronco
    glPushMatrix();
        glTranslatef(alfaTronco,0.8,0);
        glScalef(0.3,0.3,2);
        glRotatef(90,1,0,0);
        tronco->drawObjRev(true,solido,lineas,puntos,ajedrez);
    glPopMatrix();

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
        glScalef(0.4,0.4,0.4);
        glRotatef(90,1,0,0);
        rueda->drawObjRev(true,solido,lineas,puntos,ajedrez);
    glPopMatrix();
}

void ChasisTrasero::avanzarTronco(){
    alfaTronco+=aumentoAlfa;
    if(alfaTronco>0.5){
        alfaTronco=0.5;
    }
}
void ChasisTrasero::retrocederTronco(){
    alfaTronco-=aumentoAlfa;
    
    if(alfaTronco<-0.5){
        alfaTronco=-0.5;
    }
}

void ChasisTrasero::animarTronco(){
    if(avanzandoTronco){
        avanzarTronco();
        if(alfaTronco==0.5){
            avanzandoTronco=false;
        }
            
    }
    else{
        retrocederTronco();
        if(alfaTronco==-0.5)    
            avanzandoTronco=true;
    }
}

void ChasisTrasero::aumentarVelocidadTronco(){
    aumentoAlfa*=1.25;
}

void ChasisTrasero::disminuirVelocidadTronco(){
    aumentoAlfa/=1.25;
}