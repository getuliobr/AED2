#include "THEA.h"
#include <stdlib.h>

int THEA_Hash(THEA* TH, int chave, int k) {
  return ((chave % TH->m) + k) % TH->m;
}

THEA* THEA_Criar(int m) {
  THEA* out = (THEA*) malloc(sizeof(THEA));
  out->m = m;
  out->n = 0;

  out->th = (ELEM*) calloc(sizeof(ELEM), out->m);
  for(int i = 0; i < out->m; i++) {
    out->th[i].estado = E_LIVRE;
  }

  return out;
}

int THEA_Inserir(THEA* TH, int chave, int valor) {
  int k = 0;
  int h = THEA_Hash(TH, chave, k);
  int h_inicial = h;

  while(TH->th[h].estado == E_OCUPADO) {
    if (TH->th[h].chave == chave) {
      TH->n--; // chave repetida, tira um para cancelar com o TH->n++ no final da funcao.
      break;
    }
    k++;
    h = THEA_Hash(TH, chave, k);
    if(h == h_inicial) return -1;
  }

  TH->th[h].chave = chave;
  TH->th[h].valor = valor;
  TH->th[h].estado = E_OCUPADO;

  TH->n++;

  return h;
}

int THEA_ClusterMaximo(THEA* TH) {
  int maior = 0;
  int atual = 0;
  for(int i = 0; i < TH->m; i++) {
    if(TH->th[i].estado == E_OCUPADO) atual++;
    else atual = 0;
    if(atual > maior) maior = atual;
  }
  return maior;
}

int THEA_QuantidadeClusters(THEA* TH) {
  int clusters = 0;
  for(int i = 0; i < TH->m; i++) {
    if(i == 0 && TH->th[i].estado == E_OCUPADO) clusters++;
    else if(TH->th[i - 1].estado != TH->th[i].estado && TH->th[i].estado == E_OCUPADO) clusters++;
  }
  return clusters;
}

float THEA_TamMedioClusters(THEA* TH) {
  int clusters = THEA_QuantidadeClusters(TH);
  int tam = 0;

  for(int i = 0; i < TH->m; i++) {
    if(TH->th[i].estado == E_OCUPADO) tam++;
  }
  
  return (float)tam/clusters;
}

int THEA_Buscar(THEA* TH, int chave) {
  int k = 0;
  int h = THEA_Hash(TH, chave, k);
  int h_inicial = h;

  while(TH->th[h].estado != E_LIVRE) {
    if(TH->th[h].estado == E_OCUPADO && TH->th[h].chave == chave) return h;
    k++;
    h = THEA_Hash(TH, chave, k);

    if(h_inicial == h) return -1;
  }
  return -1;
}

int THEA_Remover(THEA* TH, int chave) {
  int pos = THEA_Buscar(TH, chave);
  if(pos == -1) return -1;
  
  TH->th[pos].estado == E_APAGADO;
  
  TH->n--;
  return pos;
}

float max(float x, float y) {
  return (x > y) ? x : y;
}

float THEA_CustoBemSucedida(THEA *TH) {
  int C = THEA_QuantidadeClusters(TH);
  int* T = (int*) calloc(sizeof(int), C);
  int clusterAtual = 0;

  for(int i = 0; i < TH->m; i++) {
    if(i != 0 && TH->th[i - 1].estado != TH->th[i].estado && TH->th[i].estado == E_OCUPADO) clusterAtual++;
    if(TH->th[i].estado == E_OCUPADO) T[clusterAtual]++;
  }

  int sum = 0;
  for(int i = 0; i < C; i++) sum += max(T[i]/2, 1);

  return (float) sum / TH->n;
}

float THEA_Alfa(THEA* TH) {
  return (float)TH->n/TH->m;
}

int THEA_Inseridos(THEA* TH) {
  return TH->n;
}