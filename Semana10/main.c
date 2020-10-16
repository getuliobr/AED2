#include <stdio.h>

#include "asciitrie.h"

int main(int argc, char** argv){
    ASCIITrie* T = NULL;

    AT_Inserir_I(&T, "", 42);
    printf("%d\n", T->val);
    // AT_Inserir_I(&T, "o", 1);
    // AT_Inserir_I(&T, "rato", 10);
    // AT_Inserir_I(&T, "roeu", 11);
    // AT_Inserir_I(&T, "a", 2);
    // AT_Inserir_I(&T, "roupa", 12);
    // AT_Inserir_I(&T, "do", 3);
    // AT_Inserir_I(&T, "rei", 13);
    // AT_Inserir_I(&T, "de", 14);
    // AT_Inserir_I(&T, "roma", 15);

    // AT_Imprimir(T);

    // ASCIITrie* r;

    // r = AT_Buscar_I(T, "");
    // r;

    // r = AT_Buscar_I(T, "rato");
    // r;

    // r = AT_Buscar_I(T, "roeu");
    // r;    

    // r = AT_Buscar_I(T, "roam");
    // r;        

    // r = AT_Buscar_I(T, "rou");
    // r;  

    // AT_Remover(&T, "roupa");
    
    // printf("=========");
    // AT_Imprimir(T);

    // AT_Remover(&T, "roma");
    // AT_Remover(&T, "roeu");

    // printf("=========");
    // AT_Imprimir(T);    

}
