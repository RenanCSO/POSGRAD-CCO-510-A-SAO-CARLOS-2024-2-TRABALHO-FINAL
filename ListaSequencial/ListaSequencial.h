#ifndef ALUNO_H
#define ALUNO_H
#include "../aluno.h"
#endif

#define MAX 10

typedef struct lista Lista;
Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
int insere_lista_final(Lista* li, struct aluno al);
int remove_lista_otimizado(Lista* li, int mat);
int tamanho_lista(Lista* li);
int qtd_elementos_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);

