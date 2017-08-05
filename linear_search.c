#include <stdio.h>

void linear_search(int array[], int n, int tamanho) {

	int cont;
	char mensagem[10];	
	// int tamanho = sizeof(array) / sizeof(int);

	for (cont = 0; cont < tamanho; cont++) {
		if (array[cont] == n) {
			// mensagem = ["Posição: %d\n" + (char) cont];
			// printf("Posição: %d\n", cont);
		} else {
			mensagem = ["not found"];
		}
	}
	printf(mensagem);
}

int main() {
	int numeros[10] = {8, 4, 2, 6, 3, 1, 9, 7, 5, 0 };
	int tamanho = sizeof(numeros) / sizeof(int);

	linear_search(numeros, 5, tamanho);

	return 0;
}
