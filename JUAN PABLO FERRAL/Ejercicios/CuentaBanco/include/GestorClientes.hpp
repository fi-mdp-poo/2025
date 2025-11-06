#ifndef GESTORCLIENTES_H
#define GESTORCLIENTES_H

#include <vector>
#include <fstream>
#include "Persona.hpp"

class GestorClientes
{
    public:
        GestorClientes(const char*);
        void agregarCliente(Persona*);
        Persona* buscarCliente(unsigned int) const;
        void guardarClientes() const;
        void cargarClientes();
        ~GestorClientes();
    private:
        vector<Persona*> clientes;
        const char* nombreArchivo;
        long int _buscarIndiceInsercion(unsigned int dni) const;
        void escribirString(ofstream& file, const string& str) const;
        string leerString(ifstream& file) const;
};

#endif