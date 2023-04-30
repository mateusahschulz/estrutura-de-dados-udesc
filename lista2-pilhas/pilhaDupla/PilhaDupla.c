#include <stdio.h>
#include<stdlib.h>
#include "PilhaDupla.h"

void inicializa(PilhaDupla *p, int capacidade){
	p->dados = malloc(sizeof(int) * capacidade);
	p->capacidade = capacidade;
	p->topo1 = -1;
	p->topo2 = capacidade;
}

int pilha1_vazia(PilhaDupla p){
	return p.topo1 == -1;
}

int pilha2_vazia(PilhaDupla p){
	return p.topo2 == p.capacidade;
}

int pilhas_cheias(PilhaDupla p){
	return p.topo1 + 1 == p.topo2;
}

int empilha1(PilhaDupla *p, int info){
	if(pilhas_cheias(*p)){
		return ERRO_PILHA_CHEIA;
	}
	p->topo1++;
	p->dados[p->topo1] = info;
	return 1;
}

int empilha2(PilhaDupla *p, int info){
	if(pilhas_cheias(*p)){
		return ERRO_PILHA_CHEIA;
	}
	p->topo2--;
	p->dados[p->topo2] = info;
	return 1;
}

int desempilha1(PilhaDupla *p, int *info){
	if(pilha1_vazia(*p)){
		return ERRO_PILHA_VAZIA;
	}
	
	*info = p->dados[p->topo1];
	p->topo1--;
	return 1;
}

int desempilha2(PilhaDupla *p, int *info){
	if(pilha2_vazia(*p)){
		return ERRO_PILHA_VAZIA;
	}
	
	*info = p->dados[p->topo1];
	p->topo2++;
	return 1;
}




