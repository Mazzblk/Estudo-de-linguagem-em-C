#include <stdio.h>
#include <stdlib.h>


int numero;

int main() {
    printf("Sistemas\n");
    printf("\n1- Windows");
    printf("\n2- Linux");
    printf("Escolha a opcao desejeda: \n");
    scanf("%d", &numero);
    switch (numero)
    {
    case 1:
        system("cls");
        printf("iniciando o Windows...");
        break;
    
    case 2:
        system("cls");
        printf("iniciando o Linux...");
        break;
    default:
        printf("Erro.");
        break;
    }
    return 0;
}