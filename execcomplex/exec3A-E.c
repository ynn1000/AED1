#include <stdio.h>

void print(int v[], int n);
int retorna_valor(int i, int v[]);
int maior_valor(int v[], int n);
void transfere_valor(int m[], int n);
void concatena_vetor(int a[], int m, int b[], int n);
void pares(int a[], int m, int b[], int n);

int main(){
	int n, i, m;

	printf("digite o tamanho do vetor: ");
	scanf("%d", &n);

	int v[n];
	for(i = 0; i < n; i++){
		printf("digite o valor da posição %d: ", i+1);
		scanf("%d", &v[i]);
	}

	print(v, n);
	
	printf("\ndigite a posição do valor de retorno: ");
	scanf("%d", &i);

	int valor = retorna_valor(i, v);
	printf("valor: %d\n", valor);

	valor = maior_valor(v, n);
	printf("maior valor: %d\n", valor);

	transfere_valor(v, n);
	print(v, n);

	printf("digite o tamanho do novo veotr: ");
	scanf("%d", &m);
	int w[m];

	for(int i = 0; i < m; i++){
		printf("digite o valor da posicao %d: ", i+1);
		scanf("%d", &w[i]);
	}

	concatena_vetor(v, n, w, m);
	pares(v, n, w, m);
	return 0;
}

void print(int v[], int n){
	for(int i = 0; i < n; i++){
		printf("%d | ", v[i]);
	}
	printf("\n");
}

int retorna_valor(int i, int v[]){
	return v[i - 1]; //O(1)
}

int maior_valor(int v[], int n){
	int maior = 0;

	for(int i = 0; i < n; i++){
		if(v[i] > maior) maior = v[i];
	}
	
	return maior; //O(n)
}

void transfere_valor(int m[],int n){
	if(n % 2 != 0){
		printf("é necessario um vetor de tamanho par.");
		return;
	}

	int i, j = 0, aux;
	
	for(i = 0; i < n/2; i++){
		aux = m[n/2 + j];
		m[n/2 + j] = m[i];
		m[i] = aux;
		j++;
	} //O(n)
}

void concatena_vetor(int a[], int m, int b[], int n){
	int q = m + n, c[q];

	for(int i = 0; i < m; i++){
		c[i] = a[i];
	}

	for(int i = 0; i < n; i++){
		c[m + i] = b[i];
	}
	
	print(c, q); //O(m + n)
}

void pares(int a[], int m, int b[], int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("(%d, %d)\n", a[i], b[j]);
		}
	} //O(m * n)
}
