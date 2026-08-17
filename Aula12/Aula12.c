#include <stdio.h>
#include <stdlib.h>


int main(){
    int pessoas = 4;
    int *gps;
    gps = &pessoas;
    printf("Quantidade de pessoas %d\n", pessoas);
    printf("O endereço é: %p\n", &pessoas);
    printf("Endereço gps e: %p\n", gps);
    return 0;
}