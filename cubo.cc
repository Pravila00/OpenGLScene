#include "aux.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float l)
{
   // inicializar la tabla de vértices
   //Cara 1
   v.push_back(Tupla3f(-l/2,l/2,l/2)); //V0
   v.push_back(Tupla3f(-l/2,-l/2,l/2)); //V1
   v.push_back(Tupla3f(l/2,-l/2,l/2)); //V2
   v.push_back(Tupla3f(l/2,l/2,l/2)); //v3
   f.push_back(Tupla3i(2,0,1));
   f.push_back(Tupla3i(3,0,2));

   //Cara 2
   v.push_back(Tupla3f(l/2,-l/2,l/2));
   v.push_back(Tupla3f(l/2,l/2,l/2));
   v.push_back(Tupla3f(l/2,-l/2,-l/2));
   v.push_back(Tupla3f(l/2,l/2,-l/2));
   f.push_back(Tupla3i(5,4,6));
   f.push_back(Tupla3i(5,6,7));

   //Cara 3
   v.push_back(Tupla3f(-l/2,l/2,-l/2));
   v.push_back(Tupla3f(-l/2,-l/2,-l/2));
   v.push_back(Tupla3f(l/2,-l/2,-l/2));
   v.push_back(Tupla3f(l/2,l/2,-l/2));
   f.push_back(Tupla3i(11,10,9));
   f.push_back(Tupla3i(11,9,8));

   //Cara 4
   v.push_back(Tupla3f(-l/2,l/2,-l/2));
   v.push_back(Tupla3f(-l/2,-l/2,-l/2));
   v.push_back(Tupla3f(-l/2,l/2,l/2));
   v.push_back(Tupla3f(-l/2,-l/2,l/2));
   f.push_back(Tupla3i(12,13,15));
   f.push_back(Tupla3i(12,15,14));

   //Cara 5
   v.push_back(Tupla3f(-l/2,l/2,-l/2));
   v.push_back(Tupla3f(-l/2,l/2,l/2));
   v.push_back(Tupla3f(l/2,l/2,l/2));
   v.push_back(Tupla3f(l/2,l/2,-l/2));
   f.push_back(Tupla3i(18,16,17));
   f.push_back(Tupla3i(19,16,18));

   //Cara 6
   v.push_back(Tupla3f(-l/2,-l/2,l/2)); 
   v.push_back(Tupla3f(-l/2,-l/2,-l/2)); 
   v.push_back(Tupla3f(l/2,-l/2,-l/2)); 
   v.push_back(Tupla3f(l/2,-l/2,l/2));
   f.push_back(Tupla3i(22,20,21));
   f.push_back(Tupla3i(23,20,22));
   
   
   inicializarColores();
   calcular_normales();

   caras=f.size();
   vertices=v.size();
}

void Cubo::calcularTextura(){
   ct.push_back(Tupla2f(0,0));
   ct.push_back(Tupla2f(0,1));
   ct.push_back(Tupla2f(1,1));
   ct.push_back(Tupla2f(1,0));

   ct.push_back(Tupla2f(0,1));
   ct.push_back(Tupla2f(0,0));
   ct.push_back(Tupla2f(1,1));
   ct.push_back(Tupla2f(1,0));

   ct.push_back(Tupla2f(1,0));
   ct.push_back(Tupla2f(1,1));
   ct.push_back(Tupla2f(0,1));
   ct.push_back(Tupla2f(0,0));

   ct.push_back(Tupla2f(0,0));
   ct.push_back(Tupla2f(0,1));
   ct.push_back(Tupla2f(1,0));
   ct.push_back(Tupla2f(1,1));

    ct.push_back(Tupla2f(0,0));
   ct.push_back(Tupla2f(0,1));
   ct.push_back(Tupla2f(1,1));
   ct.push_back(Tupla2f(1,0));

   ct.push_back(Tupla2f(0,0));
   ct.push_back(Tupla2f(0,1));
   ct.push_back(Tupla2f(1,1));
   ct.push_back(Tupla2f(1,0));
   
 
   
}

