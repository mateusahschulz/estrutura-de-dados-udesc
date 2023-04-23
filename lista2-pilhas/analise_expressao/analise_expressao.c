#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/Pilha.h"

//Analisa se os parenteses de uma expressao matematica estão distruibuídos de forma correta

void analisa_expressao(char *s);

int main(int argc, char *argv[]) {
	
	char expressao[30];
	printf("Digite uma expressao matematica: ");
	scanf("%s", expressao);
	analisa_expressao(expressao);
	
	return 0;
}

void analisa_expressao(char *s){
	Pilha p;
	inicializa_pilha(&p, strlen(s));
	int i, aux;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == '('){
			empilha(&p, s[i]);
		}
		if(s[i] == ')'){
			if(pilha_vazia(p)){
				printf("Fecha parenteses sem abre parenteses(posicao %d).\n", i);
				return;
			}else{
				desempilha(&p, &aux); //joga fora, porque os parenteses se fecharam.
			}
		}
	}
	
	if(!pilha_vazia(p)){
		printf("Ha parenteses abertos que nao foram fechados");
	}else{
		printf("Expressao OK");
	}
	
	desaloca_pilha(&p);
	
}

