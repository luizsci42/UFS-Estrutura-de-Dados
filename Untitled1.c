#include <stdio.h>
#include <stdlib.h>
#define inicio 1
#define max 4

typedef int Apontador;

struct Valor;
struct Array;
void iniciar_Array(struct Array *array);
void insere_ord_Array(struct Valor vl,struct Array *a);
void retira_Array(Apontador p, struct Array *array, struct Valor *valor);
void imprime_Array(struct Array lista);


struct Valor{
  int valor;
};
struct Array{
  struct Valor item[max];
  Apontador primeiro;
  Apontador ultimo;
};
void iniciar_Array(struct Array *array){
  array->primeiro=inicio;
  array->ultimo=array->primeiro;
}
void insere_ord_Array(struct Valor vl,struct Array *a){
    int j;
    int k=a->ultimo;
    if(a->ultimo>max){
        printf("Lista Cheia\n");
    }else{
        while((k>0)&&(vl.valor<a->item[k-1].valor)){
            a->item[k]=a->item[k-1];
            k--;
        }
        a->item[k]=vl;
        a->ultimo++;
    }
}
void retira_Array(Apontador p, struct Array *array, struct Valor *item){
    int i;
    if(p<array->primeiro -1||p>=array->ultimo -1){
        printf("Posicao nao existe\n");
    }else{
        array->ultimo--;
        for(i=p; i<array->ultimo;i++){
            array->item[i] = array->item[i+1];
        }
    }
}
void imprime_Array(struct Array lista){
    int i;
    for(i=lista.primeiro-1;i<lista.ultimo-1;i++){
        printf("%d\n",lista.item[i].valor);
    }
}

int main(){
    struct Valor item1;
    struct Valor item2;
    struct Valor item3;
    struct Array array;
    item1.valor=1;
    item2.valor=12;
    item3.valor=10;
    iniciar_Array(&array);
    insere_ord_Array(item1,&array);
    insere_ord_Array(item2,&array);
    insere_ord_Array(item3,&array);

    imprime_Array(array);
    printf("fim\n");
    retira_Array(1,&array,&item2);
    imprime_Array(array);
    printf("fim\n");
  return 0;
}

