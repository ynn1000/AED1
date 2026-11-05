#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void intercalar(Fila *fila1, Fila *fila2);

int main(){
	int n1, n2, v;
        Item novo;
        Fila *fila1 = create();
	Fila *fila2 = create();

        printf("digite qtd de valores da pirmeira fila: ");
        scanf("%d", &n1);

        for(int i = 0; i < n1; i++){
                printf("digite valor: ");
                scanf("%d", &v);
                novo.valor = v;
                enqueue(fila1, novo);
        }

	printf("digite qtd de valores da segunda fila: ");
        scanf("%d", &n2);

        for(int i = 0; i < n2; i++){
                printf("digite valor: ");
                scanf("%d", &v);
                novo.valor = v;
                enqueue(fila2, novo);
        }
	
	print(fila1);
	printf("\n");
	print(fila2);
	printf("\n");
	intercalar(fila1, fila2);

	clear(fila1);
	clear(fila2);
	free(fila1);
	free(fila2);
}

void intercalar(Fila *fila1, Fila *fila2){
	int tam = size(fila1) + size(fila2);
	Item item;
	Fila *fila3 = create();

	for(int i = 0; i < tam; i++){
		if(empty(fila1) == 1 || empty(fila2) == 1) break;
		item = dequeue(fila1);
		enqueue(fila3, item);
		
		if(empty(fila2) == 1) break;
		item = dequeue(fila2);
		enqueue(fila3, item);
	}

	if(empty(fila1) == 0 || empty(fila2) == 0){
		if(empty(fila1) == 0){
			tam = size(fila1);

			for(int i = 0; i < tam; i++){
				item = dequeue(fila1);
				enqueue(fila3, item);
			}
		}

		if(empty(fila2) == 0){
			tam = size(fila2);
		
			for(int i = 0; i < tam; i++){
				item = dequeue(fila2);
				enqueue(fila3, item);
			}
		}
	}

	print(fila3);
	clear(fila3);
	free(fila3);
}
