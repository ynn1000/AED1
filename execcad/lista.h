#ifndef LISTA_H
#define LISTA_H

typedef struct {
	int value;
} Info;

typedef struct Nodo {
	Info info;
	struct Nodo *pNext;
} Nodo;

typedef struct {
	Nodo *pFirst;
} Head;

Head *criaLista();
int listaVazia(Head *lista);
void inserirInicio(Head *lista, Info dado);
void inserirFinal(Head *lista, Info dado);
void removerInicio(Head *lista);
void removerFinal(Head *lista);
int buscar(Head *lista, int valor, Info *resultado);
void imprimeLista(Head *lista);
void liberaLista(Head *lista);


#endif
