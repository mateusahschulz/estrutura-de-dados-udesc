#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

//retorna maior e menor valor de um vetor.
//BOM LEBRAR: v[i] é igual à *(v + i).

void max_min(int vet[], int tam, int *pMin, int *pMax);

int main(){
	srand(time(0));
	int vet[N], i, maior, menor;
	for(i = 0; i < N; i++){
		vet[i] = rand() % 1000 + 1;
	}
	for(i = 0; i < N; i++){
		printf("%d\n", *(vet + i));  //outra forma de acessar vetor, uma vez que vetor é tratado como ponteiro e vice-versa.
	}
	max_min(vet, N, &menor, &maior);
	printf("\nMaior valor do vetor: %d\nMenor valor do vetor: %d", maior, menor);
		
	return 0;
}


void max_min(int vet[], int tam, int *pMin, int *pMax){
	*pMin = vet[0];
	*pMax = vet[0];
	int i;
	for(i = 0; i < tam; i++){
		if(vet[i] > *pMax){
			*pMax = *(vet + i);
		}
		if(vet[i] < *pMin){
			*pMin = *(vet + i);
		}
	}
}
