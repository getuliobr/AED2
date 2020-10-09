#include <stdio.h>
#include <stdlib.h>
#include "THEA.h"
#include "AUXILIAR.h"

int main(int argc, char const *argv[]){
  int N = atoi(argv[1]);
  int M = 5;

  
  int* v = random_vector(N, 10 * N, 42);

  THEA* thea = THEA_Criar(M, S_LINEAR);
  for(int i = 0; i < N; i++) THEA_Inserir(thea, v[i], v[i]);
  printf("Linear: %d\n", THEA_Colisoes(thea));

  thea = THEA_Criar(M, S_QUADRATICA);
  for(int i = 0; i < N; i++) THEA_Inserir(thea, v[i], v[i]);
  printf("Quadratico: %d\n", THEA_Colisoes(thea));

  thea = THEA_Criar(M, S_DUPLA);
  for(int i = 0; i < N; i++) THEA_Inserir(thea, v[i], v[i]);
  printf("Duplo: %d\n", THEA_Colisoes(thea));
}

