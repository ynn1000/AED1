#include <stdio.h>
#include <stdlib.h>

void min_max(int *v, int n, int *max, int *min);

int main(){
	int n = 0;
	int *v = NULL; 
	int min, max;
	
	printf("¨digite tamanho do vetor: ");
	scanf("%d", &n);

	int a[n];
	v = a;
	min = a[0];
	max = a[0];
	
	for(int i = 0; i < n; i++){
		printf("digie valor da posição %d: ", i + 1);
		scanf("%d", &a[i]);
	}

	min_max(v, n, &max, &min);
	
	return 0;
}

void min_max(int *v, int n, int *max, int *min){
	for(int i = 0; i < n; i++){
		if(*v > *max){
			*max = *v;
		}
	
		if(*v < *min){
			*min = *v;
		}

		v++;
	}
	
	printf("maior valor: %d ; menor valor: %d", *max, *min);
}
