#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int expressao_balanceada(char agr[], int len);

int main(){
	int len, flag;
	char arg[100];
	
	printf("digite uma expressão matematica: ");
	fgets(arg, 100, stdin);
	len = strlen(arg);
	flag = expressao_balanceada(arg, len);
	if(flag == 1){
		printf("expressao balanceada");
	} else printf("expressao desbalanceada");
	
	return 0;
}

int expressao_balanceada(char arg[], int len){
	Pilha *pilha = create();
	Item item;
	
	for(int i = 0; i < len; i++){
		if(arg[i] == '(' || arg[i] == '[' || arg[i] == '{'){
			item.c = arg[i];
			push(pilha, item);
		}

		if(arg[i] == ')'){
			if(!empty(pilha) && get(pilha).c == '('){
				pop(pilha);
			} else return 0;
		}

		if(arg[i] == ']'){
                        if(!empty(pilha) && get(pilha).c == '['){
                                pop(pilha);
                        } else return 0;
                }

		if(arg[i] == '}'){
                        if(!empty(pilha) && get(pilha).c == '{'){
                                pop(pilha);
                        } else return 0;
                }
	}
	int flag = empty(pilha);
	clear(pilha);
	free(pilha);
	return flag;
}

