#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
int i;
void carteado(char naip[4][10], char altura[13][8]){
    for ( i = 0; i < 4; i++){
        switch (i)
        {
        case 0:
            strcpy(naip[i],"Ouros");
            break;
        case 1:
            strcpy(naip[i], "Espadas");
            break;
        case 2:
            strcpy(naip[i], "Copas");
            break;
        case 3:
            strcpy(naip[i], "Paus");
            break;
        }
    }
    for ( i = 0; i < 13; i++){
        if (i >= 1 && i <= 9){
            sprintf(altura[i], "%d", i + 1);
        }
        else{
            switch (i)
            {
            case 0:
                strcpy(altura[i], "As");
                break;
            case 10:
                strcpy(altura[i], "Valete");
                break;
            case 11:
                strcpy(altura[i], "Dama");
                break;
            case 12:
                strcpy(altura[i], "Reis");
                break;
            }
        }
    }
}

int main (){
    char naip[4][10];
    char altura[13][8];
    carteado(naip, altura);
    srand(time(NULL));
    for(i = 0; i < 3; i++){
    printf("A %d carta tirada foi: %s de %s\n", i+1, altura[rand()%13], naip[rand()%4]);
    system("pause");
    }
    return 0;
}