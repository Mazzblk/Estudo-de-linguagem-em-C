#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct produto {
    char nome[20];
    int ID, entrada;
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

void alf(struct produto *lista,  int *ind, int *np){
    int i, j;
    struct produto aux;
   
    for (i = 0; i < *ind - 1; i++){
        for (j = 0; j < *ind - 1 - i; j++){
            if (strcmp(lista[j].nome, lista[j+1].nome)==0){
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j] = aux;
            }
        }
    }       
}

struct produto* cadastro(struct produto *lista, int *tam, int *cont, int *ind, int *np){
    int i, j;
    *cont = *ind;
    do{
        for (i = *cont; i < *tam; i++){
            lista[i].entrada = i;
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
            alf(lista, ind, np);
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
    printf("Produto nao encontrado.");
    system("pause");
}

void procad(struct produto *lista, int ind){
    int i;
    system("cls");
    cab();
    printf("-Lista de produtos cadastrados-\n");
    printf("-------------------");
    for (i = 0; i < ind; i++){
        printf("\nEstrada: %d\nProduto: %s\nID: %d\nPreco: %.2f \n",lista[i].entrada, lista[i].nome, lista[i].ID, lista[i].preco);
        printf("-------------------");
    }
    printf("\n");
    system("pause");
}

struct produto* excluir(struct produto *lista, int *ind, int *tam){
    union resposta{int ID, cont; char SN[4];}resp;
    int i;
    system("cls");
    cab();
    printf("Digite o ID do produto: ");
    scanf("%d", &resp.ID);
    for (i = 0; i < *ind; i++){
        if (resp.ID == lista[i].ID){
            printf("-------------------");
            printf("\nProduto: %s\nID: %d\nPreco: %.2f \n", lista[i].nome, lista[i].ID, lista[i].preco);
            printf("-------------------\n");
            goto excluir;
        }
    }
    printf("ID nao encontrado.");
    system("pause");
    return lista;

    excluir:
    printf("!TEM CERTEZA QUE GOSTARIA DE EXCLUIR?\n Se quiser prosseguir com a exclusao digite 'SIM'\n Do contrario, digite 'NAO': ");
    do{
        scanf("%s", resp.SN);
        if (strcmp(resp.SN, "SIM") == 0){
            resp.cont = i;
            for (i = resp.cont; i < *ind-1; i++){
                lista[i] = lista[i+1];
            }
            *tam = *tam-1;
            *ind = *ind-1;
            struct produto *temp = realloc (lista, *tam*sizeof(*lista));
            if (temp != NULL || *tam == 0){
                lista = temp;
                printf("Produto excluido.");
                system("pause");
                return lista;
            }else{
                printf("ERRO");
                system("pause");
                return lista;
            }
        }else if (strcmp(resp.SN, "NAO") == 0){
            printf("OP Cancelado");
            system("pause");
            return lista;
        }else{
            printf("!RESPOSTA INVALIDA!\nDigite'SIM' ou 'NAO': ");
        }
    }while (1);
}


void menu(struct produto *lista, int *tam){
    int resp;
    int ind =0 , cont = 0, np = 0;
    
    do{
        if (*tam == 0 || *tam == 1){*tam = 2;}
        system("CLS");
        cab();
        printf("[1] Cadastrar produtos\n");
        printf("[2] Consultar via nome\n");
        printf("[3] Lista de produtos\n");
        printf("[4] Excluir produto\n");
        printf("Digite qualquer outra coisa para sair\n");
        printf("-----------------------\n");
        printf("Digite o numero: ");
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
            lista = cadastro(lista, tam, &cont, &ind, &np);
            break;
        case 2:
            consulta(lista, ind);
            break;
        case 3:
            procad(lista, ind);
            break;
        case 4:
            lista = excluir(lista, &ind, tam);
            break;
        default:
            return;
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