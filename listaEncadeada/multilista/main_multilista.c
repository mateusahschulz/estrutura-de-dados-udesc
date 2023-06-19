#include <stdio.h>
#include <stdlib.h>
#include "../../libs/ListaEncadeada.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	Lista matriz, linha;
	inicializa_lista( &matriz, sizeof(Lista) );
	
	int lin, col, i, j, valor;
	printf("Quantas linhas? ");
	scanf("%d", &lin);
	printf("Quantas colunas? ");
	scanf("%d", &col);
	
	//Gera a multilista na memória:
	for(i = 0; i < lin; i++){
		inicializa_lista(&linha, sizeof(int));
		for(j = 0; j < col; j++){
			valor = rand() % 100 + 1;
			insere_fim(&linha, &valor);
		}
		insere_fim(&matriz, &linha);
	}
	
	//Mostra a multilista na tela, como uma matriz:
	for(i = 0; i < lin; i++){
		le_valor(matriz, &linha, i);
		for(j = 0; j < col; j++){
			le_valor(linha, &valor, j);
			printf("%4d", valor);
		}
		printf("\n");
	}
	
	//Libera espaço na memória:
	for(i = 0; i < lin; i++){
		le_valor(matriz, &linha, i);
		limpa_lista(&linha);
	}
	limpa_lista(&matriz);

	return 0;

}
