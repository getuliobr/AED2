#pragma once

typedef enum ESTADO {
  E_LIVRE,
  E_OCUPADO,
  E_APAGADO
} ESTADO;

typedef struct ELEM {
  int chave;
  int valor;
  ESTADO estado;
} ELEM;

typedef struct THEA {
  int m;
  int n;
  ELEM* th;
} THEA;

int THEA_Hash(THEA* TH, int chave, int k);
THEA* THEA_Criar(int m);
int THEA_Inserir(THEA* TH, int chave, int valor);
int THEA_ClusterMaximo(THEA* TH);
float THEA_TamMedioClusters(THEA* TH);
int THEA_Buscar(THEA* TH, int chave);
int THEA_Remover(THEA* TH, int chave);
float THEA_CustoBemSucedida(THEA* TH);
float THEA_Alfa(THEA* TH);
int THEA_Inseridos(THEA* TH);