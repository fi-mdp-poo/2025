#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <limits>
#include <iostream>
#include "MenuItem.hpp"
#include "CalculadorImpositivo.hpp"

using namespace std;
template <typename T>
class Menu
{
    vector<MenuItem<T> *> options;
    bool exitLoop;
    T& contexto;

public:
    Menu(T &calc);
    ~Menu();

    void addOption(MenuItem<T> *option);
    void print() const;
    void run();

    bool &getExitFlag() { return exitLoop; }
};

template <typename T>
Menu<T>::Menu(T &contexto)
    : exitLoop(false), contexto(contexto) {}

template <typename T>
Menu<T>::~Menu()
{
    for (MenuItem<T> *item : options)
        delete item;

    options.clear();
}

template <typename T>
void Menu<T>::addOption(MenuItem<T> *option)
{
    options.push_back(option);
}

template <typename T>
void Menu<T>::print() const
{
    int i = 1;
    for (auto opt : options)
    {
        cout << i++ << ") " << opt->name() << '\n';
    }
}

template <typename T>
void Menu<T>::run()
{
    exitLoop = false;

    while (!exitLoop)
    {
        print();
        cout << "Seleccione una opcion: ";

        int choice;
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida.\n";
            continue;
        }

        if (choice < 1 || choice > static_cast<int>(options.size()))
        {
            cout << "Opcion invalida.\n";
            continue;
        }

        cout << ">>\n";
        options[choice - 1]->execute(contexto);
        cout << "<<\n";
    }

    exitLoop = false;
}

#endif
