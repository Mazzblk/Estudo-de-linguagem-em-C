#include <stdio.h>
#include <stdlib.h>


int main() {
    float nota01, nota02, media;
    printf("Digite a nota 01: ");
    scanf("%f", &nota01);
    system("cls");
    printf("Digite a nota 02: ");
    scanf("%f", &nota02);
    system("cls");
    media = (nota01+nota02)/2;
    printf("A media e: %.1f!\n", media);
    if (media<=59)
    {
        printf("Aluno reprovado.\n");
    } 
    else 
    {
        printf("Aluno aprovado.\n");
    }
    
    system("pause");
    return 0;
}