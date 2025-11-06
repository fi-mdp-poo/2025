#ifndef IMATRIZ_H
#define IMATRIZ_H

#include <iostream>
#include <cmath>

using namespace std;

class Imatriz
{
    friend Imatriz operator * (int, const Imatriz&);
    friend Imatriz operator * (float, const Imatriz&);
    friend Imatriz operator * (double, const Imatriz&);
    friend ostream& operator << (ostream&,const Imatriz&);
    public:
        Imatriz(int f=1,int c=1);
        Imatriz(const Imatriz&);
        Imatriz& operator = (const Imatriz&);
        Imatriz operator + (const Imatriz&) const;
        Imatriz operator - (const Imatriz&) const;
        Imatriz operator * (int) const;
        Imatriz operator * (float) const;
        Imatriz operator * (double) const;
        Imatriz operator * (const Imatriz&) const;
        Imatriz& operator+=(const Imatriz&);
        Imatriz& operator-=(const Imatriz&);
        Imatriz& operator*=(int);
        Imatriz& operator*=(float);
        Imatriz& operator*=(double);
        Imatriz& operator*=(const Imatriz&);
        Imatriz trasnpuesta() const;
        Imatriz inversa() const;
        void set(int fila, int columna, double valor);
        double get(int fila, int columna) const;
        int getFilas() const;
        int getColumnas() const;
        double determinante() const;
        double* operator[](int fila);
        const double* operator[](int fila) const;
        ~Imatriz();
    private:
        int filas;
        int columnas;
        double* matrix;
        Imatriz matrizMenor(int , int)const;
};

#endif // IMATRIZ_H
