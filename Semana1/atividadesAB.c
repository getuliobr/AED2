#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int* random_vector(int n, int max, int seed) {
  int* out = (int*) calloc(sizeof(int), n);
  srand(seed);
  for(int i = 0; i < n; i++) out[i] = (int)((float)rand()/RAND_MAX * (max + 1));
  return out;
}

void troca(int* vetor, int pos1, int pos2) {
  int aux = vetor[pos1];
  vetor[pos1] = vetor[pos2];
  vetor[pos2] = aux;
}

int max(int* vector, int start, int end) {
  int max = start;

  for(int i = start; i <= end; i++) {
    if(vector[i] > vector[max]){
      max = i;
    }
  }

  return max;
}

void insertion(int* vetor, int k) {
  int i = k - 1;
  int aux = vetor[k];
  while((i >= 0) && (vetor[i] > aux)) {
    vetor[i + 1] = vetor[i];
    i--;
  }
  vetor[i + 1] = aux;
}

void insertionSort(int *vetor, int tamanho) {
  for(int i = 1; i < tamanho; i++) {
    insertion(vetor, i);
  }
}

void selectionSort(int* vetor, int tamanho) {
  int maior;

  for(int i = tamanho - 1; i > 0; i--) {
    maior = max(vetor, 0, i);
    troca(vetor, i, maior);
  }
}

void bubbleSort(int* vetor, int tamanho) {
  for (int j = tamanho - 1; j > 0; j--) {
    for (int i = 0; i < j - 1; i++) {
      if(vetor[i] > vetor[i + 1]) {
        troca(vetor, i, i+1);
      }
    }    
  }
}