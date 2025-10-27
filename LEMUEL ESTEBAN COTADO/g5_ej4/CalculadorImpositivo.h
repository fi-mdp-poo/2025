#ifndef CALCULADORIMPOSITIVO_H
#define CALCULADORIMPOSITIVO_H

#include <iostream>
#include <string>
#include <vector>

#include "Factura.h"
#include "ReciboDePago.h"
#include "FormaDePago.h"

using namespace std;

enum Categoria {LIMITADO, COMPLETO, EXTENDIDO};

class CalculadorImpositivo
{
    private:
        string nombreContribuyente;
        Categoria cat;
        FormaDePago *montoVariable;
        vector <Factura> f; // uso el estandar. -> luego evolucionar a template
        static double MONTO_FIJO;


    public:
        CalculadorImpositivo(); // x defecto
        ~CalculadorImpositivo(); // x defecto

        void inicializar(string name, Categoria c);
        void cargarFactura(string detalle, double monto, unsigned long int num);
        ReciboDePago calcularImpuesto(int desde, int hasta); // son los indices del vector?

};

#endif // CALCULADORIMPOSITIVO_H
