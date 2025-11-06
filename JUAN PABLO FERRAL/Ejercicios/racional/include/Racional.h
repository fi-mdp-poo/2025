#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

using namespace std;

class Racional
{
    friend ostream& operator << (ostream&,Racional);
    friend istream& operator >> (istream&,Racional&);
    public:
        Racional(int num=0,int den=1);
        Racional(const Racional&);
        Racional& operator = (const Racional&);
        Racional operator + (const Racional&) const;
        Racional operator + (int n) const;
        Racional operator - (const Racional&) const;
        Racional operator - (int n) const;
        Racional operator * (const Racional&) const;
        Racional operator / (const Racional&) const;
        Racional operator +() const;
        Racional operator -() const;
        Racional& operator ++ ();
        Racional operator ++ (int);
        Racional& operator -- ();
        Racional operator -- (int);
        bool operator == (const Racional&) const;
        bool operator != (const Racional&) const;
        bool operator < (const Racional&) const;
        bool operator > (const Racional&) const;
        bool operator <= (const Racional&) const;
        bool operator >= (const Racional&) const;
        float decimal () const;
        operator double() const;
        bool esCero() const;
        bool esEntero() const;
        Racional reciproco() const;
        Racional& operator+=(const Racional&);
        Racional& operator-=(const Racional&);
        Racional& operator*=(const Racional&);
        Racional& operator/=(const Racional&);
        //~Racional();
    private:
        void simplificar();
        int numerador;
        int denominador;


};

#endif // RACIONAL_H
