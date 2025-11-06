#include <iostream>
#include "Cmatriz.h"
#include "Complejo.h"

using namespace std;

int main() {
    // Crear una matriz 2x2
    Cmatriz A(2, 2);
    A.setCelda(0, 0, Complejo(1, 1));
    A.setCelda(0, 1, Complejo(2, -1));
    A.setCelda(1, 0, Complejo(3, 0));
    A.setCelda(1, 1, Complejo(0, 4));

    cout << "Matriz A:\n" << A << endl;

    // Crear otra matriz 2x2
    Cmatriz B(2, 2);
    B.setCelda(0, 0, Complejo(-1, 2));
    B.setCelda(0, 1, Complejo(0, 0));
    B.setCelda(1, 0, Complejo(5, -3));
    B.setCelda(1, 1, Complejo(2, 2));

    cout << "Matriz B:\n" << B << endl;

    // Suma
    Cmatriz C = A + B;
    cout << "A + B:\n" << C << endl;

    // Resta
    Cmatriz D = A - B;
    cout << "A - B:\n" << D << endl;

    // Multiplicación de matrices
    Cmatriz E = A * B;
    cout << "A * B:\n" << E << endl;

    // Multiplicación por escalar
    cout << "2 * A:\n" << 2 * A << endl;
    cout << "A * 1.5:\n" << A * 1.5 << endl;

    // Transpuesta
    Cmatriz At = A.transpuesta();
    cout << "Transpuesta de A:\n" << At << endl;

    // Acceso individual a celdas
    Complejo celda = A.getCelda(1, 0);
    cout << "Celda A[1][0]: " << celda << endl;

    // Tamaño
    cout << "Filas de A: " << A.getFilas() << endl;
    cout << "Columnas de A: " << A.getColumnas() << endl;

    // Operadores compuestos
    Cmatriz F = A;
    F += B;
    cout << "A += B:\n" << F << endl;

    F = A;
    F -= B;
    cout << "A -= B:\n" << F << endl;

    F = A;
    F *= 2;
    cout << "A *= 2:\n" << F << endl;

    // Determinante
    Complejo det = A.determinante();
    cout << "Determinante de A: " << det << endl;

    // Inversa
    Cmatriz invA = A.inversa();
    cout << "Inversa de A:\n" << invA << endl;

    cout << "\n" << A*A.inversa();

    return 0;
}


