#include <stdio.h>
#include "atributo.h"

int main(){
    //(char** vet_nome,char** vet_tipo,int tam_vet)
    //char nome[3][30] = {{"joao\0"},{"mari\0"},{"jose\0"}};
    char nome[3][30] = {{"joao\0"},{"mari\0"},{"jose\0"}};
    char tipo[3][30] = {{"tip1\0"},{"tip2\0"},{"tip3\0"}};
    int tam = 3;

//    for(int i =0; i<tam; i++){
//        printf("%s\n%s\n", nome[i], tipo[i]);
//    }
//    printf("\n");

    NoAtributo* a = atributo_criar(3, nome,tipo);

    atributo_imprimir(a);
    /*
    printf("%s\n", a->nome);
    printf("%s\n", a->tipo);
    if(a->valores == NULL)
        printf("valores == null\n");
    */
    atributo_destruir(a);


    return 0;
}
