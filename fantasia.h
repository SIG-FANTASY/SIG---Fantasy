typedef struct fantasia Fan; //STRUCT INSPIRADO POR @flgorgonio

struct fantasia {
	int cod;
	char quantidade[101];
	char nome[101];
	float preco;
	char tamanho[5];
	char status;
	struct fantasia *prox;
};

void moduloFantasia(void);
char menuFantasia(void);

Fan* cadastrarFantasia(void);

void exibeFantasia(Fan*);
void gravaFantasia(Fan*);

void listaFantasia(void);
void editarFantasia(void);

Fan* pesquisarFantasia(void); // inspirado por @flgorgonio
void telaExibirFantasia(Fan*);

void excluirFantasia(Fan*);

Fan* alterarFantasia(Fan*);

void relatorioFan(Fan **); // inspirado por @flgorgonio
void listaFan(Fan*); // inspirado por @flgorgonio