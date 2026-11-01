#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void rpn(char string[], int len);

int main(){
	char string[100];

	printf("digite expressao: ");
	fgets(string, 100, stdin);
	string[strcspn(string, "\n")] = '\0';
	int len = strlen(string);

	rpn(string, len);

}

void rpn(char string[], int len){
	int n, a, b; 
	float sum = 0;
	char op;
	Pilha *pilha = create();
	Pilha *aux = create();
	Item novo, temp;

	for(int i = 0; i < len; i++){
		novo.c = string[i];
		push(pilha, novo);
	}

	for(int i = 0; i < len; i++){
		temp = pop(pilha);
		push(aux, temp);
	}

	for(int i = 0; i < len; i++){
		if(get(aux).c != '+' && get(aux).c != '-' && get(aux).c != '*' && get(aux).c != '/'){
			push(pilha, pop(aux));
		} else {
			op = pop(aux).c;
			b = pop(pilha).c - '0';
			a = pop(pilha).c - '0';
			
			if(op == '+') sum += a + b;
			if(op == '-') sum += a - b;
			if(op == '*') sum += a * b;
			if(op == '/') sum += a / b;
		}
	}

	printf("%.2f", sum);
}
