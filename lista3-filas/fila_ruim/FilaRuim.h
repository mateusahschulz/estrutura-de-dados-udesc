#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2
 
typedef struct{
	int *dados;
	int fim, capacidade;
} FilaRuim;

void inicializa_fila( FilaRuim *f, int capacidade );
int fila_vazia( FilaRuim f );
int fila_cheia( FilaRuim f );
int inserir( FilaRuim *f, int info );
int remover( FilaRuim *f, int *info );
void mostra_fila( FilaRuim f );
void desaloca_fila( FilaRuim *f );




