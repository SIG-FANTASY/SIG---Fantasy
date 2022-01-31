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
	Ven* vn;
	char escolha;
	do {
		escolha = menuVenda();
		switch(escolha) {
			case '1': vn=cadastrarVenda();
				gravaVendas(vn);
				break;
			case '2': listaVenda();
				break;
			case '3': vn=pesquisarVendas();
				exibeVenda(vn);
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

void listaVenda(void)
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
	printf("||                      ====       Catalogo Vendas           ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||  _____________________________________                                           ||\n");
    FILE *fp;
	Ven* venda;
	venda = (Ven*) malloc(sizeof(Ven));
	fp = fopen("venda.dat", "rb");
	if (fp == NULL) {
	   printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
	   printf("Não é possível continuar este programa...\n");
	   exit(1);
	}
	while(fread(venda, sizeof(Ven), 1, fp)) {
		if (venda->status != 'x') {
		    exibeVenda(venda);
		}
	}
	fclose(fp);
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("3- Voltar");
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
	sleep(10);
}

Ven* cadastrarVenda(void)
{
	char escolha;
	Ven *ven;
	ven = (Ven*) malloc(sizeof(Ven));
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
    printf("Codigo: %s\n", ven->cod);
  	getchar();
  }while(validarNumeros(ven->cod,tamanhoString(ven->cod))==1);
	printf("||           |  Cód. Cliente:");
  do{
    scanf("%[A-Z a-z 0-9]", ven->cliente);
    printf("Cliente: %s\n", ven->cliente);
  	getchar();
  }while(validarNumeros(ven->cliente,tamanhoString(ven->cliente))==1);
	printf("||           |  Data (DD MM AA):");
  do{
    scanf("%d %d %d", &ven->dia, &ven->mes, &ven->ano);
    printf("Data: %d/%d/%d\n", ven->dia, ven->mes, ven->ano);
  	getchar();
  }while(validarData(ven->dia,ven->mes,ven->ano)==1);
	printf("||           |  Aluguel (dias):(use ponto para separar os centavos Ex: 00.00)");
  	scanf("%s", &ven->aluguel);
  	printf("Aluguel: %d\n\n\n", ven->aluguel);
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
/*  int valid;
  do{
    scanf("%c", &escolha);
    getchar();
    int esc= validarEscolhas(escolha);
    if (esc==0){
      if (escolha=='1'){
        listaVenda();
      }else if (escolha=='2'){
        menuVenda();
      }else{
        valid=1;
      }
    }
  }while(valid==1);
*/  
 	return ven;
}

void exibeVenda(Ven* ven) {
	if ((ven == NULL) || (ven->status == 'x')) {
    	printf("\n= = = Venda Inexistente = = =\n");
  	} else {
       printf("Código: %s\n", ven->cod);
  		printf("Cliente: %s\n", ven->cliente);
  		printf("Data: %d/%d/%d\n", ven->dia,ven->mes,ven->ano);
  		printf("Aluguel: %s\n\n", &ven->aluguel);
  	}
}

void gravaVendas(Ven* venda) {
	FILE *fp;

	fp = fopen("venda.dat","ab");
    fclose(fp);

    fp = fopen("venda.dat","ab");
	  fwrite(venda, sizeof(Ven), 1, fp);
	  fclose(fp);
	}

Ven* pesquisarVendas(void)
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
	FILE* fp;
	Ven* venda;
	char codigo[15];
	printf("\n = Buscar Vendas = \n"); 
	printf("Informe o codigo: "); 
	scanf("%s", codigo);
	venda = (Ven*) malloc(sizeof(Ven));
	fp = fopen("venda.dat", "rb");
	if (fp == NULL) {
	  printf("O programa não conseguiu encontrar o arquivo!\n");
	  exit(1);
	}
	while(!feof(fp)) {
		fread(venda, sizeof(Ven), 1, fp);
	  	if ((venda->cod == codigo) && (venda->status != 'x')) {
	    	fclose(fp);
	    	return venda;
	  	}
	}
	fclose(fp);
	return NULL;
	printf("||           |________________________________________________________|             ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||           1-Excluir   2-Editar   3-Voltar                                        ||\n");
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
	      }else if (escolha == '2'){
	        // ainda será organizado
	      }else if (escolha=='3'){
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