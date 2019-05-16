#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef int queue_info;
typedef struct queue_no * queue_ptr;

struct queue_no
{
    queue_info dado;
    queue_ptr prox;
};

typedef struct
{
    queue_ptr comeco;
    queue_ptr final;
} fila;



#endif // FILA_H_INCLUDED
