#include "THED.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

LIST** createListOfList(int size) {
  LIST** out = (LIST**) calloc(sizeof(LIST*), size);
  for(int i = 0; i < size; i++)
    out[i] = LIST_create();
  return out;
}

THED* THED_criar(int m) {
  THED* out = (THED*) malloc(sizeof(THED));
  out->M = m;
  out->th = createListOfList(m);
  return out;
}

int THED_hash(THED* TH, int key){
  return key % TH->M;  
}

int THED_inserir(THED* TH, int key, int val) {
  int pos = val%TH->M;
  LIST* list = TH->th[pos];
  return LIST_insert(list, key, val);
}

THED* inserir_n_aleatorios(int n, int m, int seed) {
  THED* out = THED_criar(m);
  srand(seed);
  int adicionados = 0;
  while(adicionados < n){
    int val = rand() % (10 * n);
    if(THED_inserir(out, val, val)) adicionados++;
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
    media += LIST_size(TH->th[i]);
  }
  return (float) media / TH->M;
}