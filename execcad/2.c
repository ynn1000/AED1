#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
	int valor;
	struct Item *prox;
} Item;

void insere(Item *head, int valor);
void imprime(Item *head);
void conta(Item *head);
void maior(Item *head, int valor);
void removeValor(Item *head, int valor);
void inverte(Item *head);

int main(){
	Item *head = malloc(sizeof(Item));
	head->prox = NULL;

	insere(head, 14);
	insere(head, 20);
	insere(head, 44);
	imprime(head);
	conta(head);
	insere(head, 100);
	insere(head, 200);
	insere(head, 20);
	imprime(head);
	conta(head);
	maior(head, 50);
	insere(head, 20);
	removeValor(head, 20);
	imprime(head);
	inverte(head);
	imprime(head);

return 0;
}

void insere(Item *head, int valor){
	Item *novo = malloc(sizeof(Item));

	if(novo == NULL){
		printf("erro ao alocar memoria");
		return;
	}
	
	novo->prox = NULL;
	novo->valor = valor;
	
	if(head->prox == NULL){
                head->prox = novo;
		printf("item inserido com sucesso\n");
		return;
        }

        Item *atual = head->prox;
	
	while(atual->prox != NULL){
		atual = atual->prox;
	}
	
	atual->prox = novo;

	printf("item inserido com sucesso\n");
}

void imprime(Item *head){
	Item *atual = head->prox;
	
	while(atual != NULL){
		printf("%d-> ", atual->valor);
		atual = atual->prox;
	}
	printf("\n");
}

void conta(Item *head){
	Item *atual = head->prox;
	int n = 0;
	
	while(atual != NULL){
		n++;
		atual = atual->prox;
	}
	printf("numero de itens na lista: %d\n", n);
}

void maior(Item *head, int valor){
	Item *atual = head->prox;
	int n = 0;
	
	while(atual != NULL){
		if(atual->valor > valor){
			n++;
		}
		atual = atual->prox;
	}
	
	printf("quantidade de itens maiores que %d: %d\n", valor, n);
}

void removeValor(Item *head, int valor){
	Item *atual = head->prox;
	Item *aux = head;

	while(atual != NULL){
		if(atual->valor == valor){
			aux->prox = atual->prox;
			free(atual);
			atual = aux->prox;
		} else {
			aux = atual;
			atual = atual->prox;
		}
	}
}

void inverte(Item *head){
	Item *esq = NULL;
	Item *atual = head->prox;
	Item *dir = NULL;
	
	while(atual != NULL){
		dir = atual->prox;
		atual->prox = esq;
		esq = atual;
		atual = dir;
	}

	head->prox = esq;
}





