#ifndef CMATRIZ_H
#define CMATRIZ_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class CMatriz
{
    friend ostream& operator << (ostream&,const CMatriz&);
    public:
        CMatriz();
        CMatriz(const CMatriz&);
        CMatriz& operator = (const CMatriz&);
        CMatriz operator + (int) const;
        CMatriz& operator += (const CMatriz&);
        void cargar(const char*);
        ~CMatriz();
    protected:
        unsigned int filas;
        unsigned int columnas;
        unsigned int* valores;
};

#endif // CMATRIZ_H
