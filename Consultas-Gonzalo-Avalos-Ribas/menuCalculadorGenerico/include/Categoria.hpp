#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP

#include <vector>
#include "Factura.hpp"
using namespace std;

class Categoria
{
public:
    virtual double calcularMontoVariable(const vector<Factura> &facturas,
                                         int desde, int hasta) const = 0;
    virtual ~Categoria() {}
};

class Limitado : public Categoria
{
public:
    double calcularMontoVariable(const vector<Factura> &facturas,
                                 int desde, int hasta) const;
};

class Completo : public Categoria
{
public:
    double calcularMontoVariable(const vector<Factura> &facturas,
                                 int desde, int hasta) const;
};

class Extendido : public Categoria
{
public:
    double calcularMontoVariable(const vector<Factura> &facturas,
                                 int desde, int hasta) const;
};

double Limitado::calcularMontoVariable(const vector<Factura> &facturas,
                                       int desde, int hasta) const
{
    double total = 0;
    for (long long unsigned i = 0; i < facturas.size(); i++)
    {
        int num = facturas[i].getNumero();
        if (num >= desde && num <= hasta)
            total += facturas[i].getMonto() * 0.005; // 0.5%
    }
    return total;
}

double Completo::calcularMontoVariable(const vector<Factura> &facturas,
                                       int desde, int hasta) const
{
    double total = 0;
    for (long long unsigned i = 0; i < facturas.size(); i++)
    {
        int num = facturas[i].getNumero();
        double monto = facturas[i].getMonto();
        if (num >= desde && num <= hasta && monto > 5000)
            total += monto * 0.5;
    }
    return total;
}

double Extendido::calcularMontoVariable(const vector<Factura> &facturas,
                                        int desde, int hasta) const
{
    double total = 0;
    for (long long unsigned i = 0; i < facturas.size(); i++)
    {
        int num = facturas[i].getNumero();
        double monto = facturas[i].getMonto();
        if (num >= desde && num <= hasta)
        {
            if (monto > 5000)
                total += monto * 0.5;
            total += 10; // +$10 por cada servicio
        }
    }
    return total;
}

#endif