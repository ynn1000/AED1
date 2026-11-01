#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

Pilha *create(void){
        Pilha *pilha = malloc(sizeof(Pilha));

        if(pilha == NULL) return NULL;

        reset(pilha);
        return pilha;
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

        strcpy(novo->item.dom, item.dom);
        novo->prox = pilha->topo;
        pilha->topo = novo;
        pilha->tamanho++;
}

Item pop(Pilha *pilha){
        if(empty(pilha) == 1){
                printf("lista vazia");
                Item erro = {{'\0'}};
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

        printf("item do topo: %s", pilha->topo->item.dom);
}

Item get(Pilha *pilha){
        if(pilha->topo == NULL){
                printf("lista vazia");
                Item erro = {{'\0'}};
                return erro;
        }

        return pilha->topo->item;
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
}

void print(Pilha *pilha){
        if(pilha->topo == NULL){
                //printf("lista vazia");
                return;
        }

        printf("[topo]\n");
        printf("  |\n");
        printf("  V\n");

        Node *atual = pilha->topo;
        while(atual != NULL){
                printf(" [%s]\n", atual->item.dom);
                atual = atual->prox;
        }
}
