#include "CPantalla.h"


void CPantalla::ajustarColor(unsigned char n)
{
    CColor color = 0;
    unsigned int aux = 0;
    for(unsigned int i=0 ; i<filas ; i++)
    {
        for(unsigned int j=0 ; j<columnas ; j++)
        {
            color = valores[i*columnas+j];
            aux = color.getAlpha() + n;
            if(aux > 0xFF) aux = 0xFF;
            color.setAlpha(static_cast<unsigned char>(aux));
            valores[i*columnas+j] = color.getValor();
        }
    }
}

void CPantalla::borrarVerde()
{
    CColor color = 0;
    for(unsigned int i=0 ; i<filas ; i++)
    {
        for(unsigned int j=0 ; j<columnas ; j++)
        {
            color = valores[i*columnas+j];
            color.setGreen(0);
            valores[i*columnas+j] = color.getValor();
        }
    }
}

void CPantalla::reforzarRojo(float porcentaje)
{
    CColor color = 0;
    float aumento = 0;
    for(unsigned int i=0 ; i<filas ; i++)
    {
        for(unsigned int j=0 ; j<columnas ; j++)
        {
            color = valores[i*columnas+j];
            aumento = color.getRed()+(color.getRed()*porcentaje);
            if(aumento  > 255) aumento = 255;
            color.setRed(static_cast<unsigned char>(aumento));
            valores[i*columnas+j] = color.getValor();
        }
    }
}

unsigned int* CPantalla::getPtr()
{
    return valores;
}

void CPantalla::generarArchivo(const char* s)
{
    ofstream fsalida(s);
    fsalida << *this << endl;
    fsalida.close();
}
