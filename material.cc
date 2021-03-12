#include "material.h"

Material::Material() {
   ambiente  = Tupla4f(0.2, 0.2, 0.2, 1.0f);
   difuso    = Tupla4f(0.8, 0.8, 0.8, 1.0f);
   especular = Tupla4f(0.0, 0.0, 0.0, 1.0f);
   brillo    = 1.0f;
}

Material::Material(Tupla4f mdifuso,Tupla4f mespecular,Tupla4f mambiente,float brillo){
    difuso=mdifuso;
    especular=mespecular;
    ambiente=mambiente;
    this->brillo=brillo;
}

void Material::aplicar(){
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambiente);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,difuso);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,especular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,&brillo);

}