#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Calcula a média de um vetor de float e em seguida gera um novo vetor com os valores acima da média

float *acimaMedia(float *v, int n, float media, int *qtd);
float calculaMedia(float *v, int n);
void mostra_vetor(float *v, int n);


int main(){
	
	int cap, i;
	srand(time(0));
	printf("Digite a capacidade do vetor: ");
	scanf("%d", &cap);
	float *vet = malloc(sizeof(float) * cap);
	for(i = 0; i < cap; i++){
		vet[i] = rand() % 100+1;
	}
	mostra_vetor(vet, cap);
	
	float media = calculaMedia(vet, cap);
	printf("Media dos valores do vetor original: %.2f\n\n", media);
	
	int *qtdAcimaMedia = malloc(sizeof(int));
	float *vetAcimaMedia = acimaMedia(vet, cap, media, qtdAcimaMedia);
	printf("Vetor com os valores acima da media: \n");
	mostra_vetor(vetAcimaMedia, *qtdAcimaMedia);
	
	free(vet);
	free(qtdAcimaMedia);
	free(vetAcimaMedia);
	
	return 0;
}


float *acimaMedia(float *v, int n, float media, int *qtd){
	int i, count = 0; 
	*qtd = 0;
	for(i = 0; i < n; i++){
		if(v[i] > media){
			(*qtd)++;
		}
	}
	float *acimaMedia = malloc(sizeof(float) * (*qtd));
	
	for(i = 0; i < n; i++){
		if(v[i] > media){
			acimaMedia[count] = v[i];
			count++;
		}
	}
	
	return acimaMedia;
}

float calculaMedia(float *v, int n){
	float soma = 0;
	int i;
	for(i= 0; i < n; i ++){
		soma += v[i];
	}
	float media = soma/n;
	
	return media;
}

void mostra_vetor(float *v, int n){
	int i; 
	for(i = 0; i < n; i++){
		printf("[%d]: %.2f\n", i, v[i]);
	}
	printf("\n");
}
