#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int maior(Fila *fila);

int main(){
	int n, v, maior_valor;
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
	maior_valor = maior(fila);
	printf("maior: %d\n", maior_valor);
	print(fila);
	free(fila);
	return 0;
}

int maior(Fila *fila){
	int tam = size(fila);
	Item maior = get(fila);
	Item transferido;

	for(int i = 0; i < tam; i++){
		if(maior.valor < get(fila).valor){
			maior.valor = get(fila).valor;
		}

		transferido = dequeue(fila);
		enqueue(fila, transferido);
	}

	return maior.valor;
}
