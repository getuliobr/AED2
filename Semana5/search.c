#include "search.h"
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

void troca(int* vetor, int pos1, int pos2) {
  int aux = vetor[pos1];
  vetor[pos1] = vetor[pos2];
  vetor[pos2] = aux;
}

int max(int* vector, int start, int end) {
  int max = start;
  for(int i = start; i < end; i++)
    if(vector[i] > vector[max])
      max = i;

  return max;
}

int min(int* vector, int start, int end) {
  int minimum = start;
  for(int i = start; i < end; i++)
    if(vector[i] <= vector[minimum])
      minimum = i;

  return minimum;
}

int SelectionMinK(int *v, int n, int k) {
  if(k >= n) {
    return v[max(v,0,n)];
  }

  int menor;
  for(int i = 0; i < k; i++) {
    menor = min(v, i, n);
    troca(v, i, menor);
  }

  return v[k - 1];
}

int esq(int i) {
  return 2*i + 1;
}

int dir(int i) {
  return 2*i + 2;
}

void minHeapify(int* v, int i, int th) {
  int esquerda = esq(i);
  int direita = dir(i);
  int menor = i;
  if((esquerda < th) && (v[esquerda] < v[menor])) menor = esquerda;
  if((direita < th) && (v[direita] < v[menor])) menor = direita;
  if(menor != i) {
    troca(v, i, menor);
    minHeapify(v, menor, th);
  }
}

void buildMinHeap(int* v, int n) {
  for(int i = n/2; i >= 0; i--) minHeapify(v, i, n);
}

int remover_min(int* fp, int n) {
  troca(fp, 0, n - 1);
  minHeapify(fp, 0, n - 1);
  return n - 1;
}

int HeapMinK(int *v, int n, int k) {
  if(k >= n) {
    return v[max(v,0,n)];
  }

  buildMinHeap(v, n);
  int out = v[0];
  int size = n;

  for(int i=0; i < k - 1; i++) {
    size = remover_min(v, size);
    out = v[0];
  }

  return out;
}

int partition(int* v, int p, int r) {
  srand(time(NULL));
  troca(v, r - 1, rand() % (r - p) + p);
  int x = v[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(v[j] <= x) {
      i++;
      troca(v, i, j);
    }
  }
  troca(v, i + 1, r);
  return i + 1;
}

int QuickMinK(int *v, int e, int d, int k) {
  int pivo;
  int valorPivo;

  if(k > d && !e) return v[max(v, e, d)];

  if(e <= d) {
    pivo = partition(v, e, d);
    if(pivo == k - 1) return v[pivo];
    else if(pivo > k - 1) valorPivo = QuickMinK(v, e, pivo - 1, k);
    else valorPivo = QuickMinK(v, pivo, d, k);
  }

  return valorPivo;
}

void embaralhar(int *v, int ini, int fim, int seed){
  int i, j;
  srand(seed);
  for(i = fim-1; i > ini; i--){
    j = (rand() % (i + 1));
    j = j <= ini ? ini+1 : j;
    troca(v, i, j);
  }
}

int* random_vector_unique_elems(int n, int seed) {
  int* out = (int *) calloc(sizeof(int), n);
  for(int i=0; i < n; i++){
    out[i] = i + 1;
  }
  embaralhar(out, 0, n, seed);
  return out;
}

