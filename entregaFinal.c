#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 50

typedef struct {
    char nome[50];
    float pKg, peso, total;
} Prod;

Prod carrinho[MAX];
int nProd = 0;
float totalCompra = 0;

int auth(const char* esperado, const char* msg);
void login(const char *user, const char *pass);
void menu();
void addProd();
void addHorti();
void showCarrinho();
void saveCarrinho();
void finalizar();

int main() {
    setlocale(LC_ALL, "");
    
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
        getchar();

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

void addProd() {
    if (nProd >= MAX) {
        printf("Carrinho cheio. Não é possível adicionar mais produtos.\n");
        return;
    }

    Prod p;
    printf("Digite o nome do produto: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;

    printf("Digite o valor do produto: ");
    if (scanf("%f", &p.total) != 1 || p.total <= 0) {
        printf("Valor inválido. Tente novamente.\n");
        while (getchar() != '\n');
        return;
    }

    p.pKg = 0;
    p.peso = 0;
    carrinho[nProd++] = p;
    totalCompra += p.total;

    printf("Produto '%s' adicionado ao carrinho. Total atual: R$%.2f\n", p.nome, totalCompra);
}

void addHorti() {
    if (nProd >= MAX) {
        printf("Carrinho cheio. Não é possível adicionar mais produtos.\n");
        return;
    }

    Prod p;
    printf("Digite o nome do produto: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;

    printf("Digite o preço por quilo: ");
    if (scanf("%f", &p.pKg) != 1 || p.pKg <= 0) {
        printf("Preço por quilo inválido. Tente novamente.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Digite o peso do produto (em kg): ");
    if (scanf("%f", &p.peso) != 1 || p.peso <= 0) {
        printf("Peso inválido. Tente novamente.\n");
        while (getchar() != '\n');
        return;
    }

    p.total = p.pKg * p.peso;
    carrinho[nProd++] = p;
    totalCompra += p.total;

    printf("Produto '%s' adicionado ao carrinho. Total atual: R$%.2f\n", p.nome, totalCompra);
}

void showCarrinho() {
    if (nProd == 0) {
        printf("Carrinho vazio.\n");
        return;
    }

    printf("\nCarrinho de compras:\n");
    for (int i = 0; i < nProd; i++) {
        printf("Produto %d: %s - ", i + 1, carrinho[i].nome);
        if (carrinho[i].peso > 0)
            printf("Peso: %.2f kg, Preço por kg: R$%.2f, Total: R$%.2f\n", carrinho[i].peso, carrinho[i].pKg, carrinho[i].total);
        else
            printf("Total: R$%.2f\n", carrinho[i].total);
    }
    printf("Total da compra até agora: R$%.2f\n", totalCompra);
}

void saveCarrinho() {
    FILE *file = fopen("carrinho.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }
    for (int i = 0; i < nProd; i++) {
        fprintf(file, "%s %.2f %.2f %.2f\n", carrinho[i].nome, carrinho[i].pKg, carrinho[i].peso, carrinho[i].total);
    }
    fclose(file);
    printf("Carrinho salvo no arquivo com sucesso.\n");
}

void finalizar() {
    float pago, troco;

    printf("Total da compra: R$%.2f\n", totalCompra);
    printf("Digite o valor pago pelo cliente: ");
    if (scanf("%f", &pago) != 1 || pago < totalCompra) {
        printf("Valor pago insuficiente ou inválido. Compra não finalizada.\n");
        while (getchar() != '\n');
        return;
    }

    troco = pago - totalCompra;
    printf("Troco: R$%.2f\n", troco);
    printf("Compra realizada com sucesso.\n");
    saveCarrinho();
}
