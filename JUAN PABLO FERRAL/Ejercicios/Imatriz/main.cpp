#include "Imatriz.h"
#include <iostream>

using namespace std;

int main() {
    // --- Crear matrices ---
    Imatriz A(3,3);
    Imatriz B(3,3);

    // Llenar A
    A.set(0,0,1); A.set(0,1,2); A.set(0,2,3);
    A.set(1,0,0); A.set(1,1,1); A.set(1,2,4);
    A.set(2,0,5); A.set(2,1,6); A.set(2,2,0);

    // Llenar B
    B.set(0,0,7); B.set(0,1,8); B.set(0,2,9);
    B.set(1,0,2); B.set(1,1,3); B.set(1,2,1);
    B.set(2,0,4); B.set(2,1,0); B.set(2,2,6);

    cout << "Matriz A:\n" << A << "\n";
    cout << "Matriz B:\n" << B << "\n";

    // --- Suma y resta ---
    Imatriz C = A + B;
    cout << "A + B:\n" << C << "\n";

    Imatriz D = A - B;
    cout << "A - B:\n" << D << "\n";

    // --- Multiplicación por escalar ---
    Imatriz E = A * 2;
    cout << "A * 2:\n" << E << "\n";

    Imatriz F = 0.5 * B;
    cout << "0.5 * B:\n" << F << "\n";

    // --- Multiplicación de matrices ---
    Imatriz G = A * B;
    cout << "A * B:\n" << G << "\n";

    // --- Transpuesta ---
    Imatriz H = A.trasnpuesta();
    cout << "Transpuesta de A:\n" << H << "\n";

    // --- Determinante ---
    double detA = A.determinante();
    cout << "Determinante de A: " << detA << "\n";

    // --- Inversa ---
    Imatriz I = A.inversa();
    cout << "Inversa de A:\n" << I << "\n";

    // --- Operadores combinados ---
    A += B;
    cout << "A += B:\n" << A << "\n";

    A -= B;
    cout << "A -= B:\n" << A << "\n";

    A *= 2;
    cout << "A *= 2:\n" << A << "\n";

    A *= B;
    cout << "A *= B:\n" << A << "\n";

    return 0;
}



