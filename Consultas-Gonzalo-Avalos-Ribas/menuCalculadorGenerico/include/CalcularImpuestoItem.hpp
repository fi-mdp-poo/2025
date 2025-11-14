#ifndef CALCULAR_IMPUESTO_ITEM_HPP
#define CALCULAR_IMPUESTO_ITEM_HPP

#include "MenuItem.hpp"
#include "CalculadorImpositivo.hpp"
#include <string>
using namespace std;

template <typename T>
class CalcularImpuestoItem : public MenuItem<T>
{
    string titulo;

public:
    CalcularImpuestoItem(const string &t = "Calcular impuesto");
    string name() const override;
    void execute(T &contexto) override;
};
template <typename T>
CalcularImpuestoItem<T>::CalcularImpuestoItem(const string &t)
    : titulo(t) {}

template <typename T>
string CalcularImpuestoItem<T>::name() const { return titulo; }

template <typename T>
void CalcularImpuestoItem<T>::execute(T &contexto)
{
    int desde, hasta;
    cout << "Numero inicial: ";
    while (!(cin >> desde))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Numero final: ";
    while (!(cin >> hasta))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    ReciboDePago recibo = contexto.calcular(desde, hasta);
    cout << recibo;
}

#endif
