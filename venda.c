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
	    Ven *lista;
	    lista = NULL;

		char escolha;
		do {
			escolha = menuVenda();
			switch(escolha) {
				case '1': 
	        		vn=cadastrarVenda();
					gravaVendas(vn);
					break;
				case '2': 
	        		listaVenda();
					break;
				case '3': 
	        		vn=pesquisarVendas();
					exibeVenda(vn);
					break;
				case '4':
			        atualizarVenda();
			        break;
			    case '5':
			        vn=pesquisarVendas();
			        excluirVenda(vn);
			        break;
			    case '6':
			    	relatorioVen(&lista);
		          	listaVen(lista);
		          	break;
			} 		
		} while (escolha != '0');  
	}

	///////////////////////////////////////////////MENU VENDAS///////////////////////////////////////////////////

	char menuVenda(void){
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
		printf("||                        |  4. Alterar Vendas               |                      ||\n");
	    printf("||                        |  5. Excluir Vendas               |                      ||\n");
		printf("||                        |  6. Relatorio de Vendas          |                      ||\n");
		printf("||                        |  0. Voltar                       |                      ||\n");
		printf("||                        |__________________________________|                      ||\n");
		printf("||                                                                                  ||\n");
		printf("||                                                                                  ||\n");
		printf("||__________________________________________________________________________________||\n");
		printf("||	Digite a opcao desejada: ");
		int valid;
	    do{
	    	scanf("%c", &escolha);
	    	getchar();
	    	valid= validarEscolhas(escolha);
	    }while(valid==1);
		return escolha;
	}

	void listaVenda(void)
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
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    	getchar();
	}

	Ven* cadastrarVenda(void)
	{
	  float aux;
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
		while(aux != ven->cod || ven->cod == 0){
		    scanf("%f", &aux);
		    getchar();
		    ven->cod = aux;
		}
		printf("Código: %d\n", ven->cod);

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

		printf("||           |  Aluguel (dias):");
		aux = 0;
	    while(aux != ven->aluguel || ven->aluguel == 0){
	    	scanf("%f", &aux);
	    	getchar();
	    	ven->aluguel = aux;
	    }
        printf("Aluguel: %d\n", ven->aluguel);
		  
        printf("||           |  Total (use ponto para separar o centavos Ex: 00.00):\n");
	    scanf("%f", &ven->valor);
	    printf("Preço: %f \n", ven->valor);
	  	getchar();
		printf("||           |________________________________________________________|             ||\n");
		printf("||                                                                                  ||\n");
		printf("||                                                                                  ||\n");
		printf("||__________________________________________________________________________________||\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    	getchar();
	 	return ven;
	 	glVen(ven);
	}

	void exibeVenda(Ven* ven) {
	  char escolha;
		if ((ven == NULL) || (ven->status == 'x')) {
	    	printf("\n= = = Venda Inexistente = = =\n");
	    	int valid;
	    	do{
	        	scanf("%c", &escolha);
	        	getchar();
	        	int esc= validarEscolhas(escolha);
	        	if (esc==0){
	          		if (escolha=='1'){
	            		menuVenda();
	          		}else{
	            		valid=1;
	          		}
	        	}
	  		}while(valid==1);
	  	}else {
	    	printf("||  Código: %d\n", ven->cod);
	  		printf("||  Cliente: %s\n", ven->cliente);
	  		printf("||  Data: %d/%d/%d\n", ven->dia,ven->mes,ven->ano);
	  		printf("||  Aluguel: %d\n", ven->aluguel);
	  		printf("||  Total: %2.f\n", ven->valor);
	    	sleep(2);
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
		int codigo;
		printf("\n = Buscar Vendas = \n"); 
		printf("Informe o codigo: "); 
		scanf("%d", &codigo);
		getchar();
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
		printf("||                                                                                  ||\n");
		printf("||__________________________________________________________________________________||\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	    getchar();

	}

	void excluirVenda(Ven* venLido) {
	  FILE* fp;
	  Ven* venArq;
	  int achou = 0;
	  if (venLido == NULL) {
	    printf("Ops! O aluno informado não existe!\n");
	  }
	  else {
	    venArq = (Ven*) malloc(sizeof(Ven));
	    fp = fopen("venda.dat", "r+b");
	    if (fp == NULL) {
	      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
	      printf("Não é possível continuar este programa...\n");
	      exit(1);
	    }
	    while(!feof(fp)) {
	      fread(venArq, sizeof(Ven), 1, fp);
	      if ((venArq->cod == venLido->cod) && (venArq->status != 'x')) {
	        achou = 1;
	        venArq->status = 'x';
	        fseek(fp, -1*sizeof(Ven), SEEK_CUR);
	        fwrite(venArq, sizeof(Ven), 1, fp);
	        printf("\nVenda excluída com sucesso!!!\n");
	        sleep(2);
	      }
	    }
	    if (!achou) {
	      printf("\nVenda não encontrada!\n");
	    }
	    fclose(fp);
	  }
	}

	void atualizarVenda(void) {
	    Ven* ven;
	    int* cod;
	    char* cliente;
  		int* dia;
  		int* mes;
  		int* ano;
  		int* aluguel;
  		float* valor;

	  	cliente= malloc(15 * sizeof(char));

	    ven = pesquisarVendas();

	    if (ven == NULL) {
	        printf("Venda inexistente");
	    } else {
	        ven = telaAtualizarVenda();
	        cliente = ven->cliente;
	        dia = &ven->dia;
	        mes = &ven->mes;
	        ano = &ven->ano;
	        aluguel = &ven->aluguel;
	        valor = &ven->valor;
	        regravarVenda(ven);
	        exibeVenda(ven);
        free(ven);
	    }
	}

	Ven* telaAtualizarVenda(void) {
    float aux;
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
	    printf("||                      ====      Atualizar Vendas           ====                   ||\n");
	    printf("||                      =========================================                   ||\n");
	    printf("||                                                                                  ||\n");
	    printf("||            ________________________________________________________              ||\n");
	    printf("||           |                                                        |             ||\n");
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

		printf("||           |  Aluguel (dias):");
		aux = 0;
	    while(aux != ven->aluguel || ven->aluguel == 0){
	    	scanf("%f", &aux);
	    	getchar();
	    	ven->aluguel = aux;
	    }
        printf("Aluguel: %d\n", ven->aluguel);
		  
        printf("||           |  Total (use ponto para separar o centavos Ex: 00.00):\n");
	    scanf("%f", &ven->valor);
	    printf("Preço: %f \n", ven->valor);
	  	getchar();
	    printf("||           |________________________________________________________|             ||\n");
	    printf("||                                                                                  ||\n");
	    printf("||                                                                                  ||\n");
	    printf("||__________________________________________________________________________________||\n");
	    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	    getchar();
	    return ven;
	}

	void regravarVenda(Ven* ven) {
	    FILE* fp;
	    Ven* vend;

	    vend = (Ven*) malloc(sizeof(Ven));
	    fp = fopen("venda.dat", "r+b");
	    if (fp == NULL) {
	        printf("Erro! O sistema não  conseguiu encontrar o arquivo\n!"); 
	        exit(1);
	    }
	    while(fread(vend, sizeof(Ven), 1, fp)) {
	        if (vend->cod==ven->cod) {
	            fseek(fp, -1*sizeof(Ven), SEEK_CUR);
	            fwrite(ven, sizeof(Ven), 1, fp);
	            fclose(fp);       
	        }
	    }
	    fclose(fp);
	    free(vend);
	}

	void relatorioVen(Ven **lista)
	{
	    FILE *fp;
	    Ven *vn;
	    
	    
	    *lista = NULL;
	    fp = fopen("venda.dat","rb");
	    if (fp == NULL)
	    {
	   	 printf("O programa não conseguiu abrir o arquivo! \n");
	   	 exit(1);
	    }
	    else
	    {
	   	 vn = (Ven *) malloc(sizeof(Ven));
	   	 while (fread(vn, sizeof(Ven), 1, fp))
	   	 {
	        if ((*lista == NULL) || (strcmp(vn->cliente, (*lista)->cliente) < 0)) {
	          vn->prox = *lista;
	          *lista = vn;
	        } else  {
	          Ven* ant = *lista;
	          Ven* atu = (*lista)->prox;
	          while ((atu != NULL) && (strcmp(atu->cliente, vn->cliente) < 0)) {
	            ant = atu;
	            atu = atu->prox;
	          }
	          ant->prox = vn;
	          vn->prox = atu;
	        }
	        vn = (Ven *) malloc(sizeof(Ven));
	   	 }
	   	 free(vn);
	   	 printf("Arquivo recuperado com sucesso! \n");
	   	 fclose(fp);
	    }    
	}

	void listaVen(Ven *aux)
	{
	  printf("\n\n");
	  printf("****************************************\n");
		printf("*** Relatorio dos Venentes Cadastrados ***\n");
	  printf("****************************************\n");
		printf("| Cod |\t| Cliente |\t| Data|\t| Aluguel|\t| Valor|\n");
	  printf("\n");
		while (aux != NULL)
		{
	    	printf("%d\t\t\t",aux->cod);
	    	printf("%s\t\t\t",aux->cliente);
	    	printf("%d/%d/%d\t\t\t",aux->dia,aux->mes,aux->ano);
	    	printf("%d\t\t\t",aux->aluguel);
	    	printf("%f\n",aux->valor);
	    	aux = aux->prox;
		}
		printf("\nFim da Lista! \n\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	}

	void glVen(Ven *lista)
	{
	    FILE *fp;
	    
	    fp = fopen("venda.dat","wb");
	    if (fp == NULL)
	    {
	   	 printf("Erro na abertura do arquivo... \n");
	   	 exit(1);
	    }
	    else
	    {
	   	 while (lista != NULL)
	   	 {
	   		 fwrite(lista, sizeof(Ven), 1, fp);
	   		 lista = lista->prox;
	   	 }
	   	 printf("Arquivo gravado com sucesso! \n");
	   	 fclose(fp);
	    }
	}