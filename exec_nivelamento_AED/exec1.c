#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[50];
	float valor;
	int quantidade;
} Produto;

void menu(int *opcao);
void cadastrarProduto(Produto *produto);
void exibirRelatorio(Produto *produto);
	
int main (){
	int select;
	int qtd = 0;
	Produto *produtos = NULL;

	do {	
		menu(&select);
		switch(select){
				case 1: {
					if(produtos == NULL){
						produtos = (Produto *) malloc(sizeof(Produto));
					} else produtos = (Produto *) realloc(produtos, (qtd + 1) * sizeof(Produto));
					
					if(produtos == NULL){
						printf("Erro ao alocar memoira\n");
						break;
					}
					
					cadastrarProduto(&produtos[qtd]);
					qtd++;
					break;
				}

				case 2: {
					printf("##### LISTA DE PRODUTOS\n");
					for(int i = 0; i < qtd; i++){
						exibirRelatorio(&produtos[i]);
						printf("\n");
					}
					
					break;
				}

				case 0: {
					free(produtos);
					printf("Saindo...");
					break;
				}

				default: {
					printf("opcao invalida\n");
					break;
				}
			}

	} while(select != 0);

	return 0;
}

void menu(int *opcao){
	printf("##### GERENCIADOR DE PRODUTOS #####\n");
	printf("1. Adicionar produto\n");
	printf("2. Exibir Relatorio\n");
	printf("0. Sair\n");
	scanf("%d", opcao);
}

void cadastrarProduto(Produto *produto){
	int c;

	printf("##### CADASTRAR PRODUTO:\n");
	
	printf("Nome: ");
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(produto->nome, 50, stdin);
	
	printf("Valor: ");
	scanf("%f", &produto->valor);

	printf("Quantidade: ");
	scanf("%d", &produto->quantidade);
}

void exibirRelatorio(Produto *produto){
	float valorTotal = produto->valor * produto->quantidade;
	printf("Nome: %s", produto->nome);
	printf("Valor p/ unidade: %.2f\n", produto->valor);
	printf("Valor total: %.2f\n", valorTotal);
}
