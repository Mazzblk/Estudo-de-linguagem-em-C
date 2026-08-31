#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct produto {
    char nome[20];
    int ID;
    float preco;
};

int compid(int tam,struct produto *lista){
    int i, ID = rand()% 99999;
    for (i = 0; i < tam; i++){
        if (lista[i].ID == ID)
        {
            return 0;
        }
    }
    return ID;
}

void cadastro(struct produto *lista, int tam, int cont){
    int i, j;
    for (i = cont; i < tam; i++){
        printf("Digite o nome do produto");
        scanf("%s", lista[i].nome);
        if (strcmp(lista[i].nome, "stop") == 0){
            free(lista);
            exit(1);
        }
        printf("Digite o preco do produto");
        scanf("%f", &lista[i].preco);
        do{   
            j = 0;
            j = compid(tam, lista);
        } while (j == 0);
        lista[i].ID = j;
    }
}

int main(int argc, char const *argv[])
{   
    srand(time(NULL));
    int tam = 2;
    int cont = 0;
    struct produto *lista = malloc(tam*sizeof(*lista));
    do{
        cadastro(lista, tam, cont);
        cont = tam;
        tam += 2;
        struct produto *temp = realloc (lista, tam*sizeof(*lista));
        if (temp != NULL){
            lista = temp;
        } else {
            printf("ERRO");
        }
    } while (1);
    
    free(lista);
    return 0;
}
