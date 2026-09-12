#include <stdio.h>

//Exercício 5. Implemente uma função void inverter(int *v, int n) que receba um vetor
//de inteiros e seu tamanho e inverta a ordem de seus elementos.
void inverter(int *v, int n);
int main(){
	int a[6] = {2, 4, 6, 8, 10, 12};
	int *v;
	int n = 6;

	v = a;
	inverter(v, n);
	
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	
	return 0;
}

void inverter(int *v, int n){
	int temp;

	for(int i = 0; i < n/2; i++){
		temp = *(v+i);
		*(v+i) = *(v +(n - 1 - i));
		*(v +(n - 1 - i)) = temp;
	}
}
