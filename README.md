Hortifruit
Algoritmo Frutinhas
Trabalho 2 de Algoritmos e Lógica
Professor: Marlon Generoso
Data: 31/10/2024
Nome: Maria Eduarda Mello

📜 Visão Geral
O "Algoritmo Frutinhas" é um programa em C que simula um sistema de compras básico, permitindo que o usuário:

Adicione produtos ao carrinho
Visualize os produtos no carrinho
Finalize a compra
O sistema exige autenticação do usuário para acesso, oferecendo um menu de opções após a autenticação bem-sucedida.

🗃️ Estruturas de Dados
Prod: estrutura para armazenar informações de cada produto:
nome: nome do produto
pKg: preço por quilograma (para produtos a granel)
peso: peso do produto em quilogramas (para produtos a granel)
total: valor total do produto
🛠️ Funções Principais
auth

Parâmetros: const char* esperado, const char* msg
Descrição: Compara a entrada do usuário com o valor esperado e retorna 1 para autenticação bem-sucedida ou 0 caso contrário.
login

Parâmetros: const char* user, const char* pass
Descrição: Gerencia o processo de login com até três tentativas de autenticação.
menu

Descrição: Exibe o menu principal e navega entre as opções disponíveis.
addProd

Descrição: Adiciona um produto unitário ao carrinho.
addHorti

Descrição: Adiciona um produto a granel ao carrinho, calculando o total baseado no peso.
showCarrinho

Descrição: Exibe todos os produtos atualmente no carrinho.
saveCarrinho

Descrição: Salva os produtos do carrinho em um arquivo chamado "carrinho.txt".
finalizar

Descrição: Finaliza a compra, calcula o troco e salva o carrinho no arquivo.
📌 Variáveis Principais
carrinho: array de Prod para armazenar os produtos.
nProd: contador do número de produtos no carrinho.
totalCompra: valor total acumulado da compra.
📋 Fluxo do Programa
1. Autenticação
Solicita nome de usuário e senha com até três tentativas. Em caso de sucesso, o usuário acessa o menu de operações. Se falhar, o programa encerra.

2. Menu de Operações

1. Produto Normal: Adiciona um item ao carrinho com nome e valor.
2. Hortifruti: Adiciona um item a granel com nome, preço por kg e peso.
3. Ver Carrinho: Exibe os produtos no carrinho e o total acumulado.
0. Finalizar: Finaliza a compra, solicitando o valor pago e calculando o troco.
3. Finalização da Compra
Calcula o troco e salva os dados do carrinho em "carrinho.txt".

🔄 Estrutura de Controle
Autenticação: Controlada por um loop while com três tentativas.
Menu de Escolha: Implementado com switch para selecionar as opções do menu.
Carrinho de Compras: Array de Prod armazena os itens adicionados ao carrinho.
📝 Observações
Entrada e Saída: fgets é usado para entradas de texto e scanf para valores numéricos.
Tratamento de Entrada: fgets utiliza strcspn para remover quebras de linha.
Validação de Entrada: Entrada inválida é tratada, solicitando ao usuário uma nova tentativa quando necessário.
💻 Exemplo de Execução
plaintext
Copiar código
Usuário: adm
Senha: 12345
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

Escolha o tipo de produto:
1. Produto normal
2. Hortifruti
3. Ver carrinho
0. Finalizar
Digite sua escolha: 0
Total da compra: R$12.50
Digite o valor pago pelo cliente: 20.00
Troco: R$7.50
Compra realizada com sucesso.
Carrinho salvo no arquivo com sucesso.






