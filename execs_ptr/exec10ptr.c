#include <stdio.h> 
#include <stdlib.h>

void min_max(int *v, int n, int *max, int *min);

int main(){
	int s, n = 0, max, min;
	int *p = (int *)malloc(sizeof(int));
	
	do{
		printf("digite valor: ");
		scanf("%d", &s);
		if(s != -1){
			n++;
			p = (int *)realloc(p, n * sizeof(int));
			p[n - 1] = s;
		}
	} while(s != -1);

	for(int i = 0; i < n; i ++){
		printf(" [%d]", *(p+i));
	}
	printf("\nnumero de elementos: %d", n);
	
	min_max(p, n, &max, &min);
	printf("\nmaior: %d || menor: %d", max, min);

	free(p);
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
}
