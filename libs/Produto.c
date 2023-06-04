#include <stdio.h>
#include <string.h>
#include "Produto.h"

char *nomes[] = {"Caderno", "Caneta", "Borracha", "Lapiseira", "Bloco de Notas"};
int num = sizeof(nomes) / sizeof(nomes[0]);

void mostra_produto(Produto p){
	printf("(%d, %s, R$%.2f)\n", p.codigo, p.descricao, p.preco);
}

void gera_produto(Produto *p){
	p->codigo = rand() % 1000 + 1;
	strcpy(p->descricao, nomes[rand() % num]);
	p->preco = (rand() % 1000 + 1) / 10.0;
}

int busca_produto(Produto v[], int n, int codigo){
	int i;
	for(i = 0; i < n; i++){
		if(v[i].codigo == codigo){
			return i; // Encontrado no indice i.
		}
	}
	return -1; //Não encontrado.
}
