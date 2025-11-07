#ifndef BANCO_H
#define BANCO_H

#include "Cuenta.hpp"
#include "CuentasFactory.hpp"
#include "PersistenciaCuentas.hpp"

class Banco
{
    public:
        Banco(const char*, const char*);
        void agregarCuenta(int tipo, unsigned int dni, const char*);
        void persistenciaGuardar();
        void persistenciaCargar();
        Cuenta* buscarCuenta(unsigned int) const;
        void mostrarCuentas() const;
        void activoBanco() const;
        string getNombre() const { return nombre; }
        ~Banco();
    private:
        string nombre;
        const char* archivo_cuentas;
        vector<Cuenta*> cuentas;
};

#endif