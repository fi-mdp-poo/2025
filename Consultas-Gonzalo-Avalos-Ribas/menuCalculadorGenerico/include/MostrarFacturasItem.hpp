#ifndef MOSTRAR_FACTURAS_ITEM_HPP
#define MOSTRAR_FACTURAS_ITEM_HPP

#include "MenuItem.hpp"
#include "CalculadorImpositivo.hpp"
#include <iomanip>

using namespace std;
template <typename T>
class MostrarFacturasItem : public MenuItem<T>
{
    string titulo;

public:
    MostrarFacturasItem(const string &t = "Mostrar facturas");
    string name() const override;
    void execute(T& contexto) override;
};

template <typename T>
MostrarFacturasItem<T>::MostrarFacturasItem(const string &t)
    : titulo(t) {}

template <typename T>
string MostrarFacturasItem<T>::name() const { return titulo; }

template <typename T>
void MostrarFacturasItem<T>::execute(T& contexto)
{
    const vector<Factura> &facturas = contexto.getFacturas();
    if (facturas.empty())
    {
        cout << "No hay facturas cargadas.\n";
        return;
    }
    cout << left << setw(10) << "Numero"
         << setw(40) << "Detalle"
         << right << setw(12) << "Monto" << "\n";
    cout << string(62, '-') << "\n";
    for (const Factura &f : facturas)
    {
        cout << left << setw(10) << f.getNumero()
             << setw(40) << f.getDetalle()
             << right << setw(12) << fixed << setprecision(2)
             << f.getMonto() << "\n";
    }
}


#endif
