#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Dado dois vetores, gera um novo vetor unindo os outros vetores.

int *uniao(int *v1, int n1, int *v2, int n2, int *p3);
void gera_valores(int *v, int n);
void mostra_vetor(int *v, int n, char* nome);

int main(){

	int tam1, tam2, tam3, i;
	
	printf("Digite a capacidade do primeiro vetor: ");
	scanf("%d", &tam1);	
	int *v1 = malloc(sizeof(int) * tam1);
	for(i = 0; i < tam1; i++){
		printf("[%d]: ", i);
		scanf("%d", &v1[i]);
	}
	
	
	printf("Digite a capacidade do segundo vetor: ");
	scanf("%d", &tam2);
	int *v2 = malloc(sizeof(int) * tam2);
	for(i = 0; i < tam2; i++){
		printf("[%d]: ", i);
		scanf("%d", &v2[i]);
	}
	
	int *vetorUnido = uniao(v1, tam1, v2, tam2, &tam3);
	mostra_vetor(vetorUnido, tam3, "Unido");
	
	
	free(v1);
	free(v2);
	free(vetorUnido);
	
	return 0;
}

int *uniao(int *v1, int n1, int *v2, int n2, int *p3){
	int *vet = malloc(sizeof(int) * (n1 + n2));
	*p3 = 0;
	int i;
	for(i = 0; i < n1; i++){
		vet[*p3] = v1[i];
		(*p3)++;
	}
	
	for(i = 0; i < n2; i++){
		vet[*p3] = v2[i];
		(*p3)++;
	}
	
	
	return vet;
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

