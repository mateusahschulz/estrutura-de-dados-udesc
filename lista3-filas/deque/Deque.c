#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void inicializa_deque(Deque *d, int capacidade){
	d->dados = malloc(sizeof(int) * capacidade);
	d->qtd = d->inicio = 0;
	d->capacidade = capacidade;
}

int deque_cheio(Deque d){
	return d.qtd == d.capacidade;
}

int deque_vazio(Deque d){
	return d.qtd == 0;
}

int inserir_fim(Deque *d, int value){
	if(deque_cheio(*d)){
		return ERRO_FILA_CHEIA;
	}	
	int fim = (d->inicio + d->qtd) % d->capacidade;
	d->dados[fim] = value;
	d->qtd++;
	return 1;
}

int inserir_inicio(Deque *d, int value){
	if(deque_cheio(*d)){
		return ERRO_FILA_CHEIA;
	}
	d->inicio = (d->inicio + d->capacidade - 1) % d->capacidade;
	d->dados[d->inicio] = value;
	d->qtd++;
	return;
}

int remove_inicio(Deque *d, int *value){
	if(deque_vazio(*d)){
		return ERRO_FILA_VAZIA;
	}
	*value = d->dados[d->inicio];
	d->inicio = (d->inicio + 1) % d->capacidade;
	d->qtd--;
	return 1;
}

int remove_fim(Deque *d, int *value){
	if(deque_vazio(*d)){
		return ERRO_FILA_VAZIA;
	}
	*value = d->dados[((d->inicio + d->qtd) % d->capacidade) - 1];
	d->qtd--;
	return 1;
}

void mostra_deque(Deque d){
	if(deque_vazio(d)){
		printf("Deque vazio");
	}else{
		int i, cont;
		for(i = d.inicio, cont = 0; cont < d.qtd; cont++, i = (i + 1) % d.capacidade){
			printf("[%d]: %d\n", i, d.dados[i]);
		}
		
	}
	printf("---------------------\n");
}
