#include <stdio.h>
#include "selection_sort.h"
// #include "heap_sort.h"

/* Faz uso de uma lista ordenada para procurar um valor.
 * Para isso, divide a lista no meio e verifica se o número
 * procurado é maior ou menor que o número do meio. Se for
 * menor, dividiremos a array ao meio e repetimos o
 * processo até encontrar o número procurado.*/
int binarySearch(int x, int len, int vetor[]) {
	return binarySearchInner(x, 0, len, vetor);
}

int binarySearchInner(int x, int left, int len, int v[]) {

	int mid, right = len;

	if(left == right) {
		return left;
	}
	else {
		mid = (left + right)/2;

		if(x > v[mid]) {
			return binary_search(x, mid+1, right, v);
		}
        else {
            return binary_search(x, left, mid, v);
        }
	}
}
