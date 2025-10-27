#ifndef RECIBODEPAGO_H
#define RECIBODEPAGO_H

#include <iostream>
#include <string>
using namespace std;

class ReciboDePago
{
    private:
        string nombreContribuyente;
        double monto_total;
        double monto_fijo;
        double monto_variable;
        int first_factura;
        int last_factura;
    public:
        ReciboDePago();
        ReciboDePago(string name, double mt, double mf, double mv, int fst, int lst);
        ReciboDePago& operator=(const ReciboDePago& otro);
        friend ostream& operator<<(ostream& os, const ReciboDePago& r);
        ~ReciboDePago();

};

#endif // RECIBODEPAGO_H
