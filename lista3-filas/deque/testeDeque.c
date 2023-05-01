#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Deque d;
	int aux;
	inicializa_deque(&d, 6);
	inserir_fim(&d, 2);
	inserir_fim(&d, 3);
	inserir_fim(&d, 4);
	inserir_inicio(&d, 6);
	inserir_inicio(&d, 4);
	mostra_deque(d);
	remove_inicio(&d, &aux);
	printf("%d\n", aux);
	mostra_deque(d);
	remove_fim(&d, &aux);
	printf("%d\n", aux);
	mostra_deque(d);
	remove_fim(&d, &aux);
	printf("%d\n", aux);
	mostra_deque(d);
	return 0;
}
