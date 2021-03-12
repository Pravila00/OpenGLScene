

#include "aux.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************



Escena::Escena()
{
   Front_plane       = 50.0;
   Back_plane        = 2000.0;
   Observer_distance = 4*Front_plane;
   Observer_angle_x  = 0.0 ;
   Observer_angle_y  = 0.0 ;

   ejes.changeAxisSize( 5000 );

   // crear los objetos de la escena....
   cubo = new Cubo();
   tetraedro= new Tetraedro();
   cilin= new Cilindro(4,32,80,50);
   con = new Cono(3,32,25,40);
   ply = new ObjPLY("plys/beethoven.ply");
   objRevPly = new ObjRevolucion("plys/peon.ply",40,true,true,eje);
   esf= new Esfera(50,20,25);
   cubo->setColores(Tupla3f(0.1,0.5,0.5));
   tetraedro->setColores(Tupla3f(0.2,0.5,0.5));
   cilin->setColores(Tupla3f(0.3,0.5,0.5));
   esf->setColores(Tupla3f(0.4,0.5,0.5));
   con->setColores(Tupla3f(0.5,0.5,0.5));
   ply->setColores(Tupla3f(0.6,0.5,0.5));
   objRevPly->setColores(Tupla3f(0.7,0.5,0.5));
    
    /*************************************************/
   //Luces
   //Luz 0
   luzDir= new LuzDireccional(Tupla2f(25.0,25.0),GL_LIGHT0,Tupla4f(0.0,0.0,0.0,1.0),Tupla4f(1.0,1.0,0.0,1.0),Tupla4f(1.0,1.0,0.0,1.0));
   
   //Luz 1
   luzPos1=new LuzPosicional(Tupla3f(0.0,100.0,0.0),GL_LIGHT1,Tupla4f(0.0,0.0,0.0,1.0),Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(1.0,1.0,1.0,1.0));

   //Luz Coche 1
   luzCoche1=new LuzPosicional(Tupla3f(60.0,5.0,50.0),GL_LIGHT2,Tupla4f(0.0,0.0,0.0,1.0),Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(1.0,1.0,1.0,1.0));

   //Luz Coche 2
   luzCoche2=new LuzPosicional(Tupla3f(60.0,5.0,-50.0),GL_LIGHT3,Tupla4f(0.0,0.0,0.0,1.0),Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(1.0,1.0,1.0,1.0));

   //Luz Puntual Animada
   luzPuntualAnimada=new LuzPosicional(Tupla3f(100.0,20.0,0.0),GL_LIGHT1,Tupla4f(0.0,0.0,0.0,1.0),Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(1.0,1.0,1.0,1.0));
   
   /*************************************************/
   //Objetos con material para probar las luces
   //Peones con material
   mBlanco=new Material(Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(0.0,0.0,0.0,0.0),Tupla4f(1.0,1.0,1.0,1.0),1.0f);
   mNegro=new Material(Tupla4f(0.0,0.0,0.0,0.0),Tupla4f(0.0,0.0,0.0,0.0),Tupla4f(0.2,0.2,0.2,0.2),1.0f);

   peonBlanco=new ObjRevolucion("plys/peon.ply",40,true,true,eje);
   peonBlanco->setColores(Tupla3f(0.3,0.3,0.3));
   peonBlanco->setMaterial(*mBlanco);

   //peonBlanco->setMaterial(mBlanco);

   peonNegro=new ObjRevolucion("plys/peon.ply",40,true,true,eje);
   peonNegro->setColores(Tupla3f(0,0,0));
   peonNegro->setMaterial(*mNegro);
   
   //Esfera con material
   mEsfera=new Material(Tupla4f(0.0,1.0,1.0,0.0),Tupla4f(0.0,1.0,1.0,0.0),Tupla4f(0.0,1.0,1.0,0.0),1);
   esfMat=new Esfera(50,20,25);
   esfMat->setColores(Tupla3f(0.5,0,1));
   esfMat->setMaterial(*mEsfera);

   //Material de seleccion
   mSeleccionado=new Material(Tupla4f(0.75164,0.606,0.226,0.0),Tupla4f(0.628,0.555,0.366,0.0),Tupla4f(0.24725,0.1995,0.0745,0.0),0.4);
   /*************************************************/
   //Modelo jerarquico
   coche=new Coche();

   /*************************************************/
   //Textura
   cuadro=new CuadroTextura(100);
   madera=new Textura("texturas/text-madera.jpg");
   ciudad=new Textura("texturas/ciudad.jpg");
   carretera=new Textura("texturas/carretera.jpg");
   techo=new Textura("texturas/techo.jpg");
   lata=new Textura("texturas/text-lata-1.jpg");
   cuboTextura=new Cubo(100);
   cocacola=new ObjRevolucion("plys/lata-pcue.ply",40,false,false,eje,true);
   tapaSupCocacola=new ObjRevolucion("plys/lata-pinf.ply",40,false,false,eje);
   tapaInfCocacola=new ObjRevolucion("plys/lata-psup.ply",40,false,false,eje);
   skyboxCubo=new Cubo(1250);
   suelo=new CuadroTextura(1200);
   fondo1=new CuadroTextura(1200);
   fondo2=new CuadroTextura(1200);
   fondo3=new CuadroTextura(1200);
   fondo4=new CuadroTextura(1200);
   cielo=new CuadroTextura(1200);
   cuboCola=new Cubo(100);
   //Colores
   cuadro->setColores(Tupla3f(0.2,0.2,0.2));
   cuboTextura->setColores(Tupla3f(0.4,0.4,0.4));
   cuboCola->setColores(Tupla3f(0.6,0.4,0.4));

   tetraedroTextura=new Tetraedro();
   cuadro->asignarTextura(lata);
   suelo->asignarTextura(carretera);
   cielo->asignarTextura(techo);
   cuboTextura->calcularTextura();
   cuboTextura->asignarTextura(madera);
   cuboCola->calcularTextura();
   cuboCola->asignarTextura(lata);
   tetraedroTextura->asignarTexturaT(madera);
   tetraedroTextura->setTexturaActivada(true);
   skyboxCubo->calcularTextura();
   skyboxCubo->asignarTextura(ciudad);
   cocacola->asignarTextura(lata);
   fondo1->asignarTextura(ciudad);
   fondo2->asignarTextura(ciudad);
   fondo3->asignarTextura(ciudad);
   fondo4->asignarTextura(ciudad);
   /*************************************************/
   //Camaras
   //Camara Perspectiva
   Camara c1(Tupla3f(0,0,200),Tupla3f(0,0,0),Tupla3f(0,1,0),PERSPECTIVA,50,1500,-400,400,400,-400);
   //Camara Ortogonal 1
   Camara c2(Tupla3f(0,0,-200),Tupla3f(0,0,0),Tupla3f(0,1,0),ORTOGONAL,50,1500,-100,100,100,-100);
   //Camara ortogonal 2
   Camara c3(Tupla3f(50,150,200),Tupla3f(0,0,0),Tupla3f(0,1,0),ORTOGONAL,50,1500,-400,400,400,-400);
   

   camaras.push_back(c1);
   camaras.push_back(c2); 
   camaras.push_back(c3);
   //camaras.push_back(c4);

   /*************************************************/
   //Mostrar opciones
   using namespace std ;
   cout <<"Opciones disponibles: "<<endl;
   cout <<"'O': Seleccion de escena"<<endl;
   cout <<"'V': Seleccion de modo de visualizacion"<<endl;
   cout <<"'D': Seleccion de modo de dibujado"<<endl;
   cout <<"'T': Seleccion de tapas"<<endl;
   cout <<"'E': Seleccion de ejes"<<endl;
   cout <<"'W': Seleccion de camaras"<<endl;
   cout <<"'U': Configuracion de luces"<<endl;
   cout <<"'C': Configuracion de la animacion"<<endl;
   cout <<"'M': Mover manualmente el grado de libertad"<<endl;
   

}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer
   glEnable(GL_NORMALIZE); //Para evitar que se altere la longitud de las normales

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
   tipoDibujo=INMEDIATO;
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
   glDisable(GL_LIGHTING);
   ejes.draw();
   glEnable(GL_CULL_FACE);
   glCullFace(GL_FRONT);
   if(EscenaActual==ESCENA_FINAL){
      skyboxCubo->draw(solido,lineas,puntos,ajedrez);
   }
   glCullFace(GL_BACK);
   

   // COMPLETAR
   //   Dibujar los diferentes elementos de la escena
   // Habrá que tener en esta primera práctica una variable que indique qué objeto se ha de visualizar
   

   //Luz ambiente global
   GLfloat lmodel_ambient[] = {0.2,0.2,0.2,1.0};
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);

   if(iluminacionActivada){
      glEnable(GL_LIGHTING);
      if(lucesActivadas[0])
         luzDir->activar();
      else
         luzDir->desactivar();

      if(lucesActivadas[1])
         luzPos1->activar();
      else
         luzPos1->desactivar();

      if(lucesActivadas[2])
         luzCoche1->activar();
      else
         luzCoche1->desactivar();

      if(lucesActivadas[3])
         luzCoche2->activar();
      else
         luzCoche2->desactivar();     
            
      if(lucesActivadas[4]){
         //Modificamos la luz
         luzPuntualAnimada->animacionLuz(Tupla3f(5.0,0.0,2.5));
         //La volvemos a activar
         luzPuntualAnimada->activar();
      }
      else{
         luzPuntualAnimada->desactivar();   
      }

      if(sombreadoSuave){
         glShadeModel(GL_SMOOTH);     
      }
      else{
         glShadeModel(GL_FLAT);
      }   

      //En funcion del tipo de camara
      if(camaras[camaraActiva].getTipo()==ORTOGONAL){
         glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_FALSE );
      }
      else{
         glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE );
      }
   }

   switch(EscenaActual){
      case ESCENA_FINAL:
         glEnable(GL_TEXTURE_2D);
         glPushMatrix();
            glTranslatef(0,-600,0);
            glRotatef(270,1,0,0);
            glRotatef(90,0,0,1);
            suelo->draw(solido,lineas,puntos,ajedrez);
         glPopMatrix();

         glPushMatrix();
            glTranslatef(0,600,0);
            glRotatef(90,1,0,0);
            cielo->draw(solido,lineas,puntos,ajedrez);
         glPopMatrix();




         glDisable(GL_TEXTURE_2D);
         glPushMatrix();
            coche->establecerModoDibujado(tipoDibujo);
            glScalef(40,50,80);
            coche->establecerModoDibujado(tipoDibujo);
            coche->dibujar(solido,lineas,puntos,ajedrez);
         glPopMatrix();
      break;

      case ESCENA_OBJETOS:
         glDisable(GL_TEXTURE_2D);
         //Cubo
         if(camaras[camaraActiva].getObjetoFijado()==CUBO){
            cubo->setColores(AMARILLO);
         }
         else{
            cubo->setColores(Tupla3f(0.1,0.5,0.5));
         }
         glPushMatrix();
            glTranslatef(-100.0f,0.0f,0.0f);
            cubo->setCoordenadas(Tupla3f(-100,0,0));
            cubo->establecerModoDibujado(tipoDibujo);
            cubo->draw(solido,lineas,puntos,ajedrez);
         glPopMatrix();
   
         //Tetraedro
         if(camaras[camaraActiva].getObjetoFijado()==TETRAEDRO){
            tetraedro->setColores(AMARILLO);
         }
         else{
            tetraedro->setColores(Tupla3f(0.2,0.5,0.5));
         }
         glPushMatrix();
            glTranslatef(0.0f,0.0f,0.0f);
            tetraedro->establecerModoDibujado(tipoDibujo);
            tetraedro->draw(solido,lineas,puntos,ajedrez);
         glPopMatrix();

         //Cilindro
         if(camaras[camaraActiva].getObjetoFijado()==CILINDRO){
            cilin->setColores(AMARILLO);
         }
         else{
            cilin->setColores(Tupla3f(0.3,0.5,0.5));
         }
         glPushMatrix();
            glTranslatef(100.0f,0.0f,0.0f);
            cilin->setCoordenadas(Tupla3f(100,0,0));
            cilin->establecerModoDibujado(tipoDibujo);
            cilin->drawObjRev(tapas,solido,lineas,puntos,ajedrez);
         glPopMatrix();
      
         //Esfera
         if(camaras[camaraActiva].getObjetoFijado()==ESFERA){
            esf->setColores(AMARILLO);
         }
         else{
            esf->setColores(Tupla3f(0.4,0.5,0.5));
         }
         glPushMatrix();
            glTranslatef(0.0f,100.0f,0.0f);
            esf->setCoordenadas(Tupla3f(0,100,0));
            esf->establecerModoDibujado(tipoDibujo);
            esf->drawObjRev(tapas,solido,lineas,puntos,ajedrez);
         glPopMatrix();
      
         //Cono
         if(camaras[camaraActiva].getObjetoFijado()==CONO){
            con->setColores(AMARILLO);
         }
         else{
            con->setColores(Tupla3f(0.5,0.5,0.5));
         }
         glPushMatrix();
            glTranslatef(0.0f,-150.0f,0.0f);
            con->setCoordenadas(Tupla3f(0,-150,0));
            con->establecerModoDibujado(tipoDibujo);
            con->drawObjRev(tapas,solido,lineas,puntos,ajedrez);
         glPopMatrix();
      
         //Objeto PLY
         if(camaras[camaraActiva].getObjetoFijado()==BEETHOVEN){
            ply->setColores(AMARILLO);
         }
         else{
            ply->setColores(Tupla3f(0.6,0.5,0.5));
         }
         glPushMatrix();
            glTranslatef(220.0f,0.0f,0.0f);
            ply->setCoordenadas(Tupla3f(220,0,0));
            glScalef(10,10,10);
            ply->establecerModoDibujado(tipoDibujo);
            ply->draw(solido,lineas,puntos,ajedrez);
         glPopMatrix();

         //Obj de revolucion PLY (Peon)
         if(camaras[camaraActiva].getObjetoFijado()==PEON){
            objRevPly->setColores(AMARILLO);
         }
         else{
            objRevPly->setColores(Tupla3f(0.7,0.5,0.5));
         }
         glPushMatrix();
            glTranslatef(-220.0f,0.0f,0.0f);
            objRevPly->setCoordenadas(Tupla3f(-220,0,0));
            glScalef(20,20,20);
            objRevPly->establecerModoDibujado(tipoDibujo);
            objRevPly->drawObjRev(tapas,solido,lineas,puntos,ajedrez);
         glPopMatrix();
      break;

      case ESCENA_LUCES:
         glDisable(GL_TEXTURE_2D);
         //Peon Negro
         if(camaras[camaraActiva].getObjetoFijado()==PEON_NEGRO){
            peonNegro->setColores(AMARILLO);
            peonNegro->setMaterial(*mSeleccionado);
         }
         else{
            peonNegro->setColores(Tupla3f(0,0,0));
            peonNegro->setMaterial(*mNegro);
         }
         glPushMatrix();
            glTranslatef(100.0f,0.0f,0.0f);
            peonNegro->setCoordenadas(Tupla3f(100,0,0));
            glScalef(20,20,20);
            peonNegro->establecerModoDibujado(tipoDibujo);
            peonNegro->drawObjRev(tapas,solido,lineas,puntos,ajedrez);
         glPopMatrix();
         
         //Peon Blanco
         if(camaras[camaraActiva].getObjetoFijado()==PEON_BLANCO){
            peonBlanco->setColores(AMARILLO);
            peonBlanco->setMaterial(*mSeleccionado);
         }
         else{
            peonBlanco->setColores(Tupla3f(0.3,0.3,0.3));
            peonBlanco->setMaterial(*mBlanco);
         }
         glPushMatrix();
            glTranslatef(-100.0f,0.0f,0.0f);
            peonBlanco->setCoordenadas(Tupla3f(-100,0,0));
            glScalef(20,20,20);
            peonBlanco->establecerModoDibujado(tipoDibujo);
            peonBlanco->drawObjRev(tapas,solido,lineas,puntos,ajedrez);
         glPopMatrix();

         //Esfera
         if(camaras[camaraActiva].getObjetoFijado()==ESF_MAT){
            esfMat->setColores(AMARILLO);
            esfMat->setMaterial(*mSeleccionado);
         }
         else{
            esfMat->setColores(Tupla3f(0.5,0,1));
            esfMat->setMaterial(*mEsfera);
         }
         glPushMatrix();
            esfMat->establecerModoDibujado(tipoDibujo);
            esfMat->drawObjRev(tapas,solido,lineas,puntos,ajedrez);
         glPopMatrix();
      break;

      case ESCENA_TEXTURA:
         
         glPushMatrix();
            cuboCola->establecerModoDibujado(tipoDibujo);
            cuboCola->draw(solido,lineas,puntos,ajedrez);
         glPopMatrix();
         //Objeto con textura
         glPushMatrix();
            glTranslatef(-150.0,0.0,0.0);
            cuboTextura->establecerModoDibujado(tipoDibujo);
            cuboTextura->setCoordenadas(Tupla3f(-150,0,0));
            cuboTextura->draw(solido,lineas,puntos,ajedrez);
         glPopMatrix();

         //Cuadro con textura
         glPushMatrix();
            glTranslatef(150.0,0.0,0.0);
            cuadro->setCoordenadas(Tupla3f(150,0,0));
            cuadro->establecerModoDibujado(tipoDibujo);
            cuadro->draw(solido,lineas,puntos,ajedrez);
         glPopMatrix();
      break;

      case ESCENA_LATA:
         //Tapa superior
         glPushMatrix();

         glPopMatrix();

         //Cuerpo
         glPushMatrix();
            //cocacola->establecerModoDibujado(tipoDibujo);
            glTranslatef(0,-75,0);
            glScalef(150,150,150);
            cocacola->drawObjRev(true,solido,lineas,puntos,ajedrez);
         glPopMatrix();

         //Tapa inferior
         glPushMatrix();

         glPopMatrix();
      break;
   }
}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout <<"Opciones disponibles: "<<endl;
   cout <<"'O': Seleccion de objetos/escena"<<endl;
   cout <<"'V': Seleccion de modo de visualizacion"<<endl;
   cout <<"'D': Seleccion de modo de dibujado"<<endl;
   cout <<"'T': Seleccion de tapas"<<endl;
   cout <<"'E': Seleccion de ejes"<<endl;
   cout <<"'U': Configuracion de luces"<<endl;
   cout <<"'C': Configuracion de la animacion"<<endl;
   cout <<"'M': Mover manualmente el grado de libertad"<<endl;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   
   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu!=NADA)
            modoMenu=NADA;            
         else {
            salir=true ;
         }
      break ;
      //Seleccion de objetos
      case 'O' :
         modoMenu=SELOBJETO;
      break;

      //Seleccion de modo de visualizacion
      case 'V' :
         modoMenu=SELVISUALIZACION;
      break;

      //Seleccion de modo de dibujado
      case 'D' :
         modoMenu=SELDIBUJADO;
      break;            

      //Seleccion de tapas
      case 'T' :
         modoMenu=TAPAS;
      break;

      //Seleccion del eje
      case 'E' :
         modoMenu=EJES;
      break;

      case 'U':
         modoMenu=menu::LUCES;
      break;

      case 'M':
         modoMenu=MOVER_GRADOS_LIBERTAD;
      break;

      case 'C':
         modoMenu=ANIMACION;
      break;

      case 'W':
         modoMenu=CAMARAS;
      break;

   }

   switch(modoMenu){
         case SELOBJETO:
            cout <<"Opciones disponibles MODO SEL OBJETO:\n";
            cout <<"'0': Escena Final"<<endl;
            cout <<"'1': Objetos basicos simultaneos"<<endl;
            cout <<"'2': Escena para probar luces"<<endl;
            cout <<"'3': Escena para probar texturas"<<endl;
            //cout <<"'4': Escena para visualizar la lata"<<endl;
            switch(toupper(tecla)){
               case '0':   EscenaActual=ESCENA_FINAL; break;
               case '1':   EscenaActual=ESCENA_OBJETOS; break;
               case '2':   EscenaActual=ESCENA_LUCES; break;
               case '3':   EscenaActual=ESCENA_TEXTURA; break;
               //case '4':   EscenaActual=ESCENA_LATA;  break;
            }
         break;

         case SELVISUALIZACION:
            cout <<"Opciones disponibles:\n";
            cout <<"'P': Puntos\n";
            cout <<"'L': Lineas\n";
            cout <<"'S': Solido\n";
            cout <<"'A': Ajedrez\n";
            cout <<"'H': Iluminacion\n";
            cout <<"'Q': Salir\n";
            switch(toupper(tecla)){
               //Puntos
               case 'P': 
                  glDisable(GL_LIGHTING);
                  iluminacionActivada=false;
                  puntos?puntos=false:puntos=true;
                  if(puntos)
                     cout<<"Modo Puntos activado\n";
                  else
                     cout<<"Modo Puntos desactivado\n";
               break;
               //Alambre
               case 'L': 
                  glDisable(GL_LIGHTING);
                  iluminacionActivada=false;
                  lineas?lineas=false:lineas=true;
                  if(lineas)
                     cout<<"Modo Lineas activado\n";
                  else
                     cout<<"Modo Lineas desactivado\n";
               break;
               //Solido
               case 'S': 
                  glDisable(GL_LIGHTING);
                  iluminacionActivada=false;
                  solido?solido=false:solido=true;
                  if(solido)
                     cout<<"Modo Solido activado\n";
                  else
                     cout<<"Modo Solido desactivado\n";
               break;
               //Ajedrez
               case 'A': 
                  glDisable(GL_LIGHTING);
                  iluminacionActivada=false;
                  ajedrez?ajedrez=false:ajedrez=true;
                  if(ajedrez){
                     cout<<"Modo Ajedrez activado\n";
                     cout<<"Asegurese de que los otros modos estan desactivados\n";
                  }
                  else
                     cout<<"Modo Ajedrez desactivado\n";
               break;
               
               //Se activa la visualizacion con iluminacion
               case 'H':
                  //Activamos las luces
                  glEnable(GL_LIGHTING); //Se enciende el cuadro de luz
                  iluminacionActivada=true;
                  cout <<"Luces Activadas\n";
               break;

               //Salir de la opcion
               case 'Q': modoMenu=NADA;  break;
            }
         break;

         case SELDIBUJADO:
            cout <<"Opciones disponibles:\n";
            cout <<"'1': Modo Inmediato\n";
            cout <<"'2': Modo diferido\n";
            cout <<"'Q': Salir\n";
            switch(toupper(tecla)){
               case '1':  
                  tipoDibujo=INMEDIATO;
                  cout <<"Se dibuja en Inmediato"<<endl;
                  
               break;
               case '2':  
                  tipoDibujo=DIFERIDO;
                  cout <<"Se dibuja en Diferido"<<endl;
               break;
               case 'Q':  modoMenu=NADA; break;
            }
         break;

         case TAPAS:
            cout <<"Opciones disponibles: \n";
            cout <<"'1': Tapas activas\n";
            cout <<"'2': Tapas desactivadas\n";
            switch(toupper(tecla)){
               case '1': tapas=true; cout <<"Tapas activadas\n";break;
               case '2': tapas=false;cout <<"Tapas desactivadas\n";break;
            }
         break;

         case ANIMACION:
            cout <<"Opciones disponibles: \n";
            cout <<"\t'0': Activar/Desactivar Animacion del Coche\n";
            cout <<"\t'1': Seleccionar velocidad general\n";
            cout <<"\t'2': Seleccionar velocidad puertas\n";
            cout <<"\t'3': Seleccionar velocidad tronco\n";
            cout <<"\t'4': Seleccionar velocidad ventana\n";
            cout <<"\t'+': Aumentar velocidad\n";
            cout <<"\t'-': Disminuir velocidad\n";
            switch(toupper(tecla)){
               case '0':   actualizarAnimacion();   break;
               case '1':   seleccionAnimacion=1;   break;
               case '2':   seleccionAnimacion=2;   break;
               case '3':   seleccionAnimacion=3;   break;
               case '4':   seleccionAnimacion=4;   break;
               case '+':
                  switch(seleccionAnimacion){
                     case 1: 
                        coche->aumentarVelocidadGeneral(); 
                        cout <<"Aumenta la velocidad GENERAL\n";
                     break;
                     
                     case 2: 
                        coche->aumentarVelocidadPuertas(); 
                        cout <<"Aumenta la velocidad PUERTAS\n";
                     break;
                     
                     case 3: 
                        coche->aumentarVelocidadTronco(); 
                        cout <<"Aumenta la velocidad TRONCO\n";
                     break;
                     
                     case 4: 
                        coche->aumentarVelocidadVentanas(); 
                        cout <<"Aumenta la velocidad VENTANAS\n";
                     break;
                  }
               break;

               case '-':
                  switch(seleccionAnimacion){
                     case 1: 
                        coche->disminuirVelocidadGeneral(); 
                        cout <<"Disminuye la velocidad GENERAL\n";
                     break;
                     
                     case 2: 
                        coche->disminuirVelocidadPuertas(); 
                        cout <<"Disminuye la velocidad PUERTAS\n";
                     break;
                     
                     case 3: 
                        coche->disminuirVelocidadTronco(); 
                        cout <<"Disminuye la velocidad TRONCO\n";
                     break;
                     
                     case 4: 
                        coche->disminuirVelocidadVentanas(); 
                        cout <<"Disminuye la velocidad VENTANAS\n";
                     break;
                  }
               break;
            }

         break;
         case EJES:
            cout<<"Opciones disponibles: \n";
            cout <<"'0': Eje x\n";
            cout <<"'1': Eje y\n";
            cout <<"'2': Eje z\n";
            cout <<"'Q': Salir\n";
            switch(toupper(tecla)){
               case '0': 
                  eje=0; 
                  objRevPly = new ObjRevolucion("plys/peon.ply",40,true,true,eje);
                  cout <<"Rotacion en eje x\n";
               break;
               case '1': 
                  eje=1; 
                  objRevPly = new ObjRevolucion("plys/peon.ply",40,true,true,eje);
                  cout <<"Rotacion en eje y\n";
               break;
               case '2': 
                  eje=2;
                  objRevPly = new ObjRevolucion("plys/peon.ply",40,true,true,eje);
                  cout <<"Rotacion en eje z\n";
               break;
               case 'Q':  modoMenu=NADA; break;

            }
         break;
         case MOVER_GRADOS_LIBERTAD:
            cout<<"Opciones disponibles: \n";
            cout <<"'0': Trasladar Tronco\n";
            cout <<"'1': Rotar Puerta 1\n";
            cout <<"'2': Rotar Puerta 2\n";
            cout <<"'3': Abrir/Cerrar Ventana1\n";
            cout <<"'4': Abrir/Cerrar Ventana2\n";
            cout <<"'+': Aumentar el grado de libertad\n";
            cout <<"'-': Disminuir el grado de libertad\n";
            cout <<"'Q': Salir";
            switch(toupper(tecla)){
               case '0':
                  gradoLibertadSeleccionado=0;
                  cout <<"Has seleccionad el TRONCO\n";
               break;

               case '1':
                  gradoLibertadSeleccionado=1;
                  cout <<"Has seleccionad la PUERTA 1\n";
               break;

               case '2':
                  gradoLibertadSeleccionado=2;
                  cout <<"Has seleccionad la PUERTA 2\n";
               break;

               case '3':
                  gradoLibertadSeleccionado=3;
                  cout <<"Has seleccionad la VENTANA 1\n";
               break;

               case '4':
                  gradoLibertadSeleccionado=4;
                  cout <<"Has seleccionad la VENTANA 2\n";
               break;

               case '+':
                  switch(gradoLibertadSeleccionado){
                     case 0: coche->avanzarTronco();cout<<"Avanzas el tronco\n"; break;
                     case 1: coche->abrirPuerta1();cout <<"Abres la puerta 1\n"; break;
                     case 2: coche->abrirPuerta2();cout <<"Abres la puerta 2\n";  break;
                     case 3: coche->abrirVentana1();cout <<"Abres la ventana 1\n"; break;
                     case 4: coche->abrirVentana2();cout <<"Abres la ventana 2\n";  break;
                  }
               break;

               case '-':
                  switch(gradoLibertadSeleccionado){
                     case 0: coche->retrocederTronco(); cout<<"Retrocedes el tronco\n"; break;
                     case 1: coche->cerrarPuerta1(); cout <<"Cierras la puerta 1\n"; break;
                     case 2: coche->cerrarPuerta2(); cout <<"Cierras la puerta 1\n"; break;
                     case 3: coche->cerrarVentana1();cout<<"Cierras la ventana 1\n"; break;
                     case 4: coche->cerrarVentana2();cout<<"Cierras la ventana 2\n";  break;
                  }
               break;
               case 'Q':  modoMenu=NADA; break;
            }
         break;

         case CAMARAS:
            cout<<"Opciones disponibles\n";
            cout<<"'0': Activa la camara 0 (PERSPECTIVA)\n";
            cout<<"'1': Activa la camara 1 (ORTOGONAL)\n";
            cout<<"'2': Activa la camara 2 (ORTOGONAL)\n";
            cout<<"'3': La camara activa mira al centro";
            cout<<"'Q': Salir\n";
            switch(toupper(tecla)){
               case '0':   camaraActiva=0; change_projection(0); change_observer();   break;
               case '1':   camaraActiva=1; change_projection(0); change_observer();  break;
               case '2':   camaraActiva=2; change_projection(0); change_observer();  break;
               case '3': camaras[camaraActiva].mover(Tupla3f(0,0,0));   break;
               case 'Q':   modoMenu=NADA; break;
            }
         break;

         case menu::LUCES:
            cout <<"Opciones disponibles \n";
            cout <<"'0: Activar/Desactiar la luz Dir\n";
            cout <<"'2: Activar/Desactivar la luz Coche Pos 1\n";
            cout <<"'3: Activar/Desactivar la luz Coche Pos 2\n";
            cout <<"'4: Activa la luz puntual\n";
            cout <<"'5': Sombreado Suave | Sombreado Plano\n";
            cout <<"'A': Activa la variacion del angulo alfa\n";
            cout <<"'B': Activa la variacion del angulo beta\n";
            cout <<"'>': Incrementa el angulo seleccionado\n";
            cout <<"'<': Decrementa el angulo seleccionado\n";
            cout <<"'Q': Salir\n";

            switch(toupper(tecla)){
               case '0':   lucesActivadas[0]?lucesActivadas[0]=false:lucesActivadas[0]=true;  break;
               case '2':   lucesActivadas[2]?lucesActivadas[2]=false:lucesActivadas[2]=true;  break;
               case '3':   lucesActivadas[3]?lucesActivadas[3]=false:lucesActivadas[3]=true;  break;
               case '4':   lucesActivadas[4]?lucesActivadas[4]=false:lucesActivadas[4]=true;  break;
               case '5':   
                  sombreadoSuave?sombreadoSuave=false:sombreadoSuave=true; 
                  if(sombreadoSuave){
                     cout<<"Se usa SOMBREADO SUAVE\n";
                  }
                  else{
                     cout<<"Se usa SOMBREADO PLANO\n";
                  }
               break;
               case 'A':  anguloSeleccionado='a'; cout<<"Se selecciona el angulo ALFA\n";   break;
               case 'B':  anguloSeleccionado='b'; cout<<"Se selecciona el angulo BETA\n";   break;
               case '>':      
                  if(anguloSeleccionado=='a'){
                     luzDir->variarAnguloAlpha(1);
                     luzDir->activar();
                  }
                  else{
                     luzDir->variarAnguloBeta(1);
                     luzDir->activar();
                  }
               break;
               case '<':   
                  if(anguloSeleccionado=='a'){
                     luzDir->variarAnguloAlpha(-5);
                     luzDir->activar();
                  }
                  if(anguloSeleccionado=='b'){
                     luzDir->variarAnguloBeta(-5);
                     luzDir->activar();
                  }   
               break;
               case 'Q':  modoMenu=NADA; break;
            }
         break;
      }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         if(camaras[camaraActiva].getObjetoFijado()!=NINGUNO){
            camaras[camaraActiva].rotarYExaminar(-0.25);
         }
         else{
            camaras[camaraActiva].rotarYFirstPerson(-0.25);
         }
            
      break;
	   case GLUT_KEY_RIGHT:
         if(camaras[camaraActiva].getObjetoFijado()!=NINGUNO){
            camaras[camaraActiva].rotarYExaminar(0.25);
         }
         else{
            camaras[camaraActiva].rotarYFirstPerson(0.25);
         }
      break;
	   case GLUT_KEY_UP:
         if(camaras[camaraActiva].getObjetoFijado()!=NINGUNO){
            camaras[camaraActiva].rotarXExaminar(-0.25);
         }
         else{
            camaras[camaraActiva].rotarXFirstPerson(-0.25);
         }
      break;
	   case GLUT_KEY_DOWN:
         if(camaras[camaraActiva].getObjetoFijado()!=NINGUNO){
            camaras[camaraActiva].rotarXExaminar(0.25);
         }
         else{
            camaras[camaraActiva].rotarXFirstPerson(0.25);
         }
      break;
	   case GLUT_KEY_PAGE_UP:
         camaras[camaraActiva].zoom(0.9);
      break;
	   case GLUT_KEY_PAGE_DOWN:
         camaras[camaraActiva].zoom(1.1);
      break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   camaras[camaraActiva].setProyeccion();
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   camaras[camaraActiva].setObserver();

}

