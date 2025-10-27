#include "CalculadorImpositivo.h"


int main()
{
    CalculadorImpositivo c1;
    c1.inicializar("Lemuel Cotado", LIMITADO);
    c1.cargarFactura("Agua", 10000, 10);
    c1.cargarFactura("Luz", 15000, 11);
    c1.cargarFactura("Gas", 3500, 12);
    ReciboDePago r1=c1.calcularImpuesto(0, 2);
    cout<<r1;

    cout<<endl;
    c1.inicializar("Gustavo Quinteros", LIMITADO);
    ReciboDePago r2=c1.calcularImpuesto(0,0);
    cout<<r2;



    return 0;
}
