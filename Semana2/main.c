#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

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

void gerarTabela(char* nome, void funcao(int* vetor, int tamanho), int tamanho, int* vetor) {
  clock_t t;
  printf("%s\n", nome);
  if(vetor == NULL) vetor = random_vector(tamanho, tamanho * 100, 0);
  t = clock();
  funcao(vetor, tamanho);
  t = clock() - t;
  printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);
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

void quicksort(int* v, int e, int d) {
  int q;
  if(e < d){
    q = partition(v, e, d);
    quicksort(v, e, q-1);
    quicksort(v, q + 1, d);
  }
}

void merge(int* v, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int *e = malloc(sizeof(int) * (n1 + 1));
  memcpy(e, v + p, sizeof(int) * n1);
  e[n1] = INT_MAX;

  int *d = malloc(sizeof(int) * (n2 + 1));
  memcpy(d, v + q + 1, sizeof(int) * n2);
  d[n2] = INT_MAX;

  int i = 0;
  int j = 0;
  for(int k = p; k <= r; k++) {
    if(e[i] <= d[j]){
      v[k] = e[i];
      i++;
    } else {
      v[k] = d[j];
      j++;
    }
  }
  free(e);
  free(d);
}

void mergeSort(int *v, int e, int d) {
  if(e < d) {
    int m = (e + d) / 2;
    mergeSort(v, e, m);
    mergeSort(v, m + 1, d);
    merge(v, e, m, d);
  }
}

int* sorted_random_vector(int n, int max, int seed) {
  int* v = random_vector(n, max, seed);
  quicksort(v, 0, n - 1);
  return v;
}

int main() {
  clock_t t;
  int* vetor;
  int tamanho = 1000;
  for(int i = 0; i < 3; i++){
    printf("----------------\nTamanho: %d\n----------------\n", tamanho);
    gerarTabela("BUBBLE", bubbleSort, tamanho, NULL);
    gerarTabela("INSERTION", insertionSort, tamanho, NULL);
    gerarTabela("SELECTION", selectionSort, tamanho, NULL);

    printf("%s\n", "QUICK");
    vetor = random_vector(tamanho, tamanho * 100, 0);
    t = clock();
    quicksort(vetor, 0, tamanho);
    t = clock() - t;
    printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);
    
    printf("%s\n", "MERGE");
    vetor = random_vector(tamanho, tamanho * 100, 0);
    t = clock();
    mergeSort(vetor, 0, tamanho - 1);
    t = clock() - t;
    printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);

    tamanho *= 10;
  }

  tamanho = 500000;

  printf("----------------\nTamanho: %d\n----------------\n", tamanho);
    gerarTabela("BUBBLE", bubbleSort, tamanho, NULL);
    gerarTabela("INSERTION", insertionSort, tamanho, NULL);
    gerarTabela("SELECTION", selectionSort, tamanho, NULL);

    printf("%s\n", "QUICK");
    vetor = random_vector(tamanho, tamanho * 100, 0);
    t = clock();
    quicksort(vetor, 0, tamanho);
    t = clock() - t;
    printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);
    
    printf("%s\n", "MERGE");
    vetor = random_vector(tamanho, tamanho * 100, 0);
    t = clock();
    mergeSort(vetor, 0, tamanho - 1);
    t = clock() - t;
    printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);

  
  printf("----------------\nOrdenado\n----------------\n");
  tamanho = 1000;

  for(int i = 0; i < 3; i++){
    printf("----------------\nTamanho: %d\n----------------\n", tamanho);
    gerarTabela("BUBBLE", bubbleSort, tamanho, vetor);
    gerarTabela("INSERTION", insertionSort, tamanho, vetor);
    gerarTabela("SELECTION", selectionSort, tamanho, vetor);

    printf("%s\n", "QUICK");
    t = clock();
    quicksort(vetor, 0, tamanho);
    t = clock() - t;
    printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);
    
    printf("%s\n", "MERGE");
    t = clock();
    mergeSort(vetor, 0, tamanho - 1);
    t = clock() - t;
    printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);

    tamanho *= 10;
  }

  tamanho = 500000;
  vetor = sorted_random_vector(tamanho, tamanho * 100, 0);

  printf("----------------\nTamanho: %d\n----------------\n", tamanho);
    gerarTabela("BUBBLE", bubbleSort, tamanho, vetor);
    gerarTabela("INSERTION", insertionSort, tamanho, vetor);
    gerarTabela("SELECTION", selectionSort, tamanho, vetor);

    printf("%s\n", "QUICK");
    t = clock();
    quicksort(vetor, 0, tamanho);
    t = clock() - t;
    printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);
    
    printf("%s\n", "MERGE");
    t = clock();
    mergeSort(vetor, 0, tamanho - 1);
    t = clock() - t;
    printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);
}

