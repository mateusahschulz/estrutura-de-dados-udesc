#include <stdio.h>
#include <stdlib.h>
#include "FilaRuim.h"

void inicializa_fila(FilaRuim *f, int capacidade){
	f->dados = malloc(sizeof(int) * capacidade);
	f->capacidade = capacidade;
	f->fim = -1;
}

int fila_vazia(FilaRuim f){
	return f.fim < 0;
}

int fila_cheia(FilaRuim f){
	return f.fim == f.capacidade - 1;
}

int inserir(FilaRuim *f, int info){
	if(fila_cheia(*f)){
		return ERRO_FILA_CHEIA;
	}
	f->fim++;
	f->dados[f->fim] = info;
	return 1;
}

int remover(FilaRuim *f, int *info){
	if(fila_vazia(*f)){
		return ERRO_FILA_VAZIA;
	}
	*info = f->dados[0];
	int i;
	for(i = 0; i < f->fim; i++){
		f->dados[i] = f->dados[i+1];
	}
	f->fim--;
}

void mostra_fila(FilaRuim f){
	if(fila_vazia(f)){
		printf("Fila vazia!");
		return;
	}else{
		printf("Dados da Fila:\n");
		int i;
		for(i = 0; i <= f.fim; i++){
			printf("[%d]: %d\n", i, f.dados[i]);
		}
	}
	printf("---------------\n\n");

}

void desaloca_fila(FilaRuim *f){
	free(f->dados);
}
