#ifndef FILA_H
#define FILA_H

typedef struct {
	int valor;
} Item;

typedef struct fila Fila;

void reset(Fila *fila);
Fila *create(void);
int empty(Fila *fila);
int size(Fila *fila);
void enqueue(Fila *fila, Item item);
Item dequeue(Fila *fila);
void front(Fila *fila);
Item get(Fila *fila);
void clear(Fila *fila);
void print(Fila *fila);

#endif
