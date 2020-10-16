#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "asciitrie.h"

ASCIITrie* AT_Buscar_R(ASCIITrie* T, unsigned char *chave, int n, int p) {
    if(T == NULL || p == n) return T;
    return AT_Buscar_R(T->filhos[chave[p]], chave, n, p+1);
}

ASCIITrie* AT_Buscar(ASCIITrie* T, unsigned char *chave) {
    return AT_Buscar_R(T, chave, strlen(chave), 0);
}

ASCIITrie* AT_Criar() {
    ASCIITrie* out = (ASCIITrie*) malloc(sizeof(ASCIITrie));
    out->val = 0;
    out->estado = ATE_LIVRE;
    for(int i =0; i <256; i++) out->filhos[i] = NULL;
    return out;
}

void AT_Inserir_R(ASCIITrie **T, unsigned char *chave, int val, int n, int p) {
    if(*T == NULL) {
        *T = AT_Criar();
    }
    if(p == n) {
        (*T)->val = val;
        (*T)->estado = ATE_OCUPADO;
        return;
    }
    AT_Inserir_R(&(*T)->filhos[chave[p]], chave, val, n, p+1);    
}

void AT_Inserir(ASCIITrie **T, unsigned char *chave, int val) {
    AT_Inserir_R(T, chave, val, strlen(chave), 0);    
}

void AT_Remover_R(ASCIITrie **T, unsigned char *chave, int n, int p) {
    if(*T == NULL) return;
    if(p == n) {
        (*T)->estado = ATE_LIVRE;
    } else {
        AT_Remover_R(&(*T)->filhos[chave[p]], chave, n, p+1);
    }
    if((*T)->estado == ATE_OCUPADO)
        return;
    for(int i = 0; i < 256; i++) {
        if((*T)->filhos[i] != NULL) return;
    }
    free(*T);
    *T = NULL;
}

void AT_Remover(ASCIITrie **T, unsigned char *chave) {
    AT_Remover_R(T, chave, strlen(chave), 0);
}

void AT_Imprimir_R(ASCIITrie* T, int nivel, unsigned char c) {
    if(T == NULL) return;
    for(int i = 0; i < nivel; i++) printf("-");
    char estado = T->estado == ATE_OCUPADO ? 'O' : 'L';
    printf("(%c) %d (%c)\n", c, T->val, estado);
    for(int i = 0; i < 256; i++) AT_Imprimir_R(T->filhos[i], nivel+1, i);
}

void AT_Imprimir(ASCIITrie* T) {
    AT_Imprimir_R(T, 0, 0);
}

ASCIITrie* AT_Buscar_I(ASCIITrie* T, unsigned char *chave) {
    int n = strlen(chave);
    ASCIITrie* atual = T;
    for(int i = 0; i < n; i++) {
        if(atual->filhos[chave[i]] == NULL) return NULL;
        atual = atual->filhos[chave[i]];
    }
    return atual;
}

void AT_Inserir_I(ASCIITrie **T, unsigned char *chave, int val) { // TODO: fix
    int n = strlen(chave);
    ASCIITrie* atual = *T;
    if(n == 0) { // vou considerar que assim que inicia uma arvore
        atual = AT_Criar();
        return;
    }
    for(int i = 0; i < n; i++) {
        if(atual == NULL) atual = AT_Criar();
        if(i == n-1) {
            atual->val = val;
            atual->estado = ATE_OCUPADO;
            return;
        }
        atual = atual->filhos[chave[i]];
    }
}