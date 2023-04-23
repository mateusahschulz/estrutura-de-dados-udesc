#include <stdio.h>

//dado raio de um círculo, calcula seu perímetro e área

void calcula_circulo(float raio, float *pPerimetro, float *pArea);

int main(){
	
	float raio, perimetro, area;
	printf("Determine a area do raio do circulo: ");
	scanf("%f", &raio);
	calcula_circulo(raio, &perimetro, &area);
	printf("O perimetro do circulo eh %.2f\nA area do circulo eh %.2f", perimetro, area);
	
	return 0;
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
	float pi = 3.14;
	*pPerimetro = 2 * pi * raio;
	*pArea = pi * raio * raio;
}

