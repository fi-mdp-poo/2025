#ifndef CPANTALLA_H
#define CPANTALLA_H

#include "CMatriz.h"
#include "CColor.h"

class CPantalla : public CMatriz
{
    public:
        CPantalla(): CMatriz(){}
        CPantalla(const CMatriz& m) : CMatriz(m) {}
        void ajustarColor(unsigned char);
        void borrarVerde();
        void reforzarRojo(float);
        unsigned int* getPtr();
        unsigned int getFilas()    { return filas;    }
        unsigned int getColumnas() { return columnas; }
        void generarArchivo(const char*);
};

#endif // CPANTALLA_H
