#include <iostream>
#include "Complejo.h"

using namespace std;

int main()
{
    cout << "=== Prueba de la clase Complejo ===" << endl;

    // 1. Crear complejos
    Complejo c1(3, 4);
    Complejo c2;
    cout << "c1: " << c1 << endl;

    // 2. Entrada por usuario
    cin >> c2;
    cout << "c2 ingresado: " << c2 << endl;

    // 3. Operadores aritméticos con complejos
    Complejo suma = c1 + c2;
    Complejo resta = c1 - c2;
    Complejo mult = c1 * c2;
    Complejo div = c1 / c2;  // el operador ya muestra mensaje si c2 es 0+0i

    cout << "\n=== Operaciones entre complejos ===" << endl;
    cout << "Suma: " << suma << endl;
    cout << "Resta: " << resta << endl;
    cout << "Multiplicación: " << mult << endl;
    cout << "División: " << div << endl;

    // 4. Operadores con números
    cout << "\n=== Operaciones con números reales ===" << endl;
    cout << "c1 + 2 = " << c1 + 2 << endl;
    cout << "2 + c1 = " << 2 + c1 << endl;
    cout << "c1 - 1.5 = " << c1 - 1.5 << endl;
    cout << "3.5 - c1 = " << 3.5 - c1 << endl;
    cout << "c1 * 2 = " << c1 * 2 << endl;
    cout << "2 * c1 = " << 2 * c1 << endl;
    cout << "c1 / 2 = " << c1 / 2 << endl;
    cout << "2 / c1 = " << 2 / c1 << endl;

    // 5. Incrementos y decrementos
    Complejo inc = c1;
    ++inc;
    cout << "\n++c1 = " << inc << endl;
    inc = c1;
    inc++;
    cout << "c1++ = " << inc << endl;

    Complejo dec = c1;
    --dec;
    cout << "--c1 = " << dec << endl;
    dec = c1;
    dec--;
    cout << "c1-- = " << dec << endl;

    // 6. Conjugado
    cout << "\nConjugado de c1: " << c1.conjugado() << endl;

    // 7. Representación polar
    cout << "\nRepresentación polar en radianes: ";
    c1.repPolar();
    cout << "Representación polar en grados: ";
    c1.repPolarGrados();
    cout << "Forma trigonométrica: ";
    c1.repPolarFormaEst();

    // 8. Comparaciones
    cout << "\nComparaciones:" << endl;
    cout << "c1 == c2 ? " << (c1 == c2 ? "true" : "false") << endl;
    cout << "c1 != c2 ? " << (c1 != c2 ? "true" : "false") << endl;

    // 9. Prueba de setear por polar
    Complejo c3;
    c3.setrepPolar(5, M_PI/3);
    cout << "\nc3 definido por polar: " << c3 << endl;
    c3.repPolar();

    return 0;
}
