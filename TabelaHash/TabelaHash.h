#ifndef ALUNO_H
#define ALUNO_H
#include "../aluno.h"
#endif

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int chaveDivisao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);
int insereHash_EncadeamentoFechado(Hash* ha, struct aluno al);
int buscaHash_EncadeamentoFechado(Hash* ha, int mat, struct aluno* al);
int removeHash_EncadeamentoFechado(Hash* ha, int mat);
void imprimeEstastisticasHash(Hash* ha);