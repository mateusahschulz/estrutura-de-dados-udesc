//Aluno: Mateus A. H. Schulz
//Disciplina: Estrutura de Dados
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void bfs(int tamanho, int matriz[tamanho][tamanho], int inicio, int fim);

int main(int argc, char *argv[]) {
	
	FILE *arquivo = fopen("teste.txt", "r");
	int tamanho, i, j, inicio, fim;
	fscanf(arquivo, "%d", &tamanho);
	printf("tamanho: %d\n", tamanho);
	
	fscanf(arquivo, "%d %d", &inicio, &fim);
	printf("%d %d\n", inicio, fim);
	
	int m[tamanho][tamanho];
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			fscanf(arquivo,"%d", &m[i][j]);
			printf("%d ", m[i][j]);
		}
		printf("\n");		
	}

	bfs(tamanho, m, inicio - 1, fim - 1);
	
	fclose(arquivo);
		
	return 0;
}



void bfs(int tamanho, int matriz[tamanho][tamanho], int inicio, int fim){
	int i;
	int *vs = malloc(sizeof(int) * tamanho);	
	int *va = malloc(sizeof(int) * tamanho);
	for(i = 0; i < tamanho; vs[i] = 0, va[i] = 0,  i++); 
	Fila f;
	inicializa_fila(&f, tamanho);
	vs[inicio] = 1;						
	inserir(&f, inicio);				
	int	achou = 0, aux;					
	while(!fila_vazia(f) && !achou){
		remover(&f, &aux);	
		if(aux == fim){
			achou = 1;
		}else{
			for (i = 0; i < tamanho; i++) {
				if (matriz[aux][i] == 1) {
					if (vs[i] == 0) {
						vs[i] = 1;
						va[i] = aux;
						inserir(&f, i);
					}
				}
			}
		}
	}
	printf("\n\n");
	if(achou){	
		Pilha p;
		inicializa_pilha(&p, tamanho);
		printf("%d\n", inicio + 1);
		while(aux != inicio){
			empilha(&p, aux);		
			aux = va[aux];	
		}
		while(!pilha_vazia(p)){
			desempilha(&p, &aux);		
			printf("%d\n", aux + 1);
		}
	}else{
		printf("B nao e alcancavel a partir de A");\
	}	
}
