#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

template <class T> class myVector

{
    //friend ostream& operator << (ostream&,const myVector&);
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
        T get(int) const;
        void set(int,const T&);
        int getSize() const;
        int getCapacity() const;
        T operator [] (int) const;
        T& operator [] (int);
        void clear();
        bool empty() const;
        void redimensionP(int nuevaLongitud, const T& valorPorDefecto = T(0,0));
        void insertar(int,const T&);
        void eliminar(int);
        
    private:
        size_t capacidad;
        size_t longitud;
        T* arreglo;
        void redimension(size_t n);
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
        for(int i=0 ; i<longitud ; i++)
        {
            aux[i]=arreglo[i];
        }
        delete[] arreglo;
        arreglo = aux;
    }
    catch(...)
    {
        delete[] aux;
    }
}






#endif // MYVECTOR_H