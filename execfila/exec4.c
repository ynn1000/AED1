#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void par_impar(Fila *fila);

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

	par_impar(fila);

	clear(fila);
	free(fila);

	return 0;
}

void par_impar(Fila *fila){
	int tam = size(fila);
	Item item;
	Fila *par = create();
	Fila *impar = create();

	for(int i = 0; i < tam; i++){
		item = dequeue(fila);
		
		if(item.valor % 2 == 0) enqueue(par, item);
		else enqueue(impar, item);
	}
	
	printf("PARES:\n");
	print(par);
	printf("\nIMPARES\n");
	print(impar);
	
	clear(par);
	clear(impar);
	free(par);
	free(impar);
}
