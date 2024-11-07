#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "carrinho.h"

int auth(const char* esperado, const char* msg);
void login(const char *user, const char *pass);
void menu();
int main() {
    setlocale(LC_ALL, ""); // Para aceitar acentos usando a localidade padrão do sistema
    
    const char *user = "adm";
    const char *pass = "12345";
    
    login(user, pass);
    menu();

    return 0;
}

int auth(const char* esperado, const char* msg) {
    char input[50];
    printf("%s", msg);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    return strcmp(input, esperado) == 0;
}

void login(const char *user, const char *pass) {
    int tries = 3;

    while (tries > 0) {
        if (auth(user, "Usuário:\n") && auth(pass, "Senha:\n")) {
            printf("Bem-vindo!\n");
            return;
        }
        tries--;
        if (tries > 0) {
            printf("Usuário ou senha incorretos! Tentativas restantes: %d\n", tries);
        } else {
            printf("Número máximo de tentativas atingido.\n");
            exit(0);
        }
    }
}

void menu() {
    int opc;

    while (1) {
        printf("\nEscolha o tipo de produto:\n1. Produto normal\n2. Hortifruti\n3. Ver carrinho\n0. Finalizar\nDigite sua escolha: ");
        
        if (scanf("%d", &opc) != 1) {
            printf("Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        switch (opc) {
            case 1:
                addProd();
                break;
            case 2:
                addHorti();
                break;
            case 3:
                showCarrinho();
                break;
            case 0:
                finalizar();
                return;
            default:
                printf("Escolha inválida. Por favor, selecione uma opção válida.\n");
                break;
        }
    }
}
