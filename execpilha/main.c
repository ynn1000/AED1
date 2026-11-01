#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
	Item item;

	Pilha *pilha = malloc(sizeof(pilha));
	reset(pilha);
	print(pilha);
	printf("\n");

	printf("digite caractere: ");
	scanf("%c", &item.c);
	getchar();
	push(pilha, item);
	printf("\n");
	printf("digite caractere: ");
        scanf("%c", &item.c);
	getchar();
	push(pilha, item);
	printf("\n");
	printf("digite caractere: ");
        scanf("%c", &item.c);
	getchar();
        push(pilha, item);
	printf("\n");
	print(pilha);
	pop(pilha);
	pop(pilha);
	pop(pilha);
	pop(pilha);
	printf("\n");
	print(pilha);

	clear(pilha);
	free(pilha);
return 0;
}
