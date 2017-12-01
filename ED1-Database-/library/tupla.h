//#include "dado.h"

//tabela->tuplas[Tabela->qtdeTuplas] = tuplas_criar()
//Tabela->qtdeTupla++;

void tupla_inserir(NoDado* sent_tupla, char* dado){

    NoDado* novo_dado = dado_criar(dado);

    novo_dado->esq = sent_tupla->esq;
    novo_dado->dir = sent_tupla;
    sent_tupla->esq = novo_dado;
    novo_dado->esq->dir = novo_dado;

}

NoDado* tuplas_criar(char vet_dados[][30],int tam_tupla){

    NoDado* new_tupla_sent = dado_criar("sentinela");
    /*replicar o codigo!*/
    for(int i = 0; i < tam_tupla; i++){
        tupla_inserir(new_tupla_sent, vet_dados[i]);
    }
    return new_tupla_sent;
}


void tupla_imprimir(NoDado* sent_tupla){

    printf("\n DADOS DA TUPLA: \n");
    NoDado* aux = sent_tupla->dir;
    while(aux != sent_tupla){
        printf(" %s \n",aux->dado);
        aux = aux->dir;
    }
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



