#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    float precoPorKg, peso, valorTotal;
} Produto;

int autenticar(const char* esperado, const char* mensagem) {
    char entrada[50];
    printf("%s", mensagem);
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;
    return strcasecmp(entrada, esperado) == 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    const char *CUser = "a maioral, duda";
    const char *CPassword = "venero a maioral";
    int tentativas = 3;
    int escolha;
    float totalCompra = 0, valorProduto, precoPorKg, peso, valorPago, troco;
    Produto carrinho[50];
    Produto produtoTemp;
    int numProdutos = 0;

    while (tentativas-- > 0) {
        if (autenticar(CUser, "Usuário:\n") && autenticar(CPassword, "Senha:\n")) {
            printf("Bem-vindo!\n");
            break;
        }
        printf("Usuário ou senha incorretos!\n");
    }

    if (tentativas < 0) {
        printf("Número máximo de tentativas atingido.\n");
        return 0;
    }

    while (1) {
        printf("\nEscolha o tipo de produto:\n1. Produto normal\n2. Hortifruti\n3. Ver carrinho\n0. Finalizar\nDigite sua escolha: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                printf("Digite o nome do produto: ");
                fgets(produtoTemp.nome, sizeof(produtoTemp.nome), stdin);
                produtoTemp.nome[strcspn(produtoTemp.nome, "\n")] = 0;

                printf("Digite o valor do produto: ");
                scanf("%f", &produtoTemp.valorTotal);

                produtoTemp.precoPorKg = 0;
                produtoTemp.peso = 0;
                totalCompra += produtoTemp.valorTotal;

                carrinho[numProdutos++] = produtoTemp;

                printf("Produto '%s' adicionado ao carrinho. Total atual: R$%.2f\n", produtoTemp.nome, totalCompra);
                break;

            case 2:
                printf("Digite o nome do produto: ");
                fgets(produtoTemp.nome, sizeof(produtoTemp.nome), stdin);
                produtoTemp.nome[strcspn(produtoTemp.nome, "\n")] = 0;

                printf("Digite o preço por quilo: ");
                scanf("%f", &produtoTemp.precoPorKg);

                printf("Digite o peso do produto (em kg): ");
                scanf("%f", &produtoTemp.peso);

                produtoTemp.valorTotal = produtoTemp.precoPorKg * produtoTemp.peso;

                totalCompra += produtoTemp.valorTotal;

                carrinho[numProdutos++] = produtoTemp;

                printf("Produto '%s' adicionado ao carrinho. Total atual: R$%.2f\n", produtoTemp.nome, totalCompra);
                break;

            case 3:
                printf("\nCarrinho de compras:\n");
                for (int i = 0; i < numProdutos; i++) {
                    printf("Produto %d: %s - ", i + 1, carrinho[i].nome);
                    if (carrinho[i].peso > 0)
                        printf("Peso: %.2f kg, Preço por kg: R$%.2f, Total: R$%.2f\n", carrinho[i].peso, carrinho[i].precoPorKg, carrinho[i].valorTotal);
                    else
                        printf("Total: R$%.2f\n", carrinho[i].valorTotal);
                }
                printf("Total da compra até agora: R$%.2f\n", totalCompra);
                break;

            case 0:
                printf("Finalizando compra...\n");
                printf("Total da compra: R$%.2f\n", totalCompra);

                printf("Digite o valor pago pelo cliente: ");
                scanf("%f", &valorPago);

                if (valorPago >= totalCompra) {
                    troco = valorPago - totalCompra;
                    printf("Troco: R$%.2f\n", troco);
                    printf("Compra realizada com sucesso.\n");
                } else {
                    printf("Valor pago insuficiente para cobrir o total da compra.\n");
                }
                return 0;

            default:
                printf("Escolha inválida. Tente novamente.\n");
        }
    }

    return 0;
}
