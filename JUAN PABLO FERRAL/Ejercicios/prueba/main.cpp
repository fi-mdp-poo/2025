#include <iostream>
#include <fstream>

int main() {
    unsigned int filas = 3;
    unsigned int columnas = 3;
    unsigned int valores[9] = {
        0xFF112233, 0xFF445566, 0xFF778899,
        0xFFAA1122, 0xFF33CC44, 0xFF556677,
        0xFF8899AA, 0xFFBBAACC, 0xFFCCDDEE
    };

    std::ofstream fsalida("colores.bin", std::ios::binary);
    if (!fsalida) {
        std::cerr << "No se pudo abrir el archivo para escritura.\n";
        return 1;
    }

    // Escribo filas y columnas
    fsalida.write(reinterpret_cast<char*>(&filas), sizeof(unsigned int));
    fsalida.write(reinterpret_cast<char*>(&columnas), sizeof(unsigned int));

    // Escribo todos los valores
    fsalida.write(reinterpret_cast<char*>(valores), sizeof(unsigned int) * filas * columnas);

    fsalida.close();

    std::cout << "Archivo 'colores.bin' creado correctamente.\n";
    return 0;
}
