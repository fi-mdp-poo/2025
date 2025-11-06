#include "Imatriz.h"

Imatriz::Imatriz(int f,int c):
    filas(f),
    columnas(c),
    matrix(NULL)
{
    matrix = new double[f*c]{0};
}

Imatriz::Imatriz(const Imatriz& m):
    filas(m.filas),
    columnas(m.columnas),
    matrix(NULL)
{
    matrix = new double[filas*columnas];
    for(int i=0 ; i<(filas*columnas) ; i++)
    {
        matrix[i] = m.matrix[i];
    }
}

Imatriz& Imatriz::operator = (const Imatriz& m)
{
    if(this == &m) return *this;
    double* aux = new double[filas*columnas];
    for(int i=0 ; i<(filas*columnas) ; i++)
    {
        aux[i] = m.matrix[i];
    }
    delete[] matrix;
    filas = m.filas;
    columnas = m.columnas;
    matrix = aux;
    return *this;
}

Imatriz::~Imatriz()
{
    delete[] matrix;
}

double* Imatriz::operator[](int fila)
{
    double* result = NULL;
    if(filas<fila)
    {
        cout << "Posicion invalida de memoria. Se devolvio NULL" << endl;
    }
    else
    {
        result = &matrix[fila * columnas];
    }
    return result;
}

const double* Imatriz::operator[](int fila) const
{
    double* result = NULL;
    if(filas<fila)
    {
        cout << "Posicion invalida de memoria. Se devolvio NULL" << endl;
    }
    else
    {
        result = &matrix[fila * columnas];
    }
    return result;
}

void Imatriz::set(int fila, int columna, double valor)
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

double Imatriz::get(int fila, int columna) const
{
    double result = 0;
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


int Imatriz::getFilas() const
{
    return filas;
}

int Imatriz::getColumnas() const
{
    return columnas;
}

Imatriz Imatriz::operator + (const Imatriz& m) const
{
    Imatriz result(filas,columnas);
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
                result.set(i,j,(get(i,j) + m.get(i,j)));

            }
        }
    }
    return result;
}

Imatriz Imatriz::operator - (const Imatriz& m) const
{
    Imatriz result(filas,columnas);
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
                result.set(i,j,(get(i,j) - m.get(i,j)));

            }
        }
    }
    return result;
}

Imatriz Imatriz::operator * (int k) const
{
    Imatriz result(filas,columnas);
    for(int i=0 ; i<filas ; i++)
    {
        for(int j=0 ; j<columnas ; j++)
        {
            result.set(i,j,(get(i,j)*k));
        }
    }
    return result;
}

Imatriz Imatriz::operator * (float k) const
{
    Imatriz result(filas,columnas);
    for(int i=0 ; i<filas ; i++)
    {
        for(int j=0 ; j<columnas ; j++)
        {
            result.set(i,j,(get(i,j)*k));
        }
    }
    return result;
}

Imatriz Imatriz::operator * (double k) const
{
    Imatriz result(filas,columnas);
    for(int i=0 ; i<filas ; i++)
    {
        for(int j=0 ; j<columnas ; j++)
        {
            result.set(i,j,(get(i,j)*k));
        }
    }
    return result;
}

Imatriz operator * (int k, const Imatriz& m)
{
    Imatriz result(m.filas,m.columnas);
    for(int i=0 ; i<m.filas ; i++)
    {
        for(int j=0 ; j<m.columnas ; j++)
        {
            result.set(i,j,(m.get(i,j)*k));
        }
    }
    return result;
}

Imatriz operator * (float k, const Imatriz& m)
{
    Imatriz result(m.filas,m.columnas);
    for(int i=0 ; i<m.filas ; i++)
    {
        for(int j=0 ; j<m.columnas ; j++)
        {
            result.set(i,j,(m.get(i,j)*k));
        }
    }
    return result;
}

Imatriz operator * (double k, const Imatriz& m)
{
    Imatriz result(m.filas,m.columnas);
    for(int i=0 ; i<m.filas ; i++)
    {
        for(int j=0 ; j<m.columnas ; j++)
        {
            result.set(i,j,(m.get(i,j)*k));
        }
    }
    return result;
}

Imatriz Imatriz::operator * (const Imatriz& m) const
{
    Imatriz result(filas,m.columnas);
    if(columnas != m.filas)
    {
        cout << "Matrices no multiplicables. Se devolvio una matriz llena de 0" << endl;
    }
    else
    {
        double suma = 0;
        for(int i=0 ; i<filas ; i++)
        {
            for(int j=0 ; j<m.columnas ; j++)
            {
                for(int k=0 ; k<columnas ; k++)
                {
                    suma = suma + (get(i,k)*m.get(k,j));
                }
                result.set(i,j,suma);
                suma = 0;
            }
        }
    }
    return result;
}

Imatriz& Imatriz::operator+=(const Imatriz& m)
{
    *this = *this + m;
    return *this;
}

Imatriz& Imatriz::operator-=(const Imatriz& m)
{
    *this = *this - m;
    return *this;
}

Imatriz& Imatriz::operator*=(int m)
{
    *this = *this * m;
    return *this;
}

Imatriz& Imatriz::operator*=(float m)
{
    *this = *this * m;
    return *this;
}

Imatriz& Imatriz::operator*=(double m)
{
    *this = *this * m;
    return *this;
}

Imatriz& Imatriz::operator*=(const Imatriz& m)
{
    *this = *this * m;
    return *this;
}

Imatriz Imatriz::matrizMenor(int fElim, int cELim)const
{
    int mi=0;
    Imatriz m(filas-1,columnas-1);
    for(int i=0 ; i<filas ; i++)
    {
        int mj=0;
        if(i != fElim)
        {
            for(int j=0 ; j<columnas ; j++)
            {
                if(j!=cELim)
                {
                    m.set(mi,mj,get(i,j));
                    mj++;
                }
            }
            mi++;
        }
    }
    return m;
}

double Imatriz::determinante() const
{
    int result = 0;
    if( filas==columnas )
    {
        if(filas==1)
        {
            result = get(0,0);
        }
        else if (filas==2)
        {
            result = (get(0,0)*get(1,1)) - (get(1,0)*get(0,1));
        }
        else
        {
            for(int j=0; j<columnas ; j++)
            {
                Imatriz menor = matrizMenor(0,j);
                double cofactor = ((j&1)?-1:1)*get(0,j);
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

Imatriz Imatriz::trasnpuesta() const
{
    Imatriz result(columnas,filas);
    for(int i=0; i<filas ; i++)
    {
        for(int j=0 ; j<columnas ; j++)
        {
            result.set(j,i,get(i,j));
        }
    }
    return result;
}

Imatriz Imatriz::inversa() const
{
    Imatriz m(filas,columnas);
    if(filas == columnas)
    {
        double detMatriz = determinante();
        if (detMatriz!=0)
        {
            for(int i=0 ; i<filas ; i++)
            {
                for(int j=0 ; j<columnas ; j++)
                {

                    double cofactor = (((i+j)&1)?-1:1)*(matrizMenor(i,j).determinante());
                    m.set(i,j,cofactor/detMatriz);
                }
            }
            m=m.trasnpuesta();
        }
    }
    else
    {
        cout << "Matriz no inversible" << endl;
    }
    return m;
}

ostream& operator << (ostream& os,const Imatriz& m)
{
    for(int i=0 ; i<m.filas ; i++)
    {
        for(int j=0 ; j<m.columnas ; j++)
        {
            os << m[i][j] << "\t";
        }
        os << "\n" ;
    }
    return os;
}






