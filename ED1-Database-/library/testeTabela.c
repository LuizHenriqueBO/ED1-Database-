#include <stdio.h>
#include "tabela.h"

/*funções*/


void funcao_tabela1(int tam){

    char nome2[3][30] = {{"atrib 1\0"},{"atrib 2\0"},{"atrib 3\0"}};
    char tipo2[3][30] = {{"tip1\0"},{"tip2\0"},{"tip3\0"}};
    Tabela* nova2 = tabela_criar("tabela 1\0",tam, nome2, tipo2);

    char dado[3][30] = {{"dado 1\0"},{"dado 2\0"},{"dado 3\0"}};
    tabela_inserir_dados_na_tupla(nova2,dado,tam);
    char dados[3][30] = {{"dado 4\0"},{"dado 5\0"},{"dado 6\0"}};
    tabela_inserir_dados_na_tupla(nova2,dados,tam);
    char dadoss[3][30] = {{"dado 7\0"},{"dado 8\0"},{"dado 9\0"}};
    tabela_inserir_dados_na_tupla(nova2,dadoss,tam);

    tabela_imprimir(nova2);
    tabela_destruir(nova2);
}


void funcao_tabela2(int tam){

    char nome[3][30] = {{"atrib 1\0"},{"atrib 2\0"},{"atrib 3\0"}};
    char tipo[3][30] = {{"tip1\0"},{"tip2\0"},{"tip3\0"}};
    Tabela* nova = tabela_criar("tabela 2\0",tam, nome, tipo);

    char dado[3][30] = {{"dado 1\0"},{"dado 2\0"},{"dado 3\0"}};
    tabela_inserir_dados_na_tupla(nova,dado,tam);
    char dados[3][30] = {{"dado 4\0"},{"dado 5\0"},{"dado 6\0"}};
    tabela_inserir_dados_na_tupla(nova,dados,tam);
    char dadoss[3][30] = {{"dado 7\0"},{"dado 8\0"},{"dado 9\0"}};
    tabela_inserir_dados_na_tupla(nova,dadoss,tam);

    tabela_imprimir(nova);
    tabela_destruir(nova);
}

void funcao_tabela3(int tam){

    char nome2[3][30] = {{"atrib 1\0"},{"atrib 2\0"},{"atrib 3\0"}};
    char tipo2[3][30] = {{"tip1\0"},{"tip2\0"},{"tip3\0"}};
    Tabela* nova2 = tabela_criar("tabela 3\0",tam, nome2, tipo2);

    char dado[3][30] = {{"dado 1\0"},{"dado 2\0"},{"dado 3\0"}};
    tabela_inserir_dados_na_tupla(nova2,dado,tam);
    char dados[3][30] = {{"dado 4\0"},{"dado 5\0"},{"dado 6\0"}};
    tabela_inserir_dados_na_tupla(nova2,dados,tam);
    char dadoss[3][30] = {{"dado 7\0"},{"dado 8\0"},{"dado 9\0"}};
    tabela_inserir_dados_na_tupla(nova2,dadoss,tam);

    tabela_imprimir(nova2);
    tabela_destruir(nova2);
}


void funcao_tabela(){

    int tam = 3;
    funcao_tabela1(tam);
    //funcao_tabela2(tam);
   // funcao_tabela3(tam);
}

int main(){
    funcao_tabela();/*TESTANDO TABELAS!*/
    return 0;
}

