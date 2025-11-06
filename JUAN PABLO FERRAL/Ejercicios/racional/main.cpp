#include "racional.h"
#include <iostream>
#include <iomanip>

using namespace std;

void mostrarMenu() {
    cout << "\n======================================\n";
    cout << "  EJERCICIO: SOBRECARGA DE OPERADORES\n";
    cout << "        CLASE RACIONAL\n";
    cout << "======================================\n";
    cout << "1. Demostracion automatica\n";
    cout << "2. Ingreso manual de fracciones\n";
    cout << "3. Calculadora de fracciones\n";
    cout << "4. Comparacion de fracciones\n";
    cout << "5. Salir\n";
    cout << "======================================\n";
    cout << "Opcion: ";
}

void demostracionAutomatica() {
    cout << "\n=== DEMOSTRACION AUTOMATICA ===\n";

    // Constructores
    cout << "\n1. CONSTRUCTORES:\n";
    Racional r1;                    // Constructor por defecto
    Racional r2(5);                 // Constructor con entero
    Racional r3(3, 4);              // Constructor completo
    Racional r4(-6, 8);             // Se simplifica a -3/4

    cout << "r1 (defecto): " << r1 << "\n";
    cout << "r2 (entero 5): " << r2 << "\n";
    cout << "r3 (3/4): " << r3 << "\n";
    cout << "r4 (-6/8 simplificado): " << r4 << "\n";


    // Operaciones aritméticas
    cout << "\n2. OPERACIONES ARITMETICAS:\n";
    Racional a(1, 2);    // 1/2
    Racional b(1, 3);    // 1/3

    cout << "a = " << a << ", b = " << b << "\n";
    cout << "a + b = " << (a + b) << "\n";
    cout << "a - b = " << (a - b) << "\n";
    cout << "a * b = " << (a * b) << "\n";
    cout << "a / b = " << (a / b) << "\n";

    // Operadores unarios
    cout << "\n3. OPERADORES UNARIOS:\n";
    Racional c(2, 3);
    cout << "c = " << c << "\n";
    cout << "+c = " << (+c) << "\n";
    cout << "-c = " << (-c) << "\n";

    // Incremento y decremento
    cout << "\n4. INCREMENTO Y DECREMENTO:\n";
    Racional d(5, 2);
    cout << "d inicial = " << d << "\n";
    cout << "++d = " << (++d) << "\n";
    cout << "d++ = " << (d++) << "\n";
    cout << "d actual = " << d << "\n";
    cout << "--d = " << (--d) << "\n";
    cout << "d-- = " << (d--) << "\n";
    cout << "d final = " << d << "\n";

    // Operadores relacionales
    cout << "\n5. OPERADORES RELACIONALES:\n";
    Racional x(1, 2);
    Racional y(2, 4);    // Equivalente a 1/2
    Racional z(3, 4);

    cout << "x = " << x << ", y = " << y << ", z = " << z << "\n";
    cout << "x == y: " << (x == y ? "true" : "false") << "\n";
    cout << "x != z: " << (x != z ? "true" : "false") << "\n";
    cout << "x < z: " << (x < z ? "true" : "false") << "\n";
    cout << "z > x: " << (z > x ? "true" : "false") << "\n";
    cout << "x <= y: " << (x <= y ? "true" : "false") << "\n";
    cout << "z >= x: " << (z >= x ? "true" : "false") << "\n";

    // Conversiones y funciones adicionales
    cout << "\n6. CONVERSIONES Y FUNCIONES:\n";
    Racional f(3, 4);
    cout << "f = " << f << "\n";
    cout << "Valor decimal: " << f.decimal() << "\n";
    cout << "Conversion a double: " << static_cast<double>(f) << "\n";
    cout << "Es cero?: " << (f.esCero() ? "Si" : "No") << "\n";
    cout << "Es entero?: " << (f.esEntero() ? "Si" : "No") << "\n";
    cout << "Reciproco: " << f.reciproco() << "\n";

    // Operadores con asignación
    cout << "\n7. OPERADORES CON ASIGNACION:\n";
    Racional g(1, 4);
    cout << "g inicial = " << g << "\n";
    g += Racional(1, 4);
    cout << "g += 1/4: " << g << "\n";
    g *= Racional(2, 1);
    cout << "g *= 2: " << g << "\n";
    g -= Racional(1, 6);
    cout << "g -= 1/6: " << g << "\n";
    g /= Racional(1, 3);
    cout << "g /= 1/3: " << g << "\n";

}

