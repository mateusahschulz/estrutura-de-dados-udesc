#include <stdio.h>
#include <string.h>


struct Produto{
	int codigo;
	char descricao[20];
	float preco;
};


int main(){
	
	struct Produto v[10];
	int i;
	for(i = 0; i < 10; i++){
		printf("Produto %d: \n", i + 1);
		scanf("%d", &v[i].codigo);
		scanf("%s", v[i].descricao);
		scanf("%f", &v[i].preco);
	}
	for(i = 0; i < 10; i++){
		printf("Dados do Produto %d: \n", i + 1);
		printf("Codigo: %d\n", v[i].codigo);
		printf("Descricao: %s\n", v[i].descricao);
		printf("Preco: %.2f\n\n", v[i].preco);
	}
	
	return 0;
}
