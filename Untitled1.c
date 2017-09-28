#include <stdio.h>
#include <stdlib.h>
#define inicio 1
#define max 3

typedef int Apontador;

struct Valor;
struct Array;
void iniciar_Array(struct Array *array);
void insere_fundo_Array(struct Valor valor, struct Array *item);
void retira_Array(Apontador p, struct Array *array, struct Valor *valor);
void imprime_Array(struct Array lista);
void insere_ord_Array(struct Valor vl,struct Array *a);

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
void insere_fundo_Array(struct Valor valor, struct Array *array){
  if(array->ultimo>max){
    printf("Lista Cheia\n");
  }else{
      array->item[array->ultimo-1]=valor;
      array->ultimo++;
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
void insere_ord_Array(struct Valor vl,struct Array *a){
    int j;
    int k = vl.valor;
    if(a->ultimo>max){
    printf("Lista Cheia\n");
    }else{
        for(j=a->ultimo;j>k;j--){
           a->item[j]=a->item[j-1];
        }
        a->item[a->ultimo-1]=vl;
        a->ultimo++;
    }
}

int main(){
    struct Valor item1;
    struct Valor item2;
    struct Valor item3;
    struct Array array;
    item1.valor=11;
    item2.valor=12;
    item3.valor=10;
    iniciar_Array(&array);
    insere_ord_Array(item1,&array);
    insere_ord_Array(item2,&array);
    insere_ord_Array(item3,&array);

    //imprime_Array(&array);
    imprime_Array(array);
    printf("fim\n");

  return 0;
}

