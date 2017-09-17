#include <stdio.h>
/* Transforma a array passada em um heaper.
 * Para isso, v[i/2] >= v[i] para todo i.
 */
void heaper(int array[], int length) {
	int i, aux;

	for (i = 1; i <= length; i++) {
		while (array[i/2] < array[i]) {
			aux = array[i/2];
			array[i/2] = array[i];
			array[i] = aux;
		}
	}

	printf("heap: \n");
	for (i = 1; i <= length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	int valores[10] = { 8, 4, 2, 6, 3, 1, 9, 7, 5, 0 };
	int tamanho = sizeof(valores) / sizeof(int);

	heaper(valores, tamanho);

	return 0;
}
