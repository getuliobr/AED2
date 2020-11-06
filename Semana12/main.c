#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Ordenar.h"
#include "ABB.h"
#include "ARN.h"

int* decrescente(int n) {
  int* out = (int*) calloc(sizeof(int), n);
  for(int i = 0, k = (n - 1); i < n; i++, k--) out[i] = k;
  return out;
}

int* random_vector(int n, int max, int seed) {
  int* out = (int*) calloc(sizeof(int), n);
  srand(seed);
  for(int i = 0; i < n; i++) out[i] = (int)((float)rand()/RAND_MAX * (max + 1));
  return out;
}

void printVetor(int *vetor, int tamanho) {
  printf("[");
  for(int i=0;i<tamanho;i++) {
		printf("%d", vetor[i]);
		if(i != tamanho - 1) printf(", ");
	}
  printf("]\n");
}

float dp(clock_t *clocks, float clockMedio, int n) {
  float dp = 0;
  for(int i = 0; i < n; i++) {
    dp += pow(clocks[i] - clockMedio, 2);
  }
  dp /= n;
  return sqrt(dp);
}

int main(int argc, const char* argv[]) {
  int n = atoi(argv[1]);
  clock_t t;
  int altura;
  int* v = decrescente(n);
  printf("ABB:\n");
  t = clock();
  altura = ABB_Sort(v, n);
  t = clock() - t;
  printf("Altura: %d\nTempo: %.2fs\n", altura, (((float)t)/CLOCKS_PER_SEC));

  printf("AVL:\n");
  v = decrescente(n);
  t = clock();
  altura = AVL_Sort(v, n);
  t = clock() - t;
  printf("Altura: %d\nTempo: %.2fs\n", altura, (((float)t)/CLOCKS_PER_SEC));

  printf("ARN:\n");
  v = decrescente(n);
  t = clock();
  altura = ARN_Sort(v, n);
  t = clock() - t;
  printf("Altura: %d\nTempo: %.2fs\n", altura, (((float)t)/CLOCKS_PER_SEC));

  printf("Vetor Aleatorio:\n");

  clock_t mediaTempo[10];
  clock_t mediaFinalTempo = 0;
  int mediaAltura = 0;
  printf("ABB:\n");
  for(int i = 0; i < 10; i++) {
    v = random_vector(n, n * 10, 42);
    t = clock();
    mediaAltura += ABB_Sort(v, n);
    mediaTempo[i] = ((float)clock() - t)/CLOCKS_PER_SEC;
    mediaFinalTempo += mediaTempo[i];
  }
  mediaFinalTempo = mediaFinalTempo;
  printf("Altura: %.2f\nTempo: %.2fs\nDP: %f\n", (float)mediaAltura/10, (float)mediaFinalTempo, dp(mediaTempo, mediaFinalTempo, 10));
  
  mediaFinalTempo = 0;
  mediaAltura = 0;
  printf("AVL:\n");
  for(int i = 0; i < 10; i++) {
    v = random_vector(n, n * 10, 42);
    t = clock();
    mediaAltura += AVL_Sort(v, n);
    mediaTempo[i] = ((float)clock() - t)/CLOCKS_PER_SEC;
    mediaFinalTempo += mediaTempo[i];
  }
  mediaFinalTempo = mediaFinalTempo;
  printf("Altura: %.2f\nTempo: %.2fs\nDP: %f\n", (float)mediaAltura/10, (float)mediaFinalTempo, dp(mediaTempo, mediaFinalTempo, 10));

  mediaFinalTempo = 0;
  mediaAltura = 0;
  printf("ARN:\n");
  for(int i = 0; i < 10; i++) {
    v = random_vector(n, n * 10, 42);
    t = clock();
    mediaAltura += ARN_Sort(v, n);
    mediaTempo[i] = ((float)clock() - t)/CLOCKS_PER_SEC;
    mediaFinalTempo += mediaTempo[i];
  }
  mediaFinalTempo = mediaFinalTempo;
  printf("Altura: %.2f\nTempo: %.2fs\nDP: %f\n", (float)mediaAltura/10, (float)mediaFinalTempo, dp(mediaTempo, mediaFinalTempo, 10));
}