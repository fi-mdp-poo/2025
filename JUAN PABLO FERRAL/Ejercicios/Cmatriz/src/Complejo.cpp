#include "Complejo.h"

Complejo::Complejo(double re,double imag):
    real(re),
    imaginario(imag)
{}

Complejo ::Complejo(const Complejo& c):
    real(c.real),
    imaginario(c.imaginario)
{}
Complejo& Complejo:: operator =(const Complejo& c)
{
    if(this==&c) return *this;
    real=c.real;
    imaginario=c.imaginario;
    return *this;
}

ostream& operator << (ostream& outStream,const Complejo& c)
{
    outStream << c.real<< "+(" << c.imaginario << "i)";
    return outStream;
}

istream& operator >> (istream& is,Complejo& c)
{
    cout <<"Ingrese la parte real:";
    is >> c.real;
    cout <<"Ingrese la parte imaginaria:";
    is >> c.imaginario;
    return is;
}

Complejo operator + (int n, const Complejo& c)
{
    return Complejo(c.real+n,c.imaginario);
}

Complejo operator + (float n, const Complejo& c)
{
    return Complejo(c.real+n,c.imaginario);
}

Complejo operator + (double n, const Complejo& c)
{
    return Complejo(c.real+n,c.imaginario);
}

Complejo operator - (int n, const Complejo& c)
{
    return Complejo(c.real-n,c.imaginario);
}

Complejo operator - (float n, const Complejo& c)
{
    return Complejo(c.real-n,c.imaginario);
}

Complejo operator - (double n, const Complejo& c)
{
    return Complejo(c.real-n,c.imaginario);
}

Complejo operator * (int n, const Complejo& c)
{
    return Complejo((c.real*n),(c.imaginario*n));
}

Complejo operator * (float n, const Complejo& c)
{
    return Complejo((c.real*n),(c.imaginario*n));
}

Complejo operator * (double n, const Complejo& c)
{
    return Complejo((c.real*n),(c.imaginario*n));
}

Complejo operator / (int n, const Complejo& c)
{
    double denominador = c.real*c.real+c.imaginario*c.imaginario;
    double pReal = (n*c.real)/denominador;
    double pImag = ((-n)*c.imaginario)/denominador;
    return Complejo(pReal,pImag);
}

Complejo operator / (float n, const Complejo& c)
{
    double denominador = c.real*c.real+c.imaginario*c.imaginario;
    double pReal = (n*c.real)/denominador;
    double pImag = ((-n)*c.imaginario)/denominador;
    return Complejo(pReal,pImag);
}

Complejo operator / (double n, const Complejo& c)
{
    double denominador = c.real*c.real+c.imaginario*c.imaginario;
    double pReal = (n*c.real)/denominador;
    double pImag = ((-n)*c.imaginario)/denominador;
    return Complejo(pReal,pImag);
}

Complejo Complejo::operator + (const Complejo& c)const
{
    return Complejo((real+c.real),(imaginario+c.imaginario));
}

Complejo Complejo::operator + (int n) const
{
    return Complejo(real+n,imaginario);
}

Complejo Complejo::operator + (float n) const
{
    return Complejo(real+n,imaginario);
}

Complejo Complejo::operator + (double n) const
{
    return Complejo(real+n,imaginario);
}

Complejo Complejo::operator - (const Complejo& c)const
{
    return Complejo((real-c.real),(imaginario-c.imaginario));
}

Complejo Complejo::operator - (int n) const
{
    return Complejo(real-n,imaginario);
}

Complejo Complejo::operator - (float n) const
{
    return Complejo(real-n,imaginario);
}

Complejo Complejo::operator - (double n) const
{
    return Complejo(real-n,imaginario);
}

Complejo Complejo::operator * (const Complejo& c)const
{
    return Complejo((real*c.real-(imaginario*c.imaginario)),(real*c.imaginario+(imaginario*c.real)));
}

Complejo Complejo::operator * (int n) const
{
    return Complejo(real*n,imaginario*n);
}

Complejo Complejo::operator * (float n) const
{
    return Complejo(real*n,imaginario*n);
}

Complejo Complejo::operator * (double n) const
{
    return Complejo(real*n,imaginario*n);
}

