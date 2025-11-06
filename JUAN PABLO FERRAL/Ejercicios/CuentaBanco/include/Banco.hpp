#ifndef BANCO_H
#define BANCO_H

#include "Cuenta.hpp"

class Banco
{
    public:
        Banco(const char*);
        void agregarCuenta(Cuenta*);
        Cuenta* buscarCuenta(unsigned int) const;
        void mostrarCuentas() const;
        const vector<Cuenta*>& getCuentas() const { return cuentas; }
        void activoBanco() const;
        string getNombre() const { return nombre; }
        ~Banco();

    private:
        string nombre;
        vector<Cuenta*> cuentas;
};

#endif