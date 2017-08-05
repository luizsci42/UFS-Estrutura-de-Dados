#include <stdio.h>

/* Ordena os valores 2 a 2
 * Iniciando da esquerda, o algoritmo verifica se o 
 * número n é menor que o numero à sua direita. Caso
 * seja, trocam de lugar. */
void bubble_sort(int numeros[], int tamanho) {

	int cont, cont1, cont2, aux;
	
	for (cont1 = 0; cont1 < tamanho; cont1++) {
		// Iniciamos o contador pela ultima posição da array
		for(cont2 = tamanho-1; cont2 > 0; cont2--) {
			// Se o número à esquerda for menor que o da direita
			if (numeros[cont2] < numeros[cont2-1]) {
				aux = numeros[cont2-1];
				numeros[cont2-1] = numeros[cont2];
				numeros[cont2] = aux;
			}
		}
	}	

	// Imprime a array ordenada
	for(cont = 0; cont < tamanho; cont++) {
		printf("%d ", numeros[cont]);
	}
	printf("\n");
}

int main() {
	int n, cont, tamanho;
	int valores[10] = { 8, 4, 2, 6, 3, 1, 9, 7, 5, 0 };
	
	tamanho = sizeof(valores) / sizeof(int);

	// Imprime a array desordenada
	for(cont = 0; cont < tamanho; cont++) {
		printf("%d ", valores[cont]);
	}
	printf("\n");

	bubble_sort(valores, tamanho);

	return 0;
}
