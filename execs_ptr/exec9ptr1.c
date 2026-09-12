#include <stdio.h>
#include <stdlib.h>

int *copia_vetor(int *v, int n);

int main(){
	int n;

	printf("digite o tamanho do vetor: ");
	scanf("%d", &n);

	int a[n];
	int *v = a;
	for(int i = 0; i < n; i++){
		printf("digite o valor da posição %d: ", i + 1);
		scanf("%d", &a[i]);
	}
	
	int *p;
	p = copia_vetor(v, n);
	
	for(int i = 0; i < n; i++){
		printf("%d ", *p);
		p++;
	}

	return 0;
}

int *copia_vetor(int *v, int n){
	int *p = malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++){
		p[i] = v[i];
	}

	return p;
}
