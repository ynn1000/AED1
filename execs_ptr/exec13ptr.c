#include <stdio.h>
#include <stdlib.h>

int remover(int **v, int *n, int posicao);

int main(){
	int n, pos, flag;

	printf("digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	int *v = malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++){
		printf("digite o valor da posição %d: ", i + 1);
		scanf("%d", (v + i));
	}

	printf("digite a posição do valor que deseja remover: ");
	scanf("%d", &pos);

	flag = remover(&v, &n, pos);
	
	for(int i = 0; i < n; i++){
		printf("%d ", *(v + i));
	}

	printf("\n\n%d", flag);
	
	free(v);	
	return 0;
}

int remover(int **v, int *n, int posicao){
	posicao--;
	if(posicao >= *n || posicao < 0){
		printf("posicao invalida!");
		return 0;
	}
	
	for(int i = posicao; i < *n - 1; i++){
		(*v)[i] = (*v)[i + 1];
	}

	(*n)--;
	
	*v = realloc(*v, (*n) * sizeof(int));

	printf("removido com sucesso!");
	return 1;
}
