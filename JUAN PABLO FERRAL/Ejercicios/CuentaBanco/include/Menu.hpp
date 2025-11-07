#ifndef MENU_H
#define MENU_H

#include <cstdlib>
#include "GestorClientes.hpp"
#include "PersistenciaCuentas.hpp" 
#include "CuentasFactory.hpp" 

class Menu 
{
public:
    Menu(Banco&, char* argv[]);
    ~Menu();
    void run();

private:

    Banco& miBanco;
    GestorClientes gestorClientes;

    const char* ARCHIVO_CLIENTES;
    const char* ARCHIVO_CUENTAS;
    const char* ARCHIVO_IDS;

    void _cargarDatos();
    void _guardarDatos();

    // Funciones de utilidad de UI
    void _mostrarMenuPrincipal() const;
    int _getOpcion();
    void _limpiarBufferCin();
    void _pausa();

    // Funciones para cada opción del menú
    void _opcionCrearCliente();
    void _opcionCrearCuenta();
    void _opcionDepositar();
    void _opcionExtraer();
    void _opcionVerCliente();
    void _opcionVerCuenta();
    void _opcionVerTodasCuentas();
    void _opcionVerActivoTotal();
};


#endif // MENU_H