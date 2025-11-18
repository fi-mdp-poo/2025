#ifndef RECIBO_DE_PAGO_HPP
#define RECIBO_DE_PAGO_HPP

#include <string>
#include <iostream>
using namespace std;

class ReciboDePago
{
private:
    string nombreContribuyente;
    double montoFijo;
    double montoVariable;
    int primeraFactura;
    int ultimaFactura;

public:
    ReciboDePago(string nombre, double fijo, double variable,
                 int primera, int ultima);

    string nombreDelContribuyente() const;
    double montoFijoTotal() const;
    double montoVariableTotal() const;
    double montoTotal() const;
    int primeraFacturaConsiderada() const;
    int ultimaFacturaConsiderada() const;

    friend ostream &operator<<(ostream &os, const ReciboDePago &r);
};

ReciboDePago::ReciboDePago(string nombre, double fijo, double variable,
                           int primera, int ultima)
    : nombreContribuyente(nombre),
      montoFijo(fijo),
      montoVariable(variable),
      primeraFactura(primera),
      ultimaFactura(ultima) {}

string ReciboDePago::nombreDelContribuyente() const { return nombreContribuyente; }
double ReciboDePago::montoFijoTotal() const { return montoFijo; }
double ReciboDePago::montoVariableTotal() const { return montoVariable; }
double ReciboDePago::montoTotal() const { return montoFijo + montoVariable; }
int ReciboDePago::primeraFacturaConsiderada() const { return primeraFactura; }
int ReciboDePago::ultimaFacturaConsiderada() const { return ultimaFactura; }

ostream &operator<<(ostream &os, const ReciboDePago &r)
{
    os << "=== RECIBO DE PAGO ===\n";
    os << "Contribuyente: " << r.nombreContribuyente << "\n";
    os << "Facturas: " << r.primeraFactura << " a " << r.ultimaFactura << "\n";
    os << "Monto fijo: $" << r.montoFijo << "\n";
    os << "Monto variable: $" << r.montoVariable << "\n";
    os << "Monto total: $" << r.montoTotal() << "\n";
    os << "=======================\n";
    return os;
}

#endif