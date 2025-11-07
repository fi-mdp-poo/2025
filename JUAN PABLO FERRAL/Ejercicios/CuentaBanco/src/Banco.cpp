#include "Banco.hpp"

Banco :: Banco(const char* name, const char* Archivo):
     nombre(name),
     archivo_cuentas(Archivo)
{
    persistenciaCargar();
}

Banco :: ~Banco()
{
    persistenciaGuardar();
    for(size_t i=0 ; i<cuentas.size() ; i++)
    {
        delete cuentas[i];
    }
}

void Banco :: agregarCuenta(int tipo, unsigned int dni, const char* ARCHIVO_IDS)
{
    cuentas.push_back(CuentasFactory::crearCuenta(tipo, dni, ARCHIVO_IDS));
    /*if(ptr != NULL)
    {
        cuentas.push_back(ptr);
        cout << "Se ha agregado una nueva cuenta con exito" << endl;
    }*/
}

void Banco :: persistenciaGuardar()
{
    PersistenciaCuentas::guardarEstadoBanco(archivo_cuentas, cuentas);
}

void Banco :: persistenciaCargar()
{
    cuentas = PersistenciaCuentas::cargarEstadoBanco(archivo_cuentas);
}

Cuenta* Banco::buscarCuenta(unsigned int id) const
{
    Cuenta* result = NULL;
    long int low = 0;
    long int high = cuentas.size()-1;
    long int mid = (high + low)/2;
    while((low<=high) && cuentas[mid]->getId() != id )
    {
        if(id < cuentas[mid]->getId())
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        mid =(high + low)/2;
    }
    if(low<=high)
    {
        result = cuentas[mid];
    }
    else
    {
        cout << "No existe una cuenta con ese ID " << endl;
    }
    return result;
}

void Banco::mostrarCuentas() const 
{
    cout << "\n--- Estado de Cuentas en el Banco '" << nombre << "' ---" <<endl<<endl;
    if (cuentas.empty()) {
        cout << "No hay cuentas registradas en el banco." << endl;
    } else {
        for (size_t i=0 ; i<cuentas.size() ; i++) 
        {
            cout << *(cuentas[i]) << endl << endl; 
        }
    }
    cout << "-------------------------------------------------" << endl;
}

void Banco :: activoBanco() const
{
    long int activoTotal = 0;
    for(size_t i=0 ; i<cuentas.size() ; i++)
    {
        activoTotal += cuentas[i]->getSaldo();
    }
    cout << "El activo total del Banco " << nombre << "es: " << activoTotal << endl;
}

