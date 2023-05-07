//Aluno: Mateus Alayo Hidalgo Schulz
//Disciplina: Estrutura de Dados - TADS
//Trabalho de implementação de pilhas: análise de expressão infixa em posfixa.

#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include <string.h>
#include <ctype.h>

void converte_para_posfixa(char infixa[]);
int precedencia(char digitoExp);
int calcula_expressao(char posfixa[]);
int calcula_operandos(int operando1, int operando2, char operador);

int main(int argc, char *argv[]) {
	
	char *entrada = malloc(sizeof(char) * 100);
	printf("Notacao infixa: ");
	scanf("%[^\n]", entrada);
	
	converte_para_posfixa(entrada);
	
	free(entrada);
	
	return 0;
}


void converte_para_posfixa(char infixa[]){
	int erro = 0, i, indexPos = 0;
	char *posfixa = malloc(sizeof(char) * strlen(infixa));
	Pilha p;
	inicializa_pilha(&p, strlen(infixa));
	char caracter_aux;
	int valorTopo, resultado;
	
	for(i = 0; infixa[i] != '\0' && !erro; i++){
		caracter_aux = infixa[i];
		switch(caracter_aux){
			case '0'...'9':
				posfixa[indexPos] = caracter_aux;
				indexPos++;
				break;
			case '(':
				empilha(&p, caracter_aux);
				break;
			case ')':
				while(le_topo(p, &valorTopo) != ERRO_PILHA_VAZIA && valorTopo != '('){ 
					desempilha(&p, &valorTopo);
					posfixa[indexPos] = valorTopo;
					indexPos++;
				}
				if(pilha_vazia(p)){
					printf("Erro: ')' sem '('");
					erro = 1;
				}else{
					desempilha(&p, &valorTopo); //descarta o '('
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/': //caracter_aux é um operador.
				le_topo(p, &valorTopo);
				if(pilha_vazia(p) || valorTopo == '('){
					empilha(&p, caracter_aux);
				}else{
					while((le_topo(p, &valorTopo) != ERRO_PILHA_VAZIA) && (precedencia(valorTopo) >= precedencia(caracter_aux))){
						desempilha(&p, &valorTopo);
						posfixa[indexPos] = valorTopo;
						indexPos++;
					}
					empilha(&p, caracter_aux);
				}
				break;
			default:
				printf("caracter invalido %c!", caracter_aux);
				erro = 1;
		}
	}
	
	if(!erro){
		while(le_topo(p, &valorTopo) != ERRO_PILHA_VAZIA && valorTopo != '('){
			desempilha(&p, &valorTopo);
			posfixa[indexPos] = valorTopo;
			indexPos++;
		}
		if(pilha_vazia(p)){
			posfixa[indexPos] = '\0';
			printf("Posfixa: %s\n", posfixa);
			resultado = calcula_expressao(posfixa); //execução da função.
			printf("Resultado da expressao: %d", resultado);
		}else{
			printf("Erro: '(' nao foi fechado!");
		}
	}
	
	free(posfixa);
	desaloca_pilha(&p);
//	mostra_pilha(p);
}

int precedencia(char digitoExp){
	if(digitoExp == '('){
		return 0;
	}else if(digitoExp == '+' || digitoExp == '-'){
		return 1;
	}else if(digitoExp == '/' || digitoExp == '*'){
		return 2;
	}
}

int calcula_expressao(char posfixa[]){
	Pilha p;
	char caracter_aux;
	inicializa_pilha(&p, strlen(posfixa));
	int i, valorInteiro, val1, val2, resultado; 
	for(i = 0; posfixa[i] != '\0'; i++){
		caracter_aux = posfixa[i];
		if(isdigit(caracter_aux)){
			valorInteiro = caracter_aux - 48;
			empilha(&p, valorInteiro);
		}else{
			desempilha(&p, &val1);
			desempilha(&p, &val2);
			resultado = calcula_operandos(val1, val2, caracter_aux);
			empilha(&p, resultado);
		}
	}
	desempilha(&p, &resultado);
	return resultado;
}

int calcula_operandos(int operando1, int operando2, char operador){
	switch(operador){
		case '+':
			return operando1 + operando2;
		case '-':
			return operando2 - operando1; // é a mesma coisa da divisão.
		case '*':
			return operando1 * operando2;
		case '/':
			return operando2 / operando1; // é invertido aqui porque o primeiro a ser desempilhado é o último que entrou, então se 
										  // por exemplo, dividirmos 8/2, como o 2 foi o primeiro a sair, ao ser passado para função o 2 é 
										  // o operador 1, e se não invertermos fica 2/8, resultando em um 0.
	}
}
