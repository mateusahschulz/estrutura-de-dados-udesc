#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../libs/PilhaEstatica.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Pilha p1;
	inicializa_pilha(&p1);
	mostra_pilha(p1);
	
	srand( time(0) );
	int i, n = rand() % MAX_PILHA + 1;
	printf("Numero gerado: %d\n", n);
	
	for(i = 0; i < n; i++){
		int x = rand() % 1000 + 1;
		empilha(&p1, x);
	}
	mostra_pilha(p1);
	
	return 0;
}
