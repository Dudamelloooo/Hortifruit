#include <stdio.h>
#include <string.h>
#include <locale.h>

// aqui armazena como se fosse o carrinho dos codigos
typedef struct {
    char nome[50];
    float precoPorKg, peso, valorTotal;
} Produto;

// aqui é o login
int autenticar(const char* esperado, const char* mensagem) {
    char entrada[50]; //50 é o padrão? acho q n é. PESQUISAR
    printf("%s", mensagem);
    fgets(entrada, sizeof(entrada), stdin);
    // fgets pra ler uma linha e armazenar emm usa string
    // estrutura: fgets(buffer, tamanho, origem)
    // buffer é onde o texto vai ser armazenado
    // tambo é o tamanho max de caracteres a serem lidos
    entrada[strcspn(entrada, "\n")] = 0;
    return strcasecmp(entrada, esperado) == 0;
    // strcasecmp compara 2 strings. usada pra verificar se sao iguais. em vez de retornar verdadeiro ou falso, ela retorna
    // 0 se a string for menor que a segunda
    // -1 se a primeira string for maior que a segunda
    // valor positivo se a primeira string for maior que a segunda
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    const char *CUser = "a maioral, duda"; //* declara um ponteiro pra char. user é um ponteiro para uma string ("a maioral"), mas o conteudo apontado nao pode ser alterado
    // ou seja, armazena o endereço de memoria onde a string "a maioral, duda" está localizada
    const char *CPassword = "venero a maioral";
    int tentativas = 3;
    int escolha;
    float totalCompra = 0, valorProduto, precoPorKg, peso, valorPago, troco;
    Produto carrinho[50];
    Produto produtoTemp;
    int numProdutos = 0;

    while (tentativas-- > 0) {
        if (autenticar(CUser, "Usuário:\n") && autenticar(CPassword, "Senha:\n")) { //&&  é o operador lógico para garantir que ambas as condiçoes sejam verdadeiras para que o if seja executado (o if só vai ser executado se as duas chamadas sejam verdadeiras)

            printf("Bem-vindo!\n");
            break;
        }
        printf("Usuário ou senha incorretos!\n");
    }

    if (tentativas < 0) {
        printf("Número máximo de tentativas atingido.\n");
        return 0;
    }

    // Sistema de compras
    while (1) {
        printf("\nEscolha o tipo de produto:\n1. Produto normal\n2. Hortifruti\n3. Ver carrinho\n0. Finalizar\nDigite sua escolha: ");
        scanf("%d", &escolha);
        getchar(); // Limpa o buffer do teclado

        switch (escolha) {
            case 1:
                printf("Digite o nome do produto: ");
                fgets(produtoTemp.nome, sizeof(produtoTemp.nome), stdin); // fgets le a string e  armazena em produtoTemp.nome
                // sifeof calcula o tamanho  max para qeu o fgets nao  leia mais do que isso
                // stdin idica od dados que devem ser lidos


                produtoTemp.nome[strcspn(produtoTemp.nome, "\n")] = 0; //strcspn conta o numero de caractecteres consecutivos ate encontar o primeiro  "\n"


                printf("Digite o valor do produto: ");
                scanf("%f", &produtoTemp.valorTotal); //

                produtoTemp.precoPorKg = 0;
                produtoTemp.peso = 0;
                totalCompra += produtoTemp.valorTotal;  // adiciona o valor do produto ao total da compra

                carrinho[numProdutos++] = produtoTemp;  // adiciona o produto ao carrinho


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

                produtoTemp.valorTotal = produtoTemp.precoPorKg * produtoTemp.peso;  // calcula o valor total do produto

                totalCompra += produtoTemp.valorTotal;   // adiciona o valor do produto ao total da compra

                carrinho[numProdutos++] = produtoTemp;   // adiciona o produto ao carrinho


                printf("Produto '%s' adicionado ao carrinho. Total atual: R$%.2f\n", produtoTemp.nome, totalCompra);
                break; 

            case 3:
                printf("\nCarrinho de compras:\n");
                for (int i = 0; i < numProdutos; i++) { 

                    printf("Produto %d: %s - ", i + 1, carrinho[i].nome);  // imprime o nome do produto

                    if (carrinho[i].peso > 0) //  se o produto tiver peso, imprime o preço por kg e o peso

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
