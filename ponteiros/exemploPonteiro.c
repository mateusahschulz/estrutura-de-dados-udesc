#include <stdio.h>

int main(){
	
	int a, b, c, *p1, *p2;  //*p1 e *p2 na declara��o, quer dizer que p1 e p2 recebem um endere�o de vari�vel int
	p1 = &a;				//p1 recebe endere�o de a e agora est� apontando para a
	p2 = &b;				//p1 recebe endere�o de b e agora est� apontando para b
	*p1 = 3;				//a = 3; (acessando o valor de a por meio de *
	scanf("%d", p2);		//em vez de passar &b, se passa p2 pq esse � o endere�o de b
	c = *p1 * *p2;			// c = a * b;
	printf("C = %d\n", c);
	
	/*
	como ler a atribui��o de ponteiro: 
		*p1 --> valor (ebb4(endere�o)) = 20;
		*p2 --> valor (ebb0(endere�o)) = 10;
		* = valor, acessar
	*/
	
	return 0;
}
