#ifndef FORMADEPAGO_H
#define FORMADEPAGO_H

#include "Factura.h"
#include <vector>
using namespace std;

class FormaDePago
{
    public:
        FormaDePago();
        virtual ~FormaDePago();
        virtual double calculoMontoVariable(const vector<Factura> &f, int desde, int hasta) = 0; // ref cte al vector de fact

};

class Limitado : public FormaDePago
{
    public:
    Limitado();
    ~Limitado();
    double calculoMontoVariable(const vector<Factura> &f, int desde, int hasta) override;

};

#endif // FORMADEPAGO_H
