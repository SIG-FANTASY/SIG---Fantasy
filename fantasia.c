#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "fantasia.h"
#include "validar.h"

  typedef struct fantasia Fan; //STRUCT INSPIRADO POR @flgorgonio

  void moduloFantasia(void)
  {
    Fan* fant;
    Fan *lista;
    lista = NULL;
    char escolha;
    do {
      escolha = menuFantasia();
      switch(escolha) {
        case '1':   
          fant=cadastrarFantasia();
          gravaFantasia(fant);
          break;
        case '2': 
          listaFantasia();
          break;
        case '3': 
          fant=pesquisarFantasia();
          telaExibirFantasia(fant);
          break;
        case '4':
          fant = pesquisarFantasia();
                alterarFantasia(fant);
          break;
        case '5':
          fant=pesquisarFantasia();
          excluirFantasia(fant);
          break;
        case '6':
          relatorioFan(&lista);
          listaFan(lista);
          break;
      }     
    } while (escolha != '0');
  }

  ///////////////////////////////////////////////MENU FANTASIA///////////////////////////////////////////////////

  char menuFantasia(void)
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
    printf("||                      ====          MENU FANTASIA          ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||                         __________________________________                       ||\n");
    printf("||                        |                                  |                      ||\n");
    printf("||                        |  1. Cadastrar Fantasia           |                      ||\n");
    printf("||                        |  2. Exibir Fantasia              |                      ||\n");
    printf("||                        |  3. Pesquisar Fantasia           |                      ||\n");
    printf("||                        |  4. Atualizar Fantasia           |                      ||\n");
    printf("||                        |  5. Excluir Fantasia             |                      ||\n");
    printf("||                        |  6. Relatorio de Fantasias       |                      ||\n");
    printf("||                        |  0. Voltar                       |                      ||\n");
    printf("||                        |__________________________________|                      ||\n");
    printf("||                                                                                  ||\n");
    printf("||                                                                                  ||\n");
    printf("||__________________________________________________________________________________||\n");
    printf("'Digite a opcao desejada:'");
    int valid;
    do{
        scanf("%c", &escolha);
        getchar();
        valid= validarEscolhas(escolha);
    }while(valid==1);
    return escolha;
  }

  void listaFantasia()
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
    printf("||                      ====            Fantasia             ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    FILE *fp;
    Fan* fan;
    fan = (Fan*) malloc(sizeof(Fan));
    fp = fopen("fantasias.dat", "rb");
    if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar este programa...\n");
      exit(1);
    }
    while(fread(fan, sizeof(Fan), 1, fp)) {
      if (fan->status != 'x') {
        exibeFantasia(fan);
      }
    }
    fclose(fp);
    printf("||                                                                                  ||\n");
    printf("||                                                                                  ||\n");
    printf("||                                                                                  ||\n");
    printf("||__________________________________________________________________________________||\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	    getchar();
  }

  Fan* cadastrarFantasia(void)
  {
    float aux;
    Fan *fan;
    fan = (Fan*) malloc(sizeof(Fan));
    
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
    printf("||                      ====      Cadastrar Fantasia         ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||            ________________________________________________________              ||\n");
    printf("||           |                                                        |             ||\n");
    printf("||           |  Cód.Fantasia:");
    while(aux != fan->cod || fan->cod == 0){
      scanf("%f", &aux);
      getchar();
      fan->cod = aux;
    }
    printf("Cod: %d\n", fan->cod);

    printf("||           |  Nome:");
    do{
      scanf("%[A-Z a-z]", fan->nome);
      printf("Nome: %s\n", fan->nome);
      getchar();
    }while(validarLetras(fan->nome,tamanhoString(fan->nome))==1);

    printf("||           |  Quantidade:");
    do{
      scanf("%[A-Z a-z 0-9]", fan->quantidade);
      printf("Quantidade: %s\n", fan->quantidade);
      getchar();
    }while(validarNumeros(fan->quantidade,tamanhoString(fan->quantidade))==1);

    printf("||           |  Tamanho:");
    do{
      scanf("%[A-Z a-z]", fan->tamanho);
      printf("Tamanho: %s\n", fan->tamanho);
      getchar();
    }while(validarLetras(fan->tamanho,tamanhoString(fan->tamanho))==1);

    printf("||           |  Preco:(use ponto para separar o centavos Ex: 00.00)");
    scanf("%f", &fan->preco);
    printf("Preço: %f \n", fan->preco);
    getchar();

    fan->status='o';
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
    return fan;
    glFan(fan);
  }

  void telaExibirFantasia(Fan * fan){
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
    printf("||                      ====            FANTASIA             ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||            ________________________________________________________              ||\n");

    exibeFantasia(fan);

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

  void exibeFantasia(Fan* fn)
  {
    char escolha;
    if ((fn == NULL) || (fn->status == 'x')) {
      printf("\n= = = Fantasia Inexistente = = =\n");
      printf("1- Voltar");
      int valid;
      do{
        scanf("%c", &escolha);
        getchar();
        int esc= validarEscolhas(escolha);
        if (esc==0){
          if (escolha=='1'){
            menuFantasia();
          }else{
            valid=1;
          }
        }
      }while(valid==1);
    } else {
      printf("||  Codigo: %d\n", fn->cod);
      printf("||  Nome: %s\n", fn->nome);
      printf("||  Quantidade: %s\n", fn->quantidade);
      printf("||  Tamanho: %s\n", fn->tamanho);
      printf("||  Preco: %f\n\n", fn->preco);
    }
  }

  void gravaFantasia(Fan* fan)
  {
    FILE *fp;

    fp = fopen("fantasias.dat","ab");
    fclose(fp);

    fp = fopen("fantasias.dat","ab");
    fwrite(fan, sizeof(Fan), 1, fp);
    fclose(fp);
  }

  Fan* pesquisarFantasia(void)
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
    printf("||                      ====       Pesquisar Fantasia        ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||            ________________________________________________________              ||\n");
    FILE* fp;
    Fan* fantasia;
    int codigo;
    printf("\n = Buscar Fantasia = \n"); 
    printf("Informe o codigo: "); 
    scanf("%d", &codigo);
    getchar();
    fantasia = (Fan*) malloc(sizeof(Fan));
    fp = fopen("fantasias.dat", "rb");
    if (fp == NULL) {
      printf("O programa não conseguiu encontrar o arquivo!\n");
      exit(1);
    }
    while(!feof(fp)) {
      fread(fantasia, sizeof(Fan), 1, fp);
      if ((fantasia->cod == codigo) && (fantasia->status != 'x')) {
        fclose(fp);
        return fantasia;
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


  void excluirFantasia(Fan* fanLido)
  {
    system("clear||cls");
    FILE* fp;
    Fan* fanArq;
    int achou=0;
    if(fanLido==NULL){
      printf("A fantasia não existe\n");
    }else{
      fanArq=(Fan*) malloc(sizeof(Fan));
      fp=fopen("fantasias.dat","r+b");
      if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
      }
      while(!feof(fp)){
        fread(fanArq, sizeof(Fan), 1, fp);
        if((fanArq->cod==fanLido->cod)&&(fanArq->status != 'x')){
          fanArq->status='x';
          fseek(fp,-1*sizeof(Fan),SEEK_CUR);
          fwrite(fanArq,sizeof(Fan), 1, fp);
          printf("\nFantasia Excluida com Sucesso\n");
          sleep(2);
        }
      }
      if(!achou){
        printf("\n Fantasia não encontrada! \n");
      }
      fclose(fp);
    }
  }

Fan* alterarFantasia(Fan* fan){
    FILE* fp;
    Fan* fant;
    int achou = 0;
    char quantidade[101];
    char nome[101];
    float preco;
    char tamanho[5];

    if (fan == NULL){
        printf("Fantasia não existe");
    }else{
        fant = (Fan*)malloc(sizeof(Fan));
        fp = fopen("fantasias.dat", "r+b");
        if (fp == NULL){
            printf("Arquivo apresentou um erro no processo de gravacao");
            exit(1);
        }

        while (!feof(fp))
        {
            fread(fant, sizeof(Fan), 1, fp);
            if ((strcmp(fant->nome, fan->nome) == 0) && (fant->status) != 'x')
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
                printf("||                      ====     Atualizando Fantasias       ====                   ||\n");
                printf("||                      =========================================                   ||\n");
                printf("||                                                                                  ||\n");
                printf("||            ________________________________________________________              ||\n");
                printf("||           |                                                        |             ||\n");
                printf("||           |  Nome (sem acento):");

                scanf("%[A-Z a-z]", nome);
                printf("Nome: %s \n", nome);
                getchar();

                printf("||           |  Quantidade:");

                scanf("%[0-9]", quantidade);
                getchar();
                printf("Quantidade: %s \n", quantidade);

                printf("||           |  Tamanho:");

                scanf("%[A-Z a-z]", tamanho);
                printf("Tamanho: %s \n", tamanho);
                getchar();

                printf("||           |  Preco(ex.: 00.00): ");
                
                scanf("%f", &preco);
                printf("Preco: %f \n\n", preco);
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

                strcpy(fant->nome, nome);
                strcpy(fant->quantidade, quantidade);
                strcpy(fant->tamanho, tamanho);
                fant->preco= preco;

                fseek(fp, -1 * sizeof(Fan), SEEK_CUR);
                fwrite(fant, sizeof(Fan), 1, fp);
                fclose(fp);
                printf("||       ||               alteração feita com sucesso           ||           ||\n"); 
                return fant;
            }
        }
        if (!achou)
        {
            printf("Fantasia não encontrada");
        }
        fclose(fp);
    }
    return fant;
}

void relatorioFan(Fan **lista)
{
    FILE *fp;
    Fan *fn;
    
    
    *lista = NULL;
    fp = fopen("fantasias.dat","rb");
    if (fp == NULL)
    {
     printf("O programa não conseguiu abrir o arquivo! \n");
     exit(1);
    }
    else
    {
     fn = (Fan *) malloc(sizeof(Fan));
     while (fread(fn, sizeof(Fan), 1, fp))
     {
        if ((*lista == NULL) || (strcmp(fn->nome, (*lista)->nome) < 0)) {
          fn->prox = *lista;
          *lista = fn;
        } else  {
          Fan* ant = *lista;
          Fan* atu = (*lista)->prox;
          while ((atu != NULL) && (strcmp(atu->nome, fn->nome) < 0)) {
            ant = atu;
            atu = atu->prox;
          }
          ant->prox = fn;
          fn->prox = atu;
        }
        fn = (Fan *) malloc(sizeof(Fan));
     }
     free(fn);
     printf("Arquivo recuperado com sucesso! \n");
     fclose(fp);
    }    
}

void listaFan(Fan *aux)
{
  printf("\n\n");
  printf("****************************************\n");
  printf("*** Relatorio das Fantasias Cadastrados ***\n");
  printf("****************************************\n");
  printf("| Cod |\t| Nome |\t| Quantidade|\t| Tamanho|\t| Preço|\n");
  printf("\n");
  while (aux != NULL)
  {
      printf("%d\t\t\t",aux->cod);
      printf("%s\t\t\t",aux->nome);
      printf("%s\t\t\t",aux->quantidade);
      printf("%s\t\t\t",aux->tamanho);
      printf("%f\n",aux->preco);
      aux = aux->prox;
  }
  printf("\nFim da Lista! \n\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}

void glFan(Fan *lista)
{
    FILE *fp;
    
    fp = fopen("Fanentes.dat","wb");
    if (fp == NULL)
    {
     printf("Erro na abertura do arquivo... \n");
     exit(1);
    }
    else
    {
     while (lista != NULL)
     {
       fwrite(lista, sizeof(Fan), 1, fp);
       lista = lista->prox;
     }
     printf("Arquivo gravado com sucesso! \n");
     fclose(fp);
    }
}