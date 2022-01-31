typedef struct cliente Cli; //STRUCT INSPIRADO POR @flgorgonio

struct cliente {
	char nome[101];
	char email[51];
	char idade[4];
	char telefone[14];
  char status;
};

void moduloCliente(void);
char menuCliente(void);

Cli* cadastrarCliente(void);

void exibeCliente(Cli*);
void gravaClientes(Cli*);
void listaCliente(void);
void editarCliente(void);
void pesquisarCliente(void);
void excluirCliente(void);