#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct vector{
   int* array;
   int size;
   int capacity;
};

vector* vector_create(void)
{
   vector *ptr = (vector*)malloc(sizeof(vector));
   ptr->size = 0;
   ptr->capacity = 10;
   ptr->array = (int*)malloc((sizeof(int)*10));
   return ptr;
}

void vector_destroy(vector* v)
{
    if(v != NULL && v->array != NULL)
    {
        free(v->array);
        free(v);
    }
}

int vector_bigger(vector* v)
{
    int result = 0;
    int cantidad = (v->capacity*2);
    int* ptr = (int*)realloc(v->array,(sizeof(int)*cantidad));
    if(ptr != NULL)
    {
        v->array = ptr;
        v->capacity = cantidad;
        result = 1;
    }
    return result;
}

void vector_push_back(vector* v, int value)
{
    if(v != NULL)
    {
        int condicion = 1;
        if(v->size >= v->capacity)
        {
            condicion = vector_bigger(v);
        }
        if(condicion == 1)
        {
            v->array[v->size] = value;
            v->size += 1;
        }

    }
}

int vector_pop_back(vector* v)
{
    int result;
    if(v != NULL && v->size > 0 )
    {
        result = v->array[(v->size)-1];
        v->size -=1;
    }
    return result;
}

int vector_get(vector* v, int index)
{
    int result;
    if(v != NULL && index >=0 && index < v->size)
    {
        result = v->array[index];
    }
    return result;
}

void vector_set(vector* v, int index, int value)
{
    if(v != NULL && index >=0 && index < v->size)
    {
        v->array[index] = value;
    }
}

int vector_size(vector* v)
{
    int result = -1;
    if(v != NULL)
    {
        result = v->size;
    }
    return result;
}

int vector_capacity(vector* v)
{
    int result = -1;
    if(v != NULL)
    {
        result = v->capacity;
    }
    return result;
}



























