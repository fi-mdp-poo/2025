#include "Cvector.h"

Cvector::Cvector(int n):
    capacidad(n),
    longitud(0),
    arreglo(NULL)
{
  arreglo = new Complejo[capacidad];
}

Cvector::Cvector(const Cvector& v):
    capacidad(v.capacidad),
    longitud(v.longitud)
{
    arreglo = new Complejo[capacidad];
    for(int i=0 ; i<longitud ; i++)
    {
        arreglo[i] = v.arreglo[i];
    }
}

Cvector& Cvector::operator = (const Cvector& v)
{
    if(this == &v) return *this;
    Complejo *aux = new Complejo[v.capacidad];
    for(int i=0 ; i<v.longitud ; i++)
    {
        aux[i]=v.arreglo[i];
    }
    delete[] arreglo;
    capacidad = v.capacidad;
    longitud = v.longitud;
    arreglo = aux;
    return *this;
}

Cvector::~Cvector()
{
    delete[] arreglo;
}

void Cvector::redimension(int n)
{
    capacidad = capacidad*2;
    if(n>capacidad)
    {
        capacidad = n;
    }
    Complejo *aux = new Complejo[capacidad];
    for(int i=0 ; i<longitud ; i++)
    {
        aux[i]=arreglo[i];
    }
    delete[] arreglo;
    arreglo = aux;
}

void Cvector::push_back(const Complejo& n)
{
    if(capacidad==longitud)
    {
        redimension();
    }
    arreglo[longitud] = n;
    longitud++;
}

Complejo Cvector::pop_back()
{
    Complejo result;
    if(longitud==0)
    {
        cout << "Posicion invalida de memoria. Se devolvio 0 + 0i" << endl;
    }
    else
    {
        longitud--;
        result = arreglo[longitud];
    }
    return result;
}

Complejo Cvector::get(int index) const
{
    Complejo result;
    if( index < 0 || index >= longitud)
    {
        cout << "Posicion invalida de memoria. Se devolvio 0 + 0i" << endl;
    }
    else
    {
        result = arreglo[index];
    }
    return result;
}

void Cvector::set(int index,const Complejo& dato)
{
    if( index < 0 || index >= longitud)
    {
        cout << "Posicion invalida de memoria" << endl;
    }
    else
    {
        arreglo[index] = dato;
    }
}

int Cvector::getSize() const
{
    return longitud;
}

int Cvector::getCapacity() const
{
    return capacidad;
}

Complejo Cvector::operator [] (int index) const
{
    Complejo result;
    if( index < 0 || index >= longitud)
    {
        cout << "Posicion invalida de memoria. Se devolvio 0 + 0i" << endl;
    }
    else
    {
        result = arreglo[index];
    }
    return result;
}

Complejo& Cvector::operator [] (int index)
{
    return arreglo[index];
}

void Cvector::clear()
{
    longitud = 0;
}

bool Cvector::empty() const
{
    return (longitud==0);
}

void Cvector::redimensionP(int nuevaLongitud, const Complejo& valorPorDefecto)
{
    if(nuevaLongitud < longitud)
    {
        longitud=nuevaLongitud;
    }
    else if(nuevaLongitud > longitud)
    {
        if(nuevaLongitud > capacidad)
        {
            redimension(nuevaLongitud);
        }
        for(int i = longitud ; i<nuevaLongitud ; i++)
        {
            arreglo[i]= valorPorDefecto;
        }
        longitud = nuevaLongitud;
    }
}

void Cvector::insertar(int index,const Complejo& valor)
{
    if( index >= 0 && index < longitud )
    {
        if(longitud==capacidad)
        {
            redimension();
        }
        for(int i=longitud ; i>index ; i--)
        {
            arreglo[i] = arreglo[i-1];
        }
        arreglo[index] = valor;
        longitud++;
    }
    else
    {
        cout << "Posicion de memoria invalida" << endl;
    }

}

void Cvector::eliminar(int index)
{
    if( index >= 0 && index < longitud )
    {
        --longitud;
        for(int i=index ; i < longitud ; i++)
        {
            arreglo[i] = arreglo[i+1];
        }
    }
    else
    {
        cout << "Posicion de memoria invalida" << endl;
    }
}

ostream& operator << (ostream& oS,const Cvector& v)
{
    oS << "[";
    for(int i=0 ; i < v.longitud ; i++)
    {
        oS << v.arreglo[i];
        if(i != (v.longitud -1) )
        {
            oS << ", ";
        }
    }
    oS << "]";
    return oS;
}

istream& operator >> (istream& is,Cvector& v)
{
    Complejo numero;
    cout << "Ingrese un Complejo(sera agregado al final del vector)" << endl;
    is >> numero;
    v.push_back(numero);
    return is;
}


