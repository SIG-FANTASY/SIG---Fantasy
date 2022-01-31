typedef struct fantasia Fan; //STRUCT INSPIRADO POR @flgorgonio

struct fantasia {
  char cod[15];
  char quantidade[101];
  char nome[101];
  float preco;
  char tamanho[5];
  char status;
};

void moduloFantasia(void);
char menuFantasia(void);

Fan* cadastrarFantasia(void);

void exibeFantasia(Fan*);
void gravaFantasia(Fan*);

void listaFantasia(void);
void editarFantasia(void);
Fan* pesquisarFantasia(void);
void excluirFantasia(void);