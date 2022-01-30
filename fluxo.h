typedef struct fluxo Flu; //STRUCT INSPIRADO POR @flgorgonio

struct fluxo{
  char motivo[51];
  int dia;
  int mes;
  int ano;
  float valor;
  char responsavel[101];
  char status;
};

void moduloFluxo(void);
char menuFluxo(void);

Flu* cadastrarGasto(void);

void exibeFluxo(Flu*);
void gravaGasto(Flu*);

void listaFluxo();
void pesquisarFluxo(void);