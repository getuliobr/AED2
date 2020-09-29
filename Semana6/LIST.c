#include "LIST.h"
#include <stdio.h>
#include <stdlib.h>

LIST* createNode(int key, int value){
  LIST* out = (LIST*) malloc(sizeof(LIST));
  out->value = value;
  out->prox = NULL;
  return out;
}

LIST* LIST_create() {
  return createNode(-1, 0);
}

int LIST_size(LIST* list) {
  return list->value;
}

int LIST_insert(LIST* list, int key, int val) {
  LIST* curr = list;
  
  while(curr->prox != NULL) {
    if(curr->key == key) return ERROR;
    curr = curr->prox;
  }

  if(curr->key == key) return ERROR;
  
  LIST* node = createNode(key, val);
  curr->prox = node;

  list->value++;

  return SUCCESS;
}

void LIST_print(LIST* list) {
  LIST* curr = list->prox;
  printf("[");

  while(curr != NULL){
    printf("%d", curr->value);
    curr = curr->prox;
    if(curr != NULL) printf(", ");
  }

  printf("]\n");
}