#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void remover(Pilha *pilha, char c);

int main(){
	char string[100], c;

	printf("digite string: ");	
	fgets(string, 100, stdin);
	string[strcspn(string, "\n")] = '\0';
	int len = strlen(string);
	
	Pilha *pilha = create();
	Item novo;
	for(int i = 0; i < len; i++){
		novo.c = string[i];
		push(pilha, novo);
	}
	
	printf("digite char pra ser removido: ");
	scanf("%c", &c);
	
	remover(pilha, c);
	return 0;
}

void remover(Pilha *pilha, char c){
	Pilha *aux = create();
	Item transferido;
	int len = size(pilha);

	for(int i = 0; i < len; i++){
		if(get(pilha).c == c){
			pop(pilha);
		} else {
			transferido = pop(pilha);
			push(aux, transferido);
		}
	}

	len = size(aux);
	for(int i = 0; i < len; i++){
		transferido = pop(aux);
		push(pilha, transferido);
	}

	print(pilha);
}
