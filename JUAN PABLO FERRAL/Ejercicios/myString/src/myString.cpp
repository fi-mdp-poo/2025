#include "myString.h"

myString::myString(int tamanio):
    longitud(0),
    capacidad(tamanio)
{
    datos = new char[tamanio];
    datos[0] = '\0';
}

myString::myString(const char* copia):
    longitud(strlen(copia)),
    capacidad(longitud*2)
{
    datos = new char[capacidad];
    strcpy(datos,copia);
}

myString::myString(const myString& s):
    longitud(s.longitud),
    capacidad(s.capacidad)
{
    datos = new char[capacidad];
    for(int i = 0 ; i<(longitud)+1 ; i++)
    {
        datos[i] = s.datos[i];
    }
}

myString::~myString()
{
    delete[] datos;
}

void myString::redimensionPriv()
{
    capacidad *= 2;
    char* aux = new char[capacidad];
    for(int i=0 ; i<(longitud)+1 ; i++)
    {
        aux[i] = datos[i];
    }
    delete [] datos;
    datos = aux;
}

myString& myString::operator = (const myString& s)
{
    if(this == &s) return *this;
    char* aux = new char[s.capacidad];
    for(int i=0 ; i<(s.longitud)+1 ; i++)
    {
        aux[i] = s.datos[i];
    }
    delete[] datos;
    longitud = s.longitud;
    capacidad = s.capacidad;
    datos = aux;
    return *this;
}

myString myString::operator + (const myString& s) const
{
    myString result(capacidad+s.capacidad);
    for(int i=0 ; i<longitud ; i++)
    {
        result[i] = datos[i];
    }
    for(int i=0 ; i<s.longitud ; i++)
    {
        result[i+longitud] = s.datos[i];
    }
    result.datos[longitud + s.longitud] = '\0';
    result.longitud = longitud + s.longitud;
    return result;
}

myString& myString::operator+=(const myString& s)
{
    *this = *this + s;
    return *this;
}

bool myString::operator==(const myString& s) const
{
    bool result = false;
    int i = 0;
    if(longitud == s.longitud)
    {
        result = true;
        while(result && i<longitud)
        {
            if(datos[i] != s.datos[i])
            {
                result = false;
            }
            i++;
        }
    }
    return result;
}

bool myString::operator!=(const myString& s) const
{
    return !(*this == s);
}

char& myString::operator[](int index)
{
    return datos[index];
}

const char& myString::operator[](int index) const
{
    return datos[index];
}

int myString::getLongitud() const
{
    return longitud;
}

void myString::clearString()
{
    longitud = 0;
    datos[0] = '\0';
}

void myString::append(const myString& s)
{
    *this=*this + s;
}

ostream& operator<<(ostream& os, const myString& s)
{
    os << s.datos;
    return os;
}

istream& operator>>(istream& is, myString& s)
{
    char* aux = new char[1000];
    is.getline(aux,1000);
    int auxlong = strlen(aux);
    while(s.capacidad < auxlong+1)
    {
        s.redimensionPriv();
    }
    s.longitud = auxlong;
    strcpy(s.datos,aux);
    delete[] aux;
    return is;
}

void myString::push_back(char c)
{
    if (longitud + 1 >= capacidad)
    {
        redimensionPriv();
    }
    datos[longitud] = c;
    longitud++;
    datos[longitud] = '\0';
}

char myString::pop_back()
{
    char result = '\0';
    if (longitud > 0)
    {
        longitud--;
        result = datos[longitud];
        datos[longitud] = '\0';
    }
    return result;
}

myString myString::subcadena(int pos, int cantidad) const
{
    myString result(cantidad + 1);
    if (pos >= 0 && pos < longitud)
    {
        int c = 0;
        for (int i = pos ; i < pos + cantidad && i < longitud ; i++)
        {
            result[c++] = datos[i];
        }
        result[c] = '\0';
        result.longitud = c;
    }
    return result;
}

void myString::insertar(int pos, const myString& s)
{
    if (pos < 0) pos = 0;
    if (pos > longitud) pos = longitud;
    while (longitud + s.longitud >= capacidad)
    {
        redimensionPriv();
    }
    for (int i = longitud - 1 ; i >= pos ; i--)
    {
        datos[i + s.longitud] = datos[i];
    }
    for (int i = 0 ; i < s.longitud ; i++)
    {
        datos[pos + i] = s.datos[i];
    }
    longitud += s.longitud;
    datos[longitud] = '\0';
}

void myString::eliminar(int pos, int cantidad)
{
    if (pos < 0 || pos >= longitud || cantidad <= 0) return;
    int fin = pos + cantidad;
    if (fin > longitud) fin = longitud;
    for (int i = fin ; i < longitud ; i++)
    {
        datos[i - cantidad] = datos[i];
    }
    longitud -= (fin - pos);
    datos[longitud] = '\0';
}

const char* myString::convertirConstchar() const
{
    return datos;
}

int myString::encontrarSubcadena(const myString& s) const
{
    if (s.longitud == 0 || s.longitud > longitud) return -1;

    int pos = -1;
    int i = 0;

    while (i <= longitud - s.longitud && pos == -1)
    {
        int j = 0;
        while (j < s.longitud && datos[i + j] == s.datos[j])
        {
            j++;
        }
        if (j == s.longitud)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}
