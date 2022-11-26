#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <pthread.h>

#define f(a, b) for(int a=0; a<b; a++)
#define nl printf("\n")

#ifndef VEC_DEF
#define VEC_DEF

typedef struct vec
{
    void *data;
    unsigned size;
    unsigned capacity;
    size_t data_size;
} vec;

void vec_err(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
vec *vec_init(size_t elements_size, unsigned initial_capacity) //initializing vec
{
    vec *v = (vec *) malloc(sizeof(vec));
        if(v == NULL) vec_err("vec_init: Fail to allocate vec!\n");
    if(initial_capacity <= 0)
        vec_err("invalid initial_capacity!\n");
    v->data = malloc(sizeof(elements_size) * initial_capacity);
        if(v->data == NULL) vec_err("vec_init: Fail to allocate vec!\n");
    v->size = 0;
    v->capacity = initial_capacity;
    v->data_size = elements_size;
    return v;
}
void vec_destroy(void *vector) //free vec
{
    free(((vec *)vector)->data);
    free((vec *) vector);
}
bool vec_check_lim(vec *vector, int pos)
{
    return (pos >= 0 && pos < vector->size); //inside the bounds
}
void vec_resize(vec *vector)
{
    vector->capacity *= 2;
    vector->data = realloc(vector->data, vector->capacity * vector->data_size);
        if(vector->data == NULL) vec_err("vec_resize: Fail to reallocate vec!\n");
}

#define INITIATE_VEC(TYPE, SUFIX) \
typedef struct vec_##SUFIX   \
{   \
    TYPE *data; \
    unsigned size;  \
    unsigned capacity;  \
    size_t data_size;   \
} vec_##SUFIX;   \
vec_##SUFIX *vec_init_##SUFIX(unsigned initial_capacity)    \
{   \
    vec_##SUFIX *vector = (vec_##SUFIX *) malloc(sizeof(vec_##SUFIX));   \
        if(vector == NULL) vec_err("vec_init: fail to allocate!\n");    \
    vector->data = malloc(sizeof(TYPE) * initial_capacity);    \
        if(vector->data == NULL) vec_err("vec_init: fail to allocate!\n");  \
    vector->size = 0; vector->capacity = initial_capacity; vector->data_size = sizeof(TYPE);   \
    return vector;  \
}   \
void write_##SUFIX(vec_##SUFIX *vector, unsigned pos, TYPE value)  \
{   \
    if(!vec_check_lim((vec *) vector, pos)) vec_err("vec_check_limit: invalid pos!\n"); \
    vector->data[pos] = value;  \
}   \
TYPE read_##SUFIX(vec_##SUFIX *vector, unsigned pos)   \
{   \
    if(!vec_check_lim((vec *) vector, pos)) vec_err("vec_check_limit: invalid pos!\n"); \
    return vector->data[pos];   \
}   \
TYPE pop_back_##SUFIX(vec_##SUFIX *vector)  \
{   \
    return vector->data[ --(vector->size) ];    \
}   \
void push_back_##SUFIX(vec_##SUFIX *vector, TYPE value) \
{   \
    if(vector->size == vector->capacity) vec_resize((vec *)vector);    \
    vector->data[ (vector->size)++ ] = value;   \
}   \
void rem_##SUFIX(vec_##SUFIX *vector, unsigned pos)  \
{   \
    if(!vec_check_lim((vec *) vector, pos)) vec_err("vec_check_limit: invalid pos!\n");\
    vector->data[ pos ] = vector->data[ --(vector->size) ];   \
}   \

#endif
