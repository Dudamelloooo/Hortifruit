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
    const char *CUser = "a maioral, duda", *CPassword = "venero a maioral"; //kkkkkkkkkkkkkkkkkkkkk
    int tentativas = 3, escolha, numProdutos = 0;
    float totalCompra = 0, valorPago, troco;
    Produto carrinho[50], produtoTemp;

    while (tentativas-- > 0 && (!autenticar(CUser, "Usuário:\n") || !autenticar(CPassword, "Senha:\n")))
        printf("Usuário ou senha incorretos!\n");
    if (tentativas < 0) return printf("Número máximo de tentativas atingido.\n"), 0;

    while (1) {
        printf("\nEscolha o tipo de produto:\n1. Produto normal\n2. Hortifruti\n3. Ver carrinho\n0. Finalizar\nDigite sua escolha: ");
        scanf("%d", &escolha); getchar();
        if (escolha == 0) {
            printf("Total da compra: R$%.2f\nDigite o valor pago: ", totalCompra);
            scanf("%f", &valorPago);
            return printf(valorPago >= totalCompra ? "Troco: R$%.2f\nCompra realizada.\n" : "Valor insuficiente.\n", valorPago - totalCompra), 0;
        }
        if (escolha == 1 || escolha == 2) {
            printf("Digite o nome do produto: ");
            fgets(produtoTemp.nome, sizeof(produtoTemp.nome), stdin);
            produtoTemp.nome[strcspn(produtoTemp.nome, "\n")] = 0;

            if (escolha == 1) {
                printf("Digite o valor do produto: ");
                scanf("%f", &produtoTemp.valorTotal);
                produtoTemp.precoPorKg = produtoTemp.peso = 0;
            } else {
                printf("Digite o preço por quilo: ");
                scanf("%f", &produtoTemp.precoPorKg);
                printf("Digite o peso do produto (em kg): ");
                scanf("%f", &produtoTemp.peso);
                produtoTemp.valorTotal = produtoTemp.precoPorKg * produtoTemp.peso;
            }
            totalCompra += produtoTemp.valorTotal;
            carrinho[numProdutos++] = produtoTemp;
            printf("Produto '%s' adicionado. Total: R$%.2f\n", produtoTemp.nome, totalCompra);
        } else if (escolha == 3) {
            printf("\nCarrinho de compras:\n");
            for (int i = 0; i < numProdutos; i++) {
                printf("Produto %d: %s - %s: %.2f, Total: R$%.2f\n", i + 1, carrinho[i].nome,
                       carrinho[i].peso > 0 ? "Peso (kg), Preço por kg" : "Total", 
                       carrinho[i].peso > 0 ? carrinho[i].peso : carrinho[i].valorTotal,
                       carrinho[i].valorTotal);
            }
            printf("Total até agora: R$%.2f\n", totalCompra);
        } else {
            printf("Escolha inválida. Tente novamente.\n");
        }
    }
}
