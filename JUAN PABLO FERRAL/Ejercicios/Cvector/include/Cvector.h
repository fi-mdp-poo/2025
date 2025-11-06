#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <cmath>
#include "Complejo.h"

using namespace std;

class Cvector
{
    friend ostream& operator << (ostream&,const Cvector&);
    friend istream& operator >> (istream&,Cvector&);
    public:
        Cvector(int n=10);
        Cvector(const Cvector&);
        Cvector& operator = (const Cvector&);
        void push_back(const Complejo&);
        Complejo pop_back();
        Complejo get(int) const;
        void set(int,const Complejo&);
        int getSize() const;
        int getCapacity() const;
        Complejo operator [] (int) const;
        Complejo& operator [] (int);
        void clear();
        bool empty() const;
        void redimensionP(int nuevaLongitud, const Complejo& valorPorDefecto = Complejo(0,0));
        void insertar(int,const Complejo&);
        void eliminar(int);
        ~Cvector();
    private:
        int capacidad;
        int longitud;
        Complejo* arreglo;
        void redimension(int n=0);
};

#endif // CVECTOR_H
