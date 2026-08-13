#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, "Portuguese");
    system("Color 20");
    printf("Olá, mundo\n");
    system("pause");
    system("cls");
    system("Color 21");
    printf("Tchau\n");
    return 0;
}