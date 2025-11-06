#ifndef CCOLOR_H
#define CCOLOR_H

#include <iostream>

using namespace std;

class CColor
{
    public:
        CColor(): valor(0xFF000000){}
        CColor(unsigned int n): valor(n){}
        CColor& operator = (unsigned int n) { valor=n; return *this;}
        unsigned char getAlpha() const { return componentes.alpha; }
        unsigned char getRed() const   { return componentes.red;   }
        unsigned char getGreen() const { return componentes.green; }
        unsigned char getBlue() const  { return componentes.blue;  }
        void setAlpha(unsigned char n) {componentes.alpha = n;}
        void setRed(unsigned char n)   {componentes.red   = n;}
        void setGreen(unsigned char n) {componentes.green = n;}
        void setBlue(unsigned char n)  {componentes.blue  = n;}
        unsigned int getValor() const { return valor; }
        void setValor(unsigned int v) { valor = v; }

    private:
        union
        {
            unsigned int valor;
            struct
            {
                unsigned char blue;
                unsigned char green;
                unsigned char red;
                unsigned char alpha;
            }componentes;
        };

    friend ostream& operator << (ostream& ,const CColor&);
};

#endif // CCOLOR_H
