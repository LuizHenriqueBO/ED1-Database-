#include <stdio.h>
#include "dado.h"



int main(){
    NoDado* teste = dado_criar("issae\n\0");

    printf("tam: %d\n",teste->tamDado);
    printf("nome: %s\n",teste->dado);



    dado_deletar(teste);
    return 0;
}
