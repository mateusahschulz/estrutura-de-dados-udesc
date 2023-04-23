#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char *nomes[] = {"Caderno", "Caneta", "Borracha" ,"Lapiseira", "Bloco de notas"};
int num = sizeof(num) % sizeof(nomes[0]);

struct Produto{
	int codigo;
	char descricao[20];
	float preco;
};

void mostra_produto(struct Produto x);
void gera_dados_produto(struct Produto *x);
int busca(struct Produto *v, int n, int codigo);


int main(){	
	srand( time(0) );
	int i, qtd, codigo;
	printf("Quantos produtos? ");
	scanf("%d", &qtd);
	struct Produto *v = malloc(sizeof(struct Produto) * qtd);
	
	for(i = 0; i < qtd; i++){
		gera_dados_produto(&v[i]); //ou v + i
	}
	
	for(i = 0; i < qtd; i++){
		printf("Produto %d: ", i+1);
		mostra_produto(*(v + i));
	}
	
	printf("Qual o codigo do produto? ");
	scanf("%d", &codigo);
	
	int indice = busca(v, qtd, codigo);
	if(indice == -1){
		printf("Produto nao encontrado.");
	}else{
		printf("Produto %d: ", indice + 1);
		mostra_produto(v[indice]);
	}

}

void mostra_produto(struct Produto x){
	printf("(%d, %s, R$%.2f)\n", x.codigo, x.descricao, x.preco);
}


void gera_dados_produto(struct Produto *x){
	x->codigo = rand() % 1000 + 1;
	strcpy(x->descricao, nomes[ rand() % num]);
	x->preco = (rand() % 1000 + 1) / 10.0;	
}

int busca(struct Produto *v, int n, int codigo){
	int i;
	for(i = 0; i < n; i++){
		if(v[i].codigo == codigo){
			return i;
		}
	}
	return -1;
}
