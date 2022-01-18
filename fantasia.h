typedef struct fantasia Fan; //STRUCT INSPIRADO POR @flgorgonio

struct fantasia {
	char cod[15];
	char quantidade[101];
	char nome[101];
	float preco;
	char tamanho[5];
};

void moduloFantasia(void);
char menuFantasia(void);

Fan* cadastrarFantasia(void);

void telaFantasia(const Fan*);
void cadastroFan(void);
void editarFantasia(void);
void pesquisarFantasia(void);
void verFantasia(void);
void excluirFantasia(void);