void Escena::pintarCubo(){
   cuboPintado?cuboPintado=false:cuboPintado=true;
}

void Escena::pintarTetraedro(){
   tetraedroPintado?tetraedroPintado=false:tetraedroPintado=true;
}

void Escena::pintarCilindro(){   
   cilindroPintado?cilindroPintado=false:cilindroPintado=true;
}

void Escena::pintarEsfera(){
   esferaPintado?esferaPintado=false:esferaPintado=true;
}

void Escena::pintarCono(){
   conoPintado?conoPintado=false:conoPintado=true;
}

void Escena::pintarPly(){
   plyPintado?plyPintado=false:plyPintado=true;
}

void Escena::animarModeloJerarquico(){
   if(modoAnimacion){
      coche->animar();
   }

}

bool Escena::getAnimacion(){
   return modoAnimacion;
}

void Escena::actualizarAnimacion(){
   modoAnimacion?modoAnimacion=false:modoAnimacion=true;
}

void Escena::clickRaton(int boton,int estado,int x,int y){
   //Se pulsa el boton derecho, se entra al estado moviendo camara
   if(boton == GLUT_RIGHT_BUTTON){
      if(estado==GLUT_DOWN){
         xant=x;
         yant=y;
         if(camaras[camaraActiva].getObjetoFijado()!=NINGUNO){
            estadoRaton=EXAMINAR;
         }
         else{
            estadoRaton=FIRSTPERSON;
         }
         
         
      }  
      else{
         estadoRaton=NO_MOVIENDO_CAMARA;
      }

   }
   else if(boton == GLUT_LEFT_BUTTON){
      if(estado==GLUT_DOWN){
         procesamientoClick(x,y);
      }
   }
   else if(boton == 3 ){
      if(estado==GLUT_UP){
         camaras[camaraActiva].zoom(0.75);
      }
   }
   else if(boton == 4){
      if(estado==GLUT_UP){
         camaras[camaraActiva].zoom(1.25);
      }
   }
}

