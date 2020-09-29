#include <stdio.h>
#include <stdlib.h>
#include "THED.h"


int main(int argc, char const *argv[]){
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  THED* hashing = inserir_n_aleatorios(n, m, 42);
  printf("Mais longa: %d\n", THED_MaisLonga(hashing));
  printf("Mais curta: %d\n", THED_MaisCurta(hashing));
  printf("Media: %.2f\n", THED_TamMedio(hashing));
  printf("Teorico: %.2f\n", (float) n/m);
}

