#include <stdio.h>
#include <stdlib.h>


int main() {
    int idade;
    printf("Digite sua idade:");
    scanf("%d", &idade);
    printf("idade: %d anos.\n", idade);
    if(idade<18)
    {
        printf("\nMenor de idade.\n");
    }
    if (idade>=18)
    {
        printf("\nMaior de idade.\n");
    }
    system("Pause");
    return 0;
}