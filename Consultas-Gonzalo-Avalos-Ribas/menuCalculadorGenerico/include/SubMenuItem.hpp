#ifndef SUBMENU_ITEM_HPP
#define SUBMENU_ITEM_HPP

#include "MenuItem.hpp"
#include "Menu.hpp"
#include "BackItem.hpp"
using namespace std;

template <typename T, typename U>
class SubMenuItem : public MenuItem<T>
{
    string title;
    Menu<U> *submenu;

public:
    SubMenuItem(const string &title, U &contexto);
    ~SubMenuItem();

    string name() const override;
    void execute(T& contexto) override;
    Menu<U> &getSubmenu();
};

template <typename T, typename U>
SubMenuItem<T, U>::SubMenuItem(const string &title, U &contexto)
    : title(title)
{
    submenu = new Menu<U>(contexto);
    submenu->addOption(new BackItem(submenu->getExitFlag(), "Volver"));
}

template <typename T, typename U>
SubMenuItem<T, U>::~SubMenuItem()
{
    delete submenu;
}

template <typename T, typename U>
string SubMenuItem<T, U>::name() const { return title; }

template <typename T, typename U>
void SubMenuItem<T, U>::execute(T& contexto)
{
    cout << "\n--- Entrando al submenu: " << title << " ---\n";
    submenu->run();
    cout << "--- Saliendo del submenu ---\n";
}
template <typename T, typename U>
Menu<U> &SubMenuItem<T, U>::getSubmenu() { return *submenu; }

#endif
