#include "camara.h"

Camara::Camara(Tupla3f eye,Tupla3f at,Tupla3f up,tipoCamara tipo,float near,float far,
                float left, float right,float top,float bottom){

    //Asignamos los argumentos a los atributos
    this->eye=eye;
    this->at=at;
    this->up=up;
    tipo=tipo; 
    this->near=near;
    this->far=far;
    this->left=left;
    this->right=right;
    this->top=top;
    this->bottom=bottom;
    objetoFijado=NINGUNO;
}

void Camara::rotarXExaminar(float angle){
    Tupla3f eyeCentro=eye-at;
    float mod=sqrt(eyeCentro.lengthSq());
    
    eyeCentro[1]=cos(angle)*eyeCentro[1]-sin(angle)*eyeCentro[2];
    eyeCentro[2]=sin(angle)*eyeCentro[1]+cos(angle)*eyeCentro[2];

    eyeCentro=eyeCentro.normalized() * mod;
    eye=eyeCentro+at;

}

void Camara::rotarYExaminar(float angle){
    Tupla3f eyeCentro=eye-at;
    float mod=sqrt(eyeCentro.lengthSq());
    
    eyeCentro[0]=cos(angle)*eyeCentro[0]+sin(angle)*eyeCentro[2];
    eyeCentro[2]=-sin(angle)*eyeCentro[0]+cos(angle)*eyeCentro[2];

    eyeCentro=eyeCentro.normalized() * mod;
    eye=eyeCentro+at;
}

void Camara::rotarZExaminar(float angle){
    Tupla3f eyeCentro=eye-at;
    float mod=sqrt(eyeCentro.lengthSq());
    
    eyeCentro[0]=cos(angle)*eyeCentro[0]-sin(angle)*eyeCentro[1];
    eyeCentro[1]=sin(angle)*eyeCentro[0]+cos(angle)*eyeCentro[1];

    eyeCentro=eyeCentro.normalized() * mod;
    eye=eyeCentro+at;
}

void Camara::rotarXFirstPerson(float angle){
    Tupla3f atCentro=at-eye;
    float mod = sqrt(atCentro.lengthSq());
    atCentro[1]=cos(angle)*atCentro[1] - sin(angle)*atCentro[2];
    atCentro[2]=cos(angle)*atCentro[2] + sin(angle)*atCentro[1];

    atCentro=atCentro.normalized() * mod;
    at=atCentro+eye;
}

void Camara::rotarYFirstPerson(float angle){
    Tupla3f atCentro=at-eye;
    float mod = sqrt(atCentro.lengthSq());
    atCentro[0]=cos(angle)*atCentro[0] + sin(angle)*atCentro[2];
    atCentro[2]=cos(angle)*atCentro[2]-sin(angle)*atCentro[0];

    atCentro=atCentro.normalized() * mod;
    at=atCentro+eye;
    
}

void Camara::rotarZFirstPerson(float angle){
    Tupla3f atCentro=at-eye;
    float mod = sqrt(atCentro.lengthSq());
    atCentro[0]=cos(angle)*atCentro[0] - sin(angle)*atCentro[1];
    atCentro[1]=cos(angle)*atCentro[1]+sin(angle)*atCentro[0];

    atCentro=atCentro.normalized() * mod;
    at=atCentro+eye;
}

void Camara::mover(Tupla3f coordenadas){
    float x,y,z;
    x=coordenadas[0];
    y=coordenadas[1];
    z=coordenadas[2];
    at[0]=x;
    at[1]=y;
    at[2]=z;

    eye[0]=x;
    eye[1]=y;
    eye[2]=z+300;
}

void Camara::zoom(float factor){
    left*=factor;
    right*=factor;
    top*=factor;
    bottom*=factor;
    //std::cout<<"Se aplica Zoom\n";
    setProyeccion();
    
}

void Camara::setObserver(){
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    gluLookAt(eye[0],eye[1],eye[2],
              at[0],at[1],at[2],
              up[0],up[1],up[2]);
}


void Camara::setProyeccion(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(tipo==tipoCamara::PERSPECTIVA){
        glFrustum(left,right,bottom,top,near,far);
    }
    else{
        glOrtho(left,right,bottom,top,near,far);
    }
}

void Camara::girarEX(float x,float y){
    rotarXExaminar(-y*0.25*PI/180);
    rotarYExaminar(-x*0.25*PI/180);
}

void Camara::girarFP(float x,float y){
    rotarXFirstPerson(-y*0.25*PI/180);
    rotarYFirstPerson(-x*0.25*PI/180);
}

objetoSeleccionado Camara::getObjetoFijado(){
    return objetoFijado;
}

void Camara::setObjetoFijado(objetoSeleccionado obj){
    objetoFijado=obj;
}

void Camara::setAt(Tupla3f at){
    this->at=at;
}

tipoCamara Camara::getTipo(){
    return tipo;
}