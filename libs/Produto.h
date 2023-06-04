typedef struct{
	int codigo;
	char descricao[50];
	float preco;
} Produto;

void mostra_produto(Produto x);
void gera_produto(Produto *p);
int busca_produto(Produto v[], int n, int codigo);
