#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void);
void tx(void);
void dx(void);
void et(void);
void uescolhe(void);
void placar(int V, int D){
    system("pause");
    system("cls");
    printf("----JoknPO----\n\n");
    printf("|Jogador |Placar| Maquina |\n");
    printf("    %d       X       %d\n", V, D);
    printf("--------------------------\n\n");
}
void gameover(int V, int D){
    printf("Vitoria para ");
    if (V > D){
        printf("o jogador! ");
    }
    else{
        printf("a maquina! ");
    }
    system("pause");
    system("cls");
    menu();
}
void rolagem(int *V, int *D){
        int ES, MC;
        printf("1.Pedra\n");
        printf("2.Papel\n");
        printf("3.Tesoura\n\n");
        scanf("%d", &ES);
        MC = (rand() % 3) + 1;
        if (ES == 1){
            printf("Pedra");
        } 
        else{
            if (ES == 2){
            printf("Papel");
            } 
            else{
                printf("Tesoura");
            }
        }
        printf(" X ");
        if (MC == 1){
            printf("Pedra\n");
        } 
        else{
            if (MC == 2){
            printf("Papel\n");
            } 
            else{
                printf("Tesoura\n");
            }
        }
        if (MC == ES){
        printf("EMPATE\n");
        }
        else {
            if ((MC == ES + 2) || (ES == 2 && MC == 1) || (ES == 3 && MC == 2)){
                printf("Vitoria\n");
                *V = *V + 1;
            }
            else{
                    printf("Derrota\n");
                    *D = *D + 1;
                }
            }
    
}

int main(){
    srand(time(NULL));
    menu();
    return 0;
}

void menu(void){
    int MN;
    printf("=========JoknPO=========\n\n");
    printf("         MENU:          \n");
    printf("[1] Melhor de 2\n");
    printf("[2] Melhor de 3\n");
    printf("[3] Escolha\n");
    printf("[4] Eterno\n");
    printf("[5] Sair\n");
    scanf("%d", &MN);
    switch (MN)
    {
    case 1:
        system("cls");
        dx();
        break;
    case 2:
        system("cls");
        tx();
        break;
    case 3:
        system("cls");
        uescolhe();
        break;
    case 4:
        system("cls");
        et();
        break;
    
    default:
        system("cls");
        printf("Ate mais!");
        break;
    }
}


//2x ==
void dx(void){
    int V, D;
    V = 0;
    D = 0;
    printf("----JoknPO----\n\n");
    do{
        rolagem(&V, &D);
        if (D == 1 && V == 1)
        {
            D = 0;
            V = 0;
        }
        placar(V, D);
    }   while (V != D + 2 && D != V + 2);
    gameover(V, D);
}
//3x ==
void tx(void){
    int V, D;
    V = 0;
    D = 0;
    printf("----JoknPO----\n\n");
    do{
        rolagem(&V, &D);
        if (D == 2 && V == 2)
        {
            D = 0;
            V = 0;
        }
        placar(V, D);
    }   while (V != D + 3 && D != V + 3);
    gameover(V, D);
}
//eterno
void et(void){
    int V, D;
    V = 0;
    D = 0;
    printf("----JoknPO----\n\n");
    do{
        rolagem(&V, &D);
        placar(V, D);
    }   while (1);
}
//escolha do usuario
void uescolhe(void){
    int V, D, ues;
    V = 0;
    D = 0;
    printf("----JoknPO----\n\n");
    printf("Ate onde o jogo vai? ");
    scanf("%d", &ues);
    printf("\n");
    system("cls");
    printf("----JoknPO----\n\n");
    do{
        rolagem(&V, &D);
        placar(V, D);
    }   while (V != ues && D != ues);
    gameover(V, D);
}