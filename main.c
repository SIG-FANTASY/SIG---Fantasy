#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fantasia.h"
#include "venda.h"
#include "cliente.h"
#include "fluxo.h"
#include "validar.h"


char menuIndex(void);
void telaEquipe(void);
void telaSobre(void);

int main(void)
{

	char escolha;
	do {
		escolha = menuIndex();
		switch(escolha) {
			case '1': 	moduloFantasia();
						break;
			case '2': 	moduloVenda();
						break;
			case '3': 	moduloFluxo();
						break;
			case '4': 	moduloCliente();
						break;
			case '5': 	telaEquipe();
						break;
			case '6': 	telaSobre();
						break;
		} 		
	} while (escolha != '0');
	return 0;  
}

///////////////////////////////////////////////MENU PRINCIPAL///////////////////////////////////////////////////

char menuIndex(void)
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
	printf("||                      ====               MENU              ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||                         __________________________________                       ||\n");
	printf("||                        |                                  |                      ||\n");
	printf("||                        |  1. Fantasia                     |                      ||\n");
	printf("||                        |  2. Vendas                       |                      ||\n");
	printf("||                        |  3. Fluxo Financeiro             |                      ||\n");
	printf("||                        |  4. Cliente                      |                      ||\n");
	printf("||                        |  5. Equipe                       |                      ||\n");
	printf("||                        |  6. Sobre Nós                    |                      ||\n");
  printf("||                        |  0. Fechar                   |                      ||\n");
	printf("||                        |  'Digite a opcao desejada:'");
  
  int valid;

  do{
    scanf("%c", &escolha);
	  getchar();
    valid= validarEscolhas(escolha);
  }while(valid==1);

	printf("||                        |__________________________________|                      ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||                                                                                  ||\n");
	printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	printf("||__________________________________________________________________________________||\n");

	return escolha;
}

void telaEquipe(void)
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
	printf("||                      ====              Equipe             ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||            ________________________________________________________              ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |   Este projeto foi desenvolvido por:                   |             ||\n");
	printf("||           | Nome: José Pereira                                     |             ||\n");
	printf("||           | E-mail: jose.marques.707@ufrn.edu.br                   |             ||\n");
	printf("||           | Github: @joseP1432                                     |             ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           | Nome: Ketlly Azevedo                                   |             ||\n");
	printf("||           | E-mail: ketlly.azevedo.090@ufrn.edu.br                 |             ||\n");
	printf("||           | Github: @ketwy                                         |             ||\n");
	printf("||           |________________________________________________________|             ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||                                                                                  ||\n");
	printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	printf("||__________________________________________________________________________________||\n");
  printf("aperte qualquer tecla para voltar");
  scanf("%c", &escolha);
  getchar();

  menuIndex();
}

void telaSobre(void)
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
	printf("||                      ====            Sobre Nós            ====                   ||\n");
	printf("||                      =========================================                   ||\n");
	printf("||                                                                                  ||\n");
	printf("||            ________________________________________________________              ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |   Este projeto foi desenvolvido com a finalidade de    |             ||\n");
	printf("||           | adicionarmos às empresas locais um sistema de alguel,  |             ||\n");
	printf("||           | o qual está voltado inicialmente para as empresas de   |             ||\n");
	printf("||           | fantasias.                                             |             ||\n");
	printf("||           |                                                        |             ||\n");
	printf("||           |   Abordado na UFRN - Caicó/RN, esta aplicação foi feita|             ||\n");
	printf("||           | a partir da disciplina de Programação, ministrada pelo |             ||\n");
	printf("||           | doscente Flavius Gorgônio.                             |             ||\n");
	printf("||           |________________________________________________________|             ||\n");
	printf("||                                                                                  ||\n");
	printf("||                                                                                  ||\n");
	printf("||__________________________________________________________________________________||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||                                                                                  ||\n");
	printf("||                         by José Pereira & Ketlly Azevedo                         ||\n");
	printf("||__________________________________________________________________________________||\n");
  printf("aperte qualquer tecla para voltar");
  scanf("%c", &escolha);
  getchar();

  menuIndex();
}