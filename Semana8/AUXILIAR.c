#include "AUXILIAR.h"
#include <stdlib.h>

int* random_vector(int n, int max, int seed) {
  int* out = (int*) calloc(sizeof(int), n);
  srand(seed);
  for(int i = 0; i < n; i++) out[i] = (int)((float)rand()/RAND_MAX * (max + 1));
  return out;
}