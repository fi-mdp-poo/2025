#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <cmath>

using namespace std;

class Complejo
{
    friend ostream& operator << (ostream&,const Complejo&);
    friend istream& operator >> (istream&,Complejo&);
    friend Complejo operator+(int, const Complejo&);
    friend Complejo operator+(float, const Complejo&);
    friend Complejo operator+(double, const Complejo&);
    friend Complejo operator-(int, const Complejo&);
    friend Complejo operator-(float, const Complejo&);
    friend Complejo operator-(double, const Complejo&);
    friend Complejo operator*(int, const Complejo&);
    friend Complejo operator*(float, const Complejo&);
    friend Complejo operator*(double, const Complejo&);
    friend Complejo operator/(int, const Complejo&);
    friend Complejo operator/(float, const Complejo&);
    friend Complejo operator/(double, const Complejo&);
    public:
        Complejo(double re=0,double imag=0);
        Complejo(const Complejo&);
        Complejo& operator = (const Complejo&);
        Complejo operator + (const Complejo&) const;
        Complejo operator + (int) const;
        Complejo operator + (float) const;
        Complejo operator + (double) const;
        Complejo operator - (const Complejo&) const;
        Complejo operator - (int) const;
        Complejo operator - (float) const;
        Complejo operator - (double) const;
        Complejo operator * (const Complejo&) const;
        Complejo operator * (int) const;
        Complejo operator * (float) const;
        Complejo operator * (double) const;
        Complejo operator / (const Complejo&) const;
        Complejo operator / (int) const;
        Complejo operator / (float) const;
        Complejo operator / (double) const;
        Complejo operator +() const;
        Complejo operator -() const;
        Complejo& operator ++ ();
        Complejo operator ++ (int);
        Complejo& operator -- ();
        Complejo operator -- (int);
        bool operator == (const Complejo&) const;
        bool operator != (const Complejo&) const;
        Complejo& operator += (const Complejo&);
        Complejo& operator += (int);
        Complejo& operator += (float);
        Complejo& operator += (double);
        Complejo& operator -= (const Complejo&);
        Complejo& operator -= (int);
        Complejo& operator -= (float);
        Complejo& operator -= (double);
        Complejo& operator *= (const Complejo&);
        Complejo& operator *= (int);
        Complejo& operator *= (float);
        Complejo& operator *= (double);
        Complejo& operator /= (const Complejo&);
        Complejo& operator /= (int);
        Complejo& operator /= (float);
        Complejo& operator /= (double);
        double modulo() const;
        double argumento() const;
        double argumentoGrados() const;
        Complejo conjugado() const;
        double getReal() const;
        double getImaginario() const;
        void setReal(double);
        void setImaginario(double);
        void repPolar() const;
        void repPolarGrados() const;
        void repPolarFormaEst() const;
    private:
        double real;
        double imaginario;
};

#endif
