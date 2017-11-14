#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define true 1
#define false 0

int menu();
void pagamento (char modo);
FILE* abrir(char modo, char caminho[30]);
void fecha (FILE *arquivo);
struct cadastro {
	int num;
	int ano;
	char carro[20];
	char marca[50];
	char letra[5];
};

main(){
	
	setlocale(LC_ALL, "portuguese");
	int i;
	char modo;
	int deci;
	FILE *arquivo;
	
	printf("\n\t\tBEM VINDO AO ESTACIONAMENTO");
	sleep(2);
	system("cls");
	
	deci = menu();	

	if(deci==1){
		struct cadastro entrada[1];
		for(i=0;i<1;i++){
			printf("Informe os números contidos na placa: "); scanf("%d",&entrada[i].num);printf("\n");
			printf("Informe as letras contidos na placa: "); scanf("%s",entrada[i].letra);printf("\n");
			printf("Informe o ano do carro: ");scanf("%d",&entrada[i].ano);printf("\n");
			printf("Informe o nome do carro: ");scanf("%s",entrada[i].carro);printf("\n");
			printf("Informe a marca do carro: ");scanf("%s",entrada[i].marca);printf("\n");
		}
		for(i=0;i<1;i++){
			printf("----------------------------------------------------\n\n\n");
			printf("Números da placa: %d",entrada[i].num);printf("\n");
			printf("Letras da placa: %s",entrada[i].letra);printf("\n");
			printf("Ano do carro: %d",entrada[i].ano);printf("\n");
			printf("Nome do carro: %s",entrada[i].carro);printf("\n");
			printf("Marca do carro: %s",entrada[i].marca);	printf("\n\n\n");
			printf("----------------------------------------------------\n\n\n");
		}	
}
}	
int menu(){
	
	int controle = true, deci=0;
	do{
		
		printf("O QUE DESEJA FAZER ?\n1 - ENTRAR\n2 - SAIR\nDECISÃO:");
		scanf("%d", &deci);
		
		if ((deci!=1)||(deci!=2)){

			printf("OPÇÃO VÁLIDA,CONTINUANDO...\n");
		
		}else{
			printf("OPÇÃO INVÁLIDA, POR FAVOR INFORME UMA OPÇÃO VÁLIDA!\n");
			controle = false;
		}
	}while (controle==false);
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

