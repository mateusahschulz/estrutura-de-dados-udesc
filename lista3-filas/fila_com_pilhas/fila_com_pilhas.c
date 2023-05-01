#include <stdio.h>
#include <stdlib.h>
#include "../../libs/Pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
	Pilha p1, p2;
}FilaPilhas;

void inicializa(FilaPilhas *fp, int capacidade){
	inicializa_pilha(&fp->p1, capacidade);
	inicializa_pilha(&fp->p2, capacidade);
}

int fila_vazia(FilaPilhas fp){
	return pilha_vazia(fp.p1) && pilha_vazia(fp.p2);
}

int fila_cheia(FilaPilhas fp){
	return pilha_cheia(fp.p1);
}

int inserir(FilaPilhas *fp, int info){
	int aux;
	while(!pilha_vazia(fp->p2)){
		desempilha(&fp->p2, &aux);
		empilha(&fp->p1, aux);
	}
	empilha(&fp->p1, info);
	return 1;
}

int remover(FilaPilhas *fp, int *info){
	int aux;
	while(!pilha_vazia(fp->p1)){
		desempilha(&fp->p1, &aux);
		empilha(&fp->p2, aux);
	}
	desempilha(&fp->p2, info);
	return 1;
}

void mostra_fila(FilaPilhas *fp){
	if(fila_vazia(*fp)){
		printf("Fila vazia");
		return;
	}
	int aux, i;
	while(!pilha_vazia(fp->p2)){
		desempilha(&fp->p2, &aux);
		empilha(&fp->p1, aux);
	}
	mostra_pilha(fp->p1);
}

int main(int argc, char *argv[]) {
	
	FilaPilhas fp;
	int aux;
	inicializa(&fp, 5);	
	inserir(&fp, 10);
	inserir(&fp, 1);
	inserir(&fp, 9);
	mostra_fila(&fp);
	remover(&fp, &aux);
	mostra_fila(&fp);
	remover(&fp, &aux);
	mostra_fila(&fp);
	remover(&fp, &aux);
	mostra_fila(&fp);
//	if(fila_vazia(fp)){
//		printf("fila vazia");
//	}
//	if(fila_cheia(fp)){
//		printf("fila cheia");
//	}

	return 0;
}
