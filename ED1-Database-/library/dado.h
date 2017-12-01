#include "lib.h"

typedef struct noDado{
    void* elemento;/*trabalhar com void e depois fazer um cast ao acessar o dado ou na hora de guardar o dado*/
    int tamDado;
    struct noDado* dir;
    struct noDado* esq;
    struct noDado* cima;
    struct noDado* baixo;
}NoDado;

NoDado* dado_criar(char* elemento);
void dado_deletar(NoDado* dado);

NoDado* dado_criar(char* elemento){

    int tam = (strlen(elemento)+1);
    char* elem_dado = (char*)calloc(tam,sizeof(char));
    strcpy(elem_dado,elemento);

    NoDado* new_dado = (NoDado*)malloc(sizeof(NoDado));
    new_dado->tamDado = tam;
    new_dado->elemento = (void*)elem_dado;// PARA RECEBER *VOID
    strcpy(new_dado->elemento,elemento);
    new_dado->dir = new_dado;
    new_dado->esq = new_dado;
    new_dado->cima = new_dado;
    new_dado->baixo = new_dado;

    return new_dado;
}

void dado_deletar(NoDado* dado){
    free(dado->elemento);
    free(dado);
    dado =  NULL;
}


