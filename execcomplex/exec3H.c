#include <stdio.h>

int main(){
	int i;

	printf("tamanho das matrizes: ");
	scanf("%d", &i);

	int j = i;
	int a[i][j];
	int b[i][j];
	int c[i][j];

	for(int w = 0; w < i; w++){
		for(int x = 0; x < j; x++){
			printf("digite o valor do vetor 1 na posicao (%d, %d): ", w+1, x+1);
			scanf("%d", &a[w][x]);
		}
	}
	
	for(int w = 0; w < i; w++){
		for(int x = 0; x < j; x++){
			printf("[%d] ", a[w][x]);
		}

		printf("\n");
	}

	for(int w = 0; w < i; w++){
		for(int x = 0; x < j; x++){
			printf("digite o valor do vetor 2 na posicao (%d, %d): ", w+1, x+1);
			scanf("%d", &b[w][x]);
		}
	}

	for(int w = 0; w < i; w++){
		for(int x = 0; x < j; x++){
			printf("[%d] ", b[i][j]);
		}

		printf("\n");
	}

	for(int w = 0; w < i; w++){
		for(int y = 0; y < j; y++){

			c[w][y] = 0;

			for(int x = 0; x < j; x++){
				c[w][y] += a[w][x] * b[x][y];
			} //O(n^3)
		}
	}

	for(int w = 0; w < i; w++){
		for(int x = 0; x < j; x++){
			printf("[%d] ", c[w][x]);
		}

		printf("\n");
	}
}
