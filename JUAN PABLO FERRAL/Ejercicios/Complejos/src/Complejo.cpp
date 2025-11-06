#include "Complejo.h"

Complejo::Complejo(double re,double imag):
    real(re),
    imaginario(imag)
{
    if(re==0 && imag==0)
    {
        modulo = 0;
        argumento = 0;
    }
    else
    {
        modulo = sqrt(real*real+imaginario*imaginario);
        argumento = atan2(imaginario,real);
    }
}

Complejo ::Complejo(const Complejo& c):
    real(c.real),
    imaginario(c.imaginario),
    modulo(c.modulo),
    argumento(c.argumento)
{}

Complejo& Complejo:: operator =(const Complejo& c)
{
    if(this==&c) return *this;
    real = c.real;
    imaginario = c.imaginario;
    modulo = c.modulo;
    argumento = c.argumento;
    return *this;
}

ostream& operator << (ostream& outStream,const Complejo& c)
{
    outStream << c.real<< "+(" << c.imaginario << "i)";
    return outStream;
}

istream& operator >> (istream& is,Complejo& c)
{
    double r = 0;
    cout <<"Ingrese la parte real:";
    is >> r;
    c.setReal(r);
    cout <<"Ingrese la parte imaginaria:";
    is >> r;
    c.setImaginario(r);
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
    Complejo result;
    if(c.real == 0 && c.imaginario ==0)
    {
        cout << "Divion no permitida se devolvio 0 + 0i" << endl;
    }
    else
    {
        double denominador = c.real*c.real+c.imaginario*c.imaginario;
        double pReal = (n*c.real)/denominador;
        double pImag = ((-n)*c.imaginario)/denominador;
        result.real=pReal;
        result.setImaginario(pImag);
    }
    return result;
}

Complejo operator / (float n, const Complejo& c)
{
    Complejo result;
    if(c.real == 0 && c.imaginario ==0)
    {
        cout << "Divion no permitida se devolvio 0 + 0i" << endl;
    }
    else
    {
        double denominador = c.real*c.real+c.imaginario*c.imaginario;
        double pReal = (n*c.real)/denominador;
        double pImag = ((-n)*c.imaginario)/denominador;
        result.real=pReal;
        result.setImaginario(pImag);
    }
    return result;
}

Complejo operator / (double n, const Complejo& c)
{
    Complejo result;
    if(c.real == 0 && c.imaginario ==0)
    {
        cout << "Divion no permitida se devolvio 0 + 0i" << endl;
    }
    else
    {
        double denominador = c.real*c.real+c.imaginario*c.imaginario;
        double pReal = (n*c.real)/denominador;
        double pImag = ((-n)*c.imaginario)/denominador;
        result.real=pReal;
        result.setImaginario(pImag);
    }
    return result;
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
    Complejo result;
    if(c.real == 0 && c.imaginario ==0)
    {
        cout << "Divion no permitida se devolvio 0 + 0i" << endl;
    }
    else
    {
        double denominador = (c.real * c.real) + (c.imaginario * c.imaginario);
        double realPart = (real * c.real + imaginario * c.imaginario) / denominador;
        double imagPart = (imaginario * c.real - real * c.imaginario) / denominador;
        result.real=realPart;
        result.setImaginario(imagPart);
    }
    return result;
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

double Complejo::getModulo() const
{
    return modulo;
}

double Complejo::getArgumento() const
{
    return argumento;
}

double Complejo::getArgumentoGrados() const
{
    return ((argumento*180)/(M_PI));
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
    if(real==0 && imaginario==0)
    {
        modulo = 0;
        argumento = 0;
    }
    else
    {
        modulo = sqrt(real*real+imaginario*imaginario);
        argumento = atan2(imaginario,real);
    }
}

void Complejo::setImaginario(double n)
{
    imaginario = n;
    if(real==0 && imaginario==0)
    {
        modulo = 0;
        argumento = 0;
    }
    else
    {
        modulo = sqrt(real*real+imaginario*imaginario);
        argumento = atan2(imaginario,real);
    }
}

void Complejo::setrepPolar(double mod,double theta)
{
    modulo = mod;
    argumento = theta;
    real = mod*cos(theta);
    imaginario = mod*sin(theta);
}

void Complejo::setrepPolarGrados(double mod,double theta)
{
    modulo = mod;
    argumento = ((theta*M_PI)/180);
    real = mod*cos(argumento);
    imaginario = mod*sin(argumento);
}

void Complejo::repPolar()const
{
    cout << "Modulo: " << modulo << " , Angulo(rad): " <<argumento << endl;
}

void Complejo::repPolarGrados()const
{
    cout << "Modulo: " << modulo << " , Angulo(grados): " <<getArgumentoGrados() << endl;
}

void Complejo::repPolarFormaEst() const
{
    double r = modulo;
    double theta = argumento;
    cout << r << "(cos(" << theta << ") + i*sin(" << theta << "))" << endl;
}

