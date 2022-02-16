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
	    Cli *lista;
	    lista = NULL;
		char escolha;
		do {
			escolha = menuCliente();
			switch(escolha) {
				case '1': 
          			clit = cadastrarCliente();
					gravaClientes(clit);
				  	break;
				case '2':   
          			listaCliente();
				  	break;
        		case '3': 
		          clit = pesquisarCliente();
		          exibeCliente(clit);
		          break;
        		case '4':
		          atualizarCliente();
		          break; 
        		case '5':
		          clit = pesquisarCliente();
		          excluirCliente(clit);
		          break;
        		case '6':
		          relatorioCli(&lista);
		          listaCli(lista);
		          break;
      		}	
		} while (escolha != '0' );
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
    	printf("||                        |  4. Atualizar Cliente            |                      ||\n");
		printf("||                        |  5. Excluir Cliente              |                      ||\n");
		printf("||                        |  6. Relatório Cliente            |                      ||\n");
		printf("||                        |  0. Voltar                       |                      ||\n");
		printf("||                        |__________________________________|                      ||\n");
		printf("||                                                                                  ||\n");
		printf("||                                                                                  ||\n");
		printf("||__________________________________________________________________________________||\n");
		int valid;
	  	do{
      		printf("||	Digite a opcao desejada: ");
	    	scanf("%c", &escolha);
	    	getchar();
	    	valid= validarEscolhas(escolha);
	  	}while(valid==1);
		return escolha;
	}

	void listaCliente(void)
	{
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
	  	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    	getchar();
	}

	Cli* cadastrarCliente(void)
	{
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
      printf("Telefone: %s \n\n", cli->telefone);
			getchar();
	  }while(validarNumeros(cli->telefone,tamanhoString(cli->telefone))==1);
    cli->status='o';
		printf("||           |________________________________________________________|             ||\n");
		printf("||                                                                                  ||\n");
		printf("||                                                                                  ||\n");
		printf("||__________________________________________________________________________________||\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("||                                                                                  ||\n");
		printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
		printf("||__________________________________________________________________________________||\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    	getchar();
	  	return cli;
	  	glCli(cli);
	}

	void exibeCliente(Cli* cl)
	{
		char escolha;
		if ((cl == NULL) || (cl->status == 'x')) {
    		printf("\n= = = Cliente Inexistente = = =\n");
      		printf("1- Voltar");
      		int valid;
      		do{
        		scanf("%c", &escolha);
        		getchar();
        		int esc= validarEscolhas(escolha);
        		if (esc==0){
          			if (escolha=='1'){
            			menuCliente();
          			}else{
            			valid=1;
          			}
        		}
      		}while(valid==1);
  		} else {
	      	printf("\n");
	      	printf("||  Código: %d\n", cl->cod);
	  		printf("||  Nome: %s\n", cl->nome);
	  		printf("||  Idade: %s\n", cl->idade);
	  		printf("||  Email: %s\n", cl->email);
	  		printf("||  Telefone: %s\n\n", cl->telefone);
  		}
  		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    	getchar();
	}

	void gravaClientes(Cli* cli)
	{
    FILE *fp;

    fp = fopen("clientes.dat","ab");
    fclose(fp);

    fp = fopen("clientes.dat","ab");
	  fwrite(cli, sizeof(Cli), 1, fp);
	  fclose(fp);
	}

	Cli* pesquisarCliente(void) 
	{
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
    getchar();
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
	  printf("||                                                                                  ||\n");
	  printf("||__________________________________________________________________________________||\n");
	  printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	  printf("||                                                                                  ||\n");
	  printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	  printf("||__________________________________________________________________________________||\n");
	  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }




	void excluirCliente(Cli* cliLido)
	{
		system("clear||cls");
    FILE* fp;
    Cli* cliArq;
    int achou=0;
    if(cliLido==NULL){
      printf("Cliente não existe\n");
    }else{
      cliArq=(Cli*) malloc(sizeof(Cli));
      fp=fopen("clientes.dat","r+b");
      if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
      }
      while(!feof(fp)){
        fread(cliArq, sizeof(Cli), 1, fp);
        if((cliArq->cod==cliLido->cod)&&(cliArq->status != 'x')){
          cliArq->status='x';
          fseek(fp,-1*sizeof(Cli),SEEK_CUR);
          fwrite(cliArq,sizeof(Cli), 1, fp);
          printf("\nCliente Excluido com Sucesso\n");
          sleep(3);
        }
      }
      if(!achou){
        printf("\n Cliente não encontrado! \n");
      }
      fclose(fp);
    }
	}

