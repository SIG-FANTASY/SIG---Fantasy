typedef struct fluxo Flu; //STRUCT INSPIRADO POR @flgorgonio

struct fluxo{
	int cod;
	char motivo[51];
	int dia;
  	int mes;
  	int ano;
  	float valor;
  	char responsavel[101];
  	char status;
  	struct fluxo *prox;
};

void moduloFluxo(void);
char menuFluxo(void);

void telaExibirFluxo(Flu*);

Flu* cadastrarGasto(void);

void exibeFluxo(Flu*);
void gravaGasto(Flu*);

void listaFluxo();
Flu* pesquisarFluxo(void);

void relatorioFlu(Flu **);
void listaFlu(Flu*);
void glFlu(Flu*);