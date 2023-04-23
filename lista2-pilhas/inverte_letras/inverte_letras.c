#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libs/Pilha.h"

//Dado uma frase, inverte as letras de cada palavra, mas mantém a ordem das palavras.
void inverte_letras(char *s);

int main(int argc, char *argv[]) {
	char str[30];
	scanf("%[^\n]", str);
	
	printf("%s\n", str);
	inverte_letras(str);
	printf("%s", str);
	
	return 0;
}

void inverte_letras(char *s){
	Pilha p;
	inicializa_pilha(&p, strlen(s));
	int i, j, pos = 0;
	char nova[strlen(s)];
	
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] != ' '){
			empilha(&p, s[i]);
		}else{
			for(j = pos; j < i; j++){
				int aux;
				desempilha(&p, &aux);
				s[j] = aux;
			}
			pos = i + 1;
//			nova[j] = ' ';  caso fosse feita a atribuição da inversão para outra string, seria necessário preencher os espaços em branco.
		}
	}
	for(j = pos; j < i; j++){
		int aux;
		desempilha(&p, &aux);
		s[j] = aux;
	}
	
	desaloca_pilha(&p);
	
//	printf("%s", nova);
}
