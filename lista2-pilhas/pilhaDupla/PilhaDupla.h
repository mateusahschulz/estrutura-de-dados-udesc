#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2

typedef struct {
	int *dados;
	int topo1, topo2;
	int capacidade;
} PilhaDupla;

void inicializa(PilhaDupla *p, int capacidade);
int pilha1_vazia(PilhaDupla p);
int pilha2_vazia(PilhaDupla p);
int pilhas_cheias(PilhaDupla p);
int empilha1(PilhaDupla *p, int info);
int empilha2(PilhaDupla *p, int info);
int desempilha1(PilhaDupla *p, int *info);
int desempilha2(PilhaDupla *p, int *info);
