#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int palindromo(Pilha *pilha);

int main(){
	int flag;
	char c;
	Item item;
	Pilha *pilha = create();
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

	flag = palindromo(pilha);
	free(pilha);
	if(flag == 1){
		printf("é um palindromo. :)");
	} else printf("não é um palindromo. :(");

return 0;
}

int palindromo(Pilha *pilha){
	Item removido;
	int n_original = size(pilha);
	int n = size(pilha)/2;
	
	Pilha *aux = create();
	for(int i = 0; i < n; i++){
		removido = pop(pilha);
		push(aux, removido);
	}
	if(n_original % 2 != 0) pop(pilha);

	Item a, b;
	for(int i = 0; i < n; i++){
		a = pop(pilha);
		b = pop(aux);
		if(a.c != b.c){
			clear(aux);
			free(aux); 
			return 0;
		}
	}
	
	free(aux);
	return 1;
}
