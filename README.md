# POSGRAD-CCO-510-A-SAO-CARLOS-2024-2-TRABALHO-FINAL

Repositório destinado ao código fonte do trabalho da disciplina de Estrutura de Dados (CCO-510-A 2024/02) do Programa de Pós-graduação em Ciência da Computação da UFSCar - São Carlos

## Descrição

Este projeto tem como objetivo avaliar o desempenho da estrutura de dados tabela Hash durante a operação de inserção de dados, considerando diferentes configurações, como o tamanho inicial da tabela, a escolha entre tamanhos primos ou não, a utilização de diversas funções de espalhamento, entre outros. Para tanto, é utilizado a estrutura de Hash com Encadeamento Separado através de Lista Sequencial.

Os códigos fontes se baseiam na implatação das estruturas disponível em: https://github.com/arbackes/Estrutura-de-Dados-em-C/

## Estrutura do Projeto

- `src/`: Contém os arquivos fonte (.c)
- `include/`: Contém os arquivos de cabeçalho (.h)
- `test/`: Contém o arquivo de dados de entrada para teste do programa (.txt)

## Compilação e Execução

Para compilar o projeto, utilize o comando:

gcc -o main src/main.c src/TabelaHash.c src/ListaSequencial.c

## Para executar o programa principal, utilize o comando:

./main
