#include <stdio.h>
#include <stdlib.h>
#include "THEA.h"
#include "AUXILIAR.h"

int main(int argc, char const *argv[]){
  int M = atoi(argv[1]);
  int N = 10000;

  FILE* f = fopen("out.txt", "a");

  THEA* thea = THEA_Criar(M);
  
  int* v = random_vector(N, 10 * N, 42);
  for(int i = 0; i < N; i++) THEA_Inserir(thea, v[i], v[i]);

  fprintf(f,
    "%d\t %d\t %.2f\t %.2f\t %.2f\t %d\n",
    M,
    THEA_Inseridos(thea),
    THEA_Alfa(thea),
    THEA_TamMedioClusters(thea),
    THEA_CustoBemSucedida(thea),
    THEA_ClusterMaximo(thea)
  );
}

