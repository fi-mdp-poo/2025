#include "Cmatriz.h"

Cmatriz::Cmatriz(int f,int c):
    filas(f),
    columnas(c)
{
    Cvector v;
    v.redimensionP(f*c);
    matrix = v;
}

Cmatriz::Cmatriz(const Cmatriz& m):
    filas(m.filas),
    columnas(m.columnas)
{
    Cvector v;
    v.redimensionP(filas*columnas);
    matrix = v;
    for(int i=0 ; i<(filas*columnas) ; i++)
    {
        matrix[i] = m.matrix[i];
    }
}

Cmatriz& Cmatriz::operator = (const Cmatriz& m)
{
    if(this == &m) return *this;
    Cvector v;
    v.redimensionP(filas*columnas);
    Cvector aux = v;
    for(int i=0 ; i<(filas*columnas) ; i++)
    {
        aux[i] = m.matrix[i];
    }
    filas = m.filas;
    columnas = m.columnas;
    matrix = aux;
    return *this;
}

void Cmatriz::setCelda(int fila, int columna, Complejo valor)
{
    if( fila>filas || columna>columnas )
    {
        cout << "Posicion invalida de memoria" << endl;
    }
    else
    {
        matrix[fila*columnas+columna] = valor;
    }
}

Complejo Cmatriz::getCelda(int fila, int columna) const
{
    Complejo result;
    if( fila>filas || columna>columnas )
    {
        cout << "Posicion invalida de memoria. Se devolvio 0" << endl;
    }
    else
    {
        result = matrix[fila*columnas+columna];
    }
    return result;
}


int Cmatriz::getFilas() const
{
    return filas;
}

int Cmatriz::getColumnas() const
{
    return columnas;
}

Cmatriz Cmatriz::operator + (const Cmatriz& m) const
{
    Cmatriz result(filas,columnas);
    if(filas != m.filas || columnas != m.columnas)
    {
        cout << "Matrices de distintas dimensiones. Se devolvio una matriz llena de 0" << endl;
    }
    else
    {
        for(int i=0 ; i<filas ; i++)
        {
            for(int j=0 ; j<columnas ; j++)
            {
                result.setCelda(i,j,(getCelda(i,j) + m.getCelda(i,j)));

            }
        }
    }
    return result;
}

Cmatriz Cmatriz::operator - (const Cmatriz& m) const
{
    Cmatriz result(filas,columnas);
    if(filas != m.filas || columnas != m.columnas)
    {
        cout << "Matrices de distintas dimensiones. Se devolvio una matriz llena de 0" << endl;
    }
    else
    {
        for(int i=0 ; i<filas ; i++)
        {
            for(int j=0 ; j<columnas ; j++)
            {
                result.setCelda(i,j,(getCelda(i,j) - m.getCelda(i,j)));

            }
        }
    }
    return result;
}

Cmatriz Cmatriz::operator * (int k) const
{
    Cmatriz result(filas,columnas);
    for(int i=0 ; i<filas ; i++)
    {
        for(int j=0 ; j<columnas ; j++)
        {
            result.setCelda(i,j,(getCelda(i,j)*k));
        }
    }
    return result;
}

Cmatriz Cmatriz::operator * (float k) const
{
    Cmatriz result(filas,columnas);
    for(int i=0 ; i<filas ; i++)
    {
        for(int j=0 ; j<columnas ; j++)
        {
            result.setCelda(i,j,(getCelda(i,j)*k));
        }
    }
    return result;
}

Cmatriz Cmatriz::operator * (double k) const
{
    Cmatriz result(filas,columnas);
    for(int i=0 ; i<filas ; i++)
    {
        for(int j=0 ; j<columnas ; j++)
        {
            result.setCelda(i,j,(getCelda(i,j)*k));
        }
    }
    return result;
}

Cmatriz operator * (int k, const Cmatriz& m)
{
    Cmatriz result(m.filas,m.columnas);
    for(int i=0 ; i<m.filas ; i++)
    {
        for(int j=0 ; j<m.columnas ; j++)
        {
            result.setCelda(i,j,(m.getCelda(i,j)*k));
        }
    }
    return result;
}

Cmatriz operator * (float k, const Cmatriz& m)
{
    Cmatriz result(m.filas,m.columnas);
    for(int i=0 ; i<m.filas ; i++)
    {
        for(int j=0 ; j<m.columnas ; j++)
        {
            result.setCelda(i,j,(m.getCelda(i,j)*k));
        }
    }
    return result;
}

