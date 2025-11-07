#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

using namespace std;

template <class T> class myVector

{
    //friend istream& operator >> (istream&,myVector&);
    public:
        myVector(size_t n=10);
        myVector(const myVector<T>&);
        myVector(myVector<T>&&) noexcept;
        myVector& operator = (const myVector<T>&);
        myVector& operator = (myVector<T>&&) noexcept;
        ~myVector();
        void push_back(const T&);
        T pop_back();
        T get(size_t) const;
        void set(size_t, const T&);
        int getSize() const { return longitud; }
        int getCapacity() const { return capacidad; }
        T operator [] (size_t) const;
        T& operator [] (size_t);
        void clear() { longitud = 0; }
        bool empty() const { return (longitud == 0); }
        void redimensionP(size_t nuevaLongitud, const T& dato);
        void insertar(size_t, const T&);
        void eliminar(size_t);

        friend ostream& operator << (ostream& oS,const myVector<T>& obj)
        {
            oS << "[";
            for(size_t i=0 ; i < obj.longitud ; i++)
            {
                oS << obj.arreglo[i];
                if(i != (obj.longitud -1) )
                {
                    oS << ", ";
                }
            }
            oS << "]";
            return oS;
        }
        
    private:
        size_t capacidad;
        size_t longitud;
        T* arreglo;
        void redimension(size_t n=0);
        void cambio(myVector<T>&) noexcept;
};

template<class T> void myVector<T> :: cambio(myVector<T>& v) noexcept
{
    using std::swap;
    swap(capacidad,v.capacidad);
    swap(longitud,v.longitud);
    swap(arreglo,v.arreglo);
}

template <class T> myVector<T> :: myVector(size_t n):
    capacidad(n),
    longitud(0),
    arreglo(nullptr)
{
    arreglo = new T[capacidad];
}

template <class T> myVector<T> :: myVector(const myVector<T>& v):
    capacidad(v.capacidad),
    longitud(v.longitud),
    arreglo(nullptr)
{
    arreglo = new T[capacidad];
    if(longitud != 0)
    {
        arreglo = new T[capacidad];
        try
        {
            for(size_t i=0; i<longitud ; i++)
            {
                arreglo[i] = v.arreglo[i];
            }
        }
        catch(...)
        {
            delete[] arreglo;
            throw;
        }
    }
}

template <class T> myVector<T> :: myVector(myVector<T>&& v) noexcept:
    capacidad(v.capacidad),
    longitud(v.longitud),
    arreglo(v.arreglo)
{
    v.capacidad = 0;
    v.longitud = 0;
    v.arreglo = nullptr;
}

template<class T>  myVector<T>& myVector<T> :: operator = (const myVector<T>& v)
{
    myVector<T> aux(v);
    cambio(aux);
    return *this;
}

template<class T> myVector<T>& myVector<T> :: operator = (myVector<T>&& v) noexcept
{
    if(this == &v) return *this;
    cambio(v);
    return *this;
}

template <class T> myVector<T> :: ~myVector()
{
    delete[] arreglo;
}

template <class T> void myVector<T> :: redimension(size_t n)
{
    capacidad = capacidad*2;
    if(n>capacidad)
    {
        capacidad = n;
    }
    T* aux = new T[capacidad];
    try
    {
        for(size_t i=0 ; i<longitud ; i++)
        {
            aux[i]=arreglo[i];
        }
        delete[] arreglo;
        arreglo = aux;
    }
    catch(...)
    {
        delete[] aux;
        throw;
    }
}

template <class T> void myVector<T> :: push_back(const T& n)
{
    if(longitud == capacidad)
    {
        redimension();
    }
    arreglo[longitud] = n;
    longitud++;
}

template<class T> T myVector<T> :: pop_back()
{
    if(longitud == 0)
    {
        throw out_of_range("Llamada a pop_back con vector vacio");
    }
    else
    {
        longitud--;
        return arreglo[longitud];
    }
}

template<class T> T myVector<T> :: get(size_t index) const
{
    if(index >= longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::get()");
    }
    else
    {
        return arreglo[index];
    }
}


template<class T> void myVector<T> :: set(size_t index, const T& dato)
{
    if(index >= longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::set()");
    }
    else
    {
        arreglo[index] = dato;
    }
}

template<class T> T myVector<T> ::operator [] (size_t index) const
{
    if(index >= longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::operator[]");
    }
    else
    {
        return arreglo[index];
    }
}

template<class T> T& myVector<T> :: operator [] (size_t index)
{
    if(index >= longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::operator[]");
    }
    else
    {
        return arreglo[index];
    }
}

template<class T> void myVector<T> :: redimensionP(size_t nuevaLongitud, const T& dato)
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
        for(size_t i = longitud ; i<nuevaLongitud ; i++)
        {
            arreglo[i]= dato;
        }
        longitud = nuevaLongitud;
    }
}

template<class T> void myVector<T> :: insertar(size_t index, const T& dato)
{
    if(index >= longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::insertar()");
    }
    else
    {
        if(longitud == capacidad)
        {
            redimension();
        }
        for(size_t i=longitud ; i>index ; i--)
        {
            arreglo[i] = arreglo[i-1];
        }
        arreglo[index] = dato;
        longitud++;
    }
}

template<class T> void myVector<T> :: eliminar(size_t index)
{
    if(index >= longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::eliminar()");
    }
    else
    {
        --longitud;
        for(size_t i=index ; i < longitud ; i++)
        {
            arreglo[i] = arreglo[i+1];
        }
    }
}

template<class T> ostream& operator << (ostream& oS,const myVector<T>& obj)
{
    oS << "[";
    for(int i=0 ; i < obj.longitud ; i++)
    {
        oS << obj.arreglo[i];
        if(i != (obj.longitud -1) )
        {
            oS << ", ";
        }
    }
    oS << "]";
    return oS;
}

/*istream& operator >> (istream& is,Cvector& v)
{
    Complejo numero;
    cout << "Ingrese un Complejo(sera agregado al final del vector)" << endl;
    is >> numero;
    v.push_back(numero);
    return is;
}*/

#endif // MYVECTOR_H