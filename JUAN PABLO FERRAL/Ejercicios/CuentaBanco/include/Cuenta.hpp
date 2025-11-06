#ifndef Cuenta_H
#define Cuenta_H

#include <vector>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;



class Cuenta
{
    friend ostream& operator <<(ostream&,const Cuenta&);
    public:
        Cuenta(unsigned int, unsigned int);
        Cuenta(unsigned int, unsigned int, long int);
        virtual bool extraccion(long int) = 0;
        virtual void serializacion(vector<uint8_t>&) const = 0; 
        void deposito();
        unsigned int getDniTit() const { return dnititular; }
        unsigned int getId() const { return id; }
        long int getSaldo() const { return saldo; }
        virtual ~Cuenta(){};
        
    protected:
       unsigned int dnititular;
       unsigned int id;
       long int saldo;

};

#endif