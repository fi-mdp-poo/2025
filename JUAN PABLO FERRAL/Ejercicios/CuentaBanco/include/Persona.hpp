#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class GestorClientes;

class Persona
{
    friend class GestorClientes;
    friend ostream& operator <<(ostream&,const Persona&);
    public:
        Persona(string, string, unsigned int, unsigned int);
        Persona(const Persona&);
        Persona& operator = (const Persona&);
        unsigned int getDni() const { return dni; }

    private:
       string nombre;
       string email;
       unsigned int dni;
       unsigned int telefono;

};

#endif