Complejo Complejo::operator / (const Complejo& c)const
{
    double denominador = (c.real * c.real) + (c.imaginario * c.imaginario);
    double realPart = (real * c.real + imaginario * c.imaginario) / denominador;
    double imagPart = (imaginario * c.real - real * c.imaginario) / denominador;
    return Complejo(realPart,imagPart);
}

Complejo Complejo::operator / (int n) const
{
    return Complejo(real/n,imaginario/n);
}

Complejo Complejo::operator / (float n) const
{
    return Complejo(real/n,imaginario/n);
}

Complejo Complejo::operator / (double n) const
{
    return Complejo(real/n,imaginario/n);
}

Complejo Complejo::operator +() const
{
    return *this;
}

Complejo Complejo::operator -() const
{
    return Complejo(-real,-imaginario);
}

Complejo& Complejo::operator ++ ()
{
    *this=*this + 1;
    return *this;
}

Complejo Complejo::operator ++ (int)
{
    Complejo result= *this;
    ++(*this);
    return result;
}

Complejo& Complejo::operator -- ()
{
    *this=*this - 1;
    return *this;
}

Complejo Complejo::operator -- (int)
{
    Complejo result= *this;
    --(*this);
    return result;
}

bool Complejo::operator == (const Complejo& c) const
{
    return (real==c.real)&&(imaginario==c.imaginario);
}

bool Complejo::operator != (const Complejo& c) const
{
    return !(*this==c);
}

Complejo& Complejo::operator += (const Complejo& c)
{
    *this = *this + c;
    return *this;
}

Complejo& Complejo::operator += (int n)
{
    *this = *this + n;
    return *this;
}

Complejo& Complejo::operator += (float n)
{
    *this = *this + n;
    return *this;
}

Complejo& Complejo::operator += (double n)
{
    *this = *this + n;
    return *this;
}

Complejo& Complejo::operator -= (const Complejo& c)
{
    *this = *this - c;
    return *this;
}

Complejo& Complejo::operator -= (int n)
{
    *this = *this - n;
    return *this;
}

Complejo& Complejo::operator -= (float n)
{
    *this = *this - n;
    return *this;
}

Complejo& Complejo::operator -= (double n)
{
    *this = *this - n;
    return *this;
}

Complejo& Complejo::operator *= (const Complejo& c)
{
    *this = *this * c;
    return *this;
}

Complejo& Complejo::operator *= (int n)
{
    *this = *this * n;
    return *this;
}

Complejo& Complejo::operator *= (float n)
{
    *this = *this * n;
    return *this;
}

Complejo& Complejo::operator *= (double n)
{
    *this = *this * n;
    return *this;
}

Complejo& Complejo::operator /= (const Complejo& c)
{
    *this = *this / c;
    return *this;
}

Complejo& Complejo::operator /= (int n)
{
    *this = *this / n;
    return *this;
}

Complejo& Complejo::operator /= (float n)
{
    *this = *this / n;
    return *this;
}

Complejo& Complejo::operator /= (double n)
{
    *this = *this / n;
    return *this;
}

double Complejo::modulo() const
{
    return sqrt(real*real+imaginario*imaginario);
}

double Complejo::argumento() const
{
    return atan2(imaginario,real);
}

double Complejo::argumentoGrados() const
{
    return ((atan2(imaginario,real)*180)/(M_PI));
}

Complejo Complejo::conjugado() const
{
    return Complejo (real,-imaginario);
}

double Complejo::getReal() const
{
    return real;
}

double Complejo::getImaginario() const
{
    return imaginario;
}

void Complejo::setReal(double n)
{
    real = n;
}

void Complejo::setImaginario(double n)
{
    imaginario = n;
}

void Complejo::repPolar()const
{
    cout << "Modulo: " << this->modulo() << " , Angulo(rad): " <<this->argumento() << endl;
}

void Complejo::repPolarGrados()const
{
    cout << "Modulo: " << this->modulo() << " , Angulo(grados): " <<this->argumentoGrados() << endl;
}

void Complejo::repPolarFormaEst() const
{
    double r = modulo();
    double theta = argumento();
    cout << r << "(cos(" << theta << ") + i*sin(" << theta << "))" << endl;
}

/*Complejo::~Complejo()
{
    //dtor
}*/
