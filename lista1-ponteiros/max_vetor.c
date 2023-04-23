#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

//retorna maior valor de um vetor junto com seu índice.


void max_vetor(float vet[], int tam, float *pMax, int *pIndice);

int main(){
	srand(time(0));
	float vet[N], maior;
	int indiceMaior, i;
	for(i = 0; i < N; i++){
		vet[i] = rand() % 1000 + 1;
	}
	for(i = 0; i < N; i++){
		printf("vet[%d]: %.2f\n", i, vet[i]);  
	}
	max_vetor(vet, N, &maior, &indiceMaior);
	printf("\nMaior valor junto com sua posicao: \n[%d]: %.2f", indiceMaior, maior);
		
	return 0;
}


void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
	*pMax = vet[0];
	int i;
	for(i = 0; i < tam; i++){
		if(vet[i] > *pMax){
			*pMax = vet[i];
			*pIndice = i;
		}
	}
}
