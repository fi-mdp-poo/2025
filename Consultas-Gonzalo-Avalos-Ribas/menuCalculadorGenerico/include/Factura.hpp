#ifndef FACTURA_HPP
#define FACTURA_HPP

#include <string>
using namespace std;

class Factura
{
private:
    int numero;
    string detalle;
    double monto;

public:
    Factura(int n, string d, double m);

    int getNumero() const;
    string getDetalle() const;
    double getMonto() const;
};

Factura::Factura(int n, string d, double m)
    : numero(n), detalle(d), monto(m) {}

int Factura::getNumero() const { return numero; }
string Factura::getDetalle() const { return detalle; }
double Factura::getMonto() const { return monto; }

#endif