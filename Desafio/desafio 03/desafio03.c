#include <stdio.h>
#include <stdlib.h>

void cab(void);

int main(int argc, char const *argv[]){    
    int i, ud, dc, lis[6];
    int in = 0;
    for (i = 0; i != 6; i++){
        system("cls");
        cab();
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &lis[i]);
        if (lis[i] > 0){
            in++;
        }
        
    }
    ud = 5;
    for (i = 0; i != 3; i++){
        dc = lis[ud];
        lis[ud] = lis[i];
        lis[i] = dc;
        ud--;
    }
    for (i = 0; i != 6; i++){
        printf("%d", lis[i]);
        if (i != 5)
        {
             printf(", ");
        }
    }
    printf("\nQuantidade de numeros inteiros: %d", in);
    return 0;
}

void cab(void){
printf("=====================\n");
printf("=====Ordenador2k=====\n");
printf("=====================\n");
}