#include "Menu.hpp"     

Menu::Menu(char* argv[]) :
    miBanco("Banco POO"), 
    gestorClientes(argv[1]), 
    ARCHIVO_CLIENTES(argv[1]),
    ARCHIVO_CUENTAS(argv[2]),
    ARCHIVO_IDS(argv[3])
{
    _cargarDatos();
}

Menu::~Menu() 
{
    _guardarDatos();
}

void Menu::run()
{
    int opcion = 0;
    while (opcion != 9) 
    {
        _mostrarMenuPrincipal();
        opcion = _getOpcion();
        switch (opcion) 
        {
            case 1: _opcionCrearCliente(); break;
            case 2: _opcionCrearCuenta(); break;
            case 3: _opcionDepositar(); break;
            case 4: _opcionExtraer(); break;
            case 5: _opcionVerCliente(); break;
            case 6: _opcionVerCuenta(); break;
            case 7: _opcionVerTodasCuentas(); break;
            case 8: _opcionVerActivoTotal(); break;
            case 9: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no valida. Intente de nuevo." << endl; break;
        }
        if (opcion != 9) 
        {
            _pausa();
        }
    }
}


void Menu::_cargarDatos() 
{
    gestorClientes.cargarClientes();
    PersistenciaCuentas::cargarEstadoBanco(ARCHIVO_CUENTAS, miBanco);
}

void Menu::_guardarDatos() 
{
    gestorClientes.guardarClientes();
    PersistenciaCuentas::guardarEstadoBanco(ARCHIVO_CUENTAS, miBanco.getCuentas());
}

void Menu::_mostrarMenuPrincipal() const 
{
    system("cls");
    cout << "\n--- MENU PRINCIPAL - BANCO " << miBanco.getNombre() << " ---" << endl;
    cout << "1. Crear Cliente" << endl;
    cout << "2. Crear Cuenta Bancaria" << endl;
    cout << "3. Realizar Deposito" << endl;
    cout << "4. Realizar Extraccion" << endl;
    cout << "5. Ver Cliente" << endl;
    cout << "6. Ver Cuenta" << endl;
    cout << "7. Ver todas las Cuentas del Banco" << endl;
    cout << "8. Ver Activo Total del Banco" << endl;
    cout << "9. Salir" << endl;
}

int Menu::_getOpcion() 
{
    cout << "Seleccione una opcion: ";
    int opcion;
    while (!(cin >> opcion)) 
    {
        cout << "Opcion no valida. Ingrese solo numeros: ";
        _limpiarBufferCin();
    }
    _limpiarBufferCin(); 
    return opcion;
}

void Menu::_limpiarBufferCin() 
{
    cin.clear(); 
    cin.ignore(100000, '\n'); 
}

void Menu::_pausa() 
{
    cout << "\nPresione Enter para continuar...";
    cin.get(); 
}

void Menu::_opcionCrearCliente() 
{
    string nombre, email;
    unsigned int dni, telefono;

    cout << endl << "--- Creacion de Nuevo Cliente ---" << endl;
    cout << "Ingrese DNI: ";
    while (!(cin >> dni)) 
    {
        cout << "DNI no valido. Ingrese solo numeros: ";
        _limpiarBufferCin();
    }
    _limpiarBufferCin(); 
    if (gestorClientes.buscarCliente(dni) != nullptr) 
    {
        cout << "Error: Ya existe un cliente con ese DNI." << endl;
        return;
    }

    cout << "Ingrese Nombre completo: ";
    getline(cin, nombre);
    cout << "Ingrese Email: ";
    getline(cin, email);
    cout << "Ingrese Telefono: ";
    while (!(cin >> telefono)) 
    {
        cout << "Telefono no valido. Ingrese solo numeros: ";
        _limpiarBufferCin();
    }
    _limpiarBufferCin();
    gestorClientes.agregarCliente(new Persona(nombre, email, dni, telefono));
}