Cmatriz operator * (double k, const Cmatriz& m)
{
    Cmatriz result(m.filas,m.columnas);
    for(int i=0 ; i<m.filas ; i++)
    {
        for(int j=0 ; j<m.columnas ; j++)
        {
            result.setCelda(i,j,(m.getCelda(i,j)*k));
        }
    }
    return result;
}

Cmatriz Cmatriz::operator * (const Cmatriz& m) const
{
    Cmatriz result(filas,m.columnas);
    if(columnas != m.filas)
    {
        cout << "Matrices no multiplicables. Se devolvio una matriz llena de 0" << endl;
    }
    else
    {
        Complejo suma;
        for(int i=0 ; i<filas ; i++)
        {
            for(int j=0 ; j<m.columnas ; j++)
            {
                for(int k=0 ; k<columnas ; k++)
                {

                    suma = suma + (getCelda(i,k)*m.getCelda(k,j));
                }
                result.setCelda(i,j,suma);
                suma = 0;
            }
        }
    }
    return result;
}

    Cmatriz& Cmatriz::operator+=(const Cmatriz& m)
{
    *this = *this + m;
    return *this;
}

Cmatriz& Cmatriz::operator-=(const Cmatriz& m)
{
    *this = *this - m;
    return *this;
}

Cmatriz& Cmatriz::operator*=(int m)
{
    *this = *this * m;
    return *this;
}

Cmatriz& Cmatriz::operator*=(float m)
{
    *this = *this * m;
    return *this;
}

Cmatriz& Cmatriz::operator*=(double m)
{
    *this = *this * m;
    return *this;
}

Cmatriz& Cmatriz::operator*=(const Cmatriz& m)
{
    *this = *this * m;
    return *this;
}

Cmatriz Cmatriz::matrizMenor(int fElim, int cELim)const
{
    int mi=0;
    Cmatriz m(filas-1,columnas-1);
    for(int i=0 ; i<filas ; i++)
    {
        int mj=0;
        if(i != fElim)
        {
            for(int j=0 ; j<columnas ; j++)
            {
                if(j!=cELim)
                {
                    m.setCelda(mi,mj,getCelda(i,j));
                    mj++;
                }
            }
            mi++;
        }
    }
    return m;
}

Complejo Cmatriz::determinante() const
{
    Complejo result;
    if( filas==columnas )
    {
        if(filas==1)
        {
            result = getCelda(0,0);
        }
        else if (filas==2)
        {
            result = (getCelda(0,0)*getCelda(1,1)) - (getCelda(1,0)*getCelda(0,1));
        }
        else
        {
            for(int j=0; j<columnas ; j++)
            {
                Cmatriz menor = matrizMenor(0,j);
                Complejo cofactor = ((j&1)?-1:1)*getCelda(0,j);
                result += cofactor*menor.determinante();
            }
        }
    }
    else
    {
        cout << "La matriz debe ser cuadrada. Se devolvio 0" << endl;
    }
    return result;
}

Cmatriz Cmatriz::transpuesta() const
{
    Cmatriz result(columnas,filas);
    for(int i=0; i<filas ; i++)
    {
        for(int j=0 ; j<columnas ; j++)
        {
            result.setCelda(j,i,getCelda(i,j));
        }
    }
    return result;
}

Cmatriz Cmatriz::inversa() const
{
    Cmatriz m(filas,columnas);
    if(filas == columnas)
    {
        Complejo detMatriz = determinante();
        if (detMatriz!=0)
        {
            for(int i=0 ; i<filas ; i++)
            {
                for(int j=0 ; j<columnas ; j++)
                {

                    Complejo cofactor = (((i+j)&1)?-1:1)*(matrizMenor(i,j).determinante());
                    m.setCelda(i,j,cofactor/detMatriz);
                }
            }
            m=m.transpuesta();
        }
    }
    else
    {
        cout << "Matriz no inversible" << endl;
    }
    return m;
}

ostream& operator << (ostream& os,const Cmatriz& m)
{
    for(int i=0 ; i<m.filas ; i++)
    {
        for(int j=0 ; j<m.columnas ; j++)
        {
            os << m.getCelda(i,j) << "\t";
        }
        os << "\n" ;
    }
    return os;
}


