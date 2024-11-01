# Hortifruit
pseudo- readme
Algoritmo Frutinhas
Trabalho 2 de Algoritmos e Lógica, simula um sistema de compras em C onde o usuário pode adicionar produtos ao carrinho, visualizar e finalizar a compra.

Professor: Marlon Generoso
Data: 31/10/2024
Nome: Maria Eduarda Mello


📜 Visão Geral
O "Algoritmo Frutinhas" é um programa em C que simula um sistema de compras simples. Ele permite ao usuário adicionar produtos ao carrinho, visualizar os produtos adicionados e finalizar a compra. Para acessar o sistema, o usuário deve se autenticar com um nome de usuário e senha. Após a autenticação, o programa oferece um menu com as opções principais de operação.

🗃️ Estruturas de Dados
Produto: estrutura que armazena informações de cada produto, incluindo:
nome: nome do produto
precoPorKg: preço do produto por quilograma (para produtos a granel)
peso: peso do produto em quilogramas (para produtos a granel)
valorTotal: valor total do produto no carrinho

🛠️ Funções
autenticar
Parâmetros: const char* esperado, const char* mensagem
Descrição: Autentica o usuário comparando a entrada com o valor esperado. Solicita a entrada do usuário e retorna 1 (verdadeiro) se a entrada for igual ao valor esperado, ou 0 (falso) caso contrário.

📌 Variáveis Principais
CUser e CPassword: constantes contendo o nome de usuário e senha requeridos para autenticação.
carrinho: array de Produto, usado para armazenar os produtos adicionados.
totalCompra: variável acumuladora do valor total da compra.
numProdutos: contador de produtos adicionados ao carrinho.

📋 Fluxo do Programa
Autenticação do Usuário

O programa solicita nome e senha, com até três tentativas. Em caso de sucesso, o usuário acessa o menu de compras; em caso de falha, o programa encerra.
Menu de Operações

1. Produto Normal: Adiciona um item unitário, solicitando nome e valor.
2. Hortifruti: Adiciona um item a granel, solicitando nome, preço por kg, e peso. O programa calcula o valor total do item e adiciona ao totalCompra.
3. Ver Carrinho: Exibe os produtos no carrinho com informações detalhadas.
0. Finalizar Compra: Exibe o valor total, solicita o valor pago e calcula o troco. Caso o valor seja insuficiente, exibe uma mensagem de erro.
Finalização da Compra

Ao finalizar, o programa calcula o troco e encerra a operação. Em caso de valor pago insuficiente, solicita um valor adicional.

🔄 Estrutura de Controle
Autenticação: Controlada por um while com limite de três tentativas.
Menu de Escolha: Implementado com um switch para selecionar as opções do menu.
Carrinho de Compras: Array de Produto para armazenar itens adicionados.

📝 Observações
Entrada e Saída: fgets é usado para entradas de texto, e scanf para valores numéricos.
Tratamento de Entrada: fgets possui tratamento para remover quebras de linha com strcspn.
Case Insensitive: Utiliza strcasecmp para comparações insensíveis a maiúsculas e minúsculas nas entradas de autenticação.

Exemplo de execução
Usuário: a maioral, duda
Senha: venero a maioral
Bem-vindo!

Escolha o tipo de produto:
1. Produto normal
2. Hortifruti
3. Ver carrinho
0. Finalizar
Digite sua escolha: 1
Digite o nome do produto: Café
Digite o valor do produto: 12.50
Produto 'Café' adicionado ao carrinho. Total atual: R$12.50
...
