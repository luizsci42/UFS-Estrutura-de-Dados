#include <stdlib.h>
#include <stdio.h>

#define NULL 0

typedef struct no {
	char chave[4];
	struct no *dir;
	struct no *esq;
} no;

typedef no *arvore; // referencia a raiz da árvore


void busca(arvore r, char key[4]) {
	if(strcmp(r-> chave, key)==0) {
        printf("Chave %s encontrada\n", r->chave);
	}

	if (strcmp(r-> chave, key)>0) {
        busca(r->esq, key);
	}

	else {
        busca(r->dir, key);
	}
}

arvore * inserir(arvore r, no *novo) {
	if(r == NULL) {
		return novo;
	}
	if (strcmp(r->chave, novo->chave)>0) {
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
	no1 -> chave[1] = 'e';
	no1 -> chave[2] = 'y';
	no1 -> chave[3] = '1';
	no1 -> esq = NULL;
	no1 -> dir = NULL;

	no *no2;
	no2 = malloc(sizeof(no));
	no2 -> chave[0] = 'k';
	no2 -> chave[1] = 'e';
	no2 -> chave[2] = 'y';
    no2 -> chave[3] = '2';
	no2 -> esq = NULL;
	no2 -> dir = NULL;

	no *tree;
	tree = inserir(NULL, no1);
	tree = inserir(tree, no2);

	busca(tree, "key2");

	return 0;
}
