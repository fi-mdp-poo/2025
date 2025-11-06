#ifndef IVECTOR_H
#define IVECTOR_H

#include <iostream>
#include <cmath>

using namespace std;

class Ivector
{
    friend ostream& operator << (ostream&,const Ivector&);
    friend istream& operator >> (istream&,Ivector&);
    public:
        Ivector(int n=10);
        Ivector(const Ivector&);
        Ivector& operator = (const Ivector&);
        void push_back(int);
        int pop_back();
        int get(int) const;
        void set(int,int);
        int getSize() const;
        int getCapacity() const;
        int operator [] (int) const;
        int& operator [] (int);
        void clear();
        bool empty() const;
        void redimensionP(int nuevaLongitud, int valorPorDefecto = 0);
        void insertar(int,int);
        void eliminar(int);
        ~Ivector();
    private:
        int capacidad;
        int longitud;
        int* arreglo;
        void redimension(int n=0);
};

#endif // IVECTOR_H
