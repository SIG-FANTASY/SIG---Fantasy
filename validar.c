#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validar.h"

int validarData(int dia, int mes, int ano){
  if (mes <= 12){
    if (ano % 2 != 0){
      if(mes == 2 && dia <= 28){
        return 0;
      }
      else if(mes % 2 == 0 || mes == 9 || mes == 11){
        if (mes != 2 && mes != 8 && mes != 10 && dia <= 30){
          return 0;
        }
        else{
          return 1;
        }
      }
      else if (mes %2 != 0 || mes == 8 || mes == 10 || mes == 12){
        if (mes != 2 && mes != 9 && mes != 11 && dia <= 31){
          return 0;
        }
        else{
          return 1;
        }
      }
    }
    else{
      if(mes == 2 && dia <= 29){
        return 0;
      }
      else if(mes % 2 == 0 || mes == 9 || mes == 11){
        if (mes != 2 && mes != 8 && mes != 10 && dia <= 30){
          return 0;
        }
        else{
          return 1;
        }
      }
      else if (mes %2 != 0 || mes == 8 || mes == 10 || mes == 12){
        if (mes != 2 && mes != 9 && mes != 11 && dia <= 31){
          return 0;
        }
        else{
          return 1;
        }
      }
    }
  }

  else{
    return 1;
  }
  return 0;
}



int tamanhoString(char a[]){
  int cont;

  for(int i=0; a[i] != '\0'; i++){
    cont++;
  }

  return cont;
}

int validarLetras(char letra[], int tamanho){

  char alfabeto[54]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','V','W','X','Y','Z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  int cont=0;

  for(int x=0; letra[x] != '\0'; x++){
    for( int y=0;alfabeto[y] != '\0';y++){
      if(letra[x] == alfabeto[y]){
        cont++;
      }
    }
  }
  if (tamanho==cont){
    return 0;
  }else{
    return 1;
  }

}

int validarNumeros(char digitos[],int tamanho){
  char numeros[11]={'1','2','3','4','5','6','7','8','9','0'};
   int cont=0;

  for(int x=0; digitos[x] != '\0'; x++){
    for( int y=0; numeros[y] != '\0';y++){
      if(digitos[x] == numeros[y]){
        cont++;
      }
    }
  }

  if(tamanho==cont){
    return 0;
  }else{
    return 1;
  }

}

int validarEscolhas(char esc){
  char numeros[11]={'0','1','2','3','4','5','6','7','8','9'};

  int escolha;

  for(int x=0; x<11 ; x++){
    if(esc == numeros[x]){
        escolha=1;
        break;
      }
  }

  if (escolha==1){
    return 0;
  }else{
    return 1;
  }
}

int validarEmail(char email[], int tamanho){
  char fim[5]=".com";
  int cont=0;

  for(int i=tamanho; i>tamanho-5; i--){
    for (int x=0; fim[x] != '\0'; x++){
      if (email[i]==fim[x]){
        cont++;
      }
    }
  }

  for(int i=0; email[i] != '\0'; i++){
    if(email[i]=='@'){
      cont++;
    }
  }
  if (cont==5){
    return 0;
  }else{
    return 1;
  }

}

