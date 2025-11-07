#ifndef CCUNIVERSITARIA_H
#define CCUNIVERSITARIA_H

#include "Cuenta.hpp"


class CCuniversitaria : public Cuenta
{
    friend ostream& operator <<(ostream&,const Cuenta&);
    public:
        CCuniversitaria(unsigned int, unsigned int);
        CCuniversitaria(unsigned int, unsigned int, int, long int);
        bool extraccion(long int) override; 
        void serializacion(vector<uint8_t>&) const override;
        void printCuenta(ostream&) const override;
        void pasarDia() { cantDia=0; }
        void setCantDia(int cantidad) { cantDia = cantidad; }       
    private:
        long int maxDiario;
        int cantDia;

};

#endif