#include "radix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void printVetor(int *vetor, int tamanho) {
  printf("[");
  for(int i=0;i<tamanho;i++) {
		printf("%d", vetor[i]);
		if(i != tamanho - 1) printf(", ");
	}
  printf("]\n");
}

int* random_vector(int n, int max, int seed) {
  int* out = (int*) calloc(sizeof(int), n);
  srand(seed);
  for(int i = 0; i < n; i++) out[i] = (int)((float)rand()/RAND_MAX * (max + 1));
  return out;
}

int max(int* v, int n) {
  int max = v[0];
  for(int i = 0; i < n; i++) {
    if(v[i] > max) max = v[i];
  }
  return max;
}

void counting_sort(int *v, int n, int div, int base, int *temp) {
  int t;
  int c[base];
  memset(c, 0, base  * sizeof(int));
  int acum = 0;

  #define DIGIT(X) ((base == 2) ? (X >> div) & 1 : (X / div) % base)

  for(int i = 0; i < n; i++){
    c[DIGIT(v[i])]++;
  }

  for(int i = 0; i < base; i++){
    t = c[i];
    c[i] = acum;
    acum += t;
  }

  for(int i = 0; i < n; i++){
    temp[c[DIGIT(v[i])]] = v[i];
    c[DIGIT(v[i])]++;
  }

  memcpy(v, temp, sizeof(int) * n);
}

void radix_sort(int *v, int n, int base) {
  int k = max(v, n);
  int div = 1;
  int *temp = malloc(sizeof(int) * n);

  if(base != 2) {
    while(k > 0) {
      counting_sort(v, n, div, base, temp);
      div *= base;
      k /= base;
    }
  } else {
    int maisSignificante = ceil(log2(max(v, n)));
    for(int pos = 0; pos < maisSignificante; pos++) {
      counting_sort(v, n, pos, base, temp);
    }
  }
  free(temp);
}

