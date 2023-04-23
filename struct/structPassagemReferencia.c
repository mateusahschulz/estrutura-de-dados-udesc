#include <stdio.h>
#include <string.h>


struct Produto{
	int codigo;
	char descricao[20];
	float preco;
};

void mostra_produto(struct Produto x);
void le_produto(struct Produto *x);

int main(){
	struct Produto k;
	le_produto(&k);
	mostra_produto(k);
}

void le_produto(struct Produto *x){
	scanf("%d", &x->codigo);
	scanf("%s", x->descricao);
	scanf("%f", &(*x).preco);
	//da para acessar com . e ->
	
}

void mostra_produto(struct Produto x){
	printf("Codigo: %d\n", x.codigo);
	printf("Descricao: %s\n", x.descricao);
	printf("Preco: %.2f\n", x.preco);
}
