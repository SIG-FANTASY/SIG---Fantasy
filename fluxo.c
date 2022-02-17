#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "fluxo.h"
#include "validar.h"

typedef struct fluxo Flu; //STRUCT INSPIRADO POR @flgorgonio

void moduloFluxo(void)
{
    Flu* flux;
    Flu *lista;
    lista = NULL;
    char escolha;
    do {
        escolha = menuFluxo();
        switch(escolha) {
            case '1':   flux=cadastrarGasto();
                gravaGasto(flux);
                break;
            case '2': listaFluxo();
                break;
            case '3': flux=pesquisarFluxo();
                telaExibirFluxo(flux);
                break;
            case '4':
                relatorioFlu(&lista);
                listaFlu(lista);
                break;
        }     
    } while (escolha != '0'); 
    free(flux);
}

  //////////////////////////////////////////////MENU FLUXO///////////////////////////////////////////////////

char menuFluxo(void)
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
    printf("||                      ====         Fluxo Financeiro         ===                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||                         __________________________________                       ||\n");
    printf("||                        |                                  |                      ||\n");
    printf("||                        |  1. Cadastrar Gastos             |                      ||\n");
    printf("||                        |  2. Exibir Gastos                |                      ||\n");
    printf("||                        |  3. Pesquisar Gastos             |                      ||\n");
    printf("||                        |  4. Relatorio de Gastos          |                      ||\n");
    printf("||                        |  0. Voltar                       |                      ||\n");
    printf("||                        |__________________________________|                      ||\n");
    printf("||                                                                                  ||\n");
    printf("||                                                                                  ||\n");
    printf("||__________________________________________________________________________________||\n");
    printf("'Digite a opção desejada:'");
    int valid;
    do{
        scanf("%c", &escolha);
        getchar();
        valid= validarEscolhas(escolha);
    }while(valid==1);
    return escolha;
}

