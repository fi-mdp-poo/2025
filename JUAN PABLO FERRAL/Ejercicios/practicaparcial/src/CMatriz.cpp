#include "CMatriz.h"

CMatriz::CMatriz()
{
    columnas = 0;
    filas = 0;
    valores = NULL;
}

CMatriz::CMatriz(const CMatriz& m):
    filas(m.filas),
    columnas(m.columnas)
{
      valores = new unsigned int[filas*columnas];
      for(unsigned int i = 0 ; i<filas ; i++)
      {
          for(unsigned int j = 0 ; j<columnas ; j++)
          {
              valores[i*columnas+j] = m.valores[i*columnas+j];
          }
      }
}

CMatriz& CMatriz::operator = (const CMatriz& m)
{
    if(this==&m) return *this;
    unsigned int* aux = new unsigned int[m.filas*m.columnas];
    for(unsigned int i = 0 ; i<m.filas ; i++)
    {
        for(unsigned int j = 0 ; j<m.columnas ; j++)
        {
            aux[i*m.columnas+j] = m.valores[i*m.columnas+j];
        }
    }
    delete[] valores;
    filas = m.filas;
    columnas = m.columnas;
    valores = aux;
    return *this;
}

CMatriz::~CMatriz()
{
    delete[] valores;
}

CMatriz CMatriz::operator + (int n) const
{
    CMatriz result = *this;
    for(unsigned int i = 0 ; i<filas ; i++)
    {
        for(unsigned int j = 0 ; j<columnas ; j++)
        {
            result.valores[i*columnas+j] += n ;
        }
    }
    return result;
}

CMatriz& CMatriz::operator += (const CMatriz& m)
{
    for(unsigned int i = 0 ; i<filas ; i++)
    {
        for(unsigned int j = 0 ; j<columnas ; j++)
        {
            valores[i*columnas+j] += m.valores[i*columnas+j] ;
        }
    }
    return *this;
}

void CMatriz::cargar(const char* s)
{
    ifstream fentrada(s,ios::binary);
    if(fentrada.is_open())
    {
        fentrada.read(reinterpret_cast<char*>(&filas),sizeof(unsigned int));
        fentrada.read(reinterpret_cast<char*>(&columnas),sizeof(unsigned int));
        delete[] valores;
        valores = new unsigned int[filas*columnas];
        fentrada.read(reinterpret_cast<char*>(valores),(sizeof(unsigned int)*filas*columnas));
    }
    fentrada.close();
}

ostream& operator << (ostream& os,const CMatriz& m)
{
    for(unsigned int i = 0 ; i<m.filas ; i++)
    {
        for(unsigned int j = 0 ; j<m.columnas ; j++)
        {
            os << "0x"
            << setw(8)
            << setfill('0')
            << hex <<m.valores[i*m.columnas+j] << " " ;
        }
        os << endl;
    }
    os << dec;
    return os;
}

