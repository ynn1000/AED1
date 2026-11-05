#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct Node {
	Item item;
	struct Node *prox;
} Node;

struct fila {
	Node *frente;
	Node *final;
	int tamanho;
};

void reset(Fila *fila){
	fila->frente = NULL;
	fila->final = NULL;
	fila->tamanho = 0;
}

Fila *create(void){
	Fila *fila = malloc(sizeof(Fila));
	if(fila == NULL) return NULL;

	reset(fila);
	return fila;
}

int empty(Fila *fila){
	if(fila->tamanho == 0) return 1;
	return 0;
}

int size(Fila *fila){
	return fila->tamanho;
}

void enqueue(Fila *fila, Item item){
	Node *novo = malloc(sizeof(Node));
	if(novo == NULL){
		printf("deu merda\n");
		return;
	}

	novo->item = item;
	novo->prox = NULL;

	if(empty(fila)){
		fila->frente = novo;
	} else {
		fila->final->prox = novo;
	}

	fila->final = novo;
	fila->tamanho++;
}

Item dequeue(Fila *fila){
	if(empty(fila) == 1){
		printf("lista vazia");
		Item erro = {'\0'};
		return erro;
	}

	Item removido;
	if(fila->frente->prox == NULL){
		removido = fila->frente->item;
		free(fila->frente);
		fila->tamanho--;
		fila->frente = NULL;
		fila->final = NULL;
	} else {
		Node *aux = fila->frente->prox;
		removido = fila->frente->item;
		free(fila->frente);
		fila->tamanho--;
		fila->frente = aux;
	}

	return removido;
}
	
void front(Fila *fila){
	if(fila->frente == NULL){
                printf("fila vazia");
                return;
        }

	printf("%d", fila->frente->item.valor);
}

Item get(Fila *fila){
	 if(fila->tamanho == 0){
                printf("fila vazia");
                Item erro = {'\0'};
                return erro;
        }

	return fila->frente->item;
}

void clear(Fila *fila){
	Node *node = fila->frente;
	Node *prev;

	for(int i = 0; i < fila->tamanho; i++){
		prev = node;
		node = node->prox;
		free(prev);
	}
	
	fila->tamanho = 0;
	fila->frente = NULL;
	fila->final = NULL;
}

void print(Fila *fila){
	Node *atual = fila->frente;
	
	printf("[frente]\n");
	printf(" v\n");

	for(int i = 0; i < fila->tamanho; i++){
		printf("[%d]\n", atual->item.valor);
		atual = atual->prox;
	}

	printf(" ^\n");
	printf("[final]\n");
}
