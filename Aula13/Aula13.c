#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
    char comp[11] = "aeiouAEIOU";
    char palavra[20] = "Linguagem C";
    int tam1 = strlen(palavra);
    int i, j, total;

    for (i = 0; i < tam1; i++){
        for (j = 0; j < 11; j++){
            if (comp[j] == palavra[i])
            {
                total++;
                break;
            }
        }
    }
    printf("%d", total);

    return 0;
}