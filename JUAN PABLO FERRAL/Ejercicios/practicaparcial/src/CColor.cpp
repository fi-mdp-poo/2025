#include "CColor.h"

ostream& operator << (ostream& os,const CColor& color)
{
    os << "componente azul: " << (int)color.componentes.blue << endl
    << "componente verde: " << (int)color.componentes.green << endl
    <<"componente rojo: " << (int)color.componentes.red << endl
    << "componentealpha: " << (int)color.componentes.alpha << endl;
    return os;
}
