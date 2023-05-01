#include <stdlib.h>
#include <time.h>
#include "../../libs/Pilha.h"
#include "../../libs/Fila.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand(time(0));
	int quantidade, i, aux;
	printf("Tamanho desejado para a fila: ");
	scanf("%d", &quantidade);
	
	Fila f;
	inicializa_fila(&f, quantidade);
	
	Pilha p;
	inicializa_pilha(&p, quantidade);
	
	while(!fila_cheia(f)){
		inserir(&f, rand() & 10 + 1);
	}
	mostra_fila(f);
	
	while(!fila_vazia(f)){
		remover(&f, &aux);
		empilha(&p, aux);
	}
//	mostra_fila(f);
//	mostra_pilha(p);
	
	while(!pilha_vazia(p)){
		desempilha(&p, &aux);
		inserir(&f, aux);
	}	
	mostra_fila(f);

	
	return 0;
}
