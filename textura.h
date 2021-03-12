#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED

#include "aux.h"
#include <string>


class Textura
{
private:
    GLuint textura_id = 0;
    std::vector<unsigned char> data;
    int tamx, tamy;
    unsigned char * texels;
    unsigned long tamX,tamY;
public:
    Textura(std::string archivo);
    void activar();
} ;

#endif