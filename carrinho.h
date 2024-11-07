#ifndef CARRINHO_H
#define CARRINHO_H

#define MAX 50

typedef struct {
    char nome[50];
    float pKg, peso, total;
} Prod;

extern Prod carrinho[MAX];
extern int nProd;
extern float totalCompra;

void addProd();
void addHorti();
void showCarrinho();
void saveCarrinho();
void finalizar();

#endif