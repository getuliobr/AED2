#pragma once

typedef enum {
  C_VERMELHO,
  C_PRETO
} C_COR;

typedef struct ARN
{
  struct ARN *esq;
  struct ARN *dir;
  int chave;
  int valor;
  C_COR cor;
} ARN;

void ARN_Inserir(ARN** A, int chave, int valor);
int ARN_Altura(ARN *A);
ARN ARN_Buscar(ARN** A, int chave);