void listaFluxo()
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
    printf("||                      ====         Fluxo Financeiro         ===                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||      __________________________________________________________________          ||\n");
    FILE *fp;
    Flu* flu;
    flu = (Flu*) malloc(sizeof(Flu));
    fp = fopen("fluxo.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(fread(flu, sizeof(Flu), 1, fp)) {
        if (flu->status != 'x') {
            exibeFluxo(flu);
        }
    }
    fclose(fp);    
    printf("||     |                                                                  |         ||\n");
    printf("||     |                                                                  |         ||\n");
    printf("||     |__________________________________________________________________|         ||\n");
    printf("||                                                                                  ||\n");
    printf("||                                                                                  ||\n");
    printf("||__________________________________________________________________________________||\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


Flu* cadastrarGasto(void)
{
    float aux;
    Flu *flu;
    flu = (Flu*) malloc(sizeof(Flu));
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
    printf("||                      ====        Cadastrar Gastos         ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||            ________________________________________________________              ||\n");
    printf("||           |                                                        |             ||\n");
    printf("||           |  Código (apenas números):");
    while(aux != flu->cod || flu->cod == 0){
        scanf("%f", &aux);
        getchar();
        flu->cod = aux;
    }
    printf("Código: %d\n", flu->cod);

    printf("||           |  Motivo:");
    do{
        scanf("%[A-Z a-z 0-9]", flu->motivo);
        printf("Motivo: %s\n", flu->motivo);
        getchar();
    }while(validarLetras(flu->motivo,tamanhoString(flu->motivo))==1);

    printf("||           |  Data (DD MM AA):");
    do{
        scanf("%d %d %d", &flu->dia, &flu->mes, &flu->ano);
        printf("Data: %d/%d/%d\n", flu->dia, flu->mes, flu->ano);
        getchar();
    }while(validarData(flu->dia, flu->mes, flu->ano)==1);

    printf("||           |  Valor:");
    scanf("%f", &flu->valor);
    printf("Valor: %f\n", flu->valor);
    getchar();
    printf("||           |  Responsável:");
    do{
        scanf("%[A-Z a-z 0-9]", flu->responsavel);
        printf("Responsável: %s\n", flu->responsavel);
        getchar();
    }while(validarLetras(flu->responsavel,tamanhoString(flu->responsavel))==1);
    flu->status='o';
    printf("||           |________________________________________________________|             ||\n");
    printf("||                                                                                  ||\n");
    printf("||__________________________________________________________________________________||\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return flu;
}

void exibeFluxo(Flu* fl)
{
    if ((fl == NULL) || (fl->status == 'x')) {
        printf("\n= = = Gasto Inexistente = = =\n");  
    } else {
        printf("||  Código: %d\n", fl->cod);
        printf("||  Motivo: %s\n", fl->motivo);
        printf("||  Data: %d/%d/%d\n", fl->dia, fl->mes, fl->ano);
        printf("||  Valor: %f\n", fl->valor);
        printf("||  Responsável: %s\n\n\n", fl->responsavel);
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void gravaGasto(Flu* flu)
{
    FILE *fp;

    fp = fopen("fluxo.dat","ab");
    fclose(fp);

    fp = fopen("fluxo.dat","ab");
    fwrite(flu, sizeof(Flu), 1, fp);
    fclose(fp);
}


Flu* pesquisarFluxo(void)
{ // inspirado por @flgorgonio
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
    printf("||                      ====      Pesquisar fluxo            ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||            ________________________________________________________              ||\n");
    FILE* fp;
    Flu* fluxo;
    int codigo;
    printf("\n = Buscar Gastos = \n"); 
    printf("Informe o codigo: "); 
    scanf("%d", &codigo);
    fluxo = (Flu*) malloc(sizeof(Flu));
    fp = fopen("fluxo.dat", "rb");
    if (fp == NULL) {
        printf("O programa não conseguiu encontrar o arquivo!\n");
        exit(1);
    } 
    while(!feof(fp)) {
        fread(fluxo, sizeof(Flu), 1, fp);
        if ((fluxo->cod == codigo) && (fluxo->status != 'x')) {
            fclose(fp);
            return fluxo;
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

void telaExibirFluxo(Flu * flu){
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
    printf("||                      ====            FLUXO                ====                   ||\n");
    printf("||                      =========================================                   ||\n");
    printf("||                                                                                  ||\n");
    printf("||            ________________________________________________________              ||\n");

    exibeFluxo(flu);

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

void relatorioFlu(Flu **lista)
{ // inspirado por @flgorgonio
    FILE *fp;
    Flu *fl;


    *lista = NULL;
    fp = fopen("fluxo.dat","rb");
    if (fp == NULL)
    {
       printf("O programa não conseguiu abrir o arquivo! \n");
       exit(1);
    }
    else
    {
        fl = (Flu *) malloc(sizeof(Flu));
        while (fread(fl, sizeof(Flu), 1, fp))
        {
            if ((*lista == NULL) || (strcmp(fl->responsavel, (*lista)->responsavel) < 0)) {
                fl->prox = *lista;
                *lista = fl;
            } else  {
                Flu* ant = *lista;
                Flu* atu = (*lista)->prox;
                while ((atu != NULL) && (strcmp(atu->responsavel, fl->responsavel) < 0)) {
                    ant = atu;
                    atu = atu->prox;
                }
                ant->prox = fl;
                fl->prox = atu;
            }
            fl = (Flu *) malloc(sizeof(Flu));
        }
        free(fl);
        printf("Arquivo recuperado com sucesso! \n");
        fclose(fp);
    }    
}

void listaFlu(Flu *aux)
{ // inspirado por @flgorgonio
    printf("\n\n");
    printf("****************************************\n");
    printf("*** Relatorio dos Gastos Cadastrados ***\n");
    printf("****************************************\n");
    printf("| Cod |\t| Responsável |\t| Data|\t| Motivo|\t| Valor|\n");
    printf("\n");
    while (aux != NULL)
    {
        printf("%d\t\t\t",aux->cod);
        printf("%s\t\t\t",aux->responsavel);
        printf("%d/%d/%d\t\t\t",aux->dia,aux->mes,aux->ano);
        printf("%s\t\t\t",aux->motivo);
        printf("%f\n",aux->valor);
        aux = aux->prox;
    }
    printf("\nFim da Lista! \n\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}