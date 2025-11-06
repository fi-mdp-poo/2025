#ifndef CUENTASFACTORY_H
#define CUENTASFACTORY_H

#include <fstream>
#include "CCahorro.hpp"
#include "CCorriente.hpp"
#include "CCuniversitaria.hpp"

class CuentasFactory
{
    public:
        static Cuenta* crearCuenta(int tipo, unsigned int dni, const char*);
};

#endif