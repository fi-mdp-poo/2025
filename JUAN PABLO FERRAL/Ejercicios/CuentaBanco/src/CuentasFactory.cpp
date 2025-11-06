#include "CuentasFactory.hpp"


Cuenta* CuentasFactory :: crearCuenta(int tipo, unsigned int dni, const char* nombreArchivo)
{
    unsigned int idNuevo = 0;
    fstream fileIDs(nombreArchivo, ios::in | ios::binary);
    if(fileIDs.is_open())
    {
        fileIDs.read(reinterpret_cast<char*>(&idNuevo),sizeof(unsigned int));
        fileIDs.close();
    }
    Cuenta* result = NULL;
    switch (tipo)
    {
    case 1:
        {
            long int limite = 0;
            cout << "Ingrese su limite para operar en descubierto: ";
            cin >> limite;
            cout << "Creando su cuenta corriente. ID de su nueva cuenta: " << idNuevo << endl;
            result = new CCorriente(dni,idNuevo,limite);
            break;
        }
    case 2:
        {
            cout << "Creando su caja de ahorro. ID de su nueva cuenta: " << idNuevo << endl;
            result = new CCahorro(dni,idNuevo);
            break;
        }  
    case 3:
        {
            cout << "Creando su cuenta universitaria. ID de su nueva cuenta: " << idNuevo << endl;
            result = new CCuniversitaria(dni,idNuevo);
            break;
        }
    }
    fileIDs.open(nombreArchivo, ios::out | ios::binary | ios::trunc);
    if(fileIDs.is_open())
    {
        idNuevo++;
        fileIDs.write(reinterpret_cast<char*>(&idNuevo),sizeof(unsigned int));
        fileIDs.close();
    }
    return result;
}