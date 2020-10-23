#pragma once

typedef enum ASCIITrie_ESTADO{
    ATE_LIVRE,
    ATE_OCUPADO
} ASCIITrie_ESTADO;

typedef struct ASCIITrie{
    int val;
    int tam;
    ASCIITrie_ESTADO estado;
    struct ASCIITrie* filhos[256];
} ASCIITrie;

ASCIITrie* AT_Buscar(ASCIITrie* T, unsigned char *chave);
ASCIITrie* AT_Buscar_I(ASCIITrie* T, unsigned char *chave);
void AT_Inserir(ASCIITrie **T, unsigned char *chave, int val);
void AT_Inserir_I(ASCIITrie **T, unsigned char *chave, int val);
ASCIITrie* AT_Criar();
void AT_Remover(ASCIITrie **T, unsigned char *chave);
void AT_Remover_I(ASCIITrie **T, unsigned char *chave);
void AT_Imprimir(ASCIITrie* T);
int AT_Limpa(ASCIITrie* T);
int AT_Tamanho_P(ASCIITrie* T);
int AT_Tamanho_A(ASCIITrie* T);
char* AT_Min(ASCIITrie* T);
char* AT_Max(ASCIITrie* T);
int SubstringCountLenL(char * s, int L);