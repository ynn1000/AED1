#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void remover(Fila *fila, int valor);

int main(){
	int n, v, valor;
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

	printf("digite valor pra ser removido da fila: ");
	scanf("%d", &valor);
	print(fila);
	remover(fila, valor);
	printf("\n");
	print(fila);

	clear(fila);
	free(fila);
	return 0;
}

void remover(Fila *fila, int valor){
	int tam = size(fila);
	
	for(int i = 0; i < tam; i++){
		if(get(fila).valor == valor){
			dequeue(fila);
		} else {
			enqueue(fila, dequeue(fila));
		}
	}
}
