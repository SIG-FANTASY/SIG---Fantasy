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
		Cli* clit;
		char escolha;
		do {
			escolha = menuCliente();
			switch(escolha) {
				case '1': clit = cadastrarCliente();
					gravaClientes(clit);
				  	break;
				case '2':   listaCliente();
				  break;
        		case '3': clit = pesquisarCliente();
          			exibeCliente(clit);
          			break;
				} 		
		} while (escolha != '0');
		free(clit);
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
		printf("||                        |  2. Exibir Cliente               |                      ||\n");
		printf("||                        |  3. Pesquisar Cliente            |                      ||\n");
		printf("||                        |  0. Voltar                       |                      ||\n");
		printf("||                        |__________________________________|                      ||\n");
		printf("||                                                                                  ||\n");
		printf("||                                                                                  ||\n");
		printf("||                                                                                  ||\n");
		printf("||__________________________________________________________________________________||\n");
		printf("Digite a opcao desejada:");
		int valid;
	    do{
	      scanf("%c", &escolha);
	      getchar();
	      valid= validarEscolhas(escolha);
	    }while(valid==1);
		return escolha;
	}

	void listaCliente(void)
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
    	FILE *fp;
	  	Cli* cli;
	  	cli = (Cli*) malloc(sizeof(Cli));
	  	fp = fopen("clientes.dat", "rb");
	  	if (fp == NULL) {
		    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		    printf("Não é possível continuar este programa...\n");
		    exit(1);
	  	}
		while(fread(cli, sizeof(Cli), 1, fp)) {
		    if (cli->status != 'x') {
		      exibeCliente(cli);
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
		sleep(5);
	}

	Cli* cadastrarCliente(void){
    char escolha;
    float aux;
		Cli *cli;
		cli = (Cli*) malloc(sizeof(Cli));
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
    printf("||           |  Código: (somente números):");
    while(aux != cli->cod || cli->cod == 0){
      scanf("%f", &aux);
      getchar();
      cli->cod = aux;
    }
    printf("Código: %d\n", cli->cod);
		printf("||           |  Nome (sem acento):");
	    do{
	      scanf("%[A-Z a-z 0-9]", cli->nome);
	      printf("Nome: %s \n", cli->nome);
			  getchar();
	    }while(validarLetras(cli->nome,tamanhoString(cli->nome))==1);

			printf("||           |  Idade:");
	    do{
	      scanf("%[0-9]", cli->idade);
	      printf("Idade: %s \n", cli->idade);
			  getchar();
	    }while(validarNumeros(cli->idade,tamanhoString(cli->idade))==1);

			printf("||           |  Email:");
	    do{
	      scanf("%[A-z a-z 0-9 @.-_]", cli->email);
	      printf("Email: %s \n", cli->email);
	      getchar();
	    }while(validarEmail(cli->email,tamanhoString(cli->email))==1);

			printf("||           |  Telefone:(sem tracos e pontos)");
	    do{
	      scanf("%[0-9]", cli->telefone);
	      printf("Telefone: %s \n\n\n", cli->telefone);
			getchar();
	    }while(validarNumeros(cli->telefone,tamanhoString(cli->telefone))==1);
	    cli->status='o';

			printf("||           |________________________________________________________|             ||\n");
			printf("||                                                                                  ||\n");
			printf("||           1-salvar   2-Voltar                                                    ||\n");
			printf("||                                                                                  ||\n");
			printf("||__________________________________________________________________________________||\n");
	    // int valid;
	    // do{
	    //   scanf("%c", &escolha);
	    //   getchar();
	    //   int esc= validarEscolhas(escolha);
	    //   if (esc==0){
	    //     if (escolha=='1'){
	    //       listaCliente();
	    //     }else if (escolha=='2'){
	    //       menuCliente();
	    //     }else{
	    //       valid=1;
	    //     }
	    //   }
	    // }while(valid==1);
	    return cli;
	}

	void exibeCliente(Cli* cl) {
		if ((cl == NULL) || (cl->status == 'x')) {
    		printf("\n= = = Cliente Inexistente = = =\n");
  		} else {
        printf("Código: %d\n", cl->cod);
  			printf("Nome: %s\n", cl->nome);
  			printf("Idade: %s\n", cl->idade);
  			printf("Email: %s\n", cl->email);
  			printf("Telefone: %s\n", cl->telefone);
        sleep(2);
  		}
	}

	void gravaClientes(Cli* cli) {
    FILE *fp;

    fp = fopen("clientes.dat","ab");
    fclose(fp);

    fp = fopen("clientes.dat","ab");
	  fwrite(cli, sizeof(Cli), 1, fp);
	  fclose(fp);
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
		int valid;
	    do{
	      scanf("%c", &escolha);
	      getchar();
	      int esc= validarEscolhas(escolha);
	      if (esc==0){
	        if (escolha=='1'){
	          cadastrarCliente();
	        }else if (escolha=='2'){
	          menuCliente();
	        }else{
	          valid=1;
	        }
	      }
	    }while(valid==1);
	}

	Cli* pesquisarCliente(void) {
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
		printf("||                      ====        Pesquisar Cliente        ====                   ||\n");
		printf("||                      =========================================                   ||\n");
		printf("||                                                                                  ||\n");
		printf("||            ________________________________________________________              ||\n");
	    FILE* fp;
	    Cli* cliente;
	    int codigo;
	    printf("\n = Buscar Cliente = \n"); 
	    printf("Informe o codigo: "); 
	    scanf("%d", &codigo);
	    cliente = (Cli*) malloc(sizeof(Cli));
	    fp = fopen("clientes.dat", "rb");
	    if (fp == NULL) {
	      printf("O programa não conseguiu encontrar o arquivo!\n");
	      exit(1);
	    }
	    while(!feof(fp)) {
	      fread(cliente, sizeof(Cli), 1, fp);
	      if ((cliente->cod == codigo) && (cliente->status != 'x')) {
	        fclose(fp);
	        return cliente;
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
