#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "venda.h"
#include "validar.h"


typedef struct venda Ven;

void moduloVenda(void)
{

	char escolha;
	do {
		escolha = menuVenda();
		switch(escolha) {
			case '1': cadastroVenda();
				break;
			case '2': telaVenda();
				break;
			case '3': pesquisarVendas();
				break;
		} 		
	} while (escolha != '0');  
}

///////////////////////////////////////////////MENU VENDAS///////////////////////////////////////////////////

char menuVenda(void)
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
	printf("||                      ====            MENU VENDAS           ===                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                         __________________________________                       ||\n");
	printf("||                        |                                  |                      ||\n");
	printf("||                        |  1. Cadastrar Vendas             |                      ||\n");
	printf("||                        |  2. Exibir Vendas                |                      ||\n");
	printf("||                        |  3. Pesquisar Vendas             |                      ||\n");
	printf("||                        |  0. Voltar                       |                      ||\n");
	printf("||                        |  'Digite a opcao desejada:'");
	int valid;
  do{
    scanf("%c", &escolha);
    getchar();
    valid= validarEscolhas(escolha);
  }while(valid==1);;
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

void telaVenda()
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
	printf("||                      ====              Vendas             ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||  _____________________________________                                           ||\n");
	printf("|| |                                     |                                          ||\n");
	    FILE *fp;
    char letra;
    fp = fopen("venda.txt", "rt");
    if (fp == NULL){
      printf("Erro! O sistema não conseguiu indentificar o arquivo!\n");
      exit(1);
    }
    letra = fgetc(fp);
    while (letra != EOF) {
      printf("%c", letra);
      letra = fgetc(fp);
    }
    fclose(fp);
    printf("|| |                1-EDITAR  2-EXCLUIR  |                                          ||\n");
	printf("|| |_____________________________________|                                          ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||                                                                                  ||\n");
	printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	printf("||__________________________________________________________________________________||\n");
  printf("3-voltar");
  int valid;
  do{
    scanf("%c", &escolha);
    getchar();
    int esc= validarEscolhas(escolha);
    if (esc==0){
      if (escolha=='1'){
        editarVenda();
      }else if (escolha=='2'){
        excluirVenda();
      }else if (escolha=='3'){
        menuVenda();
      }else{
        valid=1;
      }
    }
  }while(valid==1);
	sleep(5);
}

void cadastroVenda(void){
	Ven *ven;
	ven = cadastrarVenda();
	free(ven);
}

Ven* cadastrarVenda(void)
{
	char escolha;
	Ven *ven;
	ven = (Ven*) malloc(sizeof(Ven));

	FILE* fp;
	fp = fopen("venda.txt","at");
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
	printf("||                      ====         Cadastrar Venda         ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||            ________________________________________________________              ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |  Cód. Produto:");
  do{
    scanf("%[A-Z a-z 0-9]", ven->cod);
    fprintf(fp,"Codigo: %s\n", ven->cod);
  	getchar();
  }while(validarNumeros(ven->cod,tamanhoString(ven->cod))==1);
	printf("||           |  Cód. Cliente:");
  do{
    scanf("%[A-Z a-z 0-9]", ven->cliente);
    fprintf(fp,"Cliente: %s\n", ven->cliente);
  	getchar();
  }while(validarNumeros(ven->cliente,tamanhoString(ven->cliente))==1);
	printf("||           |  Data (DD MM AA):");
  do{
    scanf("%d %d %d", &ven->dia, &ven->mes, &ven->ano);
    fprintf(fp,"Data: %d/%d/%d\n", ven->dia, ven->mes, ven->ano);
  	getchar();
  }while(validarData(ven->dia,ven->mes,ven->ano)==1);
	printf("||           |  Aluguel (dias):(use ponto para separar os centavos Ex: 00.00)");
  	scanf("%d", &ven->aluguel);
  	fprintf(fp,"Aluguel: %d\n\n\n", ven->aluguel);
  	getchar();
	//printf("||           |  Total:[aluguel*valor]                                 |             ||\n");
	printf("||           |________________________________________________________|             ||\n");
	printf("||                                                                                  ||\n");
	printf("||           1-Salvar   2-Sair                                                      ||\n");
	printf("||                                                                                  ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||                                                                                  ||\n");
	printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	printf("||__________________________________________________________________________________||\n");
	fclose(fp);
  int valid;
  do{
    scanf("%c", &escolha);
    getchar();
    int esc= validarEscolhas(escolha);
    if (esc==0){
      if (escolha=='1'){
        telaVenda();
      }else if (escolha=='2'){
        menuVenda();
      }else{
        valid=1;
      }
    }
  }while(valid==1);
  
 	return ven;
}

void pesquisarVendas(void)
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
	printf("||                      ====      Pesquisar Vendas           ====                   ||\n");
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
        menuVenda();
      }else{
        valid=1;
      }
    }
  }while(valid==1);
}


void editarVenda(void)
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
	printf("||                      ====          Editar Venda           ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||            ________________________________________________________              ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |  Cód. Produto:[__________________]                     |             ||\n");  
	printf("||           |  Cód. Cliente:[__________________]                     |             ||\n"); 
	printf("||           |  Data (DD MM AA):[__/__/__]                            |             ||\n");
	printf("||           |  Aluguel (dias):[____]                                 |             ||\n");
	printf("||           |  Total:[preço*aluguel]                                 |             ||\n");
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
        //cadastroVenda();
      }else if (escolha=='2'){
        menuVenda();
      }else{
        valid=1;
      }
    }
  }while(valid==1);
}

void excluirVenda(void)
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
	printf("||                      ====            Venda                ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||            ________________________________________________________              ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |  Você realmente deseja excluir essa Venda?             |             ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |________________________________________________________|             ||\n");
	printf("||                                                                                  ||\n");
	printf("||           1-Sim   2-Não                                                          ||\n");
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
        //telaVenda(ven); ainda será organizado
      }else if (escolha=='2'){
        //telaVenda(ven); ainda será organizado
      }else{
        valid=1;
      }
    }
  }while(valid==1);
}