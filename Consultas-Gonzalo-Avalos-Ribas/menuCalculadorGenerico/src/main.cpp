#include "Menu.hpp"
#include "AddFacturaItem.hpp"
#include "MostrarFacturasItem.hpp"
#include "CalcularImpuestoItem.hpp"
#include "SetMontoFijoItem.hpp"
#include "MostrarMontoFijoItem.hpp"
#include "ExitProgram.hpp"
#include "BackItem.hpp"
using namespace std;

int main()
{
    Extendido cat;
    CalculadorImpositivo calc("Juan", &cat);

    Menu mainMenu(calc);
    // agregar opciones
    mainMenu.addOption(new AddFacturaItem<CalculadorImpositivo>());
    mainMenu.addOption(new MostrarFacturasItem<CalculadorImpositivo>());
    mainMenu.addOption(new CalcularImpuestoItem<CalculadorImpositivo>());
    mainMenu.addOption(new SetMontoFijoItem<CalculadorImpositivo>());
    mainMenu.addOption(new MostrarMontoFijoItem<CalculadorImpositivo>());
    mainMenu.addOption(new ExitProgram<CalculadorImpositivo>());
    mainMenu.addOption(new BackItem<CalculadorImpositivo>(mainMenu.getExitFlag()));
    mainMenu.run();
    cout << "Fuera del menu" << endl;
    return 0;
}
