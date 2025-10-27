#include "ReciboDePago.h"

ReciboDePago::ReciboDePago() {}


ReciboDePago::ReciboDePago(string name, double mt, double mf, double mv, int fst, int lst)
    : nombreContribuyente(name), monto_total(mt), monto_fijo(mf), monto_variable(mv),
      first_factura(fst), last_factura(lst) {}

ReciboDePago::~ReciboDePago() {}

ostream& operator<<(ostream& os, const ReciboDePago& r)
{
    os<<"NOMBRE: "<<r.nombreContribuyente<<endl;
    os<<"Monto Fijo: $"<<r.monto_fijo<<endl;
    os<<"Monto Variable: $"<<r.monto_variable<<endl;
    os<<"1ra Factura: "<<r.first_factura<<endl;
    os<<"Ultima Factura: "<<r.last_factura<<endl;
    os<<"Total Impuesto: $"<<r.monto_total<<endl;
    return os;
}

ReciboDePago& ReciboDePago::operator=(const ReciboDePago &otro)
{
    if (this == &otro) return *this;

    nombreContribuyente=otro.nombreContribuyente;
    monto_total=otro.monto_total;
    monto_fijo=otro.monto_fijo;
    monto_variable=otro.monto_variable;
    first_factura=otro.first_factura;
    last_factura=otro.last_factura;

    return *this;
}
