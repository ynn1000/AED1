
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {
    Head *lista = criaLista();
    int opcao, valor;
    Info dado, resultado;

    do {
        printf("\n===== MENU DA LISTA =====\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no final\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do final\n");
        printf("5. Buscar valor\n");
        printf("6. Imprimir lista\n");
        printf("7. Verificar se esta vazia\n");
        printf("0. Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            break;
        }

        switch (opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &dado.value);
                inserirInicio(lista, dado);
                break;

            case 2:
                printf("Valor: ");
                scanf("%d", &dado.value);
                inserirFinal(lista, dado);
                break;

            case 3:
                removerInicio(lista);
                break;

            case 4:
                removerFinal(lista);
                break;

            case 5:
                printf("Valor a buscar: ");
                scanf("%d", &valor);

                if (buscar(lista, valor, &resultado)) {
                    printf("Encontrado: %d\n", resultado.value);
                } else {
                    printf("Valor nao encontrado.\n");
                }
                break;

            case 6:
                imprimeLista(lista);
                printf("NULL\n");
                break;

            case 7:
                if (listaVazia(lista)) {
                    printf("A lista esta vazia.\n");
                } else {
                    printf("A lista nao esta vazia.\n");
                }
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    liberaLista(lista);
    free(lista);

    return 0;
}

