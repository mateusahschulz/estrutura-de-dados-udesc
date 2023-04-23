#include <stdio.h>

//recebe um valor em segundos e converte para horas, minutos e segundos com passagem por referência.

void converte(int seg, int *h, int *m, int *s);

int main(){
	int seg, h, m, s;
	printf("Segundos: ");
	scanf("%d", &seg);
	converte(seg, &h, &m, &s);
	printf("%d:%d%:%d\n", h, m, s);
}

void converte(int seg, int *h, int *m, int *s){
	(*h) = seg / 3600;
	seg = seg % 3600;
	(*m) = seg / 60;
	(*s) = seg % 60;
}

