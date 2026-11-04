#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
	Fila *fila = create();

	Item item1, item2, item3;
	printf("digite valor: ");
	scanf("%d", &item1.valor);
	printf("digite valor: ");
        scanf("%d", &item2.valor);
	printf("digite valor: ");
        scanf("%d", &item3.valor);

	enqueue(fila, item1);
	enqueue(fila, item2);
	enqueue(fila, item3);

	print(fila);

	printf("\n");
	dequeue(fila);
	dequeue(fila);
	dequeue(fila);
	print(fila);
	free(fila);
	return 0;
}
