#include <stdio.h>
#include "binary_search.h"
#define NULL 0
typedef enum { false, true } bool;

int iniciarVetorNulo(int vetor[]) {
	int i;
	int len = sizeof(vetor)/sizeof(int);

	for (i = 0; i<len; i++) {
		vetor[i] = NULL;
	}

	return vetor;
}

bool inserir(int x, int vetor[]) {
	int min, max;

	if (vetor[0] == NULL) {
		vetor[0] = x;
		min = x;
		max = x;
		return true;
	}
}

int main() {
	int v[50];
	int i;
	int len = sizeof(v)/sizeof(int);

	// Verificar
	int *nulo;
	nulo = iniciarVetorNulo(v);

	inserir(10, nulo);

	for(i = 0; i < len; i++) {
		printf("pos in: %d\n", nulo[i]);
	}
	return 0;
}
