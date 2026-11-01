#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){
	int select;
	char buffer[100];
	Pilha *nav = create();
	Pilha *historico = create();
	Item novo;

	do {
		printf("=+=+=+ NAVEGADOR CERTAMENTE NÃO BASEADO EM CHROMIUM +=+=+=\n");
		printf("site atual: %s\n", get(nav).dom);
		printf("1. visitar site\n");
		printf("2. voltar\n");
		printf("3. histórico\n");
		printf("4. sair\n");
		scanf("%d", &select);
		getchar();

		switch(select){
			case 1: {
				printf("digite URL: ");
				fgets(buffer, 100, stdin);
				buffer[strcspn(buffer, "\n")] = '\0';
				strcpy(novo.dom, buffer);
				push(nav, novo);
				push(historico, novo);

				break;
			}

			case 2: {
				pop(nav);
				
				break;
			}

			case 3: {
				printf("=+=+=+ HISTÓRICO +=+=+=\n");
				print(historico);
				break;
			}
	
			case 4: {
				printf("saindo...\n");
				clear(nav);
				clear(historico);
				free(nav);
				free(historico);
	
				break;
			}
		}
	
	} while(select != 4);

return 0;
}
