#include <stdio.h>

void quickSort(int v[], int len) {
   quickSortInner(v, 0, len);
}

void quickSortInner(int a[], int esq, int dir) {
   int i, j, x, y;

    i = esq;
    j = dir;
    // O pivô é o valor do meio
    x = a[(esq + dir) / 2];

    while(i <= j) {
        while(a[i] < x && i < dir) {
            i++;
        }
        while(a[j] > x && j > esq) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > esq) {
        quickSortInner(a, esq, j);
    }
    if(i < dir) {
        quickSortInner(a, i, dir);
    }
}

int main() {

   int i, valores[10] = { 8, 4, 2, 6, 3, 1, 9, 7, 5, 0 };
   int len = sizeof(valores)/sizeof(int);

   printf("Vetor desordenado\n");
   for(i = 0; i<len; i++) {
      printf("%d ", valores[i]);
   }
   printf("\n");

   quickSort(valores, len);
   
   printf("Vetor ordenado\n");
   for(i = 0; i<len; i++) {
      printf("%d ", valores[i]);
   }

   return 0;
}