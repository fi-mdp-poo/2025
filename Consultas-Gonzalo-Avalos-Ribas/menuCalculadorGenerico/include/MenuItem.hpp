#ifndef MENU_ITEM_HPP
#define MENU_ITEM_HPP

#include <string>
using namespace std;

template <typename T>
class MenuItem
{
public:
    virtual ~MenuItem() {}
    virtual string name() const = 0;
    virtual void execute(T& contexto) = 0;
};

#endif