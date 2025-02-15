
#ifndef ALUNO_H
#define ALUNO_H
#include "../include/aluno.h"
#endif

#include <stdio.h>
#include <stdlib.h>

#include "../include/TabelaHash.h"

int main() {
    struct aluno alunos;
    FILE *arquivo;

    int TABLE_SIZE = 719;
    Hash *tabelaHash = criaHash(TABLE_SIZE);
    if (tabelaHash == NULL) {
        printf("Erro ao criar a tabela hash\n");
        return 1;
    }

    arquivo = fopen("test/dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while (fscanf(arquivo, "%d %s %f %f %f", &alunos.matricula, alunos.nome, &alunos.n1, &alunos.n2, &alunos.n3) != EOF) {
        insereHash_EncadeamentoFechado(tabelaHash, alunos);
    }

    fclose(arquivo);

    imprimeEstastisticasHash(tabelaHash);

    liberaHash(tabelaHash);

    return 0;
}
