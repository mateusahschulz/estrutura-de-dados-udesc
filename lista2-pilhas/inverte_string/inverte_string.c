#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/Pilha.h"

//Função recebe uma string e uma pilha para realizar a inversão dessa string.

void inverte(char *str, Pilha *p);

int main(int argc, char *argv[]) {
	
	//Caracteres são tratados como int pela tabela ascii, então é possível fazer a manipulação. Por exemplo, ao passar o caracter 'a' para empilhar na pilha, é passado 97.
	//Na hora de desempilhar, esse 97 é passado para uma variável int auxiliar e então essa variável é atribuída ao vetor de char em sua determinada posição.
	char str[50];
	scanf("%[^\n]", str);
	printf("String normal: %s\n\n", str);
	Pilha p;
	inicializa_pilha(&p, strlen(str));
	inverte(str, &p);

	desaloca_pilha(&p);
	
	return 0;
}

void inverte(char *str, Pilha *p){
	int i;
	for(i = 0; str[i] != '\0'; i++){
		empilha(p, str[i]);
	}
	
	mostra_pilha(*p);
	
	for(i = 0; str[i] != '\0'; i++){
		int aux;
		desempilha(p, &aux);
		str[i] = aux;
	}
	
	printf("\nString invertida: %s", str);
}
