typedef struct cliente Cli; //STRUCT INSPIRADO POR @flgorgonio

struct cliente {
	char nome[101];
	char email[51];
	char idade[4];
	char telefone[14];
};

void moduloCliente(void);
char menuCliente(void);

Cli* cadastrarCliente(void);

void telaCliente(void);
void cadastroCli(void);
void editarCliente(void);
void pesquisarCliente(void);
void verCliente(void);
void excluirCliente(void);