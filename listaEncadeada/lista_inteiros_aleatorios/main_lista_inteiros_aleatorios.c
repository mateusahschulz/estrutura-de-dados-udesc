#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../libs/ListaEncadeada.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void mostra_int(void *x);

int main(int argc, char *argv[]) {
	Lista l;
	inicializa_lista(&l, sizeof(int));
	
	int n, i;
	printf("Quantidade de numeros na lista: ");
	scanf("%d", &n);
	
	srand(time(0));
	for(i = 1; i <= n; i++){
		int x = rand();
		insere_inicio(&l, &x);
	}	
	mostra_lista(l, mostra_int);
	
	return 0;
}

void mostra_int(void *x){
	int *a = x;
	printf("%d\n", *a);
}
