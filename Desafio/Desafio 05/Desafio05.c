#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum semana{domingo, segunda, terca, quarta, quinta, sexta, sabado};
union calendario{
    char res[10];
    enum semana hoje;
};
union calendario dia;

void proc(void){
    if (strcmp(dia.res, "Domingo") == 0){
        dia.hoje = domingo;
    } else if (strcmp(dia.res, "Segunda") == 0){
        dia.hoje = segunda;
    } else if (strcmp(dia.res, "Terca") == 0){
        dia.hoje = terca;
    } else if (strcmp(dia.res, "Quarta") == 0){
        dia.hoje = quarta;
    } else if (strcmp(dia.res, "Quinta") == 0){
        dia.hoje = quinta;
    } else if (strcmp(dia.res, "Sexta") == 0){
        dia.hoje = sexta; 
    } else if (strcmp(dia.res, "Sabado") == 0){
        dia.hoje = sabado;
    }
}

int main(int argc, char const *argv[]){
    int avancar;
    printf("Digite o numero correpondente ao dia da semana. Exempo: Segunda.\n");
    scanf("%s", dia.res);
    proc();
    printf("Quantos dias gostaria de avancar?\n");
    scanf("%d", &avancar);
    avancar = avancar + dia.hoje;
    printf("Caira num");
    switch (avancar % 7){
    case 0:
        printf(" Domingo");
        break;
     case 1:
        printf("a Segunda");
        break;
     case 2:
        printf("a Terca");
        break;
     case 3:
        printf("a Quarta");
        break;
     case 4:
        printf("a Quinta");
        break;
     case 5:
        printf("a Sexta");
        break;
     case 6:
        printf(" Sabado");
        break;
    }
    
    return 0;
}
