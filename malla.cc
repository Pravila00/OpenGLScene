#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato(bool solido,bool lineas,bool puntos,bool ajedrez)
{
   // habilitamos el uso del array de vertices
   glEnableClientState( GL_VERTEX_ARRAY);

   //Especificamos puntero a tabla de coordenadas de vertices
   glVertexPointer (3, GL_FLOAT, 0, v.data()); //.data() devuelve un puntero al primer elemento de v


   //Habilitamos el uso del array de colores
   glEnableClientState(GL_COLOR_ARRAY);   

   //Habilitamos el uso de las normales
   glNormalPointer(GL_FLOAT,0,nv.data());
   glEnableClientState(GL_NORMAL_ARRAY);
   if(tieneMaterial){
      m.aplicar();
   }
   
   
   //Habilitamos el uso de las texturas
   if(ct.size()!=0 && texturaActivada){
      glEnable(GL_TEXTURE_2D);
      textura->activar();
      glEnableClientState (GL_TEXTURE_COORD_ARRAY);
      glTexCoordPointer(2, GL_FLOAT,0,ct.data());
   }

   
   if(solido){
      glColorPointer(3, GL_FLOAT, 0, fill.data());
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glDrawElements( GL_TRIANGLES, caras*3, GL_UNSIGNED_INT, f.data());
   }

   if(lineas){
      glColorPointer(3, GL_FLOAT, 0, line.data());
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glDrawElements( GL_TRIANGLES, caras*3, GL_UNSIGNED_INT, f.data());
   }
   
   if(puntos){
      glColorPointer(3, GL_FLOAT, 0, point.data());
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glDrawElements( GL_TRIANGLES, caras*3, GL_UNSIGNED_INT, f.data());
   }
   if(ajedrez){
      //Pintamos las caras impares de un color y las pares de otro color
      glColorPointer(3, GL_FLOAT, 0, fill.data());
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glDrawElements(GL_TRIANGLES,(caras*3)/2,GL_UNSIGNED_INT,impar.data());
      glColorPointer(3, GL_FLOAT, 0, colorAjedrez.data());
      glDrawElements( GL_TRIANGLES, (caras*3)/2, GL_UNSIGNED_INT,par.data());
   }

   // deshabilitar array de vértices
   glDisableClientState(GL_VERTEX_ARRAY);
}
// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)
GLuint Malla3D::crearVBO(GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram){
   GLuint id_vbo; //identificador de VBO
   glGenBuffers(1, & id_vbo); //crear nuevo VBO obteniendo identificador
   //nunca 0

   glBindBuffer(tipo_vbo, id_vbo); //Activa el VBO usando el identificador

   //transferencia de datos de RAM a la GPU
   glBufferData(tipo_vbo,tamanio_bytes, puntero_ram, GL_STATIC_DRAW);

   glBindBuffer(tipo_vbo,0);//desactivacion del VBO (activar 0)
   return id_vbo;

}


void Malla3D::draw_ModoDiferido(bool solido,bool lineas,bool puntos,bool ajedrez)
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   
   if(id_vbo_ver==0){
      id_vbo_ver=crearVBO(GL_ARRAY_BUFFER,vertices*sizeof(float)*3,v.data());
   }
   if(id_vbo_tri==0){
      id_vbo_tri=crearVBO(GL_ELEMENT_ARRAY_BUFFER,caras*sizeof(int)*3,f.data());
   }
   if(id_vbo_colorSol==0){
      id_vbo_colorSol=crearVBO(GL_ARRAY_BUFFER,vertices*sizeof(float)*3,fill.data());
   }   
   if(id_vbo_colorLin==0){
      id_vbo_colorLin=crearVBO(GL_ARRAY_BUFFER,vertices*sizeof(float)*3,line.data());
   }
   if(id_vbo_colorPun==0){
      id_vbo_colorPun=crearVBO(GL_ARRAY_BUFFER,vertices*sizeof(float)*3,point.data());
   }
   if(id_vbo_color_2==0 && ajedrez){
      id_vbo_color_2=crearVBO(GL_ARRAY_BUFFER,colorAjedrez.size()*sizeof(float)*3,colorAjedrez.data());
   }
   if(id_vbo_tri_impar==0){
      id_vbo_tri_impar=crearVBO(GL_ELEMENT_ARRAY_BUFFER,impar.size()*sizeof(int)*3,impar.data());
   }
   if(id_vbo_tri_par==0){
      id_vbo_tri_par=crearVBO(GL_ELEMENT_ARRAY_BUFFER,par.size()*sizeof(int)*3,par.data());
   }

   if(id_vbo_normales==0){
      id_vbo_normales=crearVBO(GL_ARRAY_BUFFER,nv.size()*3*sizeof(float),nv.data());
   }


   glBindBuffer( GL_ARRAY_BUFFER, id_vbo_ver);
   glVertexPointer( 3, GL_FLOAT, 0 ,0); //especifica formato y offset=0
   glBindBuffer( GL_ARRAY_BUFFER,0); //desactiva VBO de vértices
   glEnableClientState (GL_VERTEX_ARRAY); //habilita tabla de vértices

   glEnableClientState(GL_NORMAL_ARRAY);
   glNormalPointer(GL_FLOAT,0,nv.data());
   m.aplicar();
   
   glEnableClientState(GL_NORMAL_ARRAY);
   //std::cout<<"Diferido ACTIVADO\n";

   //Texturas
   if(textura!=nullptr){
      glEnable(GL_TEXTURE_2D);
      textura->activar();
      glEnableClientState (GL_TEXTURE_COORD_ARRAY);
      glTexCoordPointer(2, GL_FLOAT,0,ct.data());
   }

   //Si es modo puntos o modo alambre
   if(solido){
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      //Color  
      glBindBuffer(GL_ARRAY_BUFFER,id_vbo_colorSol);
      glColorPointer(3,GL_FLOAT,0,0);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      glEnableClientState(GL_COLOR_ARRAY);
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);//activar VBO de triangulos
      glDrawElements( GL_TRIANGLES, caras*3, GL_UNSIGNED_INT, 0);
   }
   if(lineas){
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      //Color  
      glBindBuffer(GL_ARRAY_BUFFER,id_vbo_colorLin);
      glColorPointer(3,GL_FLOAT,0,0);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      glEnableClientState(GL_COLOR_ARRAY);
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);//activar VBO de triangulos
      glDrawElements( GL_TRIANGLES, caras*3, GL_UNSIGNED_INT, 0);
   }
   if(puntos){
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      //Color  
      glBindBuffer(GL_ARRAY_BUFFER,id_vbo_colorPun);
      glColorPointer(3,GL_FLOAT,0,0);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      glEnableClientState(GL_COLOR_ARRAY);
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);//activar VBO de triangulos
      glDrawElements( GL_TRIANGLES, caras*3, GL_UNSIGNED_INT, 0);
   }
   if(ajedrez && !puntos && !solido && !lineas){
      //Color  
      glBindBuffer(GL_ARRAY_BUFFER,id_vbo_colorLin);
      glColorPointer(3,GL_FLOAT,0,0);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      glEnableClientState(GL_COLOR_ARRAY);
      //Pintamos las caras impares de un color y las pares de otro color
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri_impar);//activar VBO de triangulos
      glDrawElements(GL_TRIANGLES,(caras*3)/2,GL_UNSIGNED_INT,0);
      glBindBuffer(GL_ARRAY_BUFFER,id_vbo_color_2);
      glColorPointer(3,GL_FLOAT,0,0);
      glEnableClientState(GL_COLOR_ARRAY);
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri_par);//activar VBO de triangulos
      glDrawElements(GL_TRIANGLES,(caras*3)/2,GL_UNSIGNED_INT,0);
   }

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);//descativa VBO

   if(textura!=nullptr){
      glDisable(GL_TEXTURE_2D);
      glDisable(GL_TEXTURE_COORD_ARRAY);
   }

   //Desactivamos el uso de array de vertices
   glDisableClientState (GL_VERTEX_ARRAY);
   
}

