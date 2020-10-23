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
    out->tam = 0;
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
    (*T)->tam++; 
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
    (*T)->tam--;
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

void AT_Inserir_I(ASCIITrie **T, unsigned char *chave, int val) {
    int n = strlen(chave);
    ASCIITrie** atual = T;
    if(n == 0) {
        if(*atual == NULL) {
            *atual = AT_Criar();
            (*atual)->val = val;
        }
        return;
    }
    (*T)->tam++;
    for(int i = 0; i <= n; i++) {
        if(*atual == NULL) *atual = AT_Criar();
        if(i == n) {
            (*atual)->val = val;
            (*atual)->estado = ATE_OCUPADO;
            return;
        }
        atual = &((*atual)->filhos[chave[i]]);
    }
}

void AT_Remover_I(ASCIITrie **T, unsigned char *chave) {
    int n = strlen(chave);

    ASCIITrie ***remover = (ASCIITrie***) calloc(sizeof(ASCIITrie**), n);
    ASCIITrie **atual = T;

    int qtde = 0;

    for(int i = 0; i <= n; i++) {
        if(*atual == NULL) break;

        int filhoCount = 0;

        if(i == n) (*atual)->estado = ATE_LIVRE;

        for(int j = 0; j < 256; j++) {
            if((*atual)->filhos[j] != NULL) filhoCount++;
        }

        if(filhoCount == 1) remover[qtde++] = atual;

        atual = &((*atual)->filhos[chave[i]]);
    }
    if(!qtde) return;
    
    free(*(atual));
    *(atual) = NULL;

    for(int i = 0; i < qtde; i++){
        free(*(remover[i]));
        *(remover[i]) = NULL;
    }
    (*T)->tam--;
}

int AT_Limpa(ASCIITrie* T) {
    int clean = 1;
    int folha = 1;
    if(!T) return 1;

    for(int i = 0; i < 256; i++) {
        if(T->filhos[i]) {
            clean = AT_Limpa(T->filhos[i]);
            if(!clean) return 0;

            folha = 0;
        }
    }

    if(!folha) return clean;
    else return (int)T->estado;
}

int AT_Tamanho_P(ASCIITrie* T) {
    int count = 0;
    for(int i = 0; i < 256; i++) {
        if(T->filhos[i]) count += AT_Tamanho_P(T->filhos[i]);
    }
    return count + (int)T->estado;
}

int AT_Tamanho_A(ASCIITrie* T) {
    return T->tam;
}

static void AT_Min_R(ASCIITrie* T, char** out) {
    int size = strlen(*out);
    char* new = (char*) malloc(size + 2); // 1 para um caracter e 1 para \0
    strcpy(new, *out);
    free(out);
    *out = new;
    for(int i = 0; i < 256; i++) {
        if(T->filhos[i]) {
            char toAppend = (char) i;
            strncat(*out, &toAppend, 1);
            AT_Min_R(T->filhos[i], out);
            return;
        }
    }
}

char* AT_Min(ASCIITrie* T) {
    char* out = "";
    AT_Min_R(T, &out);
    return out;
}

static void AT_Max_R(ASCIITrie* T, char** out) {
    int size = strlen(*out);
    char* new = (char*) malloc(size + 2); // 1 para um caracter e 1 para \0
    strcpy(new, *out);
    free(out);
    *out = new;
    for(int i = 255; i >= 0; i--) {
        if(T->filhos[i]) {
            char toAppend = (char) i;
            strncat(*out, &toAppend, 1);
            AT_Max_R(T->filhos[i], out);
            return;
        }
    }
}

char* AT_Max(ASCIITrie* T) {
    char* out = "";
    AT_Max_R(T, &out);
    return out;
}

int SubstringCountLenL(char * s, int L) {
    int n = strlen(s);
    if(L > n) return 0;

    ASCIITrie* T = NULL;
    AT_Inserir(&T, "", 42);
    T->tam = 0;

    char* substring = (char*) malloc(L);

    for(int i = 0; i < n; i++) {
        if(i + L > n) break;
        for(int j = i, k = 0; j < (i + L); j++, k++) {
            substring[k] = s[j];
        }
        AT_Inserir_I(&T, substring, i);
    }
    return AT_Tamanho_A(T);
}