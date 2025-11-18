#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <utility>
#include <stdexcept>
#include <memory>

using namespace std;

template <class T> class myVector

{
    public:
        myVector(size_t n=10);
        myVector(const myVector<T>&);
        myVector(myVector<T>&&) noexcept;
        myVector& operator = (const myVector<T>&);
        myVector& operator = (myVector<T>&&) noexcept;
        void push_back(const T&);
        void push_back(T&& n);
        T pop_back();
        const T& at(size_t) const;
        T& at(size_t);
        size_t size() const { return longitud; }
        size_t capacity() const { return capacidad; }
        const T& operator [] (size_t) const;
        T& operator [] (size_t);
        void clear() { longitud = 0; }
        bool empty() const { return (longitud == 0); }
        void resize(size_t nuevaLongitud);
        void resize(size_t nuevaLongitud, const T& dato);
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

        class iterator
        {
            private:
                T* i_ptr;
            public:
                iterator(T* ptr) : i_ptr(ptr) {}
                T& operator*() { return *i_ptr; }
                T* operator->() { return i_ptr; }
                iterator& operator++()
                {
                    ++i_ptr;
                    return *this;
                }
                iterator operator++(int)
                {
                    iterator aux(i_ptr++);
                    return aux;
                }
                iterator& operator--()
                {
                    --i_ptr;
                    return *this;
                }
                iterator operator--(int)
                {
                    iterator aux(i_ptr--);
                    return aux;
                }
                iterator operator + (size_t n) const
                {
                    return iterator(i_ptr + n);
                }
                iterator operator - (size_t n) const
                {
                    return iterator(i_ptr - n);
                }
                ptrdiff_t operator - (const iterator it) const
                {
                    return i_ptr - it.i_ptr;
                }
                iterator& operator += (size_t n)
                {
                    i_ptr += n;
                    return *this;
                }
                iterator& operator -= (size_t n)
                {
                    i_ptr -= n;
                    return *this;
                }
                bool operator ==(const iterator& it) const { return i_ptr == it.i_ptr ; }
                bool operator !=(const iterator& it) const { return ! ( *this == it) ; }
                bool operator < (const iterator& it) const { return i_ptr < it.i_ptr; }
                bool operator <= (const iterator& it) const { return i_ptr <= it.i_ptr; }
                bool operator > (const iterator& it) const { return !(*this <= it); }
                bool operator >= (const iterator& it) const { return !(*this < it); } 
        };

        class const_iterator
        {
            private:
                const T* ci_ptr;
            public:
                const_iterator(const T* ptr) : ci_ptr(ptr) {}
                const T& operator*() const { return *ci_ptr; }
                const T* operator->() const { return ci_ptr; }
                const_iterator& operator++()
                {
                    ++ci_ptr;
                    return *this;
                }
                const_iterator operator++(int)
                {
                    const_iterator aux(ci_ptr++);
                    return aux;
                }
                const_iterator& operator--()
                {
                    --ci_ptr;
                    return *this;
                }
                const_iterator operator--(int)
                {
                    const_iterator aux(ci_ptr--);
                    return aux;
                }
                const_iterator operator + (size_t n) const
                {
                    return const_iterator(ci_ptr + n);
                }
                const_iterator operator - (size_t n) const
                {
                    return const_iterator(ci_ptr - n);
                }
                ptrdiff_t operator - (const const_iterator it) const
                {
                    return ci_ptr - it.ci_ptr;
                }
                const_iterator& operator += (size_t n)
                {
                    ci_ptr += n;
                    return *this;
                }
                const_iterator& operator -= (size_t n)
                {
                    ci_ptr -= n;
                    return *this;
                }
                bool operator ==(const const_iterator& it) const { return ci_ptr == it.ci_ptr ; }
                bool operator !=(const const_iterator& it) const { return ! ( *this == it) ; }
                bool operator < (const const_iterator& it) const { return ci_ptr < it.ci_ptr; }
                bool operator <= (const const_iterator& it) const { return ci_ptr <= it.ci_ptr; }
                bool operator > (const const_iterator& it) const { return !(*this <= it); }
                bool operator >= (const const_iterator& it) const { return !(*this < it); } 
        };
        iterator begin() { return iterator(arreglo.get()); }
        const_iterator begin() const { return const_iterator(arreglo.get()); } 
        iterator end() { return iterator(arreglo.get() + longitud); }
        const_iterator end() const { return const_iterator(arreglo.get() + longitud); }
    private:
        size_t capacidad;
        size_t longitud;
        unique_ptr<T[]> arreglo;
        void redimension(size_t n=0);
};

