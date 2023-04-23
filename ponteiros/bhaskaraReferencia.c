#include <stdio.h>
#include <math.h>

//Calcula as raízes de uma equaão do segundo grau por meio de passagem por referência.

int bhaskara(int a, int b, int c, double *r1, double *r2);

int main(){
	int a, b, c;
	double r1, r2;
	printf("Digite a, b e c: \n");
	scanf("%d %d %d", &a, &b, &c);
	if(bhaskara(a, b, c, &r1, &r2)){
		printf("R1: %lf\nR2: %lf\n", r1, r2);
	}else{
		printf("Nao possue raizes reais!");
	}
	
	
	return 0;
}

int bhaskara(int a, int b, int c, double *r1, double *r2){
	double delta = b * b - (4 * a * c);
	if(delta == 0){
		*r1 = (-b + pow(delta, 0.5)) / (2 * a);
		*r2 = *r1;
		return 1;
	}else if(delta > 0){
		*r1 = (-b + sqrt(delta)) / (2 * a);
		*r2 = (-b - sqrt(delta)) / (2 * a);
		return 1;
	}
	return 0;
}
