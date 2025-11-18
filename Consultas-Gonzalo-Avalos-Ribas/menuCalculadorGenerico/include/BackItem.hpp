#ifndef BACK_ITEM_HPP
#define BACK_ITEM_HPP

#include "MenuItem.hpp"
#include <string>
using namespace std;

template <typename T>
class BackItem : public MenuItem<T>
{
    bool &exitFlag;
    string title;

public:
    explicit BackItem(bool &exitFlag, const string &title = "Volver");
    string name() const override;
    void execute(T& contexto) override;
};

template <typename T>
BackItem<T>::BackItem(bool& exitFlag, const string& title)
    : exitFlag(exitFlag), title(title) {}

template <typename T>
string BackItem<T>::name() const { return title; }

template <typename T>
void BackItem<T>::execute(T&) {
    exitFlag = true;
}

#endif
