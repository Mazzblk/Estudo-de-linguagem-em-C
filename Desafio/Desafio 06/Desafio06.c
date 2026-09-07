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

int continuarsn(){
    int r;
    do{
    system("cls");
    cab();
    printf("\nGostaria de contiuar?\n");
    printf("[1] SIM\n");
    printf("[2] NAO\n");
    printf("Digite: ");
    if (scanf("%d", &r) != 1){
        while (getchar() != '\n');
        printf("Resposta invalida.\n\n");
        system("pause");
    }else{return r;}
    } while (1);
}

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

void alf(struct produto *lista,  int *ind){
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

struct produto* cadastro(struct produto *lista, int *tam, int *cont, int *ind){
    int i, j;
    *cont = *ind;
    do{
        for (i = *cont; i < *tam; i++){
            lista[i].entrada = i+1;
            system("CLS");
            cab();
            printf("Digite o nome do produto: ");
            scanf("%s", lista[i].nome);
            for (j = 0; j < *ind; j++){
                if (strcmp(lista[i].nome, lista[j].nome) == 0){
                    printf("Produto ja cadastrado.\n");
                    system("pause");
                    j = 1;
                    goto last;
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
            if (scanf("%d", &lista[i]) != 1){
            while (getchar() != '\n');
            printf("Preco invalido.\n\n");
            system("pause");
            goto last;
            }
            if (lista[i].preco <= 0){
                printf("Preco invalido.\n\n");
                system("pause");
                goto last;
            }
            
            do{   
                j = 0;
                j = compid(tam, lista);
            } while (j == 0);
            lista[i].ID = j;
            printf("\nProduto cadastrado, ID: %d: \n\n", lista[i].ID = j);
            alf(lista, ind);
            *ind = *ind + 1;
            system("pause");
            
            j = continuarsn();
            if (j != 1){
                break;
            }
            
            
        }
        
        if (*ind >= *tam){
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
        }
        
        last:
    } while (j == 1);
    return lista;
}

void consultanm(struct produto *lista, int ind){
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
            printf("\nEntrada: %d\nProduto: %s\nID: %d\nPreco: %.2f \n", lista[i].entrada, lista[i].nome, lista[i].ID, lista[i].preco);
            printf("------------------- \n");
            system("pause");
            goto last;
        }
    }
    printf("Produto nao encontrado.");
    system("pause");
    last:
    return;
}
void consultaid(struct produto *lista, int ind){
    int i, resp;
    system("CLS");
    cab();
    printf("-Consulta-\n");
    printf("Digite o ID do produto: ");
    if (scanf("%d", &resp) != 1){
        while (getchar() != '\n');
        printf("Produto nao encontrado.");
        return;
    }
    if (resp <= 0){
        return;
    }
    for (i = 0; i < ind; i++){
        if (lista[i].ID == resp){
            printf("------------------- ");
            printf("\nEntrada: %d\nProduto: %s\nID: %d\nPreco: %.2f \n", lista[i].entrada, lista[i].nome, lista[i].ID, lista[i].preco);
            printf("------------------- \n");
            system("pause");
            goto last;
        }
    }
    printf("Produto nao encontrado.");
    system("pause");
    last:
    return;
}
void consulta(struct produto *lista, int ind){
    int i;
    do
    {   
        system("cls");
        cab();

        printf("O que gostaria de consultar?\n");
        printf("[1] ID\n");
        printf("[2] NOME\n");
        printf("[3] MENU\n");
        if (scanf("%d", &i) != 1){
        while (getchar() != '\n');
        i = 4;}
        switch (i)
        {
        case 1:
            consultaid(lista, ind);
            break;
        case 2:
            consultanm(lista, ind);
            break;
        case 3:
            return;
            break;
        default:
            printf("resposta invalida.\n");
            system("pause");
            break;
        }
        i = continuarsn();
    } while (i == 1);
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
    while (getchar() != '\n');
    return lista;

    excluir:
    printf("!TEM CERTEZA QUE GOSTARIA DE EXCLUIR?\n Se quiser prosseguir com a exclusao digite 'SIM'\nDo contrario, digite 'NAO': ");
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
            printf("OP Cancelado\n");
            system("pause");
            return lista;
        }else{
            printf("!RESPOSTA INVALIDA!\nDigite'SIM' ou 'NAO': ");
        }
    }while (1);
}

void menu(struct produto *lista, int *tam){
    int resp;
    int ind =0 , cont = 0;
    
    do{
        if (*tam == 0 || *tam == 1){*tam = 2;}
        system("CLS");
        cab();
        printf("[1] Cadastrar produtos\n");
        printf("[2] Consultar produto\n");
        printf("[3] Lista de produtos\n");
        printf("[4] Excluir produto\n");
        printf("Digite qualquer outro numero para sair\n");
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
    printf("      Sistema de produtos\n");
    printf("-----------------------------\n\n");
}