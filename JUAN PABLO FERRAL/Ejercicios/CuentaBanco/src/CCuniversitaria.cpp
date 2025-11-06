#include "CCuniversitaria.hpp"

CCuniversitaria::CCuniversitaria(unsigned int dni, unsigned int ident):
        Cuenta(dni, ident),
        maxDiario(20000),
        cantDia(0)
{}

CCuniversitaria::CCuniversitaria(unsigned int dni, unsigned int ident, int cantDiaActual, long int saldoActual):
        Cuenta(dni, ident, saldoActual),
        maxDiario(20000),
        cantDia(cantDiaActual)
{}

bool CCuniversitaria::extraccion(long int retiro)
{
    bool result = false;
    if(retiro > 0)
    {
        if((saldo-retiro) >=0 && ((cantDia+retiro) <= maxDiario))
        {
            saldo -= retiro;
            cantDia += retiro;
            cout << "Extraccion exitosa. Nuevo saldo: " << saldo << endl;
            if(cantDia == maxDiario)
            {
                cout << "Se ha alcanzado el monto maximo que se puede extraer por dia" << endl;
            }
            result = true;
        }
        else if((saldo - retiro) < 0)
        {
            cout << "El monto supera el saldo de la cuenta. Intentelo de nuevo" << endl;
            cout << "Su saldo es: " << saldo << endl;
        }
        else 
        {
            cout << "Se supera el monto maximo del dia" << endl;
            cout << "Puede extraer un maximo de: " << maxDiario-cantDia << endl;
        }
    }
    else
    {
        cout << "Error: El monto a extraer debe ser positivo" << endl;
    }
    return result;
} 

void CCuniversitaria :: serializacion(vector<uint8_t>& datos) const 
{
    uint8_t tipo = 3;
    const uint8_t* p;
    datos.push_back(tipo);
    p = reinterpret_cast <const uint8_t*>(&dnititular);
    datos.insert(datos.end(), p, p + sizeof(dnititular));
    p = reinterpret_cast <const uint8_t*>(&id);
    datos.insert(datos.end(), p, p + sizeof(id));
    p = reinterpret_cast <const uint8_t*>(&saldo);
    datos.insert(datos.end(), p, p + sizeof(saldo));
    p = reinterpret_cast <const uint8_t*>(&cantDia);
    datos.insert(datos.end(), p, p + sizeof(cantDia));
}