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
      case '1':   fant=cadastrarFantasia();
                  gravaFantasia(fant);
        break;
      case '2': listaFantasia();
        break;
      case '3': fant=pesquisarFantasia();
        exibeFantasia(fant);
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
  printf("||                        |  0. Voltar                       |                      ||\n");
  printf("||                        |__________________________________|                      ||\n");
  printf("||                                                                                  ||\n");
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
          editarFantasia();
        }else if (escolha=='2'){
          excluirFantasia();
        }else if (escolha=='3'){
          menuFantasia();
        }else{
          valid=1;
        }
      }
  }while(valid==1);
    sleep(5);
}

Fan* cadastrarFantasia(void)
{
  char escolha;
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
    printf("Preço: %f \n\n\n", fan->preco);
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
    return fan;
}

  void exibeFantasia(Fan* fn) {
    if ((fn == NULL) || (fn->status == 'x')) {
        printf("\n= = = Fantasia Inexistente = = =\n");
      } else {
        printf("Codigo: %d\n", fn->cod);
        printf("Nome: %s\n", fn->nome);
        printf("Quantidade: %s\n", fn->quantidade);
        printf("Tamanho: %s\n", fn->tamanho);
        printf("Preco: %f\n\n\n", fn->preco);
        sleep(3);
      }
  }

  void gravaFantasia(Fan* fan) {
    FILE *fp;

    fp = fopen("fantasias.dat","ab");
    fclose(fp);

    fp = fopen("fantasias.dat","ab");
    fwrite(fan, sizeof(Fan), 1, fp);
    fclose(fp);
  }

void editarFantasia(void)
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
  printf("||                      ====         Editar Fantasia         ====                   ||\n");
  printf("||                      =========================================                   ||\n");
  printf("||                                                                                  ||\n");
  printf("||            ________________________________________________________              ||\n");
  printf("||           |                                                        |             ||\n");
  printf("||           |  Cód.Fantasia:[_______________]                        |             ||\n");
  printf("||           |  Nome:[_______________________]                        |             ||\n");
  printf("||           |  Tamanho: [opcao]                                      |             ||\n");
  printf("||           |  Preco:[_______]                                       |             ||\n");
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
          // ainda será organizado
        }else if (escolha=='2'){
          menuFantasia();
        }else{
          valid=1;
        }
      }
    }while(valid==1);
}

Fan* pesquisarFantasia(void)
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
        menuFantasia();
      }else{
        valid=1;
      }
    }
  }while(valid==1);
}


void excluirFantasia(void)
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
  printf("||                      ====            Fantasia             ====                   ||\n");
  printf("||                      =========================================                   ||\n");
  printf("||                                                                                  ||\n");
  printf("||            ________________________________________________________              ||\n");
  printf("||           |                                                        |             ||\n");
  printf("||           |  Você realmente deseja excluir essa fantasia?          |             ||\n");
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
          // ainda será organizado
        }else if (escolha=='2'){
          // ainda será organizado
        }else{
          valid=1;
        }
      }
    }while(valid==1);
}

