#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float soma(float N1, float N2){
    return N1 + N2;
}
float sub(float N1, float N2){
    return N1 - N2;
}
float mult(float N1, float N2){
    return N1 * N2;
}
float dividir(float N1, float N2){
    if (N2 == 0){
        return 0;
    }
    else{
        return N1 / N2;
    }
}
float prc(float N1, float N2){
    if (N2 == 0 || N1 < 0){
        return 0;
    }
    else{
        return (N1 * 100) / N2;
    }
}

int main() {
    int OP;
    float res, N1, N2;
    char tip[15];
    printf("Digite o primeiro numero:\n");
    scanf("%f", &N1);
    printf("Digite o segundo numero:\n");
    scanf("%f", &N2);
    printf("\n 1- Soma.");
    printf("\n 2- Subtrair.");
    printf("\n 3- Multiplicar.");
    printf("\n 4- Divir.");
    printf("\n 5- Porcentagem\n");
    printf("\n --------------\n");
    scanf("%d", &OP);
    switch (OP)
    {
    case 1:
        strcpy(tip, "soma");
        res = soma(N1, N2);
        break;
    case 2 :
        strcpy(tip, "subtracao");
        res = sub(N1, N2);
        break;
    case 3:
        strcpy(tip, "multiplicacao");
        res = mult(N1, N2);
        break;
    case 4:
        strcpy(tip, "divisao");
        res = dividir(N1, N2);
        break;
    case 5:
        strcpy(tip, "porcentagem");
        res = prc(N1, N2);
        break;
    default:
        printf("Erro.");
        break;
    }
    if ((OP == 5 || OP == 4) && N2 == 0) {
        printf("Divisoes por zero sao impossiveis.");
    }
    else{
         if (fmod(res, 1) == 0) {
            printf("\nO resultado da %s e %.0f", tip, res);
        }
        else{
           printf("\nO resultado da %s e %.2f", tip, res); 
        }
    }
    return 0;
}
