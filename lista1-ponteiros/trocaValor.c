#include <stdio.h>

//troca o valor entre duas variáveis.

void troca_valor(float *x, float *y);

int main(){
	
	float x, y;
	printf("Digite o valor de x: ");
	scanf("%f", &x);
	printf("Digite o valor de y: ");
	scanf("%f", &y);
	troca_valor(&x, &y);
	printf("\nNovo valor x: %.2f\nNovo valor y: %.2f", x, y); 
	
	return 0;
}

void troca_valor(float *x, float *y){
	float swap = *x;
	*x = *y;
	*y = swap;
}
