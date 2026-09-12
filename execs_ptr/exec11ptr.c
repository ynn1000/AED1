#include <stdio.h>
#include <stdlib.h>

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3);

int main(){
    int n1, n2, n3;

    printf("tamanho do primeiro vetor: ");
    scanf("%d", &n1);

    printf("tamanho do segundo vetor: ");
    scanf("%d", &n2);

    int *v1 = malloc(n1 * sizeof(int));
    int *v2 = malloc(n2 * sizeof(int));

    printf("elementos do primeiro vetor:\n");
    for(int i = 0; i < n1; i++){
        scanf("%d", &v1[i]);
    }

    printf("elementos do segundo vetor:\n");
    for(int i = 0; i < n2; i++){
        scanf("%d", &v2[i]);
    }

    int *v3 = concatenar(v1, n1, v2, n2, &n3);

    printf("vetor concatenado:\n");
    for(int i = 0; i < n3; i++){
        printf("[%d] ", v3[i]);
    }

    printf("\nnumero de elementos: %d\n", n3);

    free(v1);
    free(v2);
    free(v3);

    return 0;
}

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3){
    *n3 = n1 + n2;

    int *v3 = malloc(*n3 * sizeof(int));

    for(int i = 0; i < n1; i++){
        v3[i] = v1[i];
    }

    for(int i = 0; i < n2; i++){
        v3[n1 + i] = v2[i];
    }

    return v3;
}
