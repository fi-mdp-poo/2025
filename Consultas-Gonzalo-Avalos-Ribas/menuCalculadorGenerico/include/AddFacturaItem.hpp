#ifndef ADD_FACTURA_ITEM_HPP
#define ADD_FACTURA_ITEM_HPP

#include "MenuItem.hpp"
#include "CalculadorImpositivo.hpp"
#include <string>
#include <limits>
#include <iostream>

using namespace std;
template <typename T>
class AddFacturaItem : public MenuItem<T>
{
    string titulo;

public:
    AddFacturaItem(const string &t = "Agregar factura");
    string name() const override;
    void execute(T& contexto) override;
};
template <typename T>
AddFacturaItem<T>::AddFacturaItem( const string &t)
    : titulo(t) {}

template <typename T>
string AddFacturaItem<T>::name() const { return titulo; }

template <typename T>
void AddFacturaItem<T>::execute(T& contexto)
{
    int numero;
    double monto;
    string detalle;

    cout << "Numero de factura: ";
    while (!(cin >> numero))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un numero valido: ";
    }
    cin.ignore();
    cout << "Detalle: ";
    getline(cin, detalle);
    cout << "Monto: ";
    while (!(cin >> monto))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un monto valido: ";
    }

    contexto.agregarFactura(numero, detalle, monto);
    cout << "Factura agregada.\n";
}

#endif
