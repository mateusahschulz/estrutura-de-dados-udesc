#include <stdio.h>
#include <stdlib.h>
#include "../../libs/ListaEncadeada.h"

int compara_float(void *x, void *y);
void mostra_float(void *info);

int main(int argc, char *argv[]) {
	Lista lista;
	inicializa_lista(&lista, sizeof(float));
	float x = 10;	// lista = {10}
	insere_ordem(&lista, &x, compara_float);
	x = 8;			// lista = {8, 10}
	insere_ordem(&lista, &x, compara_float);
	x = 20;			// lista = {8, 10, 20}
	insere_ordem(&lista, &x, compara_float);
	mostra_lista(lista, mostra_float);
		
	return 0;
}

int compara_float(void *x, void *y){
	float *a = x, *b = y;	// void* --> float*, agora sim posso desreferenciar o ponteiro, ponteiro void não é possível.
	if(*a > *b)
		return 1;	// a > b
		
	if(*a < *b)
		return -1;  // a < b
		
	return 0;		// a == b
}

void mostra_float(void *x){
	printf("%.2f\n", *(float *)x);
}
