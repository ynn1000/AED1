#include <stdio.h>
#include <stdlib.h>

int soma_diagonal(int **mat, int n);

int main(){
    int n;

    printf("digite o tamanho da matriz: ");
    scanf("%d", &n);

    int **mat = malloc(n * sizeof(int *));

    for(int i = 0; i < n; i++){
        mat[i] = malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nMatriz:\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Soma da diagonal: %d\n", soma_diagonal(mat, n));

    for(int i = 0; i < n; i++){
        free(mat[i]);
    }

    free(mat);

    return 0;
}

int soma_diagonal(int **mat, int n){
    int soma = 0;

    for(int i = 0; i < n; i++){
        soma += mat[i][i];
    }

    return soma;
}
