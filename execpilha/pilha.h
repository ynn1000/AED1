#ifndef PILHA_H
#define PILHA_H

typedef struct {
	char c;
} Item;

typedef struct pilha Pilha;

void reset(Pilha *pilha);
int empty(Pilha *pilha);
int size(Pilha *pilha);
void push(Pilha *pilha, Item item);
Item pop(Pilha *pilha);
void top(Pilha *pilha);
void clear(Pilha *pilha);
void print(Pilha *pilha);

#endif
