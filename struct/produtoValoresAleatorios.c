#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Produto{
	int codigo;
	char descricao[20];
	float preco;
};


int main(){
	
	char *descricoes[] = {"caderno", "caneta", "lapis", "borracha", "grampeador"}; //vetor de ponteiro, cada ponteiro aponta para cada um dos elementos
	int tam_d = sizeof(descricoes) / sizeof(descricoes[0]);
	
	srand(time(0));
	int n, i;
	printf("Quantos produtos? ");
	scanf("%d", &n);
	struct Produto *v = malloc(sizeof(struct Produto) * n);
	
	float valor;
	printf("Mostrar produtos abaixo de: ");
	scanf("%f", &valor);
	
	for(i = 0; i < n; i++){
		v[i].codigo = rand() % 100;
		strcpy(v[i].descricao, descricoes[ rand() % tam_d]);
		v[i].preco = rand() % 100 + 1;
	}
	int achou = 0;
	for(i = 0; i < n; i++){
		if(v[i].preco < valor){
			printf("Descricao: %s\n", v[i].descricao);
			printf("Preco: %.2f\n\n", v[i].preco);	
			achou = 1;
		} 
	}
	if(!achou){
		printf("Nenhum produto encontrado!");
	}
	
	free(v);
	
	return 0;
}
