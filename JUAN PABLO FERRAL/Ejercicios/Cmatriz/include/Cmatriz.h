#ifndef CMATRIZ_H
#define CMATRIZ_H

#include <iostream>
#include <cmath>
#include "Cvector.h"

using namespace std;

class Cmatriz
{
    friend Cmatriz operator * (int, const Cmatriz&);
    friend Cmatriz operator * (float, const Cmatriz&);
    friend Cmatriz operator * (double, const Cmatriz&);
    friend ostream& operator << (ostream&,const Cmatriz&);
    public:
        Cmatriz(int f=1,int c=1);
        Cmatriz(const Cmatriz&);
        Cmatriz& operator = (const Cmatriz&);
        Cmatriz operator + (const Cmatriz&) const;
        Cmatriz operator - (const Cmatriz&) const;
        Cmatriz operator * (int) const;
        Cmatriz operator * (float) const;
        Cmatriz operator * (double) const;
        Cmatriz operator * (const Cmatriz&) const;
        Cmatriz& operator+=(const Cmatriz&);
        Cmatriz& operator-=(const Cmatriz&);
        Cmatriz& operator*=(int);
        Cmatriz& operator*=(float);
        Cmatriz& operator*=(double);
        Cmatriz& operator*=(const Cmatriz&);
        Cmatriz transpuesta() const;
        Cmatriz inversa() const;
        void setCelda(int fila, int columna, Complejo valor);
        Complejo getCelda(int fila, int columna) const;
        int getFilas() const;
        int getColumnas() const;
        Complejo determinante() const;
    private:
        int filas;
        int columnas;
        Cvector matrix;
        Cmatriz matrizMenor(int , int)const;
};

#endif // CMATRIZ_H
