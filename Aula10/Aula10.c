#include <stdlib.h>
#include <stdio.h>

int main(){
    int i;
    int ii;
    float nota1 = 8;
    float nota2 = 6;
    float nota3 = 9;
    float nota4 = 3;
    printf("Sem array\n");
    printf("Nota3 %.1f\n", nota3);
    //declarando um array
    float notas[4]={8,6,9,3};
    printf("Nota3 %.1f\n", notas[2]);
    notas[1] = 7;
    printf("Nota2 %.1f\n", nota2);
    printf("Nota2 %.1f\n", notas[1]);
    float boletim[2][4]={{8,7,9,3},{4,5,8,6}};
    char materia[2][20] = {"portugues", "matematica"};
    for (ii = 0; ii < 2; ii++){ 
        printf("%s: ", materia[ii]);  
        for (i = 0; i < 4; i++){  
            printf("|%.1f ", boletim[ii][i]);
        }
        printf("|\n");
    }
    
    system("pause");
    return 0;
}