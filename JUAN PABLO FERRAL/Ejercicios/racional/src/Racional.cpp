#include "Racional.h"
#include <cmath>
int mcd(int a, int b)
{
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

void Racional::simplificar()
{
    int divisor = mcd(abs(numerador), abs(denominador));
    numerador = numerador/divisor;
    denominador = denominador/divisor;
    if (denominador < 0)
    {
        numerador = -numerador;
        denominador = -denominador;
    }
}

Racional::Racional(int num,int den):
    numerador(num),
    denominador(den)
{
    if(denominador==0)
    {
        denominador = 1;
    }
    simplificar();
}

Racional::Racional(const Racional& r1):
    numerador(r1.numerador),
    denominador(r1.denominador)
{}

Racional& Racional::operator = (const Racional& r1)
{
    if(this == &r1) return *this;
    this->numerador = r1.numerador;
    this->denominador = r1.denominador;
    return *this;
}
ostream& operator << (ostream& outStream,Racional r1)
{
    outStream << r1.numerador << "/" << r1.denominador;
    return outStream;
}

istream& operator >> (istream& is,Racional& r1)
{
    char sep = 0;
    is >> r1.numerador >> sep >> r1.denominador;
    r1.simplificar();
    return is;
}

Racional Racional::operator + (const Racional& r1) const
{
    Racional ans;
    ans.numerador = (numerador*r1.denominador)+(denominador*r1.numerador);
    ans.denominador = denominador * r1.denominador;
    ans.simplificar();
    return ans;
}

Racional Racional::operator + (int n) const
{
    return Racional(numerador + n*denominador,denominador);
}

Racional Racional::operator - (const Racional& r1) const
{
    Racional ans;
    ans.numerador = (this->numerador*r1.denominador)-(this->denominador*r1.numerador);
    ans.denominador = this->denominador * r1.denominador;
    ans.simplificar();
    return ans;
}

Racional Racional::operator - (int n) const
{
    return Racional(numerador - n*denominador,denominador);
}

Racional Racional::operator * (const Racional& r1) const
{
    Racional ans;
    ans.numerador = numerador*r1.numerador;
    ans.denominador = denominador * r1.denominador;
    ans.simplificar();
    return ans;
}

Racional Racional::operator / (const Racional& r1) const
{
    Racional ans;
    ans.numerador = numerador*r1.denominador;
    ans.denominador = denominador * r1.numerador;
    ans.simplificar();
    return ans;
}

Racional Racional::operator+() const
{
    return *this;
}

Racional Racional::operator-() const
{
    return Racional(-numerador,denominador);
}

Racional& Racional::operator++()
{
    numerador += denominador;
    return *this;
}

Racional Racional::operator++(int)
{
    Racional aux(*this);
    ++(*this);
    return aux;
}

Racional& Racional::operator--()
{
    numerador -= denominador;
    return *this;
}

Racional Racional::operator--(int)
{
    Racional aux(*this);
    --(*this);
    return aux;
}

bool Racional::operator == (const Racional& r) const
{
    return numerador * r.denominador == denominador * r.numerador;
}

bool Racional::operator != (const Racional& r) const
{
    return !(*this == r);
}

bool Racional::operator < (const Racional& r) const
{
    return numerador * r.denominador < denominador * r.numerador;
}

bool Racional::operator > (const Racional& r) const
{
    return  r < *this;
}

bool Racional::operator <= (const Racional& r) const
{
    return !(r < *this);
}

bool Racional::operator >= (const Racional& r) const
{
    return !(*this < r);
}

float Racional::decimal () const
{
    return float(numerador)/denominador;
}

Racional::operator double() const
{
    return static_cast<double>(numerador)/denominador;
}

bool Racional::esCero() const
{
    return numerador == 0;
}
bool Racional::esEntero() const
{
    return denominador == 1;
}
Racional Racional::reciproco() const
{
    return Racional(denominador,numerador);
}

Racional& Racional::operator+=(const Racional& r)
{
    *this=*this+r;
    return *this;
}

Racional& Racional::operator-=(const Racional& r)
{
    *this=*this-r;
    return *this;
}

Racional& Racional::operator*=(const Racional& r)
{
    *this=*this*r;
    return *this;
}

Racional& Racional::operator/=(const Racional& r)
{
    *this=*this/r;
    return *this;
}

