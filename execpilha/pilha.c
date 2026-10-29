#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct Node {
        Item item;
        struct Node *prox;
}Node;

struct pilha {
        Node *topo;
        int tamanho;
};

void reset(Pilha *pilha){
        pilha->topo = NULL;
        pilha->tamanho = 0;
}

int empty(Pilha *pilha){
        if(pilha->topo == NULL) return 1;

        return 0;
}

int size(Pilha *pilha){
        return pilha->tamanho;
}

void push(Pilha *pilha, Item item){
        Node *novo = malloc(sizeof(Node));
        if(novo == NULL){
                printf("deu merda");
                return;
        }

        novo->item = item;
        novo->prox = pilha->topo;
	pilha->topo = novo;
	pilha->tamanho++;

	printf("push com sucesso");
}

Item pop(Pilha *pilha){
	if(empty(pilha) == 1){
		printf("lista vazia");
		Item erro = {'\0'};
		return erro;
	}

	Item removido;

	if(pilha->topo->prox == NULL){
		removido = pilha->topo->item;
		free(pilha->topo);
		pilha->tamanho--;
		pilha->topo = NULL;
	} else {
		Node *aux = pilha->topo->prox;
		removido = pilha->topo->item;
		free(pilha->topo);
		pilha->topo = aux;
		pilha->tamanho--;
	}

	return removido;
}

void top(Pilha *pilha){
	if(pilha->topo == NULL){
		printf("llista vazia");
		return;
	}

	printf("item do topo: %c", pilha->topo->item.c);
}

void clear(Pilha *pilha){
	Node *aux = NULL;
	Node *atual = pilha->topo;

	while(atual != NULL){
		aux = atual;
		atual = atual->prox;
		free(aux);
	}
	
	pilha->tamanho = 0;
	pilha->topo = NULL;
	printf("lista limpa");
}

void print(Pilha *pilha){
	if(pilha->topo == NULL){
		printf("lista vazia");
		return;
	}

	printf("[topo]\n");
	printf("  |\n");
	printf("  V\n");

	Node *atual = pilha->topo;
	while(atual != NULL){
		printf(" [%c]\n", atual->item.c);
		printf("  |\n");
		printf("  V\n");
		atual = atual->prox;
	}
}
