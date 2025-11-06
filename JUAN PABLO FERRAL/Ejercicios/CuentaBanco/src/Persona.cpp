#include "Persona.hpp"

Persona::Persona(string name, string mail, unsigned int nuevoDni, unsigned int tel):
    nombre(name),
    email(mail),
    dni(nuevoDni),
    telefono(tel)
{}


Persona::Persona(const Persona& p):
    nombre(p.nombre),
    email(p.email),
    dni(p.dni),
    telefono(p.telefono)
{}

Persona& Persona::operator = (const Persona& p)
{
    if(this==&p) return *this;
    nombre = p.nombre;
    email = p.email;
    dni = p.dni;
    telefono = p.telefono;
    return *this;
}

ostream& operator <<(ostream& os,const Persona& p)
{
    os << "Nombre: " << p.nombre << endl
    << "DNI: " << p.dni << endl
    << "Telefono: " << p.telefono << endl
    << "Email: " << p.email << endl;
    return os;
}
