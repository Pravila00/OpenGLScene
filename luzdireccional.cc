#include "luzdireccional.h"

LuzDireccional::LuzDireccional(Tupla2f direccion, GLenum idLuzOpenGL,
    Tupla4f colorAmbiente, Tupla4f colorEspecular,
    Tupla4f colorDifuso){

    id=idLuzOpenGL;
    this->colorAmbiente=colorAmbiente;
    this->colorEspecular=colorEspecular;
    this->colorDifuso=colorDifuso;

    posicion=(Tupla4f(direccion[0],direccion[1],1.0f,0.0f));
    radio=sqrt(Tupla3f(posicion[0],posicion[1],posicion[2]).lengthSq());
    alpha=direccion[0];
    beta=direccion[1];
    

}

void LuzDireccional::variarAnguloAlpha(float incremento){
    alpha+=incremento;
    posicion[0]=sin(alpha)*cos(beta)*radio;
    posicion[1]=sin(alpha)*sin(beta)*radio;
    posicion[2]=cos(alpha)*radio;
}
void LuzDireccional::variarAnguloBeta(float incremento){
    beta+=incremento;
    posicion[0]=sin(alpha)*cos(beta)*radio;
    posicion[1]=sin(beta)*radio;
    posicion[2]=cos(alpha)*cos(beta)*radio;

}
