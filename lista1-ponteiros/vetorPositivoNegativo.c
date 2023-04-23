#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//A partir de um vetor com o tamanho informado pelo usuário, gera outros dois vetores, tanto positivo como negativos.
//Primeiro aceitava entrada de usuário, depois foram gerado os valores.

void mostra_vetor(int *v, int n, char* nome);
void gera_valores(int *v, int n);
int* gera_positivo(int *v, int n, int *tamanho);
int* gera_negativo(int *v, int n, int *tamanho);

int main(){
	
	int qtd, i, tamanho_positivo, tamanho_negativo;
	printf("Quantos valores o vetor armazenara? ");
	scanf("%d", &qtd);
	int *v = malloc(sizeof(int) * qtd);
//	for(i = 0; i < qtd; i++){
//		printf("[%d]: ", i);
//		scanf("%d", v + i);
//	}
	gera_valores(v, qtd);
	mostra_vetor(v, qtd, "Vetor Original");
	int *positivo = gera_positivo(v, qtd, &tamanho_positivo);
	int *negativo = gera_negativo(v, qtd, &tamanho_negativo);
	mostra_vetor(positivo, tamanho_positivo, "Vetor Positivo");
	mostra_vetor(negativo, tamanho_negativo, "Vetor Negativo");
	
	free(v);
	free(positivo);
	free(negativo);
	
	return 0;
}


void gera_valores(int *v, int n){
	srand(time(0));
	int i;
	for(i = 0; i < n; i ++){
		if( rand() % 2 == 0){
			v[i] = rand() % 100 + 1;
		}else{
			v[i] = -rand() % 100 + 1;
		}
	}
}

int* gera_positivo(int *v, int n, int *tamanho){
	int i, count = 0;
	*tamanho = 0;
	for(i = 0; i < n; i++){
		if(v[i] > 0){
			(*tamanho)++;
		}
	}
	int *vetPositivo = malloc(sizeof(int) * (*tamanho));
	for(i = 0; i < n; i++){
		if(v[i] > 0){
			vetPositivo[count] = v[i];
			count++;
		}
	}
	return vetPositivo;
}

int* gera_negativo(int *v, int n, int *tamanho){
	int i, count = 0;
	*tamanho = 0;
	for(i = 0; i < n; i++){
		if(v[i] < 0){
			(*tamanho)++;
		}
	}
	int *vetNegativo = malloc(sizeof(int) * (*tamanho));
	for(i = 0; i < n; i++){
		if(v[i] < 0){
			vetNegativo[count] = v[i];
			count++;
		}
	}
	return vetNegativo;
}

void mostra_vetor(int *v, int n, char* nome){
	int i; 
	printf("\n%s:\n", nome);
	if(n > 0){
		for(i = 0; i < n; i++){
			printf("[%d]: %d\n", i, v[i]);
		}
		printf("\n");
	}else{
		printf("Nenhum valor encontrado");
	}
	
}
