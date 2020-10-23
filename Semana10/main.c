#include <stdio.h>
#include <stdlib.h>
#include "asciitrie.h"

int main(int argc, char** argv){
    FILE *arq = fopen(argv[1], "r");
    int L = atoi(argv[2]);
    
    fseek(arq, 0, SEEK_END);
    int tam = ftell(arq);
    fseek(arq, 0, SEEK_SET);

    char* string = (char*) malloc(tam + 1);
    fread(string, 1, tam, arq);

    string[tam] = '\0';

    fclose(arq);

    int c = SubstringCountLenL(string, L);
    printf("Count: %d\n", c);
}
