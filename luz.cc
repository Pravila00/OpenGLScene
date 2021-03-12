#include "luz.h"

void Luz::activar(){
    glEnable(id);
    glLightfv(id,GL_AMBIENT,colorAmbiente);
    glLightfv(id,GL_DIFFUSE,colorDifuso);
    glLightfv(id,GL_SPECULAR,colorEspecular);
    glLightfv(id,GL_POSITION,posicion);
    luzActivada=true;
}
void Luz::desactivar(){
    glDisable(id);
    luzActivada=false;
}

bool Luz::getLuzActivada(){
    return luzActivada;
}