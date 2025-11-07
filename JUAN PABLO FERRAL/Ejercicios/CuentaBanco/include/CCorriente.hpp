#ifndef CCORRIENTE_H
#define CCORRIENTE_H

#include "Cuenta.hpp"


class CCorriente : public Cuenta
{
    friend ostream& operator <<(ostream&,const Cuenta&);
    public:
        CCorriente(unsigned int, unsigned int, long int);
        CCorriente(unsigned int, unsigned int, long int, long int);
        bool extraccion(long int) override;
        void printCuenta(ostream&) const override;
        void serializacion(vector<uint8_t>&) const override; 
    private:
        long int tope;
        
};

#endif