void ingresoManual() {
    cout << "\n=== INGRESO MANUAL DE FRACCIONES ===\n";

    Racional r1, r2;

    cout << "Ingrese la primera fraccion:\n";
    cin >> r1;

    cout << "Ingrese la segunda fraccion:\n";
    cin >> r2;

    cout << "\nFracciones ingresadas (simplificadas):\n";
    cout << "Primera fraccion: " << r1 << "\n";
    cout << "Segunda fraccion: " << r2 << "\n";

    cout << "\nOperaciones entre las fracciones:\n";
    cout << r1 << " + " << r2 << " = " << (r1 + r2) << "\n";
    cout << r1 << " - " << r2 << " = " << (r1 - r2) << "\n";
    cout << r1 << " * " << r2 << " = " << (r1 * r2) << "\n";

    if (!r2.esCero()) {
        cout << r1 << " / " << r2 << " = " << (r1 / r2) << "\n";
    } else {
        cout << "No se puede dividir por cero\n";
    }
}

void calculadoraFracciones() {
    cout << "\n=== CALCULADORA DE FRACCIONES ===\n";

    Racional resultado;
    char operacion;
    bool continuar = true;

    cout << "Ingrese la fraccion inicial:\n";
    cin >> resultado;

    while (continuar) {
        cout << "\nResultado actual: " << resultado << "\n";
        cout << "Operaciones disponibles: +, -, *, /, =, q(salir)\n";
        cout << "Ingrese operacion: ";
        cin >> operacion;

        if (operacion == 'q' || operacion == 'Q') {
            continuar = false;
            continue;
        }

        if (operacion == '=') {
            cout << "Resultado final: " << resultado << "\n";
            cout << "Valor decimal: " << resultado.decimal() << "\n";
            continue;
        }

        Racional operando;
        cout << "Ingrese la fraccion operando:\n";
        cin >> operando;

            switch (operacion) {
                case '+':
                    resultado += operando;
                    break;
                case '-':
                    resultado -= operando;
                    break;
                case '*':
                    resultado *= operando;
                    break;
                case '/':
                    if (operando.esCero()) {
                        cout << "Error: No se puede dividir por cero\n";
                    } else {
                        resultado /= operando;
                    }
                    break;
                default:
                    cout << "Operacion no valida\n";
            }
        }
    }


void comparacionFracciones() {
    cout << "\n=== COMPARACION DE FRACCIONES ===\n";

    Racional f1, f2;

    cout << "Ingrese la primera fraccion:\n";
    cin >> f1;

    cout << "Ingrese la segunda fraccion:\n";
    cin >> f2;

    cout << "\n--- RESULTADOS DE COMPARACION ---\n";
    cout << "Fraccion 1: " << f1 << " (decimal: " << f1.decimal() << ")\n";
    cout << "Fraccion 2: " << f2 << " (decimal: " << f2.decimal() << ")\n";

    cout << "\nComparaciones:\n";
    cout << f1 << " == " << f2 << " : " << (f1 == f2 ? "Verdadero" : "Falso") << "\n";
    cout << f1 << " != " << f2 << " : " << (f1 != f2 ? "Verdadero" : "Falso") << "\n";
    cout << f1 << " < " << f2 << " : " << (f1 < f2 ? "Verdadero" : "Falso") << "\n";
    cout << f1 << " > " << f2 << " : " << (f1 > f2 ? "Verdadero" : "Falso") << "\n";
    cout << f1 << " <= " << f2 << " : " << (f1 <= f2 ? "Verdadero" : "Falso") << "\n";
    cout << f1 << " >= " << f2 << " : " << (f1 >= f2 ? "Verdadero" : "Falso") << "\n";

    if (f1 < f2) {
        cout << "\nLa fraccion mas pequena es: " << f1 << "\n";
        cout << "La fraccion mas grande es: " << f2 << "\n";
    } else if (f1 > f2) {
        cout << "\nLa fraccion mas pequena es: " << f2 << "\n";
        cout << "La fraccion mas grande es: " << f1 << "\n";
    } else {
        cout << "\nAmbas fracciones son iguales\n";
    }
}

int main() {
    int opcion;

    cout << fixed << setprecision(4);

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                demostracionAutomatica();
                break;
            case 2:
                ingresoManual();
                break;
            case 3:
                calculadoraFracciones();
                break;
            case 4:
                comparacionFracciones();
                break;
            case 5:
                cout << "\n Chau...\n";
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo.\n";
        }

        if (opcion != 5) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcion != 5);

    return 0;
}