void Escena::ratonMovido(int x,int y){
   if(estadoRaton==FIRSTPERSON){
      camaras[camaraActiva].girarFP(x-xant,y-yant);
      yant=y;
      xant=x;
   }
   else if(estadoRaton==EXAMINAR){
      camaras[camaraActiva].girarEX(x-xant,y-yant);
      yant=y;
      xant=x;    
   }
}


void Escena::dibujaSeleccion(){
   glDisable(GL_DITHER);   //Deshabilita el degradado
   glDisable(GL_LIGHTING);
   glDisable(GL_TEXTURE);

   change_observer();

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


   dibujar();

   glEnable(GL_DITHER);
   glEnable(GL_LIGHTING);
   glEnable(GL_TEXTURE);
   
}

void Escena::procesamientoClick(int x,int y){
   glDisable(GL_DITHER);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

   GLfloat pixels[3];
   GLint viewport[4];
   glGetIntegerv(GL_VIEWPORT,viewport);
   bool auxLuz=iluminacionActivada;
   //DESACTIVAMOS LUCES Y TEXTURAS
   iluminacionActivada=false;
   tetraedroTextura->setTexturaActivada(false);
   cuadro->setTexturaActivada(false);
   cuboTextura->setTexturaActivada(false);
   skyboxCubo->setTexturaActivada(false);
   cuboCola->setTexturaActivada(false);
   //PINTAMOS SIN LA LUZ PARA PODER SELECCIONAR EL COLOR
   dibujar();
   //ACTIVAMOS LAS TEXTURAS
   tetraedroTextura->setTexturaActivada(true);
   cuadro->setTexturaActivada(true);
   cuboTextura->setTexturaActivada(true);
   cuboCola->setTexturaActivada(true);
   skyboxCubo->setTexturaActivada(true);
   glReadPixels(x,viewport[3]-y,1,1,GL_RGB,GL_FLOAT,(void *)pixels);
   iluminacionActivada=auxLuz;
   Tupla3f colorSel(pixels[0],pixels[1],pixels[2]);
   switch(EscenaActual){
      case ESCENA_OBJETOS:
         if(colorSel[0]==1){
            std::cout <<"Se selecciona NINGUNO\n";
            camaras[camaraActiva].mover(Tupla3f(0,0,0));
            camaras[camaraActiva].setObjetoFijado(NINGUNO);
         }
         //Cubo
         else if(fabs(colorSel[0]-cubo->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona el CUBO\n";
            camaras[camaraActiva].mover(cubo->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(CUBO);
         }
         //Tetraedro
         else if(fabs(colorSel[0]-tetraedro->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona el TETRAEDRO\n";
            camaras[camaraActiva].mover(tetraedro->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(TETRAEDRO);
         }


         //Cilindro
         else if(fabs(colorSel[0]-cilin->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona el CILINDRO\n";
            camaras[camaraActiva].mover(cilin->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(CILINDRO);
         }

         //Esfera
         else if(fabs(colorSel[0]-esf->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona la ESFERA\n";
            camaras[camaraActiva].mover(esf->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(ESFERA);
         }

         //Cono
         else if(fabs(colorSel[0]-con->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona el CONO\n";
            camaras[camaraActiva].mover(con->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(CONO);
         }

         //Beethoven
         else if(fabs(colorSel[0]-ply->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona BEETHOVEN \n";
            camaras[camaraActiva].mover(ply->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(BEETHOVEN);
         }

         //Peon
         else if(fabs(colorSel[0]-objRevPly->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona el PEON\n";
            camaras[camaraActiva].mover(objRevPly->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(PEON);
         }
      break;

      case ESCENA_LUCES:
         if(colorSel[0]==1){
            std::cout <<"Se selecciona NINGUNO\n";
            camaras[camaraActiva].mover(Tupla3f(0,0,0));
            camaras[camaraActiva].setObjetoFijado(NINGUNO);
         }
         //Peon Blanco
         else if(fabs(colorSel[0]-peonBlanco->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona el PEON BLANCO\n";
            camaras[camaraActiva].mover(peonBlanco->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(PEON_BLANCO);
         }
         //Peon Negro
         else if(fabs(colorSel[0]-peonNegro->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona el PEON NEGRO\n";
            camaras[camaraActiva].mover(peonNegro->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(PEON_NEGRO);
         }
         //Esfera
         else if(fabs(colorSel[0]-esfMat->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona la ESFERA\n";
            camaras[camaraActiva].mover(esfMat->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(ESF_MAT);
         }

      break;

      case ESCENA_TEXTURA:
         if(colorSel[0]==1){
            std::cout <<"Se selecciona NINGUNO\n";
            camaras[camaraActiva].mover(Tupla3f(0,0,0));
            camaras[camaraActiva].setObjetoFijado(NINGUNO);
         }
         else if(fabs(colorSel[0]-cuadro->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona CUADRO\n";
            camaras[camaraActiva].mover(cuadro->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(CUADRO);
         }

         else if(fabs(colorSel[0]-cuboTextura->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona CUBO CON TEXTURA\n";
            camaras[camaraActiva].mover(cuboTextura->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(CUBO_TEXTURA);
         }
         else if(fabs(colorSel[0]-cuboCola->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona CUBO CON TEXTURA\n";
            camaras[camaraActiva].mover(cuboCola->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(CUBO_COLA);
         }
         /*
         else if(fabs(colorSel[0]-tetraedroTextura->getColor()[0])<EPSILON_COLOR){
            std::cout <<"Se selecciona TETRAEDRO CON TEXTURA\n";
            camaras[camaraActiva].mover(tetraedroTextura->getCoordenadas());
            camaras[camaraActiva].setObjetoFijado(TETRAEDRO_TEXTURA);
         }
         */
      break;

      case ESCENA_FINAL:
         if(colorSel[0]==1){
            std::cout <<"Se selecciona COCHE\n";
            camaras[camaraActiva].mover(Tupla3f(0,0,0));
            camaras[camaraActiva].setObjetoFijado(COCHE);
         }
         else{
             std::cout <<"Se selecciona NINGUNO\n";
            camaras[camaraActiva].mover(Tupla3f(0,0,0));
            camaras[camaraActiva].setObjetoFijado(NINGUNO);
         }
      break;

   }
}