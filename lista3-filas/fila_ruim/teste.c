#include <stdio.h>
#include <stdlib.h>
#include "FilaRuim.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FilaRuim f;
	inicializa_fila(&f, 5);
	inserir(&f, 10);
	inserir(&f, 9);
	inserir(&f, 0);
	inserir(&f, 8);
	inserir(&f, 5);
	mostra_fila(f);
	int info;
	remover(&f, &info);
//	printf("removido = %d\n", info);
	mostra_fila(f);
	remover(&f, &info);
	mostra_fila(f);
	remover(&f, &info);
	mostra_fila(f);
	remover(&f, &info);
	mostra_fila(f);
	remover(&f, &info);
	mostra_fila(f);
//	if(fila_vazia(f)){
//		printf("Fila vazia");
//	}
//	if(fila_cheia(f)){
//		printf("Fila cheia");
//	}
	desaloca_fila(&f);
	return 0;
}
