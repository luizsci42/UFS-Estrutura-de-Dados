#include <stdio.h>
#include <stdlib.h>
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

    else if (strcmp(r-> chave, key)>0) {
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
    else if (strcmp(r->chave, novo->chave)>0) {
        r->esq = inserir(r->esq, novo);
    }
    else {
        r->dir = inserir(r->dir, novo);
    }
    return r;
}

void imprimirNohs (no *noh) {
    if (noh == NULL){
        return;
    }
    imprimirNohs(noh->dir);
    imprimirNohs(noh->esq);
    printf("%s\n", noh->chave);
}

no *criaNoh(no *novo, char i){
    novo ->chave[0] = 'k';
    novo ->chave[1] = 'e';
    novo ->chave[2] = 'y';
    novo ->chave[3] = i;
    novo -> esq = NULL;
    novo -> dir = NULL;
    return novo;
}

int main() {
    // Criamos 8 nohs
    no *no1 = malloc(sizeof(no));
    no1 = criaNoh(no1, '1');
    no *no2 = malloc(sizeof(no));
    no2 = criaNoh(no2, '2');
    no *no3 = malloc(sizeof(no));
    no3 = criaNoh(no3, '3');
    no *no4 = malloc(sizeof(no));
    no4 = criaNoh(no4, '4');
    no *no5 = malloc(sizeof(no));
    no5 = criaNoh(no5, '5');
    no *no6 = malloc(sizeof(no));
    no6 = criaNoh(no6, '6');
    no *no7 = malloc(sizeof(no));
    no7 = criaNoh(no7, '7');
    no *no8 = malloc(sizeof(no));
    no8 = criaNoh(no8, '8');

    no *tree;

    //Inserimos os 7 nohs na arvore no1
    tree = inserir(NULL, no8);
    tree = inserir(tree, no7);
    tree = inserir(tree, no6);
    tree = inserir(tree, no5);
    tree = inserir(tree, no4);
    tree = inserir(tree, no3);
    tree = inserir(tree, no2);
    tree = inserir(tree, no1);
    
    busca(tree, "key4");
    imprimirNohs(tree);

    return 0;
}
