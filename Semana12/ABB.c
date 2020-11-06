#include "ABB.h"
#include <stdlib.h>
#include <stdio.h>

int ABB_Altura(ABB *A) {
  if(A == NULL) return 0;
    
  int alturaEsq = ABB_Altura(A->esq);  
  int alturaDir = ABB_Altura(A->dir);  
    
  int max = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
  return max + 1;  
}

ABB* ABB_Criar(int chave, int valor, ABB* esq, ABB* dir) {
  ABB* out = (ABB*) malloc(sizeof(ABB));
  out->dir = dir;
  out->esq = esq;
  out->chave = chave;
  out->valor = valor;
  return out;
}

ABB* ABB_Buscar(ABB* Raiz, int chave) {
  if(Raiz == NULL || Raiz->chave == chave) return Raiz;

  if(chave > Raiz->chave) return ABB_Buscar(Raiz->dir, chave);
  else if(chave <= Raiz->chave) return ABB_Buscar(Raiz->esq, chave);
}

void ABB_Inserir(ABB** Raiz, int chave, int valor) {
  if((*Raiz) == NULL) {
    *Raiz = ABB_Criar(chave, valor, NULL, NULL);
  } else{
    if(chave <= (*Raiz)->chave) ABB_Inserir(&(*Raiz)->esq, chave, valor);
    else ABB_Inserir(&(*Raiz)->dir, chave, valor);
  }
}

void ABB_Remover(ABB** Raiz, int chave) {
  if((*Raiz) == NULL)
    return;
  if((*Raiz)->chave == chave) {
    ABB* toRemove = (*Raiz);
    ABB* toReplace;
    if(toRemove->esq == toRemove->dir) { // Se for folha.
      *Raiz = NULL;
      free(toRemove);
    } else if(toRemove->esq != toRemove->dir && (toRemove->esq == NULL || toRemove->dir == NULL)) { // So tem um filho
      if(toRemove->esq == NULL) toReplace = toRemove->dir;
      else toReplace = toRemove->esq;
      *Raiz = toReplace;
      free(toRemove);
    } else { // Tem mais de um filho
      ABB* father = (*Raiz);
      ABB* son = (*Raiz)->dir;
      
      int flag = 0;
      while(son->esq) {
        father = son;
        son = son->esq;
        flag++;
      }

      (*Raiz)->chave = son->chave;

      if(!flag) father->dir = son->dir;
      else father->esq = son->dir;

      free(son);
    }

  } else {
    if(chave <= (*Raiz)->chave) ABB_Remover(&(*Raiz)->esq, chave);
    else ABB_Remover(&(*Raiz)->dir, chave);
  }
}

static void ABB_ImprimirOrdenado(ABB* Raiz, int tabCount, char dir) {
  if(!Raiz) return;
  for(int i = 0; i < tabCount; i++) printf("\t");
  printf("(%c) %d\n", dir, Raiz->chave);
  ABB_ImprimirOrdenado(Raiz->esq, tabCount + 1, 'e');
  ABB_ImprimirOrdenado(Raiz->dir, tabCount + 1, 'd');
}

void ABB_Imprimir(ABB* Raiz) {
  ABB_ImprimirOrdenado(Raiz, 0, 'r');
}
