#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "cliente.h"
#include "validar.h"

	typedef struct cliente Cli; //STRUCT INSPIRADO POR @flgorgonio

	void moduloCliente(void)
	{
		char escolha;
		do {
			escolha = menuCliente();
			switch(escolha) {
				case '1': 	cadastroCli();
							break;
				case '2':   pesquisarCliente();
							break;
			} 		
		} while (escolha != '0');
	}

	/////////////////////////////////////////MENU CLIENTES//////////////////////////////////////////////////////////

	char menuCliente(void)
	{
		char escolha;
		system("clear||cls"); // Esta linha de código e suas semelhantes, desenvolvidas por @flgorgonio.
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
		printf("||                      ====          MENU CLIENTES          ====                   ||\n");
		printf("||                      =========================================                   ||\n");
		printf("||                                                                                  ||\n");
		printf("||                         __________________________________                       ||\n");
		printf("||                        |                                  |                      ||\n");
		printf("||                        |  1. Cadastrar Clientes           |                      ||\n");
		printf("||                        |  2. Pesquisar Cliente            |                      ||\n");
		printf("||                        |  0. Voltar                       |                      ||\n");
		printf("||                        |  Digite a opcao desejada:");
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

	void telaCliente(const Cli* cli)
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
		printf("||                      ====       Catalogo Clientes         ====                   ||\n");
		printf("||                      =========================================                   ||\n");
		printf("||                                                                                  ||\n");
		printf("||  _____________________________________                                           ||\n");
		printf("|| |                                     |                                          ||\n");
		printf("|| | NOME  %s                            |                                     ||\n", cli->nome);
		printf("|| | IDADE  %s                           |                                     ||\n", cli->idade);
		printf("|| | EMAIL  %s                           |                                     ||\n", cli->email);
		printf("|| | TELEFONE  %s                        |                                     ||\n", cli->telefone);
		printf("|| |                1-EDITAR  2-EXCLUIR  |                                         ||\n");
    	printf("|| |_____________________________________|                                          ||\n");
		printf("||                                                                                  ||\n");
		printf("||                                                                                  ||\n");
		printf("||                                                                                  ||\n");
		printf("||                                                                                  ||\n");
		printf("||__________________________________________________________________________________||\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("||                                                                                  ||\n");
		printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
		printf("||__________________________________________________________________________________||\n");
   		printf("3- Voltar");
    	int valid;
    	do{
	      scanf("%c", &escolha);
	      getchar();
	      int esc= validarEscolhas(escolha);
	      if (esc==0){
	        if (escolha=='1'){
	          editarCliente();         
	        }else if (escolha=='2'){
	          excluirCliente();
	        }else if (escolha=='3'){
	          menuCliente();
	        }else{
	          valid=1;
	        }
	      }
	    }while(valid==1);
		sleep(10);
	}

	void cadastroCli(void){
		Cli *cli;
		cli = cadastrarCliente();
    	free(cli);
	}

	Cli* cadastrarCliente(void){
    	char escolha;
		Cli *cli;
		cli = (Cli*) malloc(sizeof(Cli));

	    FILE* fp;
	    fp = fopen("cliente.txt","at");
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
		printf("||                      ====      Cadastrar Clientes         ====                   ||\n");
		printf("||                      =========================================                   ||\n");
		printf("||                                                                                  ||\n");
		printf("||            ________________________________________________________              ||\n");
		printf("||           |                                                        |             ||\n");
		printf("||           |  Nome (sem acento):");
	    do{
	      scanf("%[A-Z a-z 0-9]", cli->nome);
	      fprintf(fp,"Nome: %s \n", cli->nome);
			  getchar();
	    }while(validarLetras(cli->nome,tamanhoString(cli->nome))==1);

			printf("||           |  Idade:");
	    do{
	      scanf("%[A-Z a-z 0-9]", cli->idade);
	      fprintf(fp,"Idade: %s \n", cli->idade);
			  getchar();
	    }while(validarNumeros(cli->idade,tamanhoString(cli->idade))==1);

			printf("||           |  Email:");
	    do{
	      scanf("%[A-z a-z 0-9 @.-_]", cli->email);
	      fprintf(fp,"Email: %s \n", cli->email);
	      getchar();
	    }while(validarEmail(cli->email,tamanhoString(cli->email))==1);

			printf("||           |  Telefone:(sem tracos e pontos)");
	    do{
	      scanf("%[0-9]", cli->telefone);
	      fprintf(fp,"Telefone: %s \n\n\n", cli->telefone);
			getchar();
	    }while(validarNumeros(cli->telefone,tamanhoString(cli->telefone))==1);

			printf("||           |________________________________________________________|             ||\n");
			printf("||                                                                                  ||\n");
			printf("||           1-salvar   2-Voltar                                                 ||\n");
	    int valid;
	    fclose(fp);
	    do{
	      scanf("%c", &escolha);
	      getchar();
	      int esc= validarEscolhas(escolha);
	      if (esc==0){
	        if (escolha=='1'){
	          telaCliente(cli);
	        }else if (escolha=='2'){
	          menuCliente();
	        }else{
	          valid=1;
	        }
	      }
	    }while(valid==1);

			printf("||                                                                                  ||\n");
			printf("||__________________________________________________________________________________||\n");
			printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
			printf("||                                                                                  ||\n");
			printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
			printf("||__________________________________________________________________________________||\n");
	    return cli;
	}

	void editarCliente(void){
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
		printf("||                      ====         Editar Clientes         ====                   ||\n");
		printf("||                      =========================================                   ||\n");
		printf("||                                                                                  ||\n");
		printf("||            ________________________________________________________              ||\n");
		printf("||           |                                                        |             ||\n");
		printf("||           |  Nome:[_______________________]                        |             ||\n");
		printf("||           |  Idade:[_________________]                             |             ||\n");
		printf("||           |  Email  : [     ]                                      |             ||\n");
		printf("||           |  Telefone[     ]                                       |             ||\n");
		printf("||           |________________________________________________________|             ||\n");
		printf("||                                                                                  ||\n");
		printf("||           1-Salvar   2-Voltar                                                    ||\n");
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
	          cadastroCli();
	        }else if (escolha=='2'){
	          menuCliente();
	        }else{
	          valid=1;
	        }
	      }
	    }while(valid==1);
	}

	void pesquisarCliente(void) {
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
		printf("||                      ====      Pesquisar Clientes         ====                   ||\n");
		printf("||                      =========================================                   ||\n");
		printf("||                                                                                  ||\n");
		printf("||             Pesquisa:[Nome Cliente]                                              ||\n");
		printf("||            ________________________________________________________              ||\n");
		printf("||           |                                                        |             ||\n");
		printf("||           |  Nome:[_______________________]                        |             ||\n");
		printf("||           |  Idade: [_____]                                        |             ||\n");
		printf("||           |  Email:[_______]                                       |             ||\n");
		printf("||           |  Telefone:[_______]                                    |             ||\n");
		printf("||           |________________________________________________________|             ||\n");
		printf("||                                                                                  ||\n");
		printf("||           1-Exibir   2-Voltar                                                    ||\n");
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
	          //cadastroCli(); ainda será organizado
	        }else if (escolha=='2'){
	          menuCliente();
	        }else{
	          valid=1;
	        }
	      }
	    }while(valid==1);
	}


	void excluirCliente(void){
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
		printf("||                      ====            Clientes             ====                   ||\n");
		printf("||                      =========================================                   ||\n");
		printf("||                                                                                  ||\n");
		printf("||            ________________________________________________________              ||\n");
		printf("||           |                                                        |             ||\n");
		printf("||           |  Você realmente deseja excluir o cliente [nome]?       |             ||\n");
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
	          //cadastroCli(); ainda será organizado
	        }else if (escolha=='2'){
	          menuCliente();
	        }else{
	          valid=1;
	        }
	      }
	    }while(valid==1);
}
