#include <stdio.h> 

int main(){
	int n;
	printf("digite o tamanho da matriz quadrada: ");
	scanf("%d", &n);

	int a[n][n];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("digite o valor da posicao [%d, %d]: ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	}

	int soma = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			soma += a[i][j];
		}
	}

	printf("%d", soma); //O(n^2)
}
