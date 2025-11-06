#include "Ivector.h"

Ivector::Ivector(int n):
    capacidad(n),
    longitud(0),
    arreglo(NULL)
{
  arreglo = new int[capacidad];
}

Ivector::Ivector(const Ivector& v):
    capacidad(v.capacidad),
    longitud(v.longitud)
{
    arreglo = new int[capacidad];
    for(int i=0 ; i<longitud ; i++)
    {
        arreglo[i] = v.arreglo[i];
    }
}

Ivector& Ivector::operator = (const Ivector& v)
{
    if(this == &v) return *this;
    int *aux = new int[v.capacidad];
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

Ivector::~Ivector()
{
    delete[] arreglo;
}

void Ivector::redimension(int n)
{
    capacidad = capacidad*2;
    if(n>capacidad)
    {
        capacidad = n;
    }
    int *aux = new int[capacidad];
    for(int i=0 ; i<longitud ; i++)
    {
        aux[i]=arreglo[i];
    }
    delete[] arreglo;
    arreglo = aux;
}

void Ivector::push_back(int n)
{
    if(capacidad==longitud)
    {
        redimension();
    }
    arreglo[longitud] = n;
    longitud++;
}

int Ivector::pop_back()
{
    int result = 0;
    if(longitud==0)
    {
        cout << "Posicion invalida de memoria. Se devolvio 0" << endl;
    }
    else
    {
        longitud--;
        result = arreglo[longitud];
    }
    return result;
}

int Ivector::get(int index) const
{
    int result = 0;
    if( index < 0 || index >= longitud)
    {
        cout << "Posicion invalida de memoria. Se devolvio 0" << endl;
    }
    else
    {
        result = arreglo[index];
    }
    return result;
}

void Ivector::set(int index,int dato)
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

int Ivector::getSize() const
{
    return longitud;
}

int Ivector::getCapacity() const
{
    return capacidad;
}

int Ivector::operator [] (int index) const
{
    int result = 0;
    if( index < 0 || index >= longitud)
    {
        cout << "Posicion invalida de memoria. Se devolvio 0" << endl;
    }
    else
    {
        result = arreglo[index];
    }
    return result;
}

int& Ivector::operator [] (int index)
{
    return arreglo[index];
}

void Ivector::clear()
{
    longitud = 0;
}

bool Ivector::empty() const
{
    return (longitud==0);
}

void Ivector::redimensionP(int nuevaLongitud, int valorPorDefecto)
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

void Ivector::insertar(int index,int valor)
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

void Ivector::eliminar(int index)
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

ostream& operator << (ostream& oS,const Ivector& v)
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

istream& operator >> (istream& is,Ivector& v)
{
    int numero = 0;
    cout << "Ingrese un numero(sera agregado al final del vector): ";
    is >> numero;
    v.push_back(numero);
    return is;
}






