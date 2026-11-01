#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inverter(Pilha *pilha);

int main(){
	Item item;
	char c;
	Pilha *pilha = create();
	reset(pilha);
	do {
    		printf("Digite um caractere: ");
    		scanf("%c", &c);
		if(c == '\n') continue;

    		if (c != '#') {
        		Item item = {c};
        		push(pilha, item);
    		}

		getchar();

	} while (c != '#');


	inverter(pilha);
	free(pilha);
	return 0;
}

void inverter(Pilha *pilha){
	Item removido;
	Pilha *inversa = create();
	reset(inversa);
	int n = size(pilha);
	for(int i = 0; i < n; i++){
		removido = pop(pilha);
		printf("%c", removido.c);
		push(inversa, removido);
	}
	
	printf("\n");
	n = size(inversa);
	for(int i = 0; i < n; i++){
		removido = pop(inversa);
		printf("%c", removido.c);
	}
	printf("\n");
	clear(inversa);
	free(inversa);
}
