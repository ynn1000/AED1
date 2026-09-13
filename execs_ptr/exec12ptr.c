#include <stdio.h>
#include <stdlib.h>

int *inserir(int *v, int *n, int valor);

int main(){
	int n, valor;

	printf("digite o tamanho do vetor: ");
	scanf("%d", &n);

	int *v = malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++){
		printf("digite o valor da posição %d: ", i + 1);
		scanf("%d", (v + i));
	}
	
	printf("digite o novo valor: ");
	scanf("%d", &valor);
	
	v = inserir(v, &n, valor);

	for(int i = 0; i < n; i++){
		printf(" %d", *(v + i));
	}
	
	printf("\n%p", v);
	
	free(v);
	return 0;
}

int *inserir(int *v, int *n, int valor){
	(*n)++;
	v = realloc(v, (*n) * sizeof(int));
	v[*n - 1] = valor;

	return v;
}
