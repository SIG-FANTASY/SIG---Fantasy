typedef struct venda Ven; //STRUCT INSPIRADO POR @flgorgonio

struct venda {
	int cod;
	char cliente[15];
	int dia;
	int mes;
	int ano;
	char aluguel;
	char status;
};

void moduloVenda(void);
char menuVenda(void);

Ven* cadastrarVenda(void);

void exibeVenda(Ven*);
void gravaVendas(Ven*);
void listaVenda(void);
void editarVenda(void);
void excluirVenda(void);
Ven* pesquisarVendas(void);