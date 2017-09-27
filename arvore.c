#include <stdio.h>
#include <stdlib.h>
#define NULL 0

typedef struct no {
    char chave[4];
    struct no *dir;
    struct no *esq;
} no;

typedef no *arvore; // referencia a raiz da árvore

//Funcao que faz a busca de uma dada chave[4] na arvore
void busca(arvore r, char key[4]) {
    if(strcmp(r-> chave, key)==0) {
        printf("Chave %s encontrada\n", r->chave);
    }
    else if (strcmp(r-> chave, key)>0) {
        busca(r->esq, key);
    }
	else if ((strcmp(r->chave, key)!=0) && r->dir==NULL){
        printf("Chave %s naoh encontrada\n", key);
	}
    else {
        busca(r->dir, key);
    }
}
//Funcao que insere nohs na arvore
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
//Funcao que auxilia removanoh removendo o noh
struct no* removaux(struct no* noh) {
    struct no *noaux, *nohaux;
    if(noh->esq == NULL){
        nohaux = noh->dir;
        free(noh);
        return nohaux;
    }
    noaux = noh;
    nohaux = noh->esq;
    while(nohaux->dir != NULL){
        noaux = nohaux;
        nohaux = nohaux->dir;
    }
    if(noaux != noh){
        noaux->dir = nohaux->esq;
        nohaux->esq = noh->esq;
    }
    nohaux->dir = noh->dir;
    free(noh);
    return nohaux;
}
//Funcao que remove um noh dada uma chave[4], caso ela esteja na arvore
int removanoh(no *noh, char key[4]){
    if(noh == NULL){
        return 0;
    }
    no* noaux = NULL;
    no* nohaux = noh;
    while(nohaux != NULL){
        if(strcmp(key, nohaux->chave)==0){
            if(nohaux == noh){
                noh = removaux(nohaux);
            }
            else{
                if(noaux->dir == nohaux){
                    noaux->dir = removaux(nohaux);
                }
                else{
                    noaux->esq = removaux(nohaux);
                }
            }
            return 1;
        }
        noaux = nohaux;
        if(strcmp(key, nohaux->chave)>0){
            nohaux = nohaux->dir;
        }
        else{
            nohaux = nohaux->esq;
        }
    }
    return 0;
}
//Funcao que percorre e imprimi os nohs da arvore
void percorrerIn (no *noh) {
    if (noh == NULL){
        return;
    }
    percorrerIn(noh->esq);
    printf("%s\n", noh->chave);
    percorrerIn(noh->dir);
}
//Funcao que auxilia na criacao dos nohs
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
    // Criamos 9 nohs
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
    no *no9 = malloc(sizeof(no));
    no9 = criaNoh(no9, '9');
    //Raiz
    no *tree;
    //Inserimos os 9 nohs na tree
    tree = inserir(NULL, no5);
    tree = inserir(tree, no9);
    tree = inserir(tree, no7);
    tree = inserir(tree, no6);
    tree = inserir(tree, no8);
    tree = inserir(tree, no4);
    tree = inserir(tree, no3);
    tree = inserir(tree, no2);
    tree = inserir(tree, no1);
    /*teste: busca a key4, imprimi as chaves de todos os nohs,
      remove o noh da key4, imprimi as chaves de todos os nohs
      menos o 4, busca a key4 de novo.*/
    busca(tree, "key4");
    percorrerIn(tree);
    removanoh(tree, "key4");
    percorrerIn(tree);
    busca(tree, "key4");
    return 0;
}
