#include "Factura.h"

Factura::Factura(string serv, double mon, unsigned long int num)
    : servicio(serv), monto(mon), NRO(num) {}

Factura::~Factura() {}
