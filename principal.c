#include <stdio.h>
#include "selection_sort.h"

int main() {
	int valores[10] = { 8, 4, 2, 6, 3, 1, 9, 7, 5, 0 };
	int cont = 0, length;
	
	length = sizeof(valores) / sizeof(int);

	// Imprime a lista desordenada
	for (cont = 0; cont < length; cont++) {
		printf("%d ", valores[cont]);
	}
	
	printf("\n");

	// Ordena a lista
	selection_sort(valores, length);

	return 0;
}
