#include <iostream>
using namespace std;

// aca incluir tus headers reales
//#include "Complejo.h"
#include "Cvector.h"

int main() {

    // Creamos un Cvector de complejos
    Cvector v(3);

    cin >> v;

    // Agregamos algunos complejos
    v.push_back(Complejo(1, 2));
    v.push_back(Complejo(3, 4));
    v.push_back(Complejo(5, 6));
    v.redimensionP(10);

    cout << "Vector inicial: " << v << endl;

    // Probamos set en el segundo elemento
    v.set(1, Complejo(9, 9));
    cout << "Despues de set en index 1: " << v << endl;

    // Probamos insertar en el medio
    v.insertar(1, Complejo(7, 7));
    cout << "Despues de insertar en index 1: " << v << endl;

    // Probamos eliminar el ultimo
    v.eliminar(v.getSize()-1);
    cout << "Despues de eliminar el ultimo: " << v << endl;

    // Probamos pop_back
    Complejo c = v.pop_back();
    cout << "Se saco con pop_back: " << c << endl;
    cout << "Vector ahora: " << v << endl;

    // Probamos empty y clear
    cout << "Esta vacio? " << (v.empty() ? "si" : "no") << endl;
    v.clear();
    cout << "Despues de clear esta vacio? " << (v.empty() ? "si" : "no") << endl;
    cout << "Vector ahora: " << v << endl;

    return 0;
}
