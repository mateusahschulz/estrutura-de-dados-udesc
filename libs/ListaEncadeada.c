#include "ListaEncadeada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Privado-----------------------

Elemento *aloca_elemento(void *info, int tam){
	Elemento *p = malloc(sizeof(Elemento));
	if(p == NULL)
		return NULL; //Erro, falta de memória.
	p->info = malloc(tam);
	if(p->info == NULL){
		free(p);
		return NULL; //Erro, falta de memória.
	}
	memcpy(p->info, info, tam);
	return p; //Sucesso!
}

//------------------------------

void inicializa_lista(Lista *p, int t){
	p->tamInfo = t;
	p->cabeca = NULL;
	p->qtd = 0;
}

int lista_vazia(Lista l){
	return l.cabeca == NULL;
}
	
int insere_inicio(Lista *p, void *info){
	Elemento *novo = aloca_elemento(info, p->tamInfo);
	if(novo == NULL)
		return 0; //Erro, falta de memória!
	novo->proximo = p->cabeca;
	p->cabeca = novo;
	p->qtd++;
	return 1; //Sucesso!
}

int remove_inicio(Lista *p, void *info){
	if(lista_vazia(*p))
		return ERRO_LISTA_VAZIA;
	
	Elemento *aux = p->cabeca;
	memcpy(info, aux->info, p->tamInfo);
	p->cabeca = aux->proximo;
	free(aux->info);
	free(aux);
	p->qtd;
	return 1; //Sucesso!
}

int insere_fim(Lista *p, void *info){
	if(lista_vazia(*p))
		return insere_inicio(p, info);
	Elemento *aux = p->cabeca;
	while(aux->proximo != NULL)
		aux = aux->proximo;
	Elemento *novo = aloca_elemento(info, p->tamInfo);
	if(novo == NULL)
		return 0; //Erro, falta de memória!
	aux->proximo = novo;
	novo->proximo = NULL;
	p->qtd++;
	return 1; //Sucesso!
}

int remove_fim(Lista *p, void *info){
	if(lista_vazia(*p))
		return ERRO_LISTA_VAZIA;
	if(p->qtd == 1)		// ou p->cabeca->proximo == NULL;
		return remove_inicio(p, info);
	Elemento *aux = p->cabeca;
	while(aux->proximo->proximo != NULL)
		aux = aux->proximo;
	Elemento *ultimo = aux->proximo;
	memcpy(info, ultimo->info, p->tamInfo);
	free(ultimo->info);
	free(ultimo);
	aux->proximo = NULL;
	p->qtd--;
	return 1; //Sucesso!
}

void mostra_lista(Lista l, void (*mostra)(void *)){
	if(lista_vazia(l))
		printf("Lista vazia!\n");
	else{
		printf("Dados da lista:\n");
		Elemento *p = l.cabeca;
		while(p != NULL){
			mostra(p->info); //Invocação por callback.
			p = p->proximo;
		}
	}
}

int conta_elementos(Lista l){
	int count = 0;
	Elemento *p = l.cabeca;
	while(p != NULL){
		count++;
		p = p->proximo;
	}
	return count;
}

void limpa_lista(Lista *l){
	Elemento *p = l->cabeca;
	while(p != NULL){
		Elemento *prox = p->proximo;
		free(p->info);
		free(p);
		p= prox;
	}
	l->cabeca = NULL;
	l->qtd = 0;
}
