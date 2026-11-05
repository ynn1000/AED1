#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"

void inverter_com_pilha(Fila *fila);

int main(){
	int n, v;
	Item novo;
	Fila *fila = create();

	printf("digite qtd de valores: ");
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
                printf("digite valor: ");
                scanf("%d", &v);
                novo.valor = v;
                enqueue(fila, novo);
        }

	print(fila);
	printf("\n");
	inverter_com_pilha(fila);
	print(fila);

	clear(fila);
	free(fila);
	
	return 0;
}

void inverter_com_pilha(Fila *fila){
	int tam = size(fila);
	Item item;
	Pilha *pilha = pilha_create();
	
	for(int i = 0; i < tam; i++){
		item = dequeue(fila);
		pilha_push(pilha, item);
	}

	for(int i = 0; i < tam; i++){
		item = pilha_pop(pilha);
		enqueue(fila, item);
	}
}
