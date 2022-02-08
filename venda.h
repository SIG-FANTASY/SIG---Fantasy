typedef struct venda Ven; //STRUCT INSPIRADO POR @flgorgonio

struct venda {
	int cod;
	char cliente[15];
	int dia;
	int mes;
	int ano;
	int aluguel;
	float valor;
	char status;
};

void moduloVenda(void);
char menuVenda(void);

Ven* cadastrarVenda(void);

void exibeVenda(Ven*);
void gravaVendas(Ven*);
void listaVenda(void);
void editarVenda(void);
void excluirVenda(Ven*);
Ven* pesquisarVendas(void);