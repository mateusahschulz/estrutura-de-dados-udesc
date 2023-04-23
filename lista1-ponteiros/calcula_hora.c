#include <stdio.h>

//usuário informa quantos minutos passaram desde meio-dia e o programa calcula que horas são.

void calcula_hora(int totalMinutos, int *ph, int *pm);

int main(){
	int minPassado, hora, min;
	printf("Quantos minutos passaram desde meio-dia: ");
	scanf("%d", &minPassado);
	calcula_hora(minPassado, &hora, &min);
	printf("Sao %d:%d\n", hora + 12, min);
	return 0;
}

void calcula_hora(int totalMinutos, int *ph, int *pm){
	*ph = totalMinutos / 60;
	*pm = totalMinutos % 60;
}
