#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "cliente.h"
#include "validar.h"

typedef struct cliente Cli; //STRUCT INSPIRADO POR @flgorgonio


void moduloCliente(void){
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
				telaExibirCliente(clit);
				break;
			case '4':
				clit = pesquisarCliente();
				alterarCliente(clit);
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

char menuCliente(void){
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

void listaCliente(void){
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

Cli* cadastrarCliente(void){
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
	scanf("%d", &cli->cod);
	getchar();
	printf("Código: %d\n", cli->cod);

	do{
		printf("||           |  Nome (sem acento):");
		scanf("%[A-Z a-z 0-9]", cli->nome);
		printf("Nome: %s \n", cli->nome);
		getchar();
	}while(validarLetras(cli->nome,tamanhoString(cli->nome))==1);


	do{
		printf("||           |  Idade:");
		scanf("%[0-9]", cli->idade);
		printf("Idade: %s \n", cli->idade);
		getchar();
	}while(validarNumeros(cli->idade,tamanhoString(cli->idade))==1);

	do{
		printf("||           |  Email:");
		scanf("%[A-z a-z 0-9 @.-_]", cli->email);
		printf("Email: %s \n", cli->email);
		getchar();
	}while(validarEmail(cli->email,tamanhoString(cli->email))==1);

	do{
		printf("||           |  Telefone:(sem tracos e pontos)");
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
}

void exibeCliente(Cli* cl){
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
	}else{
		printf("\n");
		printf("||  Código: %d\n", cl->cod);
		printf("||  Nome: %s\n", cl->nome);
		printf("||  Idade: %s\n", cl->idade);
		printf("||  Email: %s\n", cl->email);
		printf("||  Telefone: %s\n\n", cl->telefone);
	}
}

void gravaClientes(Cli* cli){
	FILE *fp;

	fp = fopen("clientes.dat","ab");
	fclose(fp);

	fp = fopen("clientes.dat","ab");
	fwrite(cli, sizeof(Cli), 1, fp);
	fclose(fp);
}

Cli* pesquisarCliente(void){ // inspirado por @flgorgonio
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

void telaExibirCliente(Cli * cli){
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
	printf("||                      ====             CLIENTE             ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||            ________________________________________________________              ||\n");

	exibeCliente(cli);

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



void excluirCliente(Cli* cliLido){
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
				sleep(2);
			}
		}
		if(!achou){
			printf("\n Cliente não encontrado! \n");
		}
		fclose(fp);
	}
}

Cli* alterarCliente(Cli* cli){
	FILE* fp;
	Cli* clit;
	int achou = 0;
	char nome[101];
	char email[51];
	char idade[4];
	char telefone[14];

	if (cli == NULL){
		printf("Cliente não existe");
	}else{
		clit = (Cli *)malloc(sizeof(Cli));
		fp = fopen("clientes.dat", "r+b");
		if (fp == NULL){
			printf("Arquivo apresentou um erro no processo de gravacao");
			exit(1);
		}

		while (!feof(fp))
		{
			fread(clit, sizeof(Cli), 1, fp);
			if ((strcmp(clit->nome, cli->nome) == 0) && (clit->status) != 'x')
			{
				achou = 1;

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
				printf("||                      ====      Atualizando Cliente        ====                   ||\n");
				printf("||                      =========================================                   ||\n");
				printf("||                                                                                  ||\n");
				printf("||            ________________________________________________________              ||\n");
				printf("||           |                                                        |             ||\n");
				printf("||           |  Nome (sem acento):");

				scanf("%30[^\n]", nome);
				printf("Nome: %s \n", nome);
				getchar();

				printf("||           |  Idade:");

				scanf("%[0-9]", idade);
				getchar();
				printf("Idade: %s \n", idade);

				printf("||           |  Email:");

				scanf("%20[^\n]", email);
				printf("Email: %s \n", email);
				getchar();

				printf("||           |  Telefone:(sem tracos e pontos)");

				scanf("%[0-9]", telefone);
				printf("Telefone: %s \n\n", telefone);
				getchar();

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

				strcpy(clit->nome, nome);
				strcpy(clit->idade, idade);
				strcpy(clit->email, email);
				strcpy(clit->telefone, telefone);

				fseek(fp, -1 * sizeof(Cli), SEEK_CUR);
				fwrite(clit, sizeof(Cli), 1, fp);
				fclose(fp);
				printf("||       ||               alteração feita com sucesso           ||           ||\n"); 
				return clit;
			}
		}
		if (!achou)
		{
			printf("Cliente não encontrado");
		}
		fclose(fp);
	}
	return clit;
}

void relatorioCli(Cli **lista)
{ // inspirado por @flgorgonio
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
{ // inspirado por @flgorgonio
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