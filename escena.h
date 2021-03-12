#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "tetraedro.h"
#include "esfera.h"
#include "cono.h"
#include "cilindro.h"
#include "objply.h"
#include "luzdireccional.h"
#include "luzposicional.h"
#include "coche.h"
#include "cuadroTextura.h"
#include "camara.h"

typedef enum {NADA, SELOBJETO,SELVISUALIZACION,SELDIBUJADO,TAPAS,EJES,LUCES,MOVER_GRADOS_LIBERTAD,ANIMACION,TEXTURA,CAMARAS} menu;
typedef enum {ESCENA_OBJETOS,ESCENA_LUCES,ESCENA_TEXTURA,ESCENA_FINAL,ESCENA_LATA} pintar;
typedef enum {FIRSTPERSON,EXAMINAR,NO_MOVIENDO_CAMARA} estadosRaton;

class Escena
{

   private:

   

 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
   // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;
   // Transformación de cámara
   void change_projection( const float ratio_xy );
   void change_observer();



   void clear_window();

   menu modoMenu=NADA;
   modoDibujo tipoDibujo;
   pintar EscenaActual=ESCENA_FINAL;
   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   Tetraedro * tetraedro= nullptr ; // es importante inicializarlo a 'nullptr'
   Cilindro * cilin=nullptr;
   Cono * con=nullptr;
   Esfera * esf=nullptr;
   ObjPLY * ply = nullptr;
   ObjRevolucion * objRevPly=nullptr;
   LuzDireccional * luzDir=nullptr;
   LuzPosicional * luzPos1=nullptr;
   LuzPosicional * luzCoche1=nullptr;
   LuzPosicional * luzCoche2=nullptr;
   LuzPosicional * luzPuntualAnimada=nullptr;
   ObjRevolucion * peonNegro=nullptr;
   ObjRevolucion * peonBlanco=nullptr;
   ObjRevolucion * cocacola=nullptr;
   ObjRevolucion * tapaSupCocacola=nullptr;
   ObjRevolucion * tapaInfCocacola=nullptr;
   Esfera * esfMat=nullptr;
   Coche * coche=nullptr;
   Textura * madera=nullptr;
   Textura * lata=nullptr;
   Textura * skybox=nullptr;
   Textura * ciudad=nullptr;
   Textura * carretera=nullptr;
   Textura * techo=nullptr;
   CuadroTextura * suelo=nullptr;
   CuadroTextura * cielo=nullptr;
   CuadroTextura *cuadro=nullptr;
   CuadroTextura *fondo1=nullptr;
   CuadroTextura *fondo2=nullptr;
   CuadroTextura *fondo3=nullptr;
   CuadroTextura *fondo4=nullptr;
   Cubo *cuboTextura=nullptr;
   Cubo *skyboxCubo=nullptr;
   Cubo *cuboCola=nullptr;
   Tetraedro *tetraedroTextura=nullptr;

   Material *mBlanco=nullptr;
   Material *mNegro=nullptr;
   Material *mEsfera=nullptr;
   Material *mSeleccionado=nullptr;

   int  xant,yant;
   estadosRaton estadoRaton=NO_MOVIENDO_CAMARA;

   //Vector de camaras
   std::vector<Camara> camaras;

   bool cuboPintado=true;
   bool tetraedroPintado=true;
   bool cilindroPintado=true;
   bool esferaPintado=true;
   bool conoPintado=true;
   bool objRevPlyPintado=true;
   bool plyPintado=true;
   bool tapas=true;
   bool iluminacionActivada=false;
   bool sombreadoSuave=true;
   bool modoAnimacion=false;


   int gradoLibertadSeleccionado=-1;
   int seleccionAnimacion=-1;

   bool lineas=false;
   bool solido=true;
   bool puntos=false;
   bool ajedrez=false;

   int camaraActiva=0;

   bool lucesActivadas[8]={false,false,false,false,false,false,false,false};
   bool escenaFinal=true;

   char anguloSeleccionado;

   int eje=1;

   void pintarCubo();
   void pintarTetraedro();
   void pintarCilindro();
   void pintarEsfera();
   void pintarCono();
   void pintarPly();
   
   public:

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;
   void animarModeloJerarquico();

	// Dibujar
	void dibujar() ;
   void dibujaSeleccion();

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );
   void clickRaton(int boton,int estado,int x,int y);
   void ratonMovido(int x,int y);
   void procesamientoClick(int x,int y);

   bool getAnimacion();
   void actualizarAnimacion();



};
#endif
