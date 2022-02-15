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
          exibeFantasia(fant);
          break;
        case '4':
          atualizarFantasia();
          break;
         case '5':
          fant=pesquisarFantasia();
          excluirFantasia(fant);
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
      sleep(2);
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

  void atualizarFantasia(void) {
    Fan* fan;
  int* cod;
  char* quantidade;
  char* nome;
  float* preco;
  char* tamanho;

  quantidade = malloc(101 * sizeof(char));
  nome = malloc(101 * sizeof(char));
  tamanho = malloc(5 * sizeof(char));

    fan = pesquisarFantasia();

    if (fan == NULL) {
        printf("Cliente não encontrado");// relativo a inexistencia do cliente;
    } else {
        fan = telaAtualizarFantasia();
        nome = fan->nome;
        quantidade = fan->quantidade;
        preco = &fan->preco;
        tamanho = fan->tamanho;
        regravarFantasia(fan);
        exibeFantasia(fan);
      free(fan);
    }
}

Fan* telaAtualizarFantasia(void) {
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
    printf("||                      ====      Atualizar Fantasia         ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||            ________________________________________________________              ||\n");
    printf("||           |                                                        |             ||\n");
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
    printf("||           |________________________________________________________|             ||\n");
    printf("||                                                                                  ||\n");       
    printf("||__________________________________________________________________________________||\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return fan;
}

void regravarFantasia(Fan* fan) {
    FILE* fp;
    Fan* fant;

    fant = (Fan*) malloc(sizeof(Fan));
    fp = fopen("fantasias.dat", "r+b");
    if (fp == NULL) {
        printf("Erro! O sistema não  conseguiu encontrar o arquivo\n!"); 
        exit(1);
    }
    while(fread(fant, sizeof(Fan), 1, fp)) {
        if (fant->cod==fan->cod) {
            fseek(fp, -1*sizeof(Fan), SEEK_CUR);
            fwrite(fan, sizeof(Fan), 1, fp);
            fclose(fp);       
        }
    }
    fclose(fp);
    free(fant);
}