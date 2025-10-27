#include "CalculadorImpositivo.h"

CalculadorImpositivo::CalculadorImpositivo() {} // x defecto

CalculadorImpositivo::~CalculadorImpositivo() {} // x defecto

double CalculadorImpositivo::MONTO_FIJO=5.0;

void CalculadorImpositivo::inicializar(string name, Categoria c)
{
    this->nombreContribuyente=name;
    this->cat=c;
    if(cat==LIMITADO)
    {
        montoVariable=new Limitado;
    }
//    else if(cat==COMPLETO)
//    {
//        montoVariable=new Completo();
//    }
//    else if(cat==EXTENDIDO)
//    {
//        montoVariable=new Extendido();
//    }
    else{
        montoVariable=nullptr; // deberia lanzar excepcion
    }
    f.clear();
}

void CalculadorImpositivo::cargarFactura(string detalle, double monto, unsigned long int num)
{
    Factura factura(detalle, monto, num);
    f.push_back(factura);
}

ReciboDePago CalculadorImpositivo::calcularImpuesto(int desde, int hasta)
{
    double monto_tot=0;
    double monto_vble=0;

    if(cat==LIMITADO)
    {
        monto_vble=montoVariable->calculoMontoVariable(f, desde, hasta+1);
    }

    monto_tot=MONTO_FIJO+monto_vble;

    ReciboDePago r(nombreContribuyente, monto_tot, MONTO_FIJO, monto_vble, desde, hasta);
    return r;
}
