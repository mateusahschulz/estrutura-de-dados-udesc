#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fun��o que recebe uma string e retorna a quantidade de vezes que o usu�rio pediu para repetir ela, como uma nova string. 

char* repetidor(char *s, int n);

int main(){
	
	char str[30];
	int n;
	printf("Digite uma string: ");
	scanf("%[^\n]", str);
	printf("Digite a quantidade de repeticoes desejada da string: ");
	scanf("%d", &n);
	char *resultante = repetidor(str, n);
	printf("'%s'", resultante);
	
	free(resultante);
	
	
	return 0;
}

char* repetidor(char *s, int n){
	
	int length = strlen(s) * n;
	char *novaString = malloc(length);
	novaString[0] = '\0';												
	int i; 						
	for(i = 0; i < n; i ++){
		strcat(novaString, s);
	}
	
	return novaString;	
	//acredito que tenha que usar isso, uma vez que a fun��o strcat faz o seguinte: a string a ser concatenada, tem seu '\0' substituido
	//pela string que vai concatenar e ap�s toda a concatena��o, a string concatenada recebe o '\0'. Com isso � necess�rio inicializar com '\0'.
}
