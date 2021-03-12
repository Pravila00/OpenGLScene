#include "aux.h"
#include "malla.h"
#include "tetraedro.h"

Tetraedro::Tetraedro()
{  
   /*
   float tam=100;
   
   // inicializar la tabla de vértices
   Tupla3f v0(-tam/2,-tam/2,-tam/2);
   v.push_back(v0);
   
   Tupla3f v1(0,-tam/2,tam/2);
   v.push_back(v1);

   Tupla3f v2(tam/2,-tam/2,-tam/2);
   v.push_back(v2);

   Tupla3f v3(0,tam/2,0);
   v.push_back(v3);
   */
   float arista=100;
   float altura=(arista*sqrt(6.0))/3.0;

   // inicializar la tabla de vértices
   Tupla3f v0(-arista/2,-altura*0.25,altura/3.0);
   v.push_back(v0);
   
   Tupla3f v1(0,-altura*0.25,-0.666*altura);
   v.push_back(v1);

   Tupla3f v2(arista/2,-altura*0.25,altura/3.0);
   v.push_back(v2);

   Tupla3f v3(0.0,altura*0.75,0.0);
   v.push_back(v3);

    
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   
   Tupla3i t1(0,2,3);
   f.push_back(t1);

   Tupla3i t2(0,3,1);
   f.push_back(t2);

   Tupla3i t3(0,1,2);
   f.push_back(t3);

   Tupla3i t4(1,3,2);
   f.push_back(t4);

   //Inicializar la tabla de colores
   inicializarColores();
   setColores(Tupla3f(0.4,0.4,0.4));
   calcular_normales();

   caras=f.size();
   vertices=v.size();
   

}

void Tetraedro::asignarTexturaT(Textura *tex){
   
   ct.push_back(Tupla2f(0,1));
   ct.push_back(Tupla2f(1,0));
   ct.push_back(Tupla2f(1,1));
   ct.push_back(Tupla2f(0,0));
   textura=tex;
}
