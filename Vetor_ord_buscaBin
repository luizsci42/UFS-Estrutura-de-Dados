#include <stdio.h>
#include <stdlib.h>
#define inicio 1
#define max 51

typedef int Apontador;

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
        printf("Posicao naoh existe\n");
    }
    else{
        for(i=0; i<array->ultimo;i++){
            if (array->item[i].valor==item[0].valor){
                int j;
                for(j=i; j<array->ultimo;j++){
                    array->item[j] = array->item[j+1];
                }
            array->ultimo--;
            break;
            }
        }
    }
}

void imprime_Array(struct Array lista){
    int i;
    for(i=lista.primeiro-1;i<lista.ultimo-1;i++){
        printf("%d\n",lista.item[i].valor);
    }
}

int buscaBinaria (struct Array *array, struct Valor *item) {
    int ini = 0, meio, fim = array->ultimo;
    while (ini <= fim) {
        meio = (ini+fim)/2;
        if (array->item[meio].valor==item[0].valor){
            printf("Valor %d encontrado\n", item[0].valor);
            return meio;
        }else if (array->item[meio].valor<item[0].valor){
            ini = meio + 1;
        }else{
            fim = meio - 1;
        }
    }
    printf("Valor %d naoh encontrado\n", item[0].valor);
    return -1;
}

int main(){
    struct Valor item;
    struct Valor item2;
    struct Array array;
    int i;

    iniciar_Array(&array);
    for (i=50; i>0; i--) {
        item.valor=i;
        insere_ord_Array(item,&array);
    }

    imprime_Array(array);
    
    for (i=0; i<51; i++) {
        item2.valor=i;
        buscaBinaria(&array,&item2);
        if (i==25){
            int j;
            for (j=25; j<40; j++){
                item2.valor=j;
                retira_Array(0,&array,&item2);
            }
        }
    }
    
    imprime_Array(array);
  return 0;
}
