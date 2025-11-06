#ifndef PERSISTENCIA_CUENTAS_H
#define PERSISTENCIA_CUENTAS_H

#include <fstream>
#include "Banco.hpp"
#include "CCahorro.hpp"
#include "CCorriente.hpp"
#include "CCuniversitaria.hpp"


class PersistenciaCuentas
{
    public:
        static void guardarEstadoBanco(const char*,const vector<Cuenta*>&);
        static void cargarEstadoBanco(const char* , Banco&);
};

#endif