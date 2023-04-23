#include <stdio.h>

//fatorial com passagem por referência

void fatorial(int x, int *p);

int main(){
	
	int f;
	scanf("%d", &f);
	fatorial(f, &f);
	printf("%d", f);
	
	return 0;
}

void fatorial(int x, int *p){
	*p = 1;
	while(x > 0){
		*p *= x;
		x--;
	}
}
