typedef struct ABB {
  struct ABB* esq;
  struct ABB* dir;
  int chave;
} ABB;

ABB* ABB_Criar(int chave, ABB* esq, ABB* dir);
ABB* ABB_Buscar(ABB* Raiz, int chave);
void ABB_Inserir(ABB** Raiz, int chave);
void ABB_Remover(ABB** Raiz, int chave);
void ABB_Imprimir(ABB* Raiz);