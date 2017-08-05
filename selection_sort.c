#include <stdio.h>

/* Compara um numero n da lista com todos os outros. 
 * Se um elemeto m for menor que n, estes trocam de 
 * lugar até que a lista esteja completamente ordenada */

// numeros é um ponteiro que aponta para a array passada como argumento
void selection_sort(int *numeros, int tamanho) {

	/* TODO: Verificar porque o ponteiro tem um tamanho menor que
	 * a array passada como argumento
	 * int tamanho = sizeof(numeros) / sizeof(int); */
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

int main() {
	int valores[10] = { 8, 4, 2, 6, 3, 1, 9, 7, 5, 0 }; 
	int cont = 0, num, length;

	length = sizeof(valores) / sizeof(int);
	printf("tamanho: %d\n", length);

	// Imprime a lista desordenada
	for (cont = 0; cont < length; cont++) {
		printf("%d ", valores[cont]);
	}

	printf("\n");

	// Ordena a lista
	selection_sort(valores, length);

	return 0;
}