void atualizarCliente(void) {
    Cli* cli;
    int* cod;
    char *nome;
    char* email;
    char* idade;
    char* telefone;
  
    nome = malloc(101 * sizeof(char));
    email = malloc(51 * sizeof(char));
    idade = malloc(4 * sizeof(char));
    telefone = malloc(14 * sizeof(char));

    cli = pesquisarCliente();

    if (cli == NULL) {
        printf("Cliente não encontrado");// relativo a inexistencia do cliente;
    } else {
        cli = telaAtualizarCliente();
        nome = cli->nome;
        email = cli->email;
        idade = cli->idade;
        telefone = cli->telefone;
        regravarCliente(cli);
        exibeCliente(cli);
      free(cli);
    }
}

Cli* telaAtualizarCliente(void) {
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
    printf("||                      ====      Atualizar Clientes         ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||            ________________________________________________________              ||\n");
    printf("||           |                                                        |             ||\n");
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
      printf("Telefone: %s \n\n", cli->telefone);
            getchar();
      }while(validarNumeros(cli->telefone,tamanhoString(cli->telefone))==1);
    cli->status='o';
    printf("||           |________________________________________________________|             ||\n");
    printf("||                                                                                  ||\n");
    printf("||                                                                                  ||\n");
    printf("||__________________________________________________________________________________||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||                                                                                  ||\n");
    printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");       printf("||__________________________________________________________________________________||\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cli;
}

void regravarCliente(Cli* cli) {
    FILE* fp;
    Cli* clit;

    clit = (Cli*) malloc(sizeof(Cli));
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        printf("Erro! O sistema não  conseguiu encontrar o arquivo\n!"); 
        exit(1);
    }
    while(fread(clit, sizeof(Cli), 1, fp)) {
        if (clit->cod==cli->cod) {
            fseek(fp, -1*sizeof(Cli), SEEK_CUR);
            fwrite(cli, sizeof(Cli), 1, fp);
            fclose(fp);       
        }
    }
    fclose(fp);
    free(clit);
}

void relatorioCli(Cli **lista)
{
    FILE *fp;
    Cli *cl;
    
    
    *lista = NULL;
    fp = fopen("clientes.dat","rb");
    if (fp == NULL)
    {
   	 printf("O programa não conseguiu abrir o arquivo! \n");
   	 exit(1);
    }
    else
    {
   	 cl = (Cli *) malloc(sizeof(Cli));
   	 while (fread(cl, sizeof(Cli), 1, fp))
   	 {
        if ((*lista == NULL) || (strcmp(cl->nome, (*lista)->nome) < 0)) {
          cl->prox = *lista;
          *lista = cl;
        } else  {
          Cli* ant = *lista;
          Cli* atu = (*lista)->prox;
          while ((atu != NULL) && (strcmp(atu->nome, cl->nome) < 0)) {
            ant = atu;
            atu = atu->prox;
          }
          ant->prox = cl;
          cl->prox = atu;
        }
        cl = (Cli *) malloc(sizeof(Cli));
   	 }
   	 free(cl);
   	 printf("Arquivo recuperado com sucesso! \n");
   	 fclose(fp);
    }    
}

void listaCli(Cli *aux)
{
  printf("\n\n");
  printf("****************************************\n");
	printf("*** Relatorio dos Clientes Cadastrados ***\n");
  printf("****************************************\n");
	printf("| Cod |\t| Nome |\t| E-mail|\t| Idade|\t| Telefone|\n");
  printf("\n");
	while (aux != NULL)
	{
    	printf("%d\t\t\t",aux->cod);
    	printf("%s\t\t\t",aux->nome);
    	printf("%s\t\t\t",aux->email);
    	printf("%s\t\t\t",aux->idade);
    	printf("%s\n",aux->telefone);
    	aux = aux->prox;
	}
	printf("\nFim da Lista! \n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void glCli(Cli *lista)
{
    FILE *fp;
    
    fp = fopen("clientes.dat","wb");
    if (fp == NULL)
    {
   	 printf("Erro na abertura do arquivo... \n");
   	 exit(1);
    }
    else
    {
   	 while (lista != NULL)
   	 {
   		 fwrite(lista, sizeof(Cli), 1, fp);
   		 lista = lista->prox;
   	 }
   	 printf("Arquivo gravado com sucesso! \n");
   	 fclose(fp);
    }
}