#include <stdio.h>

//incrementa um n�mero por meio de uma fun��o em que par�metro passado � seu endere�o
//ou seja, passagem de par�metro por refer�ncia.

void inc(int *x);

int main(){
	
	int n = 1;
	printf("%d\n", n);
	inc(&n);
	printf("%d\n", n);
	
	return 0;
}

void inc(int *x){
	(*x)++;
}
