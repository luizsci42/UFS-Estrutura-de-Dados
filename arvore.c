#include <stdlib.h>
#include <stdio.h>

#define NULL 0

typedef struct no {
	char chave[4];
	int valor;
	struct no *dir;
	struct no *esq;
} no;

typedef no *arvore; // referencia a raiz da árvore


void busca(arvore r, int key) {
	if(r-> valor == key) {
		printf("%d\n encontrado", r->valor);
		//printf("%c\n encontrado", r->chave);
		//return r;
	}

	if (r -> valor > key) {
        busca(r->esq, key);
        printf("%d\n encontrado", r->valor);
		//printf("%c\n encontrado", r->chave);
		//return busca(r->esq, key);
	}

	else {
        busca(r->dir, key);
        printf("%d\n encontrado", r->valor);
		//printf("%c\n encontrado", r->chave);
		// return busca(r->dir, key);
	}
}

arvore * inserir(arvore r, no *novo) {
	if(r == NULL) {
		return novo;
	}
	if (r->valor > novo->valor) {
		r->esq = inserir(r->esq, novo);
	}
	else {
		r->dir = inserir(r->dir, novo);
	}
	return r;
}

int main() {
	// Criamos e inserimos 9 nós na árvore
	no *no1;
	no1 = malloc(sizeof(no));
	no1 -> chave[0] = 'k';
	no1 -> chave[1] = '1';
	no1 -> valor = 1;
	no1 -> esq = NULL;
	no1 -> dir = NULL;

	no *no2;
	no2 = malloc(sizeof(no));
	no2 -> chave[0] = 'k';
	no2 -> chave[1] = '2';
	no2 -> valor = 2;
	no2 -> esq = NULL;
	no2 -> dir = NULL;

	no *tree = inserir(NULL, no1);
	tree = inserir(tree, no2);

	busca(tree, 2);

	return 0;

}
