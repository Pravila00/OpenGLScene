// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "ply_reader.h"
#include "material.h"



// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class ObjRevolucion : public Malla3D
{
public:
   ObjRevolucion();
   ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true,int eje=1,bool tex=false) ;
   ObjRevolucion(std::vector<Tupla3f> perfil, int num_instancias, bool tapa_sup=true, bool tapa_inf=true,int eje=1,bool tex=false) ;
   void drawObjRev(bool conTapa,bool solido,bool lineas,bool puntos,bool ajedrez);
   
private:
    void crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias,int eje=1,bool tex=false);
    void extraerTapaInf(std::vector<Tupla3f> & perfil);
    void extraerTapaSup(std::vector<Tupla3f> & perfil);
    float calcularDistancia(Tupla3f v1,Tupla3f v2);
    Tupla3f tapaInf,tapaSup;
    int tamVSinTapa,tamFSinTapa;
} ;




#endif
