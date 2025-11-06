#ifndef CCAHORRO_H
#define CCAHORRO_H

#include "Cuenta.hpp"


class CCahorro : public Cuenta
{
    friend ostream& operator <<(ostream&,const Cuenta&);
    public:
        CCahorro(unsigned int, unsigned int);
        CCahorro(unsigned int, unsigned int, unsigned int ,long int);
        bool extraccion(long int) override;
        void serializacion(vector<uint8_t>&) const override;
        void cambioMes() { contador = 0; } 
        void setContador(unsigned int cantidad) { contador = cantidad; }      
    private:
       unsigned int maxExtracciones;
       unsigned int contador;

};

#endif