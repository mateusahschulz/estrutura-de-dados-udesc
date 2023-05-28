#include <stdio.h>
#include <stdlib.h>
#include "../../libs/ListaEncadeada.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void mostra_float( void *x ){ 				// mostra um float...
	printf("%.2f\n", *(float *)x ); 		// a partir de um void*
}


int main(int argc, char *argv[]) {
	Lista a;
	inicializa_lista(&a, sizeof(float));
	float x = 8.9;
	float y, o;
	float p = 5.0;
	insere_inicio(&a, &x);
	insere_inicio(&a, &x);
	remove_inicio(&a, &y);
	insere_fim(&a, &p);
	remove_fim(&a, &o);
	int qtd = conta_elementos(a);
	printf("Existem %d elementos na lista\n", qtd);
//	remove_inicio(&a, &y);
	mostra_lista(a, mostra_float);
	limpa_lista(&a);
	return 0;
}

