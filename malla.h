// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################
// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "aux.h"
#include "material.h"
#include "textura.h"

const static Tupla3f AMARILLO={1.0,1.0,0.0};
// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************
typedef enum {INMEDIATO,DIFERIDO} modoDibujo;
class Malla3D
{
   public:

   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato(bool solido,bool lineas,bool puntos,bool ajedrez);

   // dibuja el objeto en modo diferido (usando VBOs)
   void draw_ModoDiferido(bool solido,bool lineas,bool puntos,bool ajedrez);

   GLuint crearVBO(GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram);

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(bool solido,bool lineas,bool puntos,bool ajedrez);

   void establecerModoDibujado(modoDibujo modo);
   void establecerModoAjedrez(bool valor);
   void inicializarColores();
   void setColores(Tupla3f colores);
   void aplicarTextura();
   void asignarTextura(Textura *t);
   void setMaterial(Material mat);
   void setCoordenadas(Tupla3f c);
   Tupla3f getCoordenadas();
   void setTexturaActivada(bool valor);
   void borrarVBOColor();

   Tupla3f getColor();


   protected:
   modoDibujo modoDibujado=INMEDIATO;

   bool ajedrez=false;
   bool solido=true;   
   bool lineas=false;
   bool puntos=false;

   void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)

   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
   std::vector<Tupla3i> impar;
   std::vector<Tupla3i> par;
   std::vector<Tupla3f> nv;
   std::vector<Tupla2f> ct;
   Material m;
   Tupla3f coordenadas{0,0,0};
   

   // completar: tabla de colores, tabla de normales de vértices
   std::vector<Tupla3f> fill,line,point; //tabla de colores
   std::vector<Tupla3f> colorAjedrez;//tabla de colores para ajedrez

   //Identificadores de VBO inicializados a 0
   GLuint id_vbo_ver=0;
   GLuint id_vbo_tri=0;
   GLuint id_vbo_colorSol=0;
   GLuint id_vbo_colorLin=0;
   GLuint id_vbo_colorPun=0;
   GLuint id_vbo_color_2=0;
   GLuint id_vbo_tri_impar=0;
   GLuint id_vbo_tri_par=0;
   GLuint id_vbo_normales=0;

   int vertices,caras;

   bool tieneMaterial=false;
   bool texturaActivada=false;
   Textura *textura=nullptr;

} ;


#endif
