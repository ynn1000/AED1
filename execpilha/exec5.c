#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void remove_rep(char string[], int len);

int main(){
	char string[100];

	printf("digite string: ");
	fgets(string, 100, stdin);
	
	string[strcspn(string, "\n")] = '\0';
	int len = strlen(string);
	
	remove_rep(string, len);
	return 0;
}

void remove_rep(char string[], int len){
	Pilha *pilha = create();
	Item novo;
	
	novo.c = string[0];
	push(pilha, novo);

	for(int i = 1; i < len; i++){
		novo.c = string[i];
		if(novo.c == get(pilha).c){
			pop(pilha);
			push(pilha, novo);
		} else push(pilha, novo);
	}

	print(pilha);
	clear(pilha);
	free(pilha);
}
