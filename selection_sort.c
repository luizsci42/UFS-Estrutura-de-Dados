#include <stdio.h>

/* Compara um numero n da lista com todos os outros. 
 * Se um elemeto m for menor que n, estes trocam de 
 * lugar até que a lista esteja completamente ordenada */

void selection_sort(int numeros[], int tamanho) {

	int min;
	int cont1, cont2, aux, cont;

	for (cont1 = 0; cont1 < tamanho; cont1++) {
		min = numeros[cont1];
		for (cont2 = cont1 + 1; cont2 < tamanho; cont2++) {
			if (numeros[cont2] < min) {
				aux = min;
				min = numeros[cont2];
				numeros[cont2] = aux;
				numeros[cont1] = min;
			}
		}
	}

	// Imprime a lista ordenada
	for (cont = 0; cont < tamanho; cont++) {
		printf("%d ", numeros[cont]);
	}
	printf("\n");

}
