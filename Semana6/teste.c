#include "LIST.h"
#include <stdio.h>

int main() {
  LIST* teste = LIST_create();
  for(int i = 0; i < 10; i++){
    LIST_insert(teste, i, i*10);
  }
  LIST_print(teste);
}