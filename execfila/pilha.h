
#ifndef PILHA_H
#define PILHA_H

#include "item.h"

typedef struct pilha Pilha;

void pilha_reset(Pilha *pilha);
Pilha *pilha_create(void);
int pilha_empty(Pilha *pilha);
int pilha_size(Pilha *pilha);
void pilha_push(Pilha *pilha, Item item);
Item pilha_pop(Pilha *pilha);
void pilha_top(Pilha *pilha);
Item pilha_get(Pilha *pilha);
void pilha_clear(Pilha *pilha);
void pilha_print(Pilha *pilha);

#endif

