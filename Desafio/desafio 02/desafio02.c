#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void cab(void);
struct cilentes{
    char nome[80];
    int idade;
};
void começar(int *i, int cont){
    printf("Espacos na fila %d\n", cont);
    printf("Gostaria de iniciar?\n");
    printf("[1] Sim\n");
    printf("[2] nao\n");
    scanf("%d", i);
}
void continuar(int *res, int cont){
    if (cont != 0){
    printf("Espacos na fila %d\n", cont);
    printf("Gostaria de continuar?\n");
    printf("[1] Sim\n");
    printf("[2] nao\n");
    scanf("%d", res);
    }
}
void filar(struct cilentes *lis, int i){
    printf("Digite o nome do cliente: \n");
    scanf(" %79[^\n]", lis[i].nome);
    printf("Digite a idade de %s: \n", lis[i].nome);
    scanf("%d", &lis[i].idade);
}
void preferencia(struct cilentes *lis, int i, int pref){
    char auxc[80];
    int aux;
    aux = lis[pref].idade;
    lis[pref].idade = lis[i].idade;
    lis[i].idade = aux;
    strcpy(auxc, lis[pref].nome);
    strcpy(lis[pref].nome, lis[i].nome);
    strcpy(lis[i].nome, auxc);
}
void lista(struct cilentes *lis, int i, int cont){
    int ii;
    cont = i;
    for (i = 0; i != cont; i++){
        if (i % 2 == 0){
            printf("| ");
        } else{
            printf("  ");
        }
        if (i >= 0)
        {
            printf("%do: %-15.15s idade: %d\n",i+1, lis[i].nome, lis[i].idade);
        } else {
            printf("%do: %-14.15s idade: %d\n",i+1, lis[i].nome, lis[i].idade);
        }
    }
}

int main(int argc, char const *argv[]){
    int i, cont, res, pref;
    pref = 0;
    cont = 10;
    struct cilentes lis[10];
    cab(); 
    começar(&i, cont);
    if (i == 1){
        i = 0;
        do{
        system("cls");
        cab(); 
        cont--;
        filar(lis, i);
        if(lis[i].idade >= 60){
            preferencia(lis, i, pref);
            pref++;
        }
        printf("===============================\n");
        continuar(&res, cont);
        i++;
        } while (cont != 0 && res != 2);
        system("cls");
        cab();
        lista(lis, i, cont);
    }
    printf("===============================\n"); 
    return 0;
}

void cab(void){
    printf("===============================\n");
    printf("       Sistema Fila 1.0\n");
    printf("===============================\n\n");
}