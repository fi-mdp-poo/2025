#ifndef MOSTRAR_MONTO_FIJO_ITEM_HPP
#define MOSTRAR_MONTO_FIJO_ITEM_HPP

#include "MenuItem.hpp"
#include "CalculadorImpositivo.hpp"
using namespace std;

template <typename T>
class MostrarMontoFijoItem : public MenuItem<T>
{
    string titulo;

public:
    MostrarMontoFijoItem(const string &t = "Mostrar monto fijo");
    string name() const override;
    void execute(T& contexto) override;
};

template <typename T>
MostrarMontoFijoItem<T>::MostrarMontoFijoItem(const string& t)
    : titulo(t) {}

template <typename T>
string MostrarMontoFijoItem<T>::name() const { return titulo; }

template <typename T>
void MostrarMontoFijoItem<T>::execute(T& contexto) {
    cout << "Monto fijo actual: $" << contexto.getMontoFijo() << "\n";
}


#endif
