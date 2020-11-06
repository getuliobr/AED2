#include "Ordenar.h"
#include <stdlib.h>
#include <stdio.h>

static int ABB_Sort_R(ABB* raiz, int* v, int n) {
  if(raiz->esq != NULL) n = ABB_Sort_R(raiz->esq, v, n);
  v[n++] = raiz->chave;
  ABB* dir = raiz->dir;
  free(raiz);
  if(dir != NULL) n = ABB_Sort_R(dir, v, n);
  return n;
}

int ABB_Sort(int* v, int n) {
  ABB* raiz = NULL;
  int* out = (int*) calloc(sizeof(int), n);
  for(int i = 0; i < n; i++) {
    ABB_Inserir(&raiz, v[i], v[i]);
  }
  int altura = ABB_Altura(raiz);
  ABB_Sort_R(raiz, v, 0);
  return altura;
}

static int AVL_Sort_R(AAVL* raiz, int* v, int n) {
  if(raiz->esq != NULL) n = AVL_Sort_R(raiz->esq, v, n);
  v[n++] = raiz->chave;
  AAVL* dir = raiz->dir;
  free(raiz);
  if(dir != NULL) n = AVL_Sort_R(dir, v, n);
  return n;
}

int AVL_Sort(int* v, int n) {
  AAVL* raiz = NULL;
  int* out = (int*) calloc(sizeof(int), n);
  for(int i = 0; i < n; i++) {
    AAVL_Inserir(&raiz, v[i], v[i]);
  }
  int altura = AAVL_Altura(raiz);
  AVL_Sort_R(raiz, v, 0);
  return altura;
}

static int ARN_Sort_R(ARN* raiz, int* v, int n) {
  if(raiz->esq != NULL) n = ARN_Sort_R(raiz->esq, v, n);
  v[n++] = raiz->chave;
  ARN* dir = raiz->dir;
  free(raiz);
  if(dir != NULL) n = ARN_Sort_R(dir, v, n);
  return n;
}

int ARN_Sort(int* v, int n) {
  ARN* raiz = NULL;
  int* out = (int*) calloc(sizeof(int), n);
  for(int i = 0; i < n; i++) {
    ARN_Inserir(&raiz, v[i], v[i]);
  }
  int altura = ARN_Altura(raiz);
  ARN_Sort_R(raiz, v, 0);
  return altura;
}