#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/Pilha.h"

//Dada uma string, diz se a palavra é palídrome ou não.

int palindrome(char palavra[]);

int main(int argc, char *argv[]) {
	char str[15];
	printf("Digite uma string: ");
	scanf("%s", str); 
	if( palindrome(str) ){
		printf("%s eh palindrome", str);
	}else{
		printf("%s nao eh palindrome", str);
	}
	
	
	return 0;
	
}

int palindrome(char palavra[]){
	Pilha p;
	inicializa_pilha(&p, strlen(palavra));
	int i;
	int n = strlen(palavra);
	//empilha os caracteres, invertendo-os
	for(i = 0; i < n; i++){
		empilha(&p, palavra[i]);
	}
	//desempilha em uma nova string.
	char invertida[n];
	for(i = 0; i < n; i++){
		int aux;
		desempilha(&p, &aux);
		invertida[i] = aux;
	}
	
	desaloca_pilha(&p);
	
	//faz a comparação das duas strings.
	i = 0;
	while(palavra[i] != '\0'){
		if(palavra[i] != invertida[i])
			return 0;
		i++;
	}
	return 1;
}
