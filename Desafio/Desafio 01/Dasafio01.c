#include <stdlib.h>
#include <stdio.h>
int tamlis = 10;
int total = 0;
void sep(void);
void cab(void);
struct Clientes{
    int id;
    int idade;
    int telefone;
    int ativo;
    char nome[80];
    char email[80];
};
struct Clientes lista[10];
void listagem(void){
    int i;
    cab();
    for (i = 0; i != total; i++){
        if (lista[i].ativo == 1){
            printf("USER ID: %d\n\n", lista[i].id);
            printf("Nome: %s  Idade : %d\n", lista[i].nome, lista[i].idade);
            printf("Email: %s\nTelefone : %d\n", lista[i].email, lista[i].telefone);
            sep();
        }
    }
    system("pause");
}
void cadastro(void){
    lista[total].id = total + 1;
    lista[total].ativo = 1;
    cab();
    printf("    Cadastrando usuario %d\n", lista[total].id);
    printf("Nome: \n");
    scanf("%s",lista[total].nome);
    printf("Idade: \n");
    scanf("%d",&lista[total].idade);
    printf("telefone: \n");
    scanf("%d",&lista[total].telefone);
    printf("email: \n");
    scanf("%s",lista[total].email);
    system("cls");
    cab();
    printf("Usuario cadastrado\n");
    sep();
    system("pause");
    (total)++;
}
void pesquisa(void){
    int psq;
    do{
        cab();
        printf("Digite o ID que gostaria de consultar: ");
        scanf("%d", &psq);
        psq--;
        system("cls");
        if (psq <= total-1 && psq >= 0){    
            cab();
            printf("USER ID: %d\n\n", lista[psq].id);
            printf("Nome: %s  Idade : %d\n", lista[psq].nome, lista[psq].idade);
            printf("Email: %s\nTelefone : %d\n", lista[psq].email, lista[psq].telefone);
            printf("Status: ");
        if (lista[psq].ativo == 1){
            printf("Ativo\n");
        } else {
            printf("Desativado\n");
        }
        
        sep();
        }
        else{
            cab();
            printf("Usuario nao encontratado.\n");
        }
        printf("Gostaria de consultar outro ID?\n");
        printf("[1] Sim\n");
        printf("[2] Nao\n");
        sep();
        printf("Digite a opcao: ");
        scanf("%d", &psq);
        system("cls");
    } while (psq == 1);
}
void alteracao(void){
    int psq, tipo;
    do{
        cab();
        printf("Digite o ID do Usuario: \n");
        scanf("%d", &psq);
        psq--;
        system("cls");
        cab();
        if (psq <= total-1 && psq >= 0){
            printf("Qual informacao voce gostaria alterar?\n");
            printf("Usuario: %s\n", lista[psq].nome);
            printf("[1] Nome\n");
            printf("[2] Email\n");
            printf("[3] Telefone\n");
            printf("[0] Cancelar\n");
            scanf("%d", &tipo);
            switch (tipo)
            {
            case 1:
                system("cls");
                cab();
                printf("Alterar\n");
                printf("Nome: %s\n", lista[psq].nome);
                printf("PARA: ");
                scanf("%s", lista[psq].nome);
                break;
            case 2:
                system("cls");
                cab();
                printf("Alterar\n");
                printf("Email: %s\n", lista[psq].email);
                printf("PARA: ");
                scanf("%s", lista[psq].email);
                break;
            case 3:
                system("cls");
                cab();
                printf("Alterar\n");
                printf("Telefone: %d\n", lista[psq].telefone);
                printf("PARA: ");
                scanf("%d", &lista[psq].telefone);
                break;
            }
        }
        else{
            printf("Usuário não encontrado");
        }
        system("cls");
        cab();
        printf("Gostaria de fazer mais alguma alteracao?\n");
        printf("[1] Sim\n");
        printf("[2] Nao\n");
        sep();
        printf("Digite a opcao: ");
        scanf("%d", &psq);
        system("cls");
    } while (psq == 1);
}
void desligamento(void){
    int psq, c;
    cab();
    printf("Digite o ID do Usuario: \n");
    scanf("%d", &psq);
    psq--;
    system("cls");
    cab();
    if (psq <= total-1 && psq >= 0){
        printf("Tem certeza que gostaria de desativar?\n");
        printf("[1] Sim\n");
        printf("[2] Nao\n");
        sep();
        printf("Digite a opcao: ");
        scanf("%d", &c);
        if (c == 1){
            lista[psq].ativo = 0;
        }
        else{
            printf("Cancelado");
        }
    }
    else{
        printf("Usuário não encontrado");
    }

}
void menu(void){
    int res;
    do{
        system("cls");
        cab();
        printf("[1] Cadastrar novo cliente\n");
        printf("[2] Listar clientes cadastrados\n");
        printf("[3] Buscar cliente por ID\n");
        printf("[4] Alterar dados de um cliente\n");
        printf("[5] Remover cliente\n");
        printf("[0] Sair do sistema\n\n");
        sep();
        printf("Digite a opcao: ");
        scanf("%d", &res);
        system("cls");
        switch (res)
        {
        case 1:
            cadastro();
            break;
        case 2:
            listagem();
            break;
        case 3:
            pesquisa();
            break;
        case 4:
            alteraçao();
            break;
        case 5:
            desligamento();
            break;   
        }
    } while (res != 0);
}

int main(){
    menu();
    printf("Sistema encerrado\n\n\n\n");
    printf(" --| ___ |--\n");
    printf("    \\O O/\n");
    printf("     | |\n");
    system("pause");
    return 0;
}

void sep(void){
    printf("================================\n");
}

void cab(void){
    sep();
    printf ("    SISTEMA DE CLIENTES v1.0\n");
    sep();
}