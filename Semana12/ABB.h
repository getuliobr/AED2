#pragma once

typedef struct ABB {
  struct ABB* esq;
  struct ABB* dir;
  int chave;
  int valor;
} ABB;

ABB* ABB_Criar(int chave, int valor, ABB* esq, ABB* dir);
int ABB_Altura(ABB *A);
ABB* ABB_Buscar(ABB* Raiz, int chave);
void ABB_Inserir(ABB** Raiz, int chave, int valor);
void ABB_Remover(ABB** Raiz, int chave);
void ABB_Imprimir(ABB* Raiz);