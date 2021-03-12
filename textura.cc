#include "textura.h"
#include "jpg_imagen.hpp"

Textura::Textura(std::string archivo){
    //Declara punto a imagen (pimg)
    jpg::Imagen * pimg = NULL;

    //Cargar la imagen (una sola vez)
    pimg = new jpg::Imagen(archivo);

    //Usar con
    tamx = pimg->tamX();    //num columnas (unsigned)
    tamy = pimg->tamY();    //num filas (unsigned)
    
    //Leemos los pixels
    texels = pimg->leerPixels();
    /*
    for(int i=0;i<tamx;i++){
        for(int j=0;j<tamy;j++){
            data.push_back(*(pimg->leerPixel(i, j)));
            data.push_back(*(pimg->leerPixel(i, j)+1));
            data.push_back(*(pimg->leerPixel(i, j)+2));
        }
    }*/
}

void Textura::activar(){
    //Si no se ha creado la textura la creamos
    if(textura_id==0){
        //Generamos un identificador
        glGenTextures(1, &textura_id);

        //Cambiamos al id actual de textura
        glBindTexture(GL_TEXTURE_2D,textura_id);

        //Espeificamos la imagen de textura asociada al identificador
        //de textura activa
        /*
        glTexImage2D(GL_TEXTURE_2D,
                        0,  //nivel de mipmap
                        GL_RGB, //formato interno
                        tamx,   //numero de columnas
                        tamy,   //numero de filas
                        0,  //tamanio del borde usualmente 0
                        GL_RGB, //formato y orden de los texels en RAM
                        GL_UNSIGNED_BYTE,   //tipo de cada texel
                        texels) //puntero a los bytes con texels (void *)
        );
        */
       gluBuild2DMipmaps(GL_TEXTURE_2D,
                            GL_RGB,
                            tamx,
                            tamy,
                            GL_RGB,
                            GL_UNSIGNED_BYTE,
                            texels);

    }

    //Cambiamos al id actual de textura
    //glEnable( GL_TEXTURE_GEN_S ); // desactivado inicialmente
    //glEnable( GL_TEXTURE_GEN_T ); // desactivado inicialmente
    glBindTexture(GL_TEXTURE_2D,textura_id);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP );
    glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT );
    
}
