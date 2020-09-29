#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"


int main(int argc, char const *argv[]){
  int n = atoi(argv[1]);
  int k = atoi(argv[2]);
  int elemento;
  int* vetor;
  clock_t t;

  k = 1;
  printf("=============================================\nK = 1\n");
  vetor = random_vector_unique_elems(n, 42);
  t = clock();
  elemento = SelectionMinK(vetor, n, k);
  t = clock() - t;
  printf("=============================================\nSelectionMinK:\nElemento na pos %d: %d\nTempo: %f\n", k, elemento, (((float)t)/CLOCKS_PER_SEC) * 1000);
  
  vetor = random_vector_unique_elems(n, 42);
  t = clock();
  elemento = HeapMinK(vetor, n, k);
  t = clock() - t;
  printf("---------------------------------------------\nHeapMinK:\nElemento na pos %d: %d\nTempo: %f\n", k, elemento, (((float)t)/CLOCKS_PER_SEC) * 1000);
  
  vetor = random_vector_unique_elems(n, 42);
  t = clock();
  elemento = QuickMinK(vetor, 0, n-1, k);
  t = clock() - t;
  printf("---------------------------------------------\nQuickMinK:\nElemento na pos %d: %d\nTempo: %f\n", k, elemento, (((float)t)/CLOCKS_PER_SEC) * 1000);

  k = n/3;
  printf("=============================================\nK = %d/3\n", n);
  if(k <= 10000) {
    vetor = random_vector_unique_elems(n, 42);
    t = clock();
    elemento = SelectionMinK(vetor, n, k);
    t = clock() - t;
    printf("=============================================\nSelectionMinK:\nElemento na pos %d: %d\nTempo: %f\n", k, elemento, (((float)t)/CLOCKS_PER_SEC) * 1000);
  }else {
    printf("=============================================\n");
  }
  
  vetor = random_vector_unique_elems(n, 42);
  t = clock();
  elemento = HeapMinK(vetor, n, k);
  t = clock() - t;
  printf("---------------------------------------------\nHeapMinK:\nElemento na pos %d: %d\nTempo: %f\n", k, elemento, (((float)t)/CLOCKS_PER_SEC) * 1000);
  
  vetor = random_vector_unique_elems(n, 42);
  t = clock();
  elemento = QuickMinK(vetor, 0, n-1, k);
  t = clock() - t;
  printf("---------------------------------------------\nQuickMinK:\nElemento na pos %d: %d\nTempo: %f\n", k, elemento, (((float)t)/CLOCKS_PER_SEC) * 1000);

  k = n/2;
  printf("=============================================\nK = %d/2\n", n);
  if(k <= 10000) {
    vetor = random_vector_unique_elems(n, 42);
    t = clock();
    elemento = SelectionMinK(vetor, n, k);
    t = clock() - t;
    printf("=============================================\nSelectionMinK:\nElemento na pos %d: %d\nTempo: %f\n", k, elemento, (((float)t)/CLOCKS_PER_SEC) * 1000);
  }else {
    printf("=============================================\n");
  }
  vetor = random_vector_unique_elems(n, 42);
  t = clock();
  elemento = HeapMinK(vetor, n, k);
  t = clock() - t;
  printf("---------------------------------------------\nHeapMinK:\nElemento na pos %d: %d\nTempo: %f\n", k, elemento, (((float)t)/CLOCKS_PER_SEC) * 1000);
  
  vetor = random_vector_unique_elems(n, 42);
  t = clock();
  elemento = QuickMinK(vetor, 0, n-1, k);
  t = clock() - t;
  printf("---------------------------------------------\nQuickMinK:\nElemento na pos %d: %d\nTempo: %f\n---------------------------------------------\n", k, elemento, (((float)t)/CLOCKS_PER_SEC) * 1000);
}

