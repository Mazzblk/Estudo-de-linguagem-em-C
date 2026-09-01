#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct produto {
    char nome[20];
    int ID;
    float preco;
};

void cab(void);

int compid(int *tam,struct produto *lista){
    int i, ID = rand()% 99999;
    for (i = 0; i < *tam; i++){
        if (lista[i].ID == ID)
        {
            return 0;
        }
    }
    return ID;
}

struct produto* cadastro(struct produto *lista, int *tam, int *cont, int *ind){
    int i, j;
    do{
        for (i = *cont; i < *tam; i++){

            system("CLS");
            cab();
            printf("Digite o nome do produto: ");
            scanf("%s", lista[i].nome);
            for (j = 0; j < *ind; j++){
                if (strcmp(lista[i].nome, lista[j].nome) == 0){
                    printf("ERRO\n");
                    system("pause");
                    return lista;
                }
            }
            if (strcmp(lista[i].nome, "stop") == 0){
                free(lista);
                exit(1);
            }
            if (strcmp(lista[i].nome, "menu") == 0){
                return lista;
            }
            printf("\nDigite o preco do produto: ");
            scanf("%f", &lista[i].preco);
            if (lista[i].preco <= 0){
                printf("Preco invalido.");
                system("pause");
                goto repete;
            }
            do{   
                j = 0;
                j = compid(tam, lista);
            } while (j == 0);
            lista[i].ID = j;
            printf("\nProduto cadastrado, ID: %d: \n\n", lista[i].ID = j);
            *ind = *ind + 1;
            system("pause");
        }
        *cont = *tam;
        *tam += 2;
        struct produto *temp = realloc (lista, *tam*sizeof(*lista));
        if (temp != NULL){
            lista = temp;
        } else {
            printf("ERRO");
            return lista;
            system("pause");
        }
        repete:
    } while (1);
    
}

void consulta(struct produto *lista, int ind){
    char resp[20];
    int i;
    system("CLS");
    cab();
    printf("-Consulta-\n");
    printf("Digite o nome do produto: ");
    scanf("%s", resp);
    if (strcmp(resp, "menu") == 0){
        return;
    }
    for (i = 0; i < ind; i++){
        if (strcmp(lista[i].nome, resp) == 0){
            printf("------------------- ");
            printf("\nProduto: %s\nID: %d\nPreco: %.2f \n", lista[i].nome, lista[i].ID, lista[i].preco);
            printf("------------------- \n");
            system("pause");
            return;
        }
    }
    printf("Produto não encontrado.");
    system("pause");
}

void procad(struct produto *lista, int ind){
    int i;
    cab();
    printf("-Lista de produtos cadastrados-\n");
    printf("-------------------");
    for (i = 0; i < ind; i++){
        printf("\nProduto: %s\nID: %d\nPreco: %.2f \n", lista[i].nome, lista[i].ID, lista[i].preco);
        printf("-------------------");
    }
    printf("\n");
    system("pause");
}

void menu(struct produto *lista, int *tam){
    int resp;
    int ind, cont = 0;
    do{
        system("CLS");
        cab();
        printf("[1] Cadastrar produtos\n");
        printf("[2] Consultar via nome\n");
        printf("[3] Lista de produtos\n");
        printf("-----------------------\n");
        printf("Digite o numero: ");
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
            lista = cadastro(lista, tam, &cont, &ind);
            break;
        case 2:
            consulta(lista, ind);
            break;
        case 3:
            procad(lista, ind);
            break;
        default:
            break;
        }
    } while (1);
}

int main(int argc, char const *argv[])
{   
    srand(time(NULL));
    int tam = 2;
    struct produto *lista = malloc(tam*sizeof(*lista));

    menu(lista, &tam);
    
    free(lista);
    return 0;
}


void cab(void){
    printf("_____________________________\n");
    printf("      Leitor de Precos\n");
    printf("-----------------------------\n\n");
}