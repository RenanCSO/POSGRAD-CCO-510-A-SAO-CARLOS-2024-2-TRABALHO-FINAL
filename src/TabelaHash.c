#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/TabelaHash.h"
#include "../include/ListaSequencial.h"

struct hash {
    int qtd, qtd_listas, qtd_colisoes, TABLE_SIZE;
    struct lista **itens;
};

Hash* criaHash(int TABLE_SIZE) {
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if (ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->qtd = 0;
        ha->qtd_listas = 0;
        ha->qtd_colisoes = 0;

        ha->itens = (struct lista**) malloc(TABLE_SIZE * sizeof(struct lista*));

        if (ha->itens == NULL) {
            free(ha);
            return NULL;
        }

        for(i = 0; i < ha->TABLE_SIZE; i++) {
            ha->itens[i] = NULL;
        }
    }

    return ha;
}

void liberaHash(Hash* ha) {
    if (ha != NULL) {
        int i;
        for(i=0; i < ha->TABLE_SIZE; i++) {
            if (ha->itens[i] != NULL) {
                libera_lista(ha->itens[i]);
            }
        }

        free(ha->itens);
        free(ha);
    }
}

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int chaveDobra(int chave, int TABLE_SIZE){
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE-1);

    // Código fonte base alterado para retornar um valor semppre válido para a tabela hash
    return (parte1 ^ parte2) % TABLE_SIZE;
}

int chaveMultiplicacao(int chave, int TABLE_SIZE){
    double A = 0.6180339887; // constante: 0 < A < 1
    double val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
}

int insereHash_EncadeamentoFechado(Hash* ha, struct aluno al) {
    if (ha == NULL) {
        return 0;
    }
        
    int chave = al.matricula;
    
    int i, pos, newPos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);
    
    // Verifica se a posicao do Hash esta vazia. Se estiver vazia, cria uma lista
    if (ha->itens[pos] == NULL) {
        ha->itens[pos] = cria_lista();
        
        if (ha->itens[pos] == NULL) {
            return 0;
        }

        ha->qtd_listas++;
    } else {
        // Se a posicao nao estiver vazia, entao houve colisao
        ha->qtd_colisoes++;
    }
    
    // Cria um novo aluno
    struct aluno* novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if (novo == NULL) {
        return 0;
    }
    *novo = al;

    // Insere o aluno na lista de encadeamento fechado
    if (insere_lista_final(ha->itens[pos], *novo) == 0) {
        return 0;
    }
    ha->qtd++;

    return 1;
}

int buscaHash_EncadeamentoFechado(Hash* ha, int mat, struct aluno* al) {
    if (ha == NULL) {
        return 0;
    }
        
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if (ha->itens[pos] == NULL) {
        return 0;
    }
    
    if (consulta_lista_mat(ha->itens[pos], mat, al) == 0) {
        return 0;
    }

    return 1;
}

int removeHash_EncadeamentoFechado(Hash* ha, int mat) {
    if (ha == NULL) {
        return 0;
    }

    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if (ha->itens[pos] == NULL) {
        return 0;
    }
    
    if (remove_lista_otimizado(ha->itens[pos], mat) == 0) {
        return 0;
    }
    ha->qtd--;

    return 1;
}

void imprimeEstastisticasHash(Hash* ha) {
    if (ha == NULL) {
        return;
    }

    int i;
    int total_posicoes_listas = 0;
    int total_posicoes_ociosas_listas = 0;
    int tamanho_medio_listas = 0;
    int menor_tamanho_lista = 2147483647;
    int maior_tamanho_lista = 0;

    for(i = 0; i < ha->TABLE_SIZE; i++) {
        if (ha->itens[i] != NULL) {
            int tam_lista = tamanho_lista(ha->itens[i]);
            total_posicoes_listas += tam_lista;
            total_posicoes_ociosas_listas += tam_lista - qtd_elementos_lista(ha->itens[i]);

            if (menor_tamanho_lista > tam_lista) {
                menor_tamanho_lista = tam_lista;
            }
            
            if (maior_tamanho_lista < tam_lista) {
                maior_tamanho_lista = tam_lista;
            }
        }
    }

    tamanho_medio_listas = total_posicoes_listas / ha->qtd_listas;

    printf("---------- ESTATISTICAS DA TABELA HASH ----------\n");
    printf("Quantidade de elementos na tabela hash: %d\n", ha->qtd);
    printf("Quantidade de colisoes: %d\n", ha->qtd_colisoes);
    printf("Quantidade de listas utilizadas pela tabela hash: %d\n", ha->qtd_listas);
    printf("Tamanho medio das listas: %d\n", tamanho_medio_listas);
    printf("Menor tamanho de lista: %d\n", menor_tamanho_lista);
    printf("Maior tamanho de lista: %d\n", maior_tamanho_lista);
    printf("Quantidade total de posicoes nas listas: %d\n", total_posicoes_listas);
    printf("Quantidade total de posicoes ociosas nas listas: %d\n", total_posicoes_ociosas_listas);
    printf("-------------------------------------------------\n");
}
