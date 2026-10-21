#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Head *criaLista(){
	Head *head = malloc(sizeof(Head));

	if(head == NULL){
		printf("erro ao alocar memoria");
		exit(1);
	}

	head->pFirst = NULL;

	return head;
}

int listaVazia(Head *lista){
	return lista->pFirst == NULL;
}

void inserirInicio(Head *lista, Info info){
	Nodo *novo = malloc(sizeof(Nodo));
	
	if(novo == NULL){
		printf("erro");
		exit(1);
	}

	novo->info = info;
	if(lista->pFirst == NULL){
		lista->pFirst = novo;
		novo->pNext = NULL;
	} 
	else {
		novo->pNext = lista->pFirst;
		lista->pFirst = novo;
	}
}

void inserirFinal(Head *lista, Info info){
	Nodo *novo = malloc(sizeof(Nodo));
	Nodo *atual = lista->pFirst;

	if(novo == NULL){
		printf("erro");
		exit(1);
	}

	novo->info = info;
	novo->pNext = NULL;

	if(lista->pFirst == NULL){
		lista->pFirst = novo;
		return;
 	}
	
	while(atual->pNext != NULL){
		atual = atual->pNext;
	}
	
	atual->pNext = novo;
}

void removerInicio(Head *lista){
	Nodo *aux = lista->pFirst;
	
	if(aux == NULL){
		return;
	}

	lista->pFirst = aux->pNext;
	free(aux);
	printf("removido com sucesso");
}

void removerFinal(Head *lista){
	Nodo *atual = lista->pFirst;
	Nodo *aux = NULL;
	
	 if(atual == NULL){
                return;
        }

        if(atual->pNext == NULL){
                free(atual);
                lista->pFirst = NULL;
                printf("removido com sucesso");
                return;
        }

	while(atual->pNext != NULL){
		aux = atual;
		atual = atual->pNext;
	}

	free(atual);
	aux->pNext = NULL;
	printf("removido com sucesso");
}

int buscar(Head *lista, int valor, Info *resultado){
	Nodo *atual = lista->pFirst;
	if(atual == NULL){
		return 0;
	}

	while(atual != NULL){
		if(atual->info.value == valor){
			*resultado = atual->info;
			return 1;
		}

		atual = atual->pNext;
	}
	
	printf("%d", resultado->value);

return 0;
}

void imprimeLista(Head *lista){
	Nodo *atual = lista->pFirst;
	
	while(atual != NULL){
		printf("%d ->", atual->info.value);
		atual = atual->pNext;
	}
}

void liberaLista(Head *lista){
	Nodo *atual = lista->pFirst;
	Nodo *anterior = NULL;

	while(atual != NULL){
		anterior = atual;
		atual = atual->pNext;
		free(anterior);
	}
	
	lista->pFirst = NULL;
	printf("lista limpa com sucesso");
}


