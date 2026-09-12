#include <stdio.h>
#include <stdlib.h>

int soma(int *v, int n);

int main (){
	int n, total;
	int *v = NULL;
	
	printf("digite o tamanho do vetor: ");
	scanf("%d", &n);

	int a[n];
	v = a;

	for(int i = 0; i < n; i++){
		printf("digite valor da posição %d: ", i+1);
		scanf("%d", &a[i]);
	}

	total = soma(v, n);
	printf("Soma de todos os elementos: %d", total);

	return 0;
}

int soma(int *v, int n){
	int total;

	for(int i = 0; i < n; i++){
		total += *v;
		v++;
	}

	return total;
}
