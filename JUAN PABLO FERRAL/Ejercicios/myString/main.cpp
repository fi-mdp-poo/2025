#include <iostream>
#include "myString.h"

using namespace std;

int main() {
    // --- Constructores ---
    myString s1(10);                 // constructor con tamaño
    myString s2("Hola");             // constructor desde C-string
    myString s3(s2);                 // constructor copia

    cout << "s2: " << s2 << endl;
    cout << "s3 (copia de s2): " << s3 << endl;

    // --- Operador =
    s1 = s2;
    cout << "s1 después de s1 = s2: " << s1 << endl;

    // --- Concatenación +
    myString s4 = s2 + myString(" Mundo");
    cout << "s4 = s2 + \" Mundo\": " << s4 << endl;

    // --- Operador +=
    s2 += myString(" C++");
    cout << "s2 después de s2 += \" C++\": " << s2 << endl;

    // --- Comparación
    cout << "s2 == s3 ? " << (s2 == s3) << endl;
    cout << "s2 != s3 ? " << (s2 != s3) << endl;

    // --- Acceso []
    cout << "s2[1] = " << s2[1] << endl;
    s2[1] = 'a';
    cout << "s2 después de modificar s2[1] = 'a': " << s2 << endl;

    // --- getLongitud
    cout << "Longitud de s2: " << s2.getLongitud() << endl;

    // --- clearString
    myString s5("Eliminar esto");
    s5.clearString();
    cout << "s5 después de clearString(): \"" << s5 << "\"" << endl;

    // --- append
    s5.append(myString("Nuevo contenido"));
    cout << "s5 después de append: " << s5 << endl;

    // --- push_back / pop_back
    s5.push_back('!');
    cout << "s5 después de push_back('!'): " << s5 << endl;
    s5.pop_back();
    cout << "s5 después de pop_back(): " << s5 << endl;

    // --- subcadena
    myString s6 = s4.subcadena(5, 5);
    cout << "Subcadena de s4 desde 5, 5 chars: " << s6 << endl;

    // --- insertar
    s4.insertar(5, myString("INSERT"));
    cout << "s4 después de insertar \"INSERT\" en pos 5: " << s4 << endl;

    // --- eliminar
    s4.eliminar(5, 6);
    cout << "s4 después de eliminar 6 chars desde pos 5: " << s4 << endl;

    // --- convertirConstchar
    const char* cstr = s4.convertirConstchar();
    cout << "s4 como const char*: " << cstr << endl;

    // --- encontrarSubcadena
    int pos = s4.encontrarSubcadena(myString("Mun"));
    cout << "Posición de \"Mun\" en s4: " << pos << endl;

    // --- cin >>
    myString s7;
    cout << "Ingrese una palabra: ";
    cin >> s7;
    cout << "Ingresó: " << s7 << endl;

    return 0;
}

