#include <stdio.h>
#include <stdlib.h>
#include "../../libs/Pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Pilha p;
	inicializa_pilha(&p, 2);
	int n, i, resto;
	printf("Digite um numero inteiro para o converte-lo em binario: ");
	scanf("%d", &n);
	while(n > 0){
		resto = n % 2;
		empilha(&p, resto);
		n /= 2;
	}
	mostra_pilha(p);	
	
	printf("Binario: ");
	int aux;
	while( !pilha_vazia(p) ){
		desempilha(&p, &aux);
		printf("%d", aux);
	}
	
	desaloca_pilha(&p);
	
	return 0;
}
