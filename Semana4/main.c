#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "radix.h"


int main(int argc, char const *argv[]){
  int n = atoi(argv[1]);

  int* v = random_vector(n, n * 100, 0);
  clock_t t = clock();
  radix_sort(v, n, 2);
  t = clock() - t;
  printf("Base: 2\nTempo: %f\n", (((float)t)/CLOCKS_PER_SEC) * 1000);
  
  v = random_vector(n, n * 100, 0);
  t = clock();
  radix_sort(v, n, 10);
  t = clock() - t;
  printf("Base: 10\nTempo: %f\n", (((float)t)/CLOCKS_PER_SEC) * 1000);
  
}

