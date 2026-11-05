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

void pilha_reset(Pilha *pilha){
        pilha->topo = NULL;
        pilha->tamanho = 0;
}

Pilha *pilha_create(void){
        Pilha *pilha = malloc(sizeof(Pilha));

        if(pilha == NULL) return NULL;

        pilha_reset(pilha);
        return pilha;
}

int pilha_empty(Pilha *pilha){
        if(pilha->topo == NULL) return 1;

        return 0;
}

int pilha_size(Pilha *pilha){
        return pilha->tamanho;
}

void pilha_push(Pilha *pilha, Item item){
        Node *novo = malloc(sizeof(Node));
        if(novo == NULL){
                printf("deu merda");
                return;
        }

        novo->item = item;
        novo->prox = pilha->topo;
        pilha->topo = novo;
        pilha->tamanho++;

        //printf("push com sucesso\n");
}

Item pilha_pop(Pilha *pilha){
        if(pilha_empty(pilha) == 1){
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

void pilha_top(Pilha *pilha){
        if(pilha->topo == NULL){
                printf("llista vazia");
                return;
        }

        printf("item do topo: %d", pilha->topo->item.valor);
}

Item pilha_get(Pilha *pilha){
        if(pilha->topo == NULL){
                printf("lista vazia");
                Item erro = {'\0'};
                return erro;
        }

        return pilha->topo->item;
}

void pilha_clear(Pilha *pilha){
        Node *aux = NULL;
        Node *atual = pilha->topo;

        while(atual != NULL){
                aux = atual;
                atual = atual->prox;
                free(aux);
        }

        pilha->tamanho = 0;
        pilha->topo = NULL;
//      printf("lista limpa");
}

void pilha_print(Pilha *pilha){
        if(pilha->topo == NULL){
                printf("lista vazia");
                return;
        }

        printf("[topo]\n");
        printf("  |\n");
        printf("  V\n");

        Node *atual = pilha->topo;
        while(atual != NULL){
                printf(" [%d]\n", atual->item.valor);
                atual = atual->prox;
        }
}
