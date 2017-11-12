#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define true 1
#define false 0

int menu();
void pagamento (char modo);
FILE* abrir(char modo, char caminho[30]);
void fecha (FILE *arquivo);

main(){
	
	setlocale(LC_ALL, "portuguese");
	
	char modo;
	int deci;
	FILE *arquivo;
	
	printf("\n\t\tBEM VINDO AO ESTACIONAMENTO");
	sleep(2);
	system("cls");
	
	deci = menu();	
	
int menu(){
	
	int controle = true, deci;
	do{
		system ("cls ");
		printf("O QUE DESEJA FAZER ?\n1 - ENTRAR\n2 - SAIR\nDECISÃO:");
		scanf("%d", &deci);
		
		if ((deci != 1)||(deci != 2)){
			printf("OPÇÃO INVÁLIDA, POR FAVOR, ESCOLHA UMA OPÇÃO VÁLIDA");
			controle = false;
		}
	}while (controle = false);
	return deci;	
}
FILE* abrir(char modo, char caminho[30]){
	
	FILE *arquivo;
	
	if (modo == 'g'){
		arquivo = fopen (caminho,  "w");
	}
	if (modo == 'l'){
		arquivo = fopen (caminho, "r+");
	}
	if (modo == 'a'){
		arquivo =  fopen (caminho, "a");
	}
	if (arquivo == NULL){
		printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO");
	}
	return arquivo;	
}
void fecha (FILE *arquivo){
	fclose(arquivo);
}

