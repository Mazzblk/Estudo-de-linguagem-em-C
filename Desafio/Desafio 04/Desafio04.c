#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    float md[5], nt[3], sm;
    int i, qn;
    char nm[5][50];
    qn = 0;
    do{ 
        sm = 0;
        printf("Registrar Notas\n\n");
        for (i = 0; i != 3; i++){
            printf("Escreva a nota %d: ", i+1);
            scanf("%f", &nt[i]); 
            if (nt[i] == -1){
                goto fim_programa;
            } 
            if ((nt[i] > 100) || (nt[i] < 0)){
            break;
            }  
        }
        if ((nt[i] > 100) || (nt[i] < 0)){
            break;
        }
        for (i = 0; i != 3; i++){
            sm += nt[i];  
        }
        printf("Escreva o nome do aluno %d: ", qn+1);
        scanf(" %49[^\n]", nm[qn]);
        system("cls");
        md[qn] = sm/3; 
        if (qn == 4){
            goto fim_programa;
        }
        qn++;
    }while (1);
    system("cls");
    printf("Erro: Valor de nota invalido.");
    goto f;
    fim_programa:
    system("cls");
    printf("\nNotas registradas:\n");
    for (i = 0; i != qn; i++){
        printf("%d: %s - %.1f\n", i+1, nm[i], md[i]);
    }
    f:
    return 0;
}
