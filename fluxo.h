typedef struct fluxo Flu; //STRUCT INSPIRADO POR @flgorgonio

struct fluxo{
	char motivo[51];
	int dia;
	int mes;
	int ano;
	float valor;
	char responsavel[101];
};

void moduloFluxo(void);
char menuFluxo(void);

Flu* cadastrarGasto(void);

void telaFluxo(const Flu*);
void pesquisarFluxo(void);
void cadastroGasto(void);