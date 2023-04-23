#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../libs/Pilha.h"

//Função recebe duas pilhas e passa todo o valor de p2 para p1.

void concatena(Pilha *p1, Pilha *p2);
void preenche_pilha(Pilha *p, int quantidade);

int main(int argc, char *argv[]) {
	
	Pilha p1, p2;
	inicializa_pilha(&p1, 10);
	inicializa_pilha(&p2, 10);
	
	int qtd1, qtd2;
	do{
		printf("Com quantos valores preencher a pilha 1 (informe um valor ate 10, que e a cap. da pilha)? ");
		scanf("%d", &qtd1);
	}while(qtd1 > 10);
	
	do{
		printf("com quantos valores preencher a pilha 2 (informe um valor ate 10, que e a cap. da pilha)? ");
		scanf("%d", &qtd2);
	}while(qtd2 > 10);
	preenche_pilha(&p1, qtd1);
	preenche_pilha(&p2, qtd2);
	
	printf("\nAntes da concatenacao:\n");
	mostra_pilha(p1);
	mostra_pilha(p2);
	
	
	concatena(&p1, &p2);
	
	printf("\n\n\nApos a concatenacao:\n");
	mostra_pilha(p1);
	mostra_pilha(p2);
	
	desaloca_pilha(&p1);
	desaloca_pilha(&p2);
	
	return 0;
}

void concatena(Pilha *p1, Pilha *p2){
	int aux;
	while( !pilha_cheia(*p1) && !pilha_vazia(*p2) ){
		desempilha(p2, &aux);
		empilha(p1, aux);
	}
}

void preenche_pilha(Pilha *p, int quantidade){
	int i;
	for(i = 0; i < quantidade; i++){
		empilha(p, rand() % 10);
	}
}

