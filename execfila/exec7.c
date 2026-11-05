#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int gerar_senha(Fila *fila);
void chamar_senha(Fila *fila);

int main(){
	int select, prox = 1, gerar = 1;
	Fila *fila = create();
	do {
		printf("+=+=+ FILA +=+=+\n");
		printf("proximo: %d | esperando: %d\n", prox, size(fila));
		printf("1. gerar senha\n");
		printf("2. chamar o proximo\n");
		printf("3. sair\n");
		printf("digite opção: ");
		scanf("%d", &select);

		switch(select){
			case 1: {
				Item novo;
				novo.valor = gerar++;
				enqueue(fila, novo);
				break;
			}
			
			case 2: {
				chamar_senha(fila);
				if(!empty(fila)) prox = get(fila).valor;
				else prox = gerar;

				break;
			}
	
			case 3: {
				printf("saindo...\n");
				clear(fila);
				free(fila);
				return 0;
			}
		}
	} while(select != 3);
}

int gerar_senha(Fila *fila){
	if(empty(fila) == 1) return 1;
	return get(fila).valor + 1;
}

void chamar_senha(Fila *fila){
	printf("atendendo ");
	front(fila);
	printf("\n\n");
	dequeue(fila);
}

