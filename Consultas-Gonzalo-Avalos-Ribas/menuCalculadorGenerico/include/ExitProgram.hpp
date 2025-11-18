#ifndef EXIT_PROGRAM_HPP
#define EXIT_PROGRAM_HPP

#include "MenuItem.hpp"
using namespace std;

template <typename T>
class ExitProgram : public MenuItem<T>
{
    string titulo;

public:
    ExitProgram(const string &t = "Salir");
    string name() const override;
    void execute(T& contexto) override;
};

template <typename T>
ExitProgram<T>::ExitProgram(const string &t) : titulo(t) {}

template <typename T>
string ExitProgram<T>::name() const { return titulo; }

template <typename T>
void ExitProgram<T>::execute(T&)
{
    cout << "Saliendo del programa...\n";
    exit(0);
}


#endif
