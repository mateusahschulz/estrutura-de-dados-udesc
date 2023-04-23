#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/Pilha.h"

//Fun��o recebe uma string e uma pilha para realizar a invers�o dessa string.

void inverte(char *str, Pilha *p);

int main(int argc, char *argv[]) {
	
	//Caracteres s�o tratados como int pela tabela ascii, ent�o � poss�vel fazer a manipula��o. Por exemplo, ao passar o caracter 'a' para empilhar na pilha, � passado 97.
	//Na hora de desempilhar, esse 97 � passado para uma vari�vel int auxiliar e ent�o essa vari�vel � atribu�da ao vetor de char em sua determinada posi��o.
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
