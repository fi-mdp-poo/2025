#include "Menu.hpp"    
#include <iostream>

int main(int argc, char* argv[]) 
{
    if (argc != 4) 
    {
        std::cerr << "Error: Se esperan 3 argumentos." << std::endl;
        std::cerr << "Uso: " << argv[0] << " <archivo_clientes> <archivo_cuentas> <archivo_ids>" << std::endl;
        return 1; 
    }
    Banco b("Banco POO", argv[2]);
    Menu menuPrincipal(b, argv);
    menuPrincipal.run();
    return 0; 
}
