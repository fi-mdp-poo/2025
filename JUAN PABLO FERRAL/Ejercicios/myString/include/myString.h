#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

using namespace std;

class myString
{
    friend ostream& operator<<(ostream& os, const myString& s);
    friend istream& operator>>(istream& is, myString& s);
    public:
        myString(int tamanio=100);
        myString(const char*);
        myString(const myString&);
        myString& operator=(const myString&);
        myString operator+(const myString&) const;
        myString& operator+=(const myString&);
        bool operator==(const myString&) const;
        bool operator!=(const myString&) const;
        char& operator[](int);
        const char& operator[](int) const;
        int getLongitud() const;
        void clearString();
        void append(const myString&);
        void push_back(char);
        char pop_back();
        myString subcadena(int,int) const;
        int encontrarSubcadena(const myString& s) const;
        void insertar(int pos, const myString& s);
        void eliminar(int pos, int count);
        const char* convertirConstchar() const;
        ~myString();
    private:
        int longitud;
        int capacidad;
        char* datos;
        void redimensionPriv();
};

#endif // MYSTRING_H
