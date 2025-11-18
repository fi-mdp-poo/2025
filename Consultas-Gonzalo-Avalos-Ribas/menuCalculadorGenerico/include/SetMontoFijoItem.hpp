#ifndef SET_MONTO_FIJO_ITEM_HPP
#define SET_MONTO_FIJO_ITEM_HPP

#include "MenuItem.hpp"
#include "CalculadorImpositivo.hpp"
using namespace std;

template <typename T>
class SetMontoFijoItem : public MenuItem<T>
{
    string titulo;

public:
    SetMontoFijoItem(const string &t = "Setear monto fijo");
    string name() const override;
    void execute(T& contexto) override;
};

template <typename T>
SetMontoFijoItem<T>::SetMontoFijoItem(const string &t)
    :  titulo(t) {}

template <typename T>
string SetMontoFijoItem<T>::name() const { return titulo; }

template <typename T>
void SetMontoFijoItem<T>::execute(T& contexto)
{
    double nuevo;
    cout << "Nuevo monto fijo: ";
    while (!(cin >> nuevo))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    contexto.setMontoFijo(nuevo);
    cout << "Monto fijo actualizado a $" << contexto.getMontoFijo() << "\n";
}


#endif
