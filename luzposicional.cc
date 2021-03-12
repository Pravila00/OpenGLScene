#include "luzposicional.h"

LuzPosicional::LuzPosicional(Tupla3f posicion, GLenum idLuzOpenGL,
            Tupla4f colorAmbiente, Tupla4f colorEspecular,
            Tupla4f colorDifuso){
            
    id = idLuzOpenGL;
    this->colorAmbiente=colorAmbiente;
    this->colorEspecular=colorEspecular;
    this->colorDifuso=colorDifuso;
    this->posicion=Tupla4f(posicion[0],posicion[1],posicion[2],1.0f);

}

void LuzPosicional::animacionLuz(Tupla3f variacion){
    //Hay que variar el color ambiente de nuestra luz
    colorAmbiente[0]+=variacion[0];
    colorAmbiente[1]+=variacion[1];
    colorAmbiente[2]+=variacion[2];

    //Si se pasan de un limite la establecemos a 0
    if(colorAmbiente[0]>=60.0){
        colorAmbiente[0]=0;
    }
    if(colorAmbiente[1]>=60.0){
        colorAmbiente[1]=0;
    }
    if(colorAmbiente[2]>=60.0){
        colorAmbiente[2]=0;
    }
}