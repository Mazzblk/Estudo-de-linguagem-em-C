#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
    printf("Jogo do dado\n");
    srand(time(NULL));
    printf("face: %d\n", rand()%6 + 1);
    system("pause");
    return 0;
}