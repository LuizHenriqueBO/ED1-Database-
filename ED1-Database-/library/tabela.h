#include "atributo.h"
#define tam_vet_tupla 4

typedef struct {
    char nome[30];
    NoAtributo* atributos;
    NoDado** tuplas;
    unsigned short int tamTuplas;
    unsigned short int qtdeTuplas;
}Tabela;

/********************** NOMES DAS FUNÇÕES DO PROGRAMA************************/

Tabela* tabela_vazia(char* nome);
Tabela* tabela_criar(char* nome, int tam_vet, char vet_nome[][30], char vet_tipo[][30]);
void tabela_inserir_dados_na_tupla(Tabela* table, char vet_dados[][30],int tam_tupla);
void tabela_imprimir(Tabela* table);
void tabela_destruir(Tabela* table);
/*####################################*/
void tupla_inserir(NoDado* sent_atr, NoDado* sent_tupla, char* elemento);
NoDado* tuplas_criar(NoAtributo* sent_pont_atr, char vet_elem[][30],int tam);
void tupla_imprimir(NoDado* sent_tupla);
void tupla_destruir(NoDado* sen_tupla);

/************************************* F I M ********************************/


/************************* CODIGO DAS TABELAS ******************************/

Tabela* tabela_vazia(char* nome){

    Tabela* new_table = (Tabela*)malloc(sizeof(Tabela));
    new_table->tamTuplas = tam_vet_tupla;
    strcpy(new_table->nome,nome);
    new_table->qtdeTuplas = 0;
    new_table->tuplas = NULL;
    new_table->atributos = NULL;
    return new_table;
}

Tabela* tabela_criar(char* nome, int tam_vet, char vet_nome[][30], char vet_tipo[][30]){
    Tabela* new_table = tabela_vazia(nome);
    new_table->tuplas = (NoDado**)calloc(new_table->tamTuplas,sizeof(NoDado*));
    new_table->atributos = atributo_criar(tam_vet, vet_nome, vet_tipo);
    return new_table;
}

void tabela_inserir_dados_na_tupla(Tabela* table, char vet_dados[][30],int tam_tupla){

    table->tuplas[table->qtdeTuplas] = tuplas_criar(table->atributos,vet_dados,tam_tupla);
    table->qtdeTuplas++;
}

void tabela_imprimir(Tabela* table){

    printf("\n\n # TABELA:  %s",table->nome);
    atributo_imprimir(table->atributos);
    for(int i = 0; i < table->qtdeTuplas; i++){
        tupla_imprimir(table->tuplas[i]);
    }
    printf("\n\n");
}

void tabela_destruir(Tabela* table){/*FALTA COLOCAR OS DADOS DO ATRIBUTO!*/

    atributo_destruir(table->atributos);
    for(int i = 0; i < table->qtdeTuplas; i++){
        tupla_destruir(table->tuplas[i]);
    }
    free(table->tuplas);
    free(table);
    table = NULL;
}

/******************************** FIM *************************************/



/************************* CODIGO DAS TUPLAS ******************************/

void tupla_inserir(NoDado* sent_atr, NoDado* sent_tupla, char* elemento){

    NoDado* novo_dado = dado_criar(elemento);
    /*********** AGRUPAMDO NA SENTINELA TUPLA *******/
    novo_dado->esq = sent_tupla->esq;
    novo_dado->dir = sent_tupla;
    sent_tupla->esq = novo_dado;
    novo_dado->esq->dir = novo_dado;
    /*********** F I M  *******/
    /*********** AGRUPAMDO NA SENTINELA VALORES *******/
    novo_dado->cima = sent_atr->cima;
    novo_dado->baixo = sent_atr;
    sent_atr->cima = novo_dado;
    novo_dado->cima->baixo = novo_dado;
     /*********** F I M  *******/

}


NoDado* tuplas_criar(NoAtributo* sent_pont_atr, char vet_elem[][30],int tam){

    NoAtributo* sent_ponteiro_atr = sent_pont_atr->dir;
    NoDado* aux_sent_atr = sent_ponteiro_atr->valores;
    NoDado* new_tupla_sent = dado_criar("sentinela\0");

    for(int i = 0; i < tam; i++){/*for esta adaptado para o fim do codigo*/
        tupla_inserir(aux_sent_atr, new_tupla_sent, vet_elem[i]);//PARÂM: ATRIBUTO/TUPLA/ELEM.

        sent_ponteiro_atr = sent_ponteiro_atr->dir;
        aux_sent_atr = sent_ponteiro_atr->valores;
    }
    return new_tupla_sent;
}


void tupla_imprimir(NoDado* sent_tupla){/** A FUNÇÃO FOI ADAPTADA PRA RECEBER *VOID E IMPRIMIR**/

    printf(" DADOS: ");
    NoDado* aux = sent_tupla->dir;
    while(aux != sent_tupla){
        char* dado = (char*)aux->elemento;
        printf("  ( %s )   ",dado);
        aux = aux->dir;
    }
    printf("\n");
}

void tupla_destruir(NoDado* sen_tupla){
    NoDado* aux = sen_tupla->dir;
    while(aux != sen_tupla){
        aux = aux->dir;
        dado_deletar(aux->esq);
    }
    free(sen_tupla);
    sen_tupla = NULL;
}

/******************************** FIM *************************************/



