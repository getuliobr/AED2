#include "THED.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SUCCESS 1;
#define ERROR 0;

LIST* createNode(int key, int value){
  LIST* out = (LIST*) malloc(sizeof(LIST));
  out->value = value;
  out->prox = NULL;
  return out;
}

LIST** createListOfList(int size) {
  LIST** out = (LIST**) calloc(sizeof(LIST*), size);
  for(int i = 0; i < size; i++)
    out[i] = createNode(-1, 0);
  return out;
}

THED* THED_criar(int m) {
  THED* out = (THED*) malloc(sizeof(THED));
  out->M = m;
  out->th = createListOfList(m);
  return out;
}

int THED_Hash(THED* TH, int key){
  return key % TH->M;
}

int THED_inserir(THED* TH, int key, int val) {
  int pos = THED_Hash(TH, key);
  LIST* curr = TH->th[pos];

  while(curr->prox != NULL) {
    if(curr->key == key) return ERROR;
    curr = curr->prox;
  }
  
  LIST* node = createNode(key, val);
  curr->prox = node;
  TH->th[pos]->value++;

  return SUCCESS;
}

THED* inserir_n_aleatorios(int n, int m, int seed) {
  THED* out = THED_criar(m);
  srand(seed);
  int added = 0;
  while(added < n) {
    int val = rand() % (10 * n);
    if(THED_inserir(out, val, val)) added++;
  }

  return out;
}

int THED_MaisLonga(THED* TH) {
  if(!TH) return -1;
  int maior = TH->th[0]->value;
  for(int i = 0; i < TH->M; i++)
    if(TH->th[i]->value > maior) maior = TH->th[i]->value;
  return maior;
}

int THED_MaisCurta(THED* TH) {
  if(!TH) return -1;
  int menor = TH->th[0]->value;
  for(int i = 0; i < TH->M; i++)
    if(TH->th[i]->value < menor) menor = TH->th[i]->value;
  return menor;
}

float THED_TamMedio(THED* TH) {
  if(!TH) return -1;
  float media = 0;
  for(int i = 0; i < TH->M; i++) {
    media += TH->th[i]->value;
  }
  return (float) media / TH->M;
}


