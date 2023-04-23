#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Gera um vetor do tipo float alocado dinamicamente. 
//Em seguida chama uma função que gera um vetor clone também alocado dinamicamente.

float *clone(float *v, int n);
void mostra_vetor(float *v, int n);

int main(){
	
	int i, n;
	printf("Tamanho do vetor: ");
	scanf("%d", &n);	
	srand(time(0));
	
	float *v = malloc(sizeof(float) * n);
	for(i = 0; i < n; i++){
		v[i] = rand() % 100 + 1;
	}
	mostra_vetor(v, n);
	
	float *novoVetor = clone(v, n);
	mostra_vetor(novoVetor, n);
	
	free(v);
	free(novoVetor);
	return 0;
}

float *clone(float *v, int n){
	int i;
	float *resultante = malloc(sizeof(float) * n);
	for(i = 0; i < n; i++){
		*(resultante + i) = *(v + i);
	}
	
	return resultante;
}

void mostra_vetor(float *v, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("[%d]: %.2f\n", i, v[i]);
	}
	printf("\n");
}
