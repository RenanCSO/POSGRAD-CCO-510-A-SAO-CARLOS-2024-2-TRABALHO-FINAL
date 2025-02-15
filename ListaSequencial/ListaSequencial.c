#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h" 

struct lista {
    int qtd, tamanho;
    struct aluno *dados;
};

Lista* cria_lista() {
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    
    if (li != NULL) {
        li->qtd = 0;
        li->tamanho = MAX;
        li->dados = (struct aluno*) malloc(MAX * sizeof(struct aluno));
    }
    
    return li;
}

void libera_lista(Lista* li) {
    if (li != NULL) {
        free(li->dados);
        free(li);
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    *al = li->dados[i];
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if (li == NULL) {
        return 0;
    }

    if (li->qtd == li->tamanho) { //lista cheia, precisa aumentar a lista em 50%
        int novo_tamamnho = li->tamanho * 1.5;
        struct aluno *novos_dados = (struct aluno*) realloc(li->dados, novo_tamamnho * sizeof(struct aluno));
        
        if (novos_dados == NULL) {
            printf("Erro ao realocar a lista\n");
            return 0;
        }

        li->dados = novos_dados;
        li->tamanho = novo_tamamnho;
    }

    li->dados[li->qtd] = al;
    li->qtd++;
    
    return 1;
}

int remove_lista_otimizado(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 1;
}

int tamanho_lista(Lista* li) {
    if (li == NULL) {
        return -1;
    }
    else {
        return li->tamanho;
    }
}

int qtd_elementos_lista(Lista* li) {
    if (li == NULL) {
        return -1;
    }
    else {
        return li->qtd;
    }
}

int lista_cheia(Lista* li){
    if (li == NULL) {
        return -1;
    }

    return (li->qtd == li->tamanho);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    int i;
    for(i=0; i< li->qtd; i++){
        printf("Matricula: %d\n",li->dados[i].matricula);
        printf("Nome: %s\n",li->dados[i].nome);
        printf("Notas: %f %f %f\n",li->dados[i].n1,
                                   li->dados[i].n2,
                                   li->dados[i].n3);
        printf("-------------------------------\n");
    }
}