#include "CCorriente.hpp"

CCorriente::CCorriente(unsigned int dni, unsigned int ident, long int limite):
        Cuenta(dni, ident)
{
    if (limite > 0)
    {
        tope = -limite;
    }
    else
    {
        tope = limite;
    }
}

CCorriente::CCorriente(unsigned int dni, unsigned int ident, long int limite, long int saldoActual):
        Cuenta(dni, ident, saldoActual)
{
    if (limite > 0)
    {
        tope = -limite;
    }
    else
    {
        tope = limite;
    }
}

bool CCorriente::extraccion(long int retiro)
{
   bool result = false;
   if(retiro > 0)
   {
        if((saldo-retiro) >= tope)
        {
            saldo -= retiro;
            cout << "Extraccion exitosa. Nuevo saldo: " << saldo << endl;
            if(saldo < 0)
            {
                cout << "AVISO: Esta operando con giro en descubierto" << endl;
            }
            result = true;
        }
        else
        {
            cout << "Monto no permitido. Supera el tope pactado para sobregiro, intentelo de nuevo" << endl;
            cout << "Su saldo es: " << saldo << endl << "Su tope de descubierto le permite llegar hasta: " << tope << endl;
        }
   }
   else
   {
      cout << "Error: El monto a extraer debe ser positivo" << endl;
   }
   return result;
} 

void CCorriente :: serializacion(vector<uint8_t>& datos) const
{
    uint8_t tipo = 1;
    const uint8_t* p;
    datos.push_back(tipo);
    p = reinterpret_cast <const uint8_t*>(&dnititular);
    datos.insert(datos.end(), p, p + sizeof(dnititular));
    p = reinterpret_cast <const uint8_t*>(&id);
    datos.insert(datos.end(), p, p + sizeof(id));
    p = reinterpret_cast <const uint8_t*>(&saldo);
    datos.insert(datos.end(), p, p + sizeof(saldo));
    p = reinterpret_cast <const uint8_t*>(&tope);
    datos.insert(datos.end(), p, p + sizeof(tope));
}

void CCorriente :: printCuenta(ostream& os) const
{
    os << "Cuenta corriente" << endl
    << "Id de la cuenta: " << id << endl
    << "Dni del titular: " << dnititular << endl
    << "Tope pactado para giro en descubierto: " << tope << endl
    << "Saldo en la cuenta: " << saldo << endl;
}
