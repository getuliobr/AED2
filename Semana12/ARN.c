#include "ARN.h"
#include <stdlib.h>
#include <stdio.h>


static ARN* ARN_Criar(int chave, int valor) {
  ARN* out = (ARN*) malloc(sizeof(ARN));
  out->valor = valor;
  out->chave = chave;
  out->cor = C_VERMELHO;
  out->esq = out->dir = NULL;
  return out;
}

static inline int vermelho(ARN* A) {
  if(!A) return 0;
  return (A->cor == C_VERMELHO) ? 1 : 0;
}

int ARN_Altura(ARN *A) {
  if(A == NULL) return 0;
    
  int alturaEsq = ARN_Altura(A->esq);  
  int alturaDir = ARN_Altura(A->dir);  
    
  int max = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
  return max + !vermelho(A);  
}

static inline void inverter_cores(ARN* A) {
  A->cor = C_VERMELHO;
  A->esq->cor = C_PRETO;
  A->dir->cor = C_PRETO;
}

static void rot_esq(ARN** A) {
  ARN* h = (*A);
  ARN* x = (*A)->dir;

  h->dir = x->esq;
  x->esq = h;
  x->cor = h->cor;
  h->cor = C_VERMELHO;

  *A = x;
}

static void rot_dir(ARN** A) {
  ARN* h = (*A);
  ARN* x = (*A)->esq;
  
  h->esq = x->dir;
  x->dir = h;
  x->cor = h->cor;
  h->cor = C_VERMELHO;

  *A = x;
}

static void ARN_Inserir_R(ARN** A, int chave, int valor) {
  if((*A) == NULL) {
    *A = ARN_Criar(chave, valor);
    return;
  }

  if(chave < (*A)->chave) {
    ARN_Inserir_R(&(*A)->esq, chave, valor);
  }

  if(chave > (*A)->chave) {
    ARN_Inserir_R(&(*A)->dir, chave, valor);
  }

  if(vermelho((*A)->dir) && !vermelho((*A)->esq)) {
    rot_esq(A);
  }

  if(vermelho((*A)->esq) && vermelho((*A)->esq->esq)) {
    rot_dir(A);
  }

  if(vermelho((*A)->esq) && vermelho((*A)->dir)) {
    inverter_cores(*A);
  }
}

void ARN_Inserir(ARN** A, int chave, int valor) {
  ARN_Inserir_R(A, chave, valor);
  (*A)->cor = C_PRETO;
}