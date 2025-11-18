#include <iostream>
using namespace std;


#include "Complejo.hpp"
#include "myVector.hpp"

int main() {

    // Creamos un Cvector de complejos
    myVector<Complejo> v(3);

    // Agregamos algunos complejos
    v.push_back(Complejo(1, 2));
    v.push_back(Complejo(3, 4));
    v.push_back(Complejo(5, 6));
    v.resize(10, Complejo(7,99));

    cout << "Vector inicial: " << v << endl;

    // Probamos set en el segundo elemento
    Complejo c1(9,9);
    v.at(1) = c1;
    cout << "Despues de set en index 1: " << v << endl;

    // Probamos insertar en el medio
    v.insertar(1, Complejo(7, 7));
    cout << "Despues de insertar en index 1: " << v << endl;

    // Probamos eliminar el ultimo
    v.eliminar(v.size()-1);
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

    int a;
    cin >> a ;
    a=0;

    return 0;
}
