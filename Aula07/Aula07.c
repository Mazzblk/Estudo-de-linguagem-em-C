// Arvore de natal
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int I, II, TAM, ESP, R;

int main (){
    printf("Feliz natal!\n");
    printf("Tamanho: ");
    scanf("%d", &TAM);
    ESP = TAM;
    srand(time(NULL));
    for (I = 1; I <= TAM-1; I++){
                printf(" ");
            }
    printf ("<^>");
    printf("\n");
    for (I = 1; I <=TAM*2; I++) {
        if (I % 2 == 1) {
            for (II = 1; II <= ESP; II++){
                printf(" ");
            } 
            for (II = 1; II <= I; II++){
                R = rand() % 8;
                if (R == 0 || R == 1)
                {
                    printf("o");
                }
                if (R >= 3)
                {
                    printf("*");
                }
                if (R == 2)
                {
                    printf("J");
                }
            }   
            ESP = ESP - 1;
            printf("\n");
        }
    }
    for (I = 1; I <= TAM-1; I++){
                printf(" ");
            }
    printf ("| |");
    printf("\n");
    system ("pause");
    return 0;
}