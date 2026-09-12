#include <stdio.h>
#include <stdlib.h>

void troca_vizinho(int *a, int *b);

int main(){
	int n;
	int *a = NULL, *b = NULL;
	
	printf("digite o tamanho do vetor [TAMANHO PAR OBRIGATÓRIO]: ");
	scanf("%d", &n);

	int v[n];
	a = v;
	b = v + 1;

	for(int i = 0; i < n; i++){
		printf("digite o valor da posição %d: ", i+1);
		scanf("%d", &v[i]);
	}

	for(int i = 0; i < n; i++){
		printf(" [%d]", v[i]);
	}

	printf(" || ");

	for(int i = 0; i < n; i += 2){
		troca_vizinho(&v[i], &v[i] + 1);
	}
	
	for(int i = 0; i < n; i++){
		printf(" [%d]", v[i]);
	}	
	return 0;
}

void troca_vizinho(int *a, int *b){
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
