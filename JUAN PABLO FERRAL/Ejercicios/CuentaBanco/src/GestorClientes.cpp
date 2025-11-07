#include <GestorClientes.hpp>

GestorClientes :: GestorClientes(const char* nombreArchPersistencia):
    nombreArchivo(nombreArchPersistencia)
{}


GestorClientes :: ~GestorClientes()
{
    for (size_t i = 0; i < clientes.size(); i++)
    {
        delete clientes[i];
    }
}

long int GestorClientes::_buscarIndiceInsercion(unsigned int dni) const
{
    long int low = 0;
    long int high = static_cast<long int>(clientes.size()-1);
    long int mid = (high + low)/2;
    long int indiceInsercion = clientes.size();
    while(low<=high)
    {
        mid = (high + low)/2;
        if(clientes[mid]->getDni() < dni)
        {
            low = mid+1;
        }
        else
        {
            indiceInsercion = mid;
            high = mid-1;
        }
    }
    return indiceInsercion;
}

void GestorClientes :: agregarCliente(Persona* ptr)
{
    long int index = _buscarIndiceInsercion(ptr->getDni());
    auto it = clientes.begin() + index;
    clientes.insert(it, ptr);
}

Persona* GestorClientes::buscarCliente(unsigned int dni) const
{
    Persona* result = NULL;
    size_t index = _buscarIndiceInsercion(dni);
    if(index < clientes.size() && dni == clientes[index]->getDni())
    {
        result = clientes[index];
    }
    else
    {
        cout << "No existe un cliente con ese DNI " << endl;
    }
    return result;
}

void GestorClientes::escribirString(ofstream& file, const string& str) const 
{
    size_t len = str.length();
    file.write(reinterpret_cast<const char*>(&len), sizeof(len));
    file.write(str.c_str(), len);
}

string GestorClientes::leerString(ifstream& file) const 
{
    size_t len = 0;
    file.read(reinterpret_cast<char*>(&len), sizeof(len));
    string str(len, ' '); 
    file.read(&str[0], len);
    return str;
}

void GestorClientes::guardarClientes() const
{
    ofstream fsalida(nombreArchivo, ios::binary | ios::trunc);
    if(fsalida.is_open())
    {
        for (size_t i = 0; i < clientes.size() ; i++)
        {
            const Persona* p = clientes[i];
            escribirString(fsalida,p->nombre);
            escribirString(fsalida,p->email);
            fsalida.write(reinterpret_cast<const char*>(&p->dni),sizeof(unsigned int));
            fsalida.write(reinterpret_cast<const char*>(&p->telefono),sizeof(unsigned int));
        }
        fsalida.close();
    }
    else
    {
        cout << "Error al abrir el achivo: " << nombreArchivo << endl;
    }
}
void GestorClientes::cargarClientes()
{
    ifstream fentrada(nombreArchivo, ios::binary);
    if(fentrada.is_open())
    {
        string nombreAux;
        string emailAux;
        unsigned int dniAux;
        unsigned int telefonoAux;
        while(fentrada.peek() != EOF)
        {
            nombreAux = leerString(fentrada);
            emailAux = leerString(fentrada);
            fentrada.read(reinterpret_cast<char*>(&dniAux),sizeof(unsigned int));
            fentrada.read(reinterpret_cast<char*>(&telefonoAux),sizeof(unsigned int));
            clientes.push_back(new Persona(nombreAux,emailAux,dniAux,telefonoAux));
        }
        fentrada.close();
    }
    else
    {
        cout << "Error al abrir el achivo: " << nombreArchivo << endl;
    }
}