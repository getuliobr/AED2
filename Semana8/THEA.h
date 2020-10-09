#include "prime_list.h"

#pragma once

typedef enum ESTADO {
  E_LIVRE,
  E_OCUPADO,
  E_APAGADO
} ESTADO;

typedef enum FSONDAGEM {
  S_LINEAR,
  S_QUADRATICA,
  S_DUPLA
} FSONDAGEM;

typedef struct ELEM {
  int chave;
  int valor;
  ESTADO estado;
} ELEM;

typedef struct THEA {
  int m;
  int n;
  int colisoes;
  ELEM* th;
  FSONDAGEM f;
  prime_list_t* primeList;
} THEA;

int THEA_Hash(THEA* TH, int chave, int k);
THEA* THEA_Criar(int m, FSONDAGEM funcao);
int THEA_Inserir(THEA* TH, int chave, int valor);
int THEA_ClusterMaximo(THEA* TH);
float THEA_TamMedioClusters(THEA* TH);
int THEA_Buscar(THEA* TH, int chave);
int THEA_Remover(THEA* TH, int chave);
float THEA_CustoBemSucedida(THEA* TH);
float THEA_Alfa(THEA* TH);
int THEA_Inseridos(THEA* TH);
int THEA_Colisoes(THEA* TH);