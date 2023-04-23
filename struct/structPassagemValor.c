#include <stdio.h>
#include <string.h>


struct Produto{
	int codigo;
	char descricao[20];
	float preco;
};

void mostra_produto(struct Produto x);

int main(){
	struct Produto k;
	k.codigo = 123;
	strcpy(k.descricao, "Caderno");
	k.preco = 10.0;
	
	mostra_produto(k);
}


void mostra_produto(struct Produto x){
	printf("Codigo: %d\n", x.codigo);
	printf("Descricao: %s\n", x.descricao);
	printf("Preco: %.2f\n", x.preco);
}
