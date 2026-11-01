
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

#define SEPARADOR '#'

int rpn(char string[], int *resultado) {
    Pilha *pilha = create();

    if (pilha == NULL)
        return 0;

    char *token = strtok(string, " \t\n");

    while (token != NULL) {

        // Verifica se o token é um operador
        if (strlen(token) == 1 &&
            strchr("+-*/", token[0]) != NULL) {

            if (size(pilha) == 0) {
                clear(pilha);
                free(pilha);
                return 0;
            }

            // Recupera o segundo operando
            char numB[32];
            int i = 0;

            Item item;

            while (size(pilha) > 0) {
                item = pop(pilha);

                if (item.c == SEPARADOR)
                    break;

                if (i >= 30) {
                    clear(pilha);
                    free(pilha);
                    return 0;
                }

                numB[i++] = item.c;
            }

            if (i == 0 || item.c != SEPARADOR) {
                clear(pilha);
                free(pilha);
                return 0;
            }

            numB[i] = '\0';

            // Inverte o número recuperado
            for (int j = 0; j < i / 2; j++) {
                char temp = numB[j];
                numB[j] = numB[i - j - 1];
                numB[i - j - 1] = temp;
            }

            // Recupera o primeiro operando
            char numA[32];
            i = 0;

            while (size(pilha) > 0) {
                item = pop(pilha);

                if (item.c == SEPARADOR)
                    break;

                if (i >= 30) {
                    clear(pilha);
                    free(pilha);
                    return 0;
                }

                numA[i++] = item.c;
            }

            if (i == 0 || item.c != SEPARADOR) {
                clear(pilha);
                free(pilha);
                return 0;
            }

            numA[i] = '\0';

            for (int j = 0; j < i / 2; j++) {
                char temp = numA[j];
                numA[j] = numA[i - j - 1];
                numA[i - j - 1] = temp;
            }

            char *fimA, *fimB;
            long a = strtol(numA, &fimA, 10);
            long b = strtol(numB, &fimB, 10);

            if (*fimA != '\0' || *fimB != '\0') {
                clear(pilha);
                free(pilha);
                return 0;
            }

            long valor;

            switch (token[0]) {
                case '+':
                    valor = a + b;
                    break;

                case '-':
                    valor = a - b;
                    break;

                case '*':
                    valor = a * b;
                    break;

                case '/':
                    if (b == 0) {
                        clear(pilha);
                        free(pilha);
                        return 0;
                    }
                    valor = a / b;
                    break;
            }

            // Converte o resultado para caracteres
            char buffer[32];
            snprintf(buffer, sizeof(buffer), "%ld", valor);

            // Empilha o resultado, da direita para a esquerda
            Item novo;

            push(pilha, (Item){.c = SEPARADOR});

            for (int j = strlen(buffer) - 1; j >= 0; j--) {
                novo.c = buffer[j];
                push(pilha, novo);
            }

        } else {

            // Valida o número recebido
            char *fim;
            strtol(token, &fim, 10);

            if (*fim != '\0' || fim == token) {
                clear(pilha);
                free(pilha);
                return 0;
            }

            // Empilha o número como caracteres
            Item novo;

            push(pilha, (Item){.c = SEPARADOR});

            for (int i = strlen(token) - 1; i >= 0; i--) {
                novo.c = token[i];
                push(pilha, novo);
            }
        }

        token = strtok(NULL, " \t\n");
    }

    // Deve restar exatamente um operando
    if (size(pilha) == 0) {
        clear(pilha);
        free(pilha);
        return 0;
    }

    char numero[32];
    int i = 0;
    Item item;

    while (size(pilha) > 0) {
        item = pop(pilha);

        if (item.c == SEPARADOR)
            break;

        if (i >= 30) {
            clear(pilha);
            free(pilha);
            return 0;
        }

        numero[i++] = item.c;
    }

    if (i == 0 || item.c != SEPARADOR || size(pilha) != 0) {
        clear(pilha);
        free(pilha);
        return 0;
    }

    numero[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = numero[j];
        numero[j] = numero[i - j - 1];
        numero[i - j - 1] = temp;
    }

    char *fim;
    long valor = strtol(numero, &fim, 10);

    if (*fim != '\0') {
        clear(pilha);
        free(pilha);
        return 0;
    }

    *resultado = (int) valor;

    clear(pilha);
    free(pilha);

    return 1;
}

int main(void) {
    char string[256];
    int resultado;

    printf("Digite a expressao: ");

    if (fgets(string, sizeof(string), stdin) == NULL)
        return 1;

    string[strcspn(string, "\n")] = '\0';

    if (rpn(string, &resultado))
        printf("Resultado: %d\n", resultado);
    else
        printf("Expressao invalida!\n");

    return 0;
}

