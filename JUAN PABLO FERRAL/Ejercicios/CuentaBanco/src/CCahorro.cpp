#include "CCahorro.hpp"

CCahorro::CCahorro(unsigned int dni, unsigned int ident):
        Cuenta(dni, ident),
        maxExtracciones(10),
        contador(0)
{}

CCahorro::CCahorro(unsigned int dni, unsigned int ident, unsigned int contadorActual, long int saldoActual):
        Cuenta(dni, ident, saldoActual),
        maxExtracciones(10),
        contador(contadorActual)
{}

bool CCahorro::extraccion(long int retiro)
{
    bool result = false;
    if(retiro > 0)
    {
        if((saldo-retiro) >=0 && (contador < maxExtracciones))
        {
            saldo -= retiro;
            contador++;
            cout << "Extraccion exitosa. Nuevo saldo: " << saldo << endl;
            if(contador == maxExtracciones)
            {
                cout << "Se han alcanzado el maximo de extracciones mensuales" << endl;
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
            cout << "Se han superado el maximo de extracciones mensuales" << endl;
        }
    }
    else
    {
        cout << "Error: El monto a extraer debe ser positivo" << endl;
    }
    return result;
} 

void CCahorro :: serializacion(vector<uint8_t>& datos) const
{
    uint8_t tipo = 2;
    const uint8_t* p;
    datos.push_back(tipo);
    p = reinterpret_cast <const uint8_t*>(&dnititular);
    datos.insert(datos.end(), p, p + sizeof(dnititular));
    p = reinterpret_cast <const uint8_t*>(&id);
    datos.insert(datos.end(), p, p + sizeof(id));
    p = reinterpret_cast <const uint8_t*>(&saldo);
    datos.insert(datos.end(), p, p + sizeof(saldo));
    p = reinterpret_cast <const uint8_t*>(&contador);
    datos.insert(datos.end(), p, p + sizeof(contador));
}