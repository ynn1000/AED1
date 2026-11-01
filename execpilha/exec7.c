#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inverter(char string[]);

int main(){
	char string[100];

	printf("digite string pra ser invertida: ");
	fgets(string, 100, stdin);

	inverter(string);
	return 0;
}

void inverter(char string[]){
	Pilha *pilha = create();
	Item novo;
	int len = strlen(string);

	for(int i = 0; i < len; i++){
		novo.c = string[i];
		push(pilha, novo);
	}

	for(int i = 0; i < len; i++){
		novo = pop(pilha);
		string[i] = novo.c;
	}

	printf("%s", string);
}
