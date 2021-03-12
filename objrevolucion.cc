#include "aux.h"
#include "objrevolucion.h"



// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion(){}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf,int eje,bool tex){
   //Leemos del archivo para tener nuestra tabla de triangulos y caras
   std::vector<Tupla3f> perfil;
   ply::read_vertices(archivo,perfil);
   ObjRevolucion obj(perfil,num_instancias,tapa_sup,tapa_inf,eje,tex);
   *this=obj;
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> perfil, int num_instancias, bool tapa_sup, bool tapa_inf,int eje,bool tex){
   //Si el perfil esta dando en descendente le damos la vuelta para trabajar en ascendente
   if(perfil.front()[eje] > perfil.back()[eje]){
      std::reverse(perfil.begin(),perfil.end());
   }

   //DETECCION DE TAPAS
   //EJE X
   if(eje==0){
      //Tapa inferior
      if(fabs(perfil.front()[2])<EPSILON){
         tapaInf=perfil.front();
         perfil.erase(perfil.begin());
      }
      //Si no detectamos tapa pero se nos indica que tiene se la creamos
      else if(tapa_inf){
         tapaInf=Tupla3f(perfil.front()[0],perfil.front()[1],0.0);
      }

      //Tapa superior
      if(fabs(perfil.back()[2])<EPSILON){
         tapaSup=perfil.back();
         perfil.pop_back();
      }
      //Si no detectamos tapa pero se nos indica que tiene se la creamos
      else if(tapa_sup){
         tapaSup=Tupla3f(perfil.back()[0],perfil.back()[1],0.0);
      }
   }



   //EJE Y
   if(eje==1){
      //Tapa inferior
      if(fabs(perfil.front()[0])<EPSILON){
         tapaInf=perfil.front();
         perfil.erase(perfil.begin());
      }
      //Si no detectamos tapa pero se nos indica que tiene se la creamos
      else if(tapa_inf){
         tapaInf=Tupla3f(0.0,perfil.front()[1],perfil.front()[2]);
      }

      //Tapa superior
      if(fabs(perfil.back()[0])<EPSILON){
         tapaSup=perfil.back();
         perfil.pop_back();
      }
      //Si no detectamos tapa pero se nos indica que tiene se la creamos
      else if(tapa_sup){
         tapaSup=Tupla3f(0.0,perfil.back()[1],perfil.back()[2]);
      }
   }

   //EJE Z
   if(eje==2){
      //Tapa inferior
      if(fabs(perfil.front()[1])<EPSILON){
         tapaInf=perfil.front();
         perfil.erase(perfil.begin());
      }
      //Si no detectamos tapa pero se nos indica que tiene se la creamos
      else if(tapa_inf){
         tapaInf=Tupla3f(perfil.front()[0],perfil.front()[0],perfil.front()[2]);
      }

      //Tapa superior
      if(fabs(perfil.back()[1])<EPSILON){
         tapaSup=perfil.back();
         perfil.pop_back();
      }
      //Si no detectamos tapa pero se nos indica que tiene se la creamos
      else if(tapa_sup){
         tapaSup=Tupla3f(perfil.back()[0],0.0,perfil.back()[2]);
      }
   }



   crearMalla(perfil,num_instancias,eje,tex);

   //A continuacion si hay tapas las insertamos
   tamVSinTapa=v.size();
   tamFSinTapa=f.size();
   if(tapa_inf){
      v.push_back(tapaInf);
      for(int i=0;i<num_instancias;i++){
         int a,b;
         a=perfil.size()*i;
         b=perfil.size()*((i+1)%num_instancias);
         f.push_back(Tupla3i(a,v.size()-1,b));
      }
   }
   
   if(tapa_sup){
      v.push_back(tapaSup);
      for(int i=0;i<num_instancias;i++){
         int a,b;
         a=perfil.size()+i*perfil.size()-1;
         b=perfil.size()*((i+1)%num_instancias)+perfil.size()-1;
         f.push_back(Tupla3i(a,b,v.size()-1));
      }
   }
   inicializarColores();
   calcular_normales();
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias,int eje,bool tex) {
   float anguloRotacion=(2.0*PI)/num_instancias;
   //Creacion de tabla de vertices
   float x,y,z;
   float tex_x,tex_y,distAux;
   std::vector<float> distancias;
   for(int i=0;i<=num_instancias;i++){
      //Aniadimos a la malla la instancia i
      distancias.clear();
      if(i!=num_instancias)
         tex_x=i/(num_instancias-1);
      else
         tex_x=0;

      for(int j=0;j<perfil_original.size();j++){
         float anguloActual=anguloRotacion*i;
         //Calculamos las nuevas coordenadas
         if(eje==0){
            x=perfil_original[j][0];
            y=cos(anguloActual)*perfil_original[j][1] - sin(anguloActual)*perfil_original[j][2];
            z=sin(anguloActual)*perfil_original[j][1] + cos(anguloActual)*perfil_original[j][2];
         }

         else if(eje==1){
            x=perfil_original[j][0]*cos(anguloActual) + sin(anguloActual)*perfil_original[j][2];
            y=perfil_original[j][1];
            z=cos(anguloActual)*perfil_original[j][2]-perfil_original[j][0]*sin(anguloActual);      
         }
         else{
            x=cos(anguloActual)*perfil_original[j][0] - sin(anguloActual)*perfil_original[j][1];
            y=sin(anguloActual)*perfil_original[j][0]+cos(anguloActual)*perfil_original[j][1];
            z=perfil_original[j][2];
         }


         //Creamos el vertice y lo aniadimos
         Tupla3f vertice(x,y,z);
         //if(i!=num_instancias){
            v.push_back(vertice);
         //}
         

         if(tex){
         //Calculamos la distancia y la almacenamos
            if(j==0){
                  distancias.push_back(0);
               }
            else{
                  distAux=calcularDistancia(v.back(),v[v.size()-2]);
                  distancias.push_back(distancias.back()+distAux);
               }
         }
         
      } 

		for(int j=0;j<perfil_original.size() && tex;j++){
			tex_y=distancias[j]/distancias.back();
			ct.push_back(Tupla2f(tex_x,tex_y));
	  	}
   }

   //Creacion de tabla de triangulos
   for(int i=0;i<num_instancias;i++){
      for(int j=0;j<perfil_original.size()-1;j++){
         int a,b;
         a=perfil_original.size()*i+j;
         b=perfil_original.size()*((i+1)%num_instancias)+j;
         Tupla3i t1(a,b,b+1);
         Tupla3i t2(a,b+1,a+1);

         f.push_back(t1);
         f.push_back(t2);
      }
   }
}

void ObjRevolucion::drawObjRev(bool conTapa,bool solido,bool lineas,bool puntos,bool ajedrez){
   if(conTapa){
      vertices=v.size();
      caras=f.size();
      draw(solido,lineas,puntos,ajedrez);
   }
   else{
      vertices=tamVSinTapa;
      caras=tamFSinTapa;
      draw(solido,lineas,puntos,ajedrez);
   }
}


float ObjRevolucion::calcularDistancia(Tupla3f v1,Tupla3f v2){	
	return sqrt((v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[1]-v2[1])*(v1[1]-v2[1]) + (v1[2]-v2[2])*(v1[2]-v2[2]));
}