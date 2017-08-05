#include <stdio.h>
#include "selection_sort.h"
 
/* Faz uso de uma lista ordenada para procurar um valor.
 * Para isso, divide a lista no meio e verifica se o número
 * procurado é maior ou menor que o número do meio. Se for
 * menor, dividiremos a array da direita no meio e repetimos o
 * processo até encontrar o número procurado.*/
void binary_search(int numeros[]) {

	int *vetor = &numeros;
	vetor = selection_sort(*vetor);
}
