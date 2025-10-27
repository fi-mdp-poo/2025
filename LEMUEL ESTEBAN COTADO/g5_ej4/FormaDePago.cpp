#include "FormaDePago.h"

FormaDePago::FormaDePago() {}

FormaDePago::~FormaDePago() {}

Limitado::Limitado() {}

Limitado::~Limitado() {}

double Limitado::calculoMontoVariable(const vector<Factura> &f, int desde, int hasta)
{
    double res=0;
    for(int i=desde; i<hasta; i++)
    {
        res=res+f.at(i).get_monto();
    }

    res=(res*0.5)/100;

    return res;
}