// -----------------------------------------------------------------------------
void Malla3D::establecerModoDibujado(modoDibujo modo){
   modoDibujado=modo;
}

void Malla3D::draw(bool solido,bool lineas,bool puntos,bool ajedrez)
{  
   if(modoDibujado==INMEDIATO){
      draw_ModoInmediato(solido,lineas,puntos,ajedrez);
   }
   else{
      draw_ModoDiferido(solido,lineas,puntos,ajedrez);
   }
}

void Malla3D::inicializarColores(){
   //inicializar tabla de colores
   colorAjedrez.clear();
   Tupla3f c1(0,1,0);
   Tupla3f c2(0,0,1);
   Tupla3f c3(1,0,0);
   Tupla3f c4(0,0,0);
   for(int i=0;i<v.size();i++){
      fill.push_back(c1);
      point.push_back(c3);
      line.push_back(c4);
      colorAjedrez.push_back(c2);

   }

   //Creamos un vector con caras impares y otro con caras pares para AJEDREZ
   for(int i=0;i<f.size();i++){
      if(i%2==0){
         par.push_back(f[i]);
      }
      else
      {
         impar.push_back(f[i]);
      }
      
   }
}

void Malla3D::setColores(Tupla3f colores){
   fill.clear();
   //point.clear();
   //line.clear();
   for(int i=0;i<v.size();i++){
      fill.push_back(colores);
      //point.push_back(colores);
      //line.push_back(colores);
   }
   borrarVBOColor();
}
Tupla3f Malla3D::getColor(){
   return fill[0];
}


//Eficiencia O(n)
void Malla3D::calcular_normales(){
   Tupla3f normalCara;
   Tupla3f vector1,vector2,vectorPerpendicular;

   //Inicializamos nv
   for(int i=0;i<v.size();i++){
      nv.push_back(Tupla3f(0,0,0));
   }
   for(int i=0;i<f.size();i++){
      vector1=v[f[i][1]] - v[f[i][0]]; 
      vector2=v[f[i][2]] - v[f[i][0]];
      
      //Calculamos el vector perpendicular con el producto vectorial
      vectorPerpendicular=vector1.cross(vector2);

      //Comprobamos que la longitud del vector no es 0
      if(vectorPerpendicular.lengthSq() !=0){
         //Calculamos la normal a la cara del triangulo
         normalCara=vectorPerpendicular.normalized();
      }
      
      //Ahora calculamos las normales a los vertices
      nv[f[i][0]]=nv[f[i][0]]+normalCara;
      nv[f[i][1]]=nv[f[i][1]]+normalCara;
      nv[f[i][2]]=nv[f[i][2]]+normalCara;

   }

   for(int i=0;i<nv.size();i++){
      if(nv[i].lengthSq()){
         nv[i]=nv[i].normalized();
      }
   }
   
}

void Malla3D::setMaterial(Material mat){
   m=mat;
   tieneMaterial=true;
}

void Malla3D::asignarTextura(Textura *t){
   textura=t;
   texturaActivada=true;
}

void Malla3D::setTexturaActivada(bool valor){
   texturaActivada=valor;
}

void Malla3D::setCoordenadas(Tupla3f c){
   coordenadas=c;
}

Tupla3f Malla3D::getCoordenadas(){
   return coordenadas;
}

void Malla3D::borrarVBOColor(){
   id_vbo_colorSol=0;
}