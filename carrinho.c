#include "carrinho.h"4
#include <stdio.h>
#include <string.h>

Prod carrinho[MAX];
int nProd = 0;
float totalCompra = 0;

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