template <class T> myVector<T> :: myVector(size_t n):
    capacidad(n),
    longitud(0),
    arreglo(make_unique<T[]>(capacidad))
{}

template <class T> myVector<T> :: myVector(const myVector<T>& v):
    capacidad(v.capacidad),
    longitud(v.longitud),
    arreglo(make_unique<T[]>(capacidad))
{
    for(size_t i=0 ; i<longitud ; i++)
    {
        arreglo[i] = v.arreglo[i];
    }
}

template <class T> myVector<T> :: myVector(myVector<T>&& v) noexcept:
    capacidad(v.capacidad),
    longitud(v.longitud),
    arreglo(move(v.arreglo))
{
    v.capacidad = 0;
    v.longitud = 0;
}

template<class T>  myVector<T>& myVector<T> :: operator = (const myVector<T>& v)
{
    if(this == &v) return *this;
    myVector<T> aux(v);
    capacidad = v.capacidad;
    longitud = v.longitud;
    arreglo.swap(aux.arreglo);
    return *this;
}

template<class T> myVector<T>& myVector<T> :: operator = (myVector<T>&& v) noexcept
{
    if(this == &v) return *this;
    capacidad = v.capacidad;
    longitud = v.longitud;
    v.capacidad = 0;
    v.longitud = 0;
    arreglo.swap(v.arreglo);
    return *this;
}

template <class T> void myVector<T> :: redimension(size_t n)
{
    size_t nuevaCapacidad = (capacidad == 0) ?  10 : capacidad*2;
    if(n>nuevaCapacidad)
    {
        nuevaCapacidad = n;
    }
    auto aux = make_unique<T[]>(nuevaCapacidad);
    for(size_t i=0 ; i<longitud ; i++)
    {
        aux[i] = move(arreglo[i]);
    }
    capacidad = nuevaCapacidad;
    arreglo.swap(aux);
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

template <class T> void myVector<T> :: push_back(T&& n) 
{
    if(longitud == capacidad)
    {
        redimension();
    }
    arreglo[longitud] = move(n);
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
        T dato = move(arreglo[longitud-1]);
        longitud--;
        return dato;
    }
}

template<class T> const T& myVector<T> :: at(size_t index) const
{
    if(index >= longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::at()");
    }
    else
    {
        return arreglo[index];
    }
}


template<class T> T& myVector<T> :: at(size_t index)
{
    if(index >= longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::at()");
    }
    else
    {
        return arreglo[index];
    }
}

template<class T> const T& myVector<T> ::operator [] (size_t index) const
{
    return arreglo[index];
}

template<class T> T& myVector<T> :: operator [] (size_t index)
{
    return arreglo[index];
}

template<class T> void myVector<T> :: resize(size_t nuevaLongitud)
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
        longitud = nuevaLongitud;
    }
}

template<class T> void myVector<T> :: resize(size_t nuevaLongitud, const T& dato)
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
    if(index > longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::insertar()");
    }
    if(longitud == capacidad)
    {
        redimension();
    }
    for(size_t i=longitud ; i>index ; i--)
    {
        arreglo[i] = move(arreglo[i-1]);
    }
    arreglo[index] = dato;
    longitud++;
}

template<class T> void myVector<T> :: eliminar(size_t index)
{
    if(index >= longitud)
    {
        throw out_of_range("Indice fuera de rango en myVector::eliminar()");
    }
    --longitud;
    for(size_t i=index ; i < longitud ; i++)
    {
        arreglo[i] = move(arreglo[i+1]);
    }
}

#endif // MYVECTOR_H