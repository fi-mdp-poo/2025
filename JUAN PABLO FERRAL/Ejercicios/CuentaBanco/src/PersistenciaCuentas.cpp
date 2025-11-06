#include "PersistenciaCuentas.hpp"

void PersistenciaCuentas::guardarEstadoBanco(const char* nombreArchivo ,const vector<Cuenta*>& cuentas)
{
    ofstream fsalida(nombreArchivo, ios::binary | ios::trunc);
    if(fsalida.is_open())
    {
        vector<uint8_t> datos;
        for (size_t i = 0; i < cuentas.size() ; i++)
        {
            datos.clear();
            cuentas[i]->serializacion(datos);
            if(!datos.empty())
            {
                fsalida.write(reinterpret_cast<char*>(datos.data()),datos.size());
            }
        }
        fsalida.close();
    }
    else
    {
        cout << "Error al abrir el achivo: " << nombreArchivo << endl;
    }
}

void PersistenciaCuentas::cargarEstadoBanco(const char* nombreArchivo, Banco& bank)
{
    ifstream fentrada(nombreArchivo, ios::binary);
    if(fentrada.is_open())
    {
        uint8_t tipo = 0;
        unsigned int dnititular = 0;
        unsigned int id = 0;
        long int saldo = 0;
        unsigned int contador = 0;
        int cantDia = 0;
        long int tope = 0;
        while(fentrada.read(reinterpret_cast<char*>(&tipo),sizeof(uint8_t)))
        {
            fentrada.read(reinterpret_cast<char*>(&dnititular),sizeof(unsigned int));
            fentrada.read(reinterpret_cast<char*>(&id),sizeof(unsigned int));
            fentrada.read(reinterpret_cast<char*>(&saldo),sizeof(long int));
            switch (tipo)
            {
                case 1:
                    fentrada.read(reinterpret_cast<char*>(&tope),sizeof(long int));
                    bank.agregarCuenta(new CCorriente(dnititular,id,tope,saldo));
                    break;
                case 2:
                    fentrada.read(reinterpret_cast<char*>(&contador),sizeof(unsigned int));
                    bank.agregarCuenta(new CCahorro(dnititular,id,contador,saldo));
                    break;
                case 3:
                    fentrada.read(reinterpret_cast<char*>(&cantDia),sizeof(int));
                    bank.agregarCuenta(new CCuniversitaria(dnititular,id,cantDia,saldo));
                    break;
            }
        }
        fentrada.close();
    }
    else
    {
        cout << "Error al abrir el achivo: " << nombreArchivo << endl;
    }
}