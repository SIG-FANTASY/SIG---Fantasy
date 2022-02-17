typedef struct venda Ven; //STRUCT INSPIRADO POR @flgorgonio

struct venda {
	int cod;
	char cliente[15];
  char produto[15];
	int dia;
	int mes;
	int ano;
	int aluguel;
	float valor;
	char status;
	struct venda *prox;
};

void moduloVenda(void);
char menuVenda(void);

Ven* cadastrarVenda(void);

Ven* alterarVendas(Ven*);

void exibeVenda(Ven*);
void telaExibirVenda(Ven*);
void gravaVendas(Ven*);
void listaVenda(void);
void excluirVenda(Ven*);
Ven* pesquisarVendas(void);

void relatorioVen(Ven **);
void listaVen(Ven*);
void glVen(Ven*);