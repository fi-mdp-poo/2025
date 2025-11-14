#ifndef CALCULADOR_IMPOSITIVO_HPP
#define CALCULADOR_IMPOSITIVO_HPP

#include <string>
#include <vector>
#include "Factura.hpp"
#include "Categoria.hpp"
#include "ReciboDePago.hpp"
using namespace std;

class CalculadorImpositivo
{
private:
    string nombreContribuyente;
    const Categoria *categoria; // Relación polimórfica
    vector<Factura> facturas;
    double montoFijo; // Ahora es una variable de instancia

public:
    // Constructor: inicia con monto fijo por defecto (5.0)
    CalculadorImpositivo(string nombre, const Categoria *cat, double montoFijoInicial = 5.0);

    void agregarFactura(int numero, string detalle, double monto);
    ReciboDePago calcular(int desde, int hasta) const;

    void setMontoFijo(double nuevoMonto);
    double getMontoFijo() const;
    const vector<Factura> &getFacturas() const;
};

CalculadorImpositivo::CalculadorImpositivo(string nombre, const Categoria *cat, double montoFijoInicial)
    : nombreContribuyente(nombre),
      categoria(cat),
      montoFijo(montoFijoInicial) {}

void CalculadorImpositivo::agregarFactura(int numero, string detalle, double monto)
{
    facturas.push_back(Factura(numero, detalle, monto));
}

ReciboDePago CalculadorImpositivo::calcular(int desde, int hasta) const
{
    double variable = categoria->calcularMontoVariable(facturas, desde, hasta);
    return ReciboDePago(nombreContribuyente, montoFijo, variable, desde, hasta);
}

void CalculadorImpositivo::setMontoFijo(double nuevoMonto)
{
    montoFijo = nuevoMonto;
}

double CalculadorImpositivo::getMontoFijo() const
{
    return montoFijo;
}
const vector<Factura> &CalculadorImpositivo::getFacturas() const
{
    return facturas;
}

#endif