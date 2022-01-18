#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "fluxo.h"
#include "validar.h"

typedef struct fluxo Flu; //STRUCT INSPIRADO POR @flgorgonio

void moduloFluxo(void)
{

	char escolha;
	do {
		escolha = menuFluxo();
		switch(escolha) {
			case '1': 	cadastroGasto();
						break;
      case '2': 	pesquisarFluxo();
						break;
		} 		
	} while (escolha != '0'); 
}

///////////////////////////////////////////////MENU FLUXO///////////////////////////////////////////////////

char menuFluxo(void)
{
	char escolha;
	system("clear||cls");
	printf("______________________________________________________________________________________\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||                                                                                  ||\n");
	printf("||                      :::::::::::::::::::::::::::::::::::::::::                   ||\n");
	printf("||                      ::||           SIG-Fantasy           ||::                   ||\n");
	printf("||                      :::::::::::::::::::::::::::::::::::::::::                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||==================================================================================||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                      ====         Fluxo Financeiro         ===                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||                         __________________________________                       ||\n");
	printf("||                        |                                  |                      ||\n");
	printf("||                        |  1. Cadastrar Gastos             |                      ||\n");
  printf("||                        |  2. Pesquisar fluxo              |                      ||\n");
	printf("||                        |  0. Voltar                       |                      ||\n");
	printf("||                        |  'Digite a opcao desejada:'");
	int valid;
  do{
    scanf("%c", &escolha);
    getchar();
    valid= validarEscolhas(escolha);
  }while(valid==1);
	printf("||                        |__________________________________|                      ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||                                                                                  ||\n");
	printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	printf("||__________________________________________________________________________________||\n");
	return escolha;
}

void telaFluxo(const Flu* flu)
{
  char escolha;
	system("clear||cls");
	printf("______________________________________________________________________________________\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||                                                                                  ||\n");
	printf("||                      :::::::::::::::::::::::::::::::::::::::::                   ||\n");
	printf("||                      ::||           SIG-Fantasy           ||::                   ||\n");
	printf("||                      :::::::::::::::::::::::::::::::::::::::::                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||==================================================================================||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                      ====         Fluxo Financeiro         ===                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||      __________________________________________________________________          ||\n");
	printf("||     |                                                                  |         ||\n");
	printf("||     |  Motivo: %s | Responsável: %s [%d/%d/%d]............ ....... %2.f  |         ||\n", flu->motivo, flu->responsavel, flu->dia, flu->mes, flu->ano, flu->valor);
	printf("||     |  Motivo: %s | Responsável: %s [%d/%d/%d]............ ....... %2.f  |         ||\n", flu->motivo, flu->responsavel, flu->dia, flu->mes, flu->ano, flu->valor);
	printf("||     |  Motivo: %s | Responsável: %s [%d/%d/%d]............ ....... %2.f  |         ||\n", flu->motivo, flu->responsavel, flu->dia, flu->mes, flu->ano, flu->valor);
	printf("||     |  Motivo: %s | Responsável: %s [%d/%d/%d]............ ....... %2.f  |         ||\n", flu->motivo, flu->responsavel, flu->dia, flu->mes, flu->ano, flu->valor);
	printf("||     |                                                                  |         ||\n");
	printf("||     |                                                                  |         ||\n");
	printf("||     |                                                                  |         ||\n");
	printf("||     |                                                  [saldo Total]   |         ||\n");
	printf("||     |__________________________________________________________________|         ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||   1-voltar                                                                       ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||                                                                                  ||\n");
	printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	printf("||__________________________________________________________________________________||\n");
  int valid;
  do{
    scanf("%c", &escolha);
    getchar();
    int esc= validarEscolhas(escolha);
    if (esc==0){
      if (escolha=='1'){
        menuFluxo();
      }else{
        valid=1;
      }
    }
  }while(valid==1);
	sleep(5);
}


void cadastroGasto(void){
	Flu *flu;
	flu = cadastrarGasto();
	free(flu);
}
Flu* cadastrarGasto(void)
{
  char escolha;
	Flu *flu;
	flu = (Flu*) malloc(sizeof(Flu));

  FILE* fp;
	fp = fopen("fantasia.txt","at");
	if (fp == NULL){
	    printf("Erro! O sistema não conseguiu criar o arquivo\n!");
	    exit(1);
	}

	system("clear||cls");
	printf("______________________________________________________________________________________\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||                                                                                  ||\n");
	printf("||                      :::::::::::::::::::::::::::::::::::::::::                   ||\n");
	printf("||                      ::||           SIG-Fantasy           ||::                   ||\n");
	printf("||                      :::::::::::::::::::::::::::::::::::::::::                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||==================================================================================||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                      ====        Cadastrar Gastos         ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||            ________________________________________________________              ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |  Motivo:");
	do{
	    scanf("%[A-Z a-z 0-9]", flu->motivo);
	    fprintf(fp,"Motivo: %s\n", flu->motivo);
		getchar();
	}while(validarLetras(flu->motivo,tamanhoString(flu->motivo))==1);
		printf("||           |  Data (DD MM AA):");
	do{
	    scanf("%d %d %d", &flu->dia, &flu->mes, &flu->ano);
	    fprintf(fp,"Data: %d/%d/%d\n", flu->dia, flu->mes, flu->ano);
		getchar();
	}while(validarData(flu->dia, flu->mes, flu->ano)==1);
		printf("||           |  Valor:");
		scanf("%f", &flu->valor);
		fprintf(fp,"Valor: %f\n", flu->valor);
		getchar();
		printf("||           |  Responsável:");
	do{
	    scanf("%[A-Z a-z 0-9]", flu->responsavel);
		  getchar();
	  }while(validarLetras(flu->responsavel,tamanhoString(flu->responsavel))==1);
	printf("||           |________________________________________________________|             ||\n");
	printf("||                                                                                  ||\n");
	printf("||           1-Salvar   2-Sair                                                      ||\n");
	printf("||                                                                                  ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||                                                                                  ||\n");
	printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	printf("||__________________________________________________________________________________||\n");
  int valid;
  do{
    scanf("%c", &escolha);
    getchar();
    int esc= validarEscolhas(escolha);
    if (esc==0){
      if (escolha=='1'){
        telaFluxo(flu);
      }else if (escolha=='2'){
        menuFluxo();
      }else{
        valid=1;
      }
    }
  }while(valid==1);
	return flu;
}


void pesquisarFluxo(void)
{
  char escolha;
	system("clear||cls");
	printf("______________________________________________________________________________________\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||                                                                                  ||\n");
	printf("||                      :::::::::::::::::::::::::::::::::::::::::                   ||\n");
	printf("||                      ::||           SIG-Fantasy           ||::                   ||\n");
	printf("||                      :::::::::::::::::::::::::::::::::::::::::                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||==================================================================================||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                      ====      Pesquisar fluxo            ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||            ________________________________________________________              ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |  Pesquisa:[Data   ]                                    |             ||\n");
	printf("||           |________________________________________________________|             ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||           1-Pesquisar   2-Voltar                                                 ||\n");
	printf("||                                                                                  ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||                                                                                  ||\n");
	printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	printf("||__________________________________________________________________________________||\n");
  int valid;
  do{
    scanf("%c", &escolha);
    getchar();
    int esc= validarEscolhas(escolha);
    if (esc==0){
      if (escolha=='1'){
        // ainda será organizado
      }else if (escolha=='2'){
        menuFluxo();
      }else{
        valid=1;
      }
    }
  }while(valid==1);
}
