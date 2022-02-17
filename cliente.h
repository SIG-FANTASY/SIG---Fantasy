typedef struct cliente Cli; //STRUCT INSPIRADO POR @flgorgonio

struct cliente {
  int cod;
  char nome[101];
  char email[51];
  char idade[4];
  char telefone[14];
  char status;
  struct cliente *prox;
};

Cli* alterarCliente(Cli*);

void moduloCliente(void);
char menuCliente(void);

void excluirCliente(Cli*);

Cli* cadastrarCliente(void);
void gravaClientes(Cli*);

void listaCliente(void);

Cli* pesquisarCliente(void);
void exibeCliente(Cli*);
void telaExibirCliente(Cli*);

void relatorioCli(Cli **);
void listaCli(Cli*);
void glCli(Cli*);