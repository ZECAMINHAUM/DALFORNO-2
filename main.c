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
	
	struct cadastro{
		int num_placa=0,ano=0;
		char carro[20];
		char marca[50];
		char placa_letra[5];
	};
	char modo;
	int deci;
	FILE *arquivo;
	
	printf("\n\t\tBEM VINDO AO ESTACIONAMENTO");
	sleep(2);
	system("cls");
	
	deci = menu();	

	if(deci==1){
		struct cadastro entrada[2];
		for(int i=0;i<2;i++){
			scanf("%d",&entrada[i].num_placa);
			scanf("%s",entrada[i].placa_letra);
			scanf("%d",&entrada[i].ano);
			scanf("%s",entrada[i].carro);
			scanf("%s",entrada[i].marca);
		}
		for (int i = 0; i < 2; i++){
			printf("%d",entrada[i].num_placa);
			printf("%s",entrada[i].placa_letra);
			printf("%d",entrada[i].ano);
			printf("%s",entrada[i].carro);
			printf("%s",entrada[i].marca);	
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

