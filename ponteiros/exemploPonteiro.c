#include <stdio.h>

int main(){
	
	int a, b, c, *p1, *p2;  //*p1 e *p2 na declaração, quer dizer que p1 e p2 recebem um endereço de variável int
	p1 = &a;				//p1 recebe endereço de a e agora está apontando para a
	p2 = &b;				//p1 recebe endereço de b e agora está apontando para b
	*p1 = 3;				//a = 3; (acessando o valor de a por meio de *
	scanf("%d", p2);		//em vez de passar &b, se passa p2 pq esse é o endereço de b
	c = *p1 * *p2;			// c = a * b;
	printf("C = %d\n", c);
	
	/*
	como ler a atribuição de ponteiro: 
		*p1 --> valor (ebb4(endereço)) = 20;
		*p2 --> valor (ebb0(endereço)) = 10;
		* = valor, acessar
	*/
	
	return 0;
}
