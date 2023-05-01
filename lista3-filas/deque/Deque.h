#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct{
	int *dados;
	int qtd, capacidade, inicio;
} Deque;

void inicializa_deque(Deque *d, int capacidade);
int deque_cheio(Deque d);
int deque_vazio(Deque d);
int inserir_inicio(Deque *d, int value);
int inserir_fim(Deque *d, int value);
int remove_inicio(Deque *d, int *value);
int remove_fim(Deque *d, int *value);
void mostra_deque(Deque d);
