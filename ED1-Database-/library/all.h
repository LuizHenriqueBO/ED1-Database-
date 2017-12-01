typedef struct noDado{
    void* dado;
    int tamDado;
    struct noDado* dir;
    struct noDado* esq;
    struct noDado* cima;
    struct noDado* baixo;
} NoDado;

typedef struct noAtributo{
    char nome[30];
    char tipo[30];
    NoDado* valores;
    struct noAtributo* dir;
    struct noAtributo* esq;
} NoAtributo;

typedef struct {
    char nome[30];
    NoAtributo* atributos;
    NoDado** tuplas;
    unsigned short int tamTuplas;
    unsigned short int qtdeTuplas;
} Tabela;


typedef struct {
    char nome[30];
    Tabela** tabelas;
    unsigned short int tamTabelas;
    unsigned short int qtdeTabelas;
} Database;


// PROTOTIPOS EXEMPLO
Database* criarDatabase(char* nome);
void criarTabela(Database* db, char* nome, char* atributos, char* tipos, int qtdeAtributos);



// FUNCOES AUXILIARES
void printDado(void* dado, char* tipo){
    if(strcmp(tipo,"string")==0){
        printf("%s\t", *(char*)dado);
    } else if (strcmp(tipo,"integer")==0){
        printf("%d\t", *(int*)dado);
    } else if (strcmp(tipo,"float")==0){
        printf("%.2f\t", *(float*)dado);
    }
}

void imprimirTupla(NoDado* sentinelaTupla, NoAtributo* sentinelaAtributo){

    NoDado* auxDado = sentinelaTupla->dir;
    NoAtributo* auxAtributo = sentinelaAtributo->dir;
    while(auxDado != sentinelaTupla){
        printDado(auxDado->dado, auxAtributo->tipo);
        auxDado = auxDado->dir;
        auxAtributo = auxAtributo->dir;
    }

}

void imprimirTabela(Tabela* table){
    printf("Tabela: %s\n", table->nome);
    //imprime o cabecalho da tabela
    NoAtributo* aux = table->atributos->dir;
    while(aux != table->atributos){
        printf("%s\t", aux->nome);
        aux = aux->dir;
    }
    //imprime os dados
    int i;

    for (int i = 0; i < table->qtdeTuplas; i++){
        imprimirTupla(table->tuplas[i], table->atributos);
    }
}

void imprimirDatabase(Database* db){
    printf("Database: %s\n", db->nome);
    printf("TABELAS \n", );
    int i;
    for (int i = 0; i < db->qtdeTabelas; i++){
        imprimirTabela(db->tabelas[i]);
    }

}




int main(){

    Database* db = criarDatabase("Universidade");
    criarTabela(db, "Alunos", {"ra", "nome", "nota"}, {"integer", "string", "float"}, 3);
    imprimirDatabase(db);


}
