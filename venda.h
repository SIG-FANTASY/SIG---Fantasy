typedef struct venda Ven; //STRUCT INSPIRADO POR @flgorgonio

struct venda {
	char cod[15];
	char cliente[15];
	int dia;
	int mes;
	int ano;
	int aluguel;
};

void moduloVenda(void);
char menuVenda(void);

Ven* cadastrarVenda(void);

void telaVenda();
void cadastroVenda(void);
void editarVenda(void);
void excluirVenda(void);
void pesquisarVendas(void);