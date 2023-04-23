#include <stdio.h>
#include <stdlib.h>
#include "../../libs/Pilha.h"

//recebe um valor em decimal e o converte para binario usando uma pilha.

int main(int argc, char *argv[]) {
	Pilha p;
	inicializa_pilha(&p, 32);
	int n, resto;
	printf("Digite o numero em decimal para ser convertido para binario: ");
	scanf("%d", &n);
	while(n > 0){
		resto = n % 2;
		empilha(&p, resto);
		n /= 2;
	}
	int bit;
	printf("Binario: ");
	while( !pilha_vazia(p) ){
		desempilha(&p, &bit);
		printf("%d", bit);
	}
	
	desaloca_pilha(&p);
	
	return 0;
}
