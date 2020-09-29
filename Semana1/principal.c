#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int comparacoes;
int trocas;

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
  trocas++;
}

int max(int* vector, int start, int end) {
  int max = start;

  for(int i = start; i <= end; i++) {
    if(vector[i] > vector[max]){
      max = i;
    }
    comparacoes++;
  }

  return max;
}

void insertion(int* vetor, int k) {
  int i = k - 1;
  int aux = vetor[k];
  while((i >= 0) && (vetor[i] > aux)) {
    vetor[i + 1] = vetor[i];
    i--;
    comparacoes++;
  }
  vetor[i + 1] = aux;
}

void insertionSort(int *vetor, int tamanho) {
  comparacoes = 0;
  for(int i = 1; i < tamanho; i++) {
    insertion(vetor, i);
  }
}

void selectionSort(int* vetor, int tamanho) {
  comparacoes = 0;
  trocas = 0;
  int maior;

  for(int i = tamanho - 1; i > 0; i--) {
    maior = max(vetor, 0, i);
    troca(vetor, i, maior);
  }
  printf("Trocas: %d\n", trocas);
}

void bubbleSort(int* vetor, int tamanho) {
  comparacoes = 0;
  trocas = 0;

  for (int j = tamanho - 1; j > 0; j--) {
    for (int i = 0; i < j - 1; i++) {
      if(vetor[i] > vetor[i + 1]) {
        troca(vetor, i, i+1);
      }
      comparacoes++;
    }    
  }
  printf("Trocas: %d\n", trocas);

}

void gerarTabela(char* nome, void funcao(int* vetor, int tamanho), int tamanho) {
  int* vetor;
  clock_t t;
  printf("%s\n", nome);
  vetor = random_vector(tamanho, 1000, 0);
  t = clock();
  funcao(vetor, tamanho);
  t = clock() - t;
  printf("Comparacoes: %d\n", comparacoes);
  printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);
}

int main() {
  clock_t t;
  int* vetor;
  int tamanho = 10;
  for(int i = 0; i < 4; i++){
    printf("----------------\nTamanho: %d\n----------------\n", tamanho);
    gerarTabela("BUBBLE", bubbleSort, tamanho);
    gerarTabela("INSERTION", insertionSort, tamanho);
    gerarTabela("SELECTION", selectionSort, tamanho);
    tamanho *= 10;
  }
}

