#include <stdio.h>

#include "tupla.h"


int main(){

    char nome[][30] = {{"joao\0"},{"mari\0"},{"jose\0"}};

    int tam = 3;

    NoDado* nova =  tuplas_criar(nome,tam);

    tupla_imprimir(nova);

    tupla_destruir(nova);

    return 0;
}
