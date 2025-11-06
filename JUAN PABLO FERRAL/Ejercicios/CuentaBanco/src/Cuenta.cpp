#include "Cuenta.hpp"

Cuenta::Cuenta(unsigned int dni, unsigned int ident):
     dnititular(dni),
     id(ident),
     saldo(0)
{}
Cuenta::Cuenta(unsigned int dni, unsigned int ident, long int saldoActual):
     dnititular(dni),
     id(ident),
     saldo(saldoActual)
{}

void Cuenta::deposito()
{
    unsigned int deposito;
    cout << "Ingrese el monto del deposito: ";
    cin >> deposito;
    saldo += deposito; 
}

ostream& operator << (ostream& os,const Cuenta& c)
{
    os << "Id de la cuenta: " << c.id << endl
    << "Dni del titular: " << c.dnititular << endl 
    << "Saldo en la cuenta: " << c.saldo << endl;
    return os;
}