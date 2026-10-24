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

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("[%d] ", a[i][j]);
		}
		
		printf("\n");
	}

	int b[n][n];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			b[i][j] = a[j][i];
		}
	}

	printf("\n");

	for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        printf("[%d] ", b[i][j]);
                }

                printf("\n");
        } //O(n^2)
}
