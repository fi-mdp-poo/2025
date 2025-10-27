#ifndef FACTURA_H
#define FACTURA_H

#include <string>
using namespace std;

class Factura
{
    private:
        string servicio;
        double monto;
        unsigned long int NRO;

    public:
        Factura(string serv, double mon, unsigned long int num);
        ~Factura();
        string get_servicio() const { return servicio; }
        double get_monto() const { return monto; }
        unsigned long int get_NRO() const { return NRO; }
};

#endif // FACTURA_H
