#include <stdio.h>
#include <stdlib.h>

int *intercalar(int *v1, int *v2, int n, int *n3);

int main(){
	int n, n3;
	
	printf("digite o tamanho dos vetores: ");
	scanf("%d", &n);

	n3 = 2 * n;
	int *v1 = malloc(n * sizeof(int));
	int *v2 = malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++){
		printf("(vetor 1) digite o valor da posição %d: ", i + 1);
		scanf("%d", (v1 + i));
	}

	for(int i = 0; i < n; i++){
		printf("(vetor 2) digite o valor da posição %d: ", i + 1);
		scanf("%d", (v2 + i));
	}

	int *v3 = intercalar(v1, v2, n, &n3);
	for(int i = 0; i < n3; i++){
		printf(" %d", *(v3 + i));
	}

	printf("\n%p", v3);

	free(v1);
	free(v2);
	free(v3);
	return 0;
}

int *intercalar(int *v1, int *v2, int n, int *n3){
	int *v3 = malloc((*n3) * sizeof(int));
	int j = 0;
	
	for(int i = 0; i <= *n3; i++){
		*(v3 + i) = *(v1 + j);
		*(v3 + i + 1) = *(v2 + j);
		i++;
		j++;
	}

	return v3;
}
