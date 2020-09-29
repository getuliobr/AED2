#include "LIST.h"

typedef struct thed {
  int M;
  LIST** th;
} THED;

THED* THED_criar(int m);
int THED_hash(THED* TH, int key);
int THED_inserir(THED* TH, int key, int val);
THED* inserir_n_aleatorios(int n, int m, int seed);

int THED_MaisLonga(THED* TH);
int THED_MaisCurta(THED* TH);
float THED_TamMedio(THED* TH);