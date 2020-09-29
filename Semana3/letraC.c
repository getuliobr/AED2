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

int raiz(int i) {
  return (i - 1) / 2;
}

int esq(int i) {
  return 2*i + 1;
}

int dir(int i) {
  return 2*i + 2; //esq(i) + 1
}

void maxHeapify(int* v, int i, int th) {
  int esquerda = esq(i);
  int direita = dir(i);
  int maior = i;
  if((esquerda < th) && (v[esquerda] > v[maior])) maior = esquerda;
  if((direita < th) && (v[direita] > v[maior])) maior = direita;
  if(maior != i) {
    troca(v, i, maior);
    maxHeapify(v, maior, th);
  }
}

void buildMaxHeap(int* v, int n) {
  for(int i = n/2; i >= 0; i--) maxHeapify(v, i, n);
}

void heapsort(int* v, int n) {
  for(int i = n - 1; i > 0; i--) {
    troca(v, 0, i);
    maxHeapify(v, 0, i);
  }
}

int FP_inicio(int* fp, int n) {
  return fp[0];
}

int FP_remover_max(int* fp, int n) {
  troca(fp, 0, n - 1);
  buildMaxHeap(fp, n - 1);
  return n - 1;
}

int FP_inserir_max(int* fp, int n, int x) {
  fp[n] = x;
  int pos = n;
  while(fp[pos] > fp[raiz(pos)] && pos > 0) {
    troca(fp, pos, raiz(pos));
    pos = raiz(pos);
  }
  return n + 1;
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

void heapsortMin(int* v, int n) {
  for(int i = n - 1; i > 0; i--) {
    troca(v, 0, i);
    minHeapify(v, 0, i);
  }
}

int FP_remover_min(int* fp, int n) {
  troca(fp, 0, n - 1);
  buildMinHeap(fp, n - 1);
  return n - 1;
}

int FP_inserir_min(int* fp, int n, int x) {
  fp[n] = x;
  int pos = n;
  while(fp[pos] < fp[raiz(pos)] && pos > 0) {
    troca(fp, pos, raiz(pos));
    pos = raiz(pos);
  }
  return n + 1;
}

int main(int argc, char const *argv[]){
  clock_t t = clock();
  FILE *file = fopen(argv[1], "r");

  if(!file) return 0;

  int M, N;
  fscanf(file,"%d", &M);
  fscanf(file,"%d", &N);
  int* X = (int*) calloc(sizeof(int), M);
  for(int i = 0; i < M; i++){
    fscanf(file,"%d", &X[i]);
  }
  buildMinHeap(X, M);
  int lucro = 0;
  int disponiveis = M;
  int menor = FP_inicio(X, disponiveis);
  for(int i = 0; i < N; i++, menor--) {
    if(menor == 0) {
      disponiveis = FP_remover_min(X, disponiveis);
      menor = FP_inicio(X, disponiveis);
    }
    int preco = 100 + 100/menor;
    lucro += preco;
  }

  printf("lucro: %d\n", lucro);
  t = clock() - t;
  printf("Tempo: %f\n", ((float)t)/CLOCKS_PER_SEC);

  return 0;
}


