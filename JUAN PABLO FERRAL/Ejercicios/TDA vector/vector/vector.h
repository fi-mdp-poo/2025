#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

//#define VECTOR_ELEMENT int

typedef struct vector vector;  //  Definición opaca

vector* vector_create(void);
void vector_destroy(vector* v);
void vector_push_back(vector* v, int value);
int vector_pop_back(vector* v);
int vector_get(vector* v, int index);
void vector_set(vector* v, int index, int value);
int vector_size(vector* v);
int vector_capacity(vector* v);

#endif // VECTOR_H_INCLUDED
