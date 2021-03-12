#ifndef CAMARA_H_INCLUDED
#define CAMARA_INCLUDED

#include "aux.h"

typedef enum {ORTOGONAL,PERSPECTIVA} tipoCamara;
typedef enum {CUBO,TETRAEDRO,CILINDRO,CONO,ESFERA,BEETHOVEN,PEON,PEON_NEGRO,PEON_BLANCO,ESF_MAT,
              TETRAEDRO_TEXTURA,CUBO_TEXTURA,CUADRO,COCHE,NINGUNO,CUBO_COLA} objetoSeleccionado;

class Camara{
private:
    Tupla3f eye,at,up;
    tipoCamara tipo; 
    float left,right,near,far,top,bottom;
    objetoSeleccionado objetoFijado;

public:
    Camara(Tupla3f eye,Tupla3f at,Tupla3f up,tipoCamara tipo,float near,float far,
        float left, float right,float top,float bottom);
    void rotarXExaminar(float angle);
    void rotarYExaminar(float angle);
    void rotarZExaminar(float angle);
    void rotarXFirstPerson(float angle);
    void rotarYFirstPerson(float angle);
    void rotarZFirstPerson(float angle);
    void mover(Tupla3f c);
    void zoom(float factor);
    void setObserver();
    void setProyeccion(); 
    void girarFP(float x,float y);
    void girarEX(float x,float y);
    objetoSeleccionado getObjetoFijado();
    void setObjetoFijado(objetoSeleccionado obj);
    void setAt(Tupla3f at);
    tipoCamara getTipo();
};


#endif
