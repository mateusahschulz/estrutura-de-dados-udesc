#include <stdio.h>
#include <string.h>


struct Produto{
	int codigo;
	char descricao[20];
	float preco;
};

int main(){
	
	struct Produto x;
	x.codigo = 123;
	strcpy(x.descricao, "Caderno");
	x.preco = 10.0;
	
	printf("%s (codigo %d) custa R$%.2f\n", x.descricao, x.codigo, x.preco);
	
	struct Produto y;
	y = x;
	printf("\nVariavel y que recebeu x como atribuicao:\n%s (codigo %d) custa R$%.2f\n", y.descricao, y.codigo, y.preco);
	
	return 0;
}
