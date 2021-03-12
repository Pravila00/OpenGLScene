#include "cuadroTextura.h"

CuadroTextura::CuadroTextura(float l){
    v.push_back(Tupla3f(-l/2,-l/2,0));
    v.push_back(Tupla3f(l/2,-l/2,0));
    v.push_back(Tupla3f(l/2,l/2,0));
    v.push_back(Tupla3f(-l/2,l/2,0));

    f.push_back(Tupla3i(3,0,2));
    f.push_back(Tupla3i(2,0,1));

    calcular_normales();
    inicializarColores();

    ct.push_back(Tupla2f(0.0,1.0));
    ct.push_back(Tupla2f(1.0,1.0));
    ct.push_back(Tupla2f(1.0,0.0));
    ct.push_back(Tupla2f(0.0,0.0));
    
    
    
    

    caras=f.size();
    vertices=v.size();
}