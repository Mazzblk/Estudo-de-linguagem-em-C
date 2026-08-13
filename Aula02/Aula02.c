#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main() {
    //"char" é o tipo de de variavel em carctere. "nome" é o nome da variavel e "[50]" é a quantidade maxima de carteres que a variavel pode receber.
    char nome[50];
    printf("Digite seu nome:");
    //gets é o "leia". Para ler a variavel não mode estar entre parenteses.
    gets(nome);
    system("cls");
    printf("ola, %s.\n", nome);
    system("Pause");
    return 0;
}