void Menu::_opcionCrearCuenta() 
{
    cout << endl << "--- Creacion de Nueva Cuenta ---" << endl;
    cout << "Ingrese el DNI del titular de la cuenta: ";
    unsigned int dni;
    while (!(cin >> dni)) 
    {
        cout << "DNI no valido. Ingrese solo numeros: ";
        _limpiarBufferCin();
    }
    _limpiarBufferCin();
    Persona* cliente = gestorClientes.buscarCliente(dni);
    if (cliente == NULL) 
    {
        cout << "Error: No se encontro un cliente con ese DNI." << endl;
        cout << "Por favor, cree el cliente primero (Opcion 1)." << endl;
    }
    else
    {
        cout << "Cliente encontrado: " << (*cliente); 
        cout << "Seleccione tipo de cuenta (1: Corriente, 2: Ahorro, 3: Universitaria): ";
        int tipo;
        while (!(cin >> tipo) || tipo < 1 || tipo > 3) 
        {
            cout << "Tipo de cuenta no valido. (1, 2 o 3): ";
            _limpiarBufferCin();
        }
        _limpiarBufferCin();
        Cuenta* nuevaCuenta = CuentasFactory::crearCuenta(tipo, dni, ARCHIVO_IDS);
        if (nuevaCuenta) 
        {
            miBanco.agregarCuenta(nuevaCuenta);
        }
    }  
}

void Menu::_opcionDepositar() 
{
    cout << endl << "--- Realizar Deposito ---" << endl;
    cout << "Ingrese el ID de la cuenta: ";
    unsigned int id;
    while (!(cin >> id)) 
    {
        cout << "ID no valido. Ingrese solo numeros: ";
        _limpiarBufferCin();
    }
    _limpiarBufferCin(); 
    Cuenta* c = miBanco.buscarCuenta(id);
    if (c) 
    {
        c->deposito(); 
    }
}

void Menu::_opcionExtraer() 
{
    cout << endl << "--- Realizar Extraccion ---" << endl;
    cout << "Ingrese el ID de la cuenta: ";
    unsigned int id;
    while (!(cin >> id)) 
    {
        cout << "ID no valido. Ingrese solo numeros: ";
        _limpiarBufferCin();
    }
    _limpiarBufferCin();
    Cuenta* c = miBanco.buscarCuenta(id);
    if (c) 
    {
        cout << "Su saldo actual es: " << c->getSaldo() << endl;
        long int monto;
        do
        {
            cout << "Ingrese el monto a extraer: ";
            while (!(cin >> monto)) 
            {
                cout << "Monto no valido. Ingrese solo numeros: ";
                _limpiarBufferCin();
            }
            _limpiarBufferCin();
        } while (!c->extraccion(monto));     
    }
}

void Menu::_opcionVerCliente() 
{
    cout << endl << "--- Consultar Cliente ---" << endl;
    cout << "Ingrese DNI del cliente: ";
    unsigned int dni;
    while (!(cin >> dni)) 
    {
        cout << "DNI no valido. Ingrese solo numeros: ";
        _limpiarBufferCin();
    }
    _limpiarBufferCin();
    Persona* p = gestorClientes.buscarCliente(dni);
    if (p) 
    {
        cout << "--- Datos del Cliente ---" << endl;
        cout << *p; 
    }
    else
    {
        cout << "No existe un cliente con en el DNI: " << dni << endl;
    }
}

void Menu::_opcionVerCuenta() 
{
    cout << endl << "--- Consultar Cuenta ---" << endl;
    cout << "Ingrese ID de la cuenta: ";
    unsigned int id;
    while (!(cin >> id)) 
    {
        cout << "ID no valido. Ingrese solo numeros: ";
        _limpiarBufferCin();
    }
    _limpiarBufferCin();
    Cuenta* c = miBanco.buscarCuenta(id);
    if (c) 
    {
        cout << "--- Datos de la Cuenta ---" << endl;
        cout << *c;
    }
    else
    {
        cout << "No existe una cuenta con en el ID: " << id << endl;
    }
}

void Menu::_opcionVerTodasCuentas() 
{
    miBanco.mostrarCuentas();
}

void Menu::_opcionVerActivoTotal() 
{
    miBanco.activoBanco();
}

