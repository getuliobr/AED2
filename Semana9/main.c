#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

int main() {
  printf("Letra A:\n");
  ABB* arvoreA = ABB_Criar(70, NULL, NULL);
  ABB_Inserir(&arvoreA, 39);
  ABB_Inserir(&arvoreA, 88);
  ABB_Remover(&arvoreA, 70);
  ABB_Imprimir(arvoreA);
  
  printf("Letra B:\n");
  ABB* arvoreB = ABB_Criar(10, NULL, NULL);
  ABB_Inserir(&arvoreB, 4);
  ABB_Inserir(&arvoreB, 20);
  ABB_Inserir(&arvoreB, 6);
  ABB_Inserir(&arvoreB, 2);
  ABB_Inserir(&arvoreB, 3);
  ABB_Inserir(&arvoreB, 5);
  ABB_Inserir(&arvoreB, 7);
  ABB_Remover(&arvoreB, 10);
  ABB_Remover(&arvoreB, 4);
  ABB_Remover(&arvoreB, 5);
  ABB_Imprimir(arvoreB);
  
  printf("Letra C:\n");
  ABB* arvoreC = ABB_Criar(30, NULL, NULL);
  ABB_Inserir(&arvoreC, 50);
  ABB_Inserir(&arvoreC, 40);
  ABB_Inserir(&arvoreC, 47);
  ABB_Inserir(&arvoreC, 15);
  ABB_Inserir(&arvoreC, 20);
  ABB_Inserir(&arvoreC, 25);
  ABB_Inserir(&arvoreC, 17);
  ABB_Inserir(&arvoreC, 19);
  ABB_Inserir(&arvoreC, 4);
  ABB_Inserir(&arvoreC, 7);
  ABB_Inserir(&arvoreC, 0);
  ABB_Remover(&arvoreC, 0);
  ABB_Remover(&arvoreC, 30);
  ABB_Remover(&arvoreC, 15);
  ABB_Remover(&arvoreC, 20);
  ABB_Imprimir(arvoreC);
}