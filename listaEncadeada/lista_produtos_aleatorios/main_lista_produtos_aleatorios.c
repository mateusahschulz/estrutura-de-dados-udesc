#include <stdio.h>
#include <stdlib.h>
#include "../../libs/ListaEncadeada.h"
#include "../../libs/Produto.h"

void mostra_prod(void *x);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Lista l;
	inicializa_lista(&l, sizeof(Produto));
	
	int n, i;
	printf("Quantos produtos voce deseja gerar? ");
	scanf("%d", &n);
	
	Produto x;
	
	for(i = 0; i < n; i++){
		gera_produto(&x);
		insere_fim(&l, &x);
	}
	mostra_lista(l, mostra_prod);
	
	while(!lista_vazia(l)){
		remove_fim(&l, &x);
		printf("\nProduto removido: ");
		mostra_produto(x);
		mostra_lista(l, mostra_prod);
	}
	
	limpa_lista(&l);
	
	return 0;
}

void mostra_prod(void *x){
	Produto *prod = x;
	mostra_produto(*prod);
}
