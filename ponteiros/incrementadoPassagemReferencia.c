#include <stdio.h>

//incrementa um número por meio de uma função em que parâmetro passado é seu endereço
//ou seja, passagem de parâmetro por referência.

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
