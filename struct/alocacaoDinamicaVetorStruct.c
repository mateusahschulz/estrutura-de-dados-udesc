#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Produto{
	int codigo;
	char descricao[20];
	float preco;
};


int main(){
	
	int n;
	printf("Quantos produtos? ");
	scanf("%d", &n);
	struct Produto *v = malloc(sizeof(struct Produto) * n);
	
	float valor;
	printf("Mostrar produtos abaixo de: ");
	scanf("%f", &valor);
	
	int i;
	for(i = 0; i < n; i++){
		printf("Produto %d: \n", i + 1);
		scanf("%d", &v[i].codigo);
		scanf("%s", v[i].descricao);
		scanf("%f", &v[i].preco);
		printf("\n\n");
	}
	for(i = 0; i < n; i++){
		if(v[i].preco < valor){
			printf("Dados do Produto %d: \n", i + 1);
			printf("Codigo: %d\n", v[i].codigo);
			printf("Descricao: %s\n", v[i].descricao);
			printf("Preco: %.2f\n\n", v[i].preco);	
		}
	}
	
	free(v);
	
	return 0;
}
