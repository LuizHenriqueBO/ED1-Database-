#include "dado.h"

typedef struct noAtributo{
    char nome[30];
    char tipo[30];
    NoDado* valores;
    struct noAtributo* dir;
    struct noAtributo* esq;
} NoAtributo;

NoAtributo* Atributo(char* nome, char* tipo);
void atributo_inserir(NoAtributo* sent_atr, char* nome, char* tipo);
NoAtributo* atributo_criar(int tam_vet, char vet_nome[][30],char vet_tipo[][30]);
void atributo_destruir(NoAtributo* sent_atr);

/*FUNCOES QUE NAO DERAM CERTO!
//NoAtributo* atributo_criar(int tam_vet,char (*vet_nome)[tam_vet],char (*vet_tipo)[tam_vet]);
//NoAtributo* atributo_criar(int tam_vet, int col, char vet_nome[tam_vet][col],char vet_tipo[tam_vet][col]);
//NoAtributo* atributo_criar(int tam_vet, char **vet_nome,char vet_tipo[][30]);
*/

NoAtributo* Atributo(char* nome, char* tipo){

    NoAtributo* new_atributo = (NoAtributo*)malloc(sizeof(NoAtributo));
    new_atributo->dir = new_atributo;
    new_atributo->esq = new_atributo;
    new_atributo->valores = NULL;
    strcpy(new_atributo->nome,nome);
    strcpy(new_atributo->tipo,tipo);
    return new_atributo;
}

void atributo_imprimir(NoAtributo* sent_atr){

    printf("\n\n # ATRUBUTOS: \n");
    NoAtributo* aux = sent_atr->dir;
    printf("\n NOME: ");
    while(aux != sent_atr){
        printf("  [ %s ]  ",aux->nome);
        aux = aux->dir;
    }
    aux = sent_atr->dir;
    printf("\n TIPO: ");
    while(aux != sent_atr){
        printf("   { %s }    ",aux->tipo);
        aux = aux->dir;
    }
    printf("\n\n");
}

NoAtributo* atributo_criar(int tam_vet, char vet_nome[][30],char vet_tipo[][30]){

    NoAtributo* new_atributo = Atributo("Sentinela", "NULL");
    for(int i =0; i< tam_vet; i++){
        atributo_inserir(new_atributo,vet_nome[i],vet_tipo[i]);
    }
    new_atributo->valores = NULL;
    return new_atributo; // retornando o atributo para a tabela
}

void atributo_inserir(NoAtributo* sent_atr, char* nome, char* tipo){

    NoAtributo* novo = Atributo(nome, tipo);
    novo->esq = sent_atr->esq;
    novo->dir = sent_atr;
    sent_atr->esq = novo;
    novo->esq->dir = novo;
    novo->valores = dado_criar("sentinela");
}

void atributo_destruir(NoAtributo* sent_atr){

    NoAtributo* aux = sent_atr->dir;
    while(aux != sent_atr){
        aux = aux->dir;
        dado_deletar(aux->esq->valores);
        free(aux->esq);
    }
    free(sent_atr);
    sent_atr = NULL;
}
