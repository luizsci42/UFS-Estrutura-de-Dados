/* Faz uso de uma lista ordenada para procurar um valor.
 * Para isso, divide a lista no meio e verifica se o número
 * procurado é maior ou menor que o número do meio. Se for
 * menor, dividiremos a array ao meio e repetimos o
 * processo até encontrar o número procurado.*/

// Função externa chamada pelo usuário
int binarySearch(int x, int len, int vetor[]) {
	return binarySearchInner(x, 0, len, vetor);
}

// Função interna. Faz a busca binária propriamente dita
int binarySearchInner(int x, int left, int len, int v[]) {

	int mid, right = len;

	/* Se ambos os lados forem iguais, a divisão chegou ao fim.
	 * Logo, o valor foi encontrado */
	if(left == right) {
		return left;
	}
	// Do contrário, divida o vetor ao meio
	else {
		mid = (left + right)/2;
		/* Caso seja maior que o valor do meio, 
		 * procure o valor do lado direito do vetor */
		if(x > v[mid]) {
			return binary_search(x, mid+1, right, v);
		}
		// Caso contrário, busque ao lado esquerdo
        else {
            return binary_search(x, left, mid, v);
        }
	}
}
