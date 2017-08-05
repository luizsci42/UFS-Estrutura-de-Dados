#include <stdio.h>

void insertion_sort(int numeros[], int tamanho) {

	int n = numeros[0], cont1, cont2;
	// int tamanho = sizeof(numeros) / sizeof(int);

	// 5 3 2 7
	for(cont1 = 0; cont1 < tamanho; cont1++) {
		for(cont2 = 1; cont2 < tamanho; cont2++) {
			if (numeros[cont2] < numeros[cont1]) {
				int aux = numeros[cont1];
				numeros[cont1] = numeros[cont2];
				numeros[cont2] = aux;
			}
		}
	}

	for (cont1 = 0; cont1 < tamanho; cont1++) {
		printf("%d ", numeros[cont1]);
	}

}

int main() {

	int valores[4] = { 5, 3, 2, 7 }, tamanho = sizeof(valores) / sizeof(int), cont;

	// Imprime a lista desordenada
	for (cont = 0; cont < tamanho; cont++) {
		printf("%d ", valores[cont]);
	}
	printf("\n");

	insertion_sort(valores, tamanho);

	return 0;
}
