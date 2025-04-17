# Estrutura-de-Dados
Aqui estão alguns projetos feitos para a disciplina Estrutura de Dados Lineares. Todos os códigos foram feitos no Dev C++ e eu disponibilizei tanto o código fonte como o executável.

(WIP)

Estruturas estáticas:

Pilhas:


Filas:
O código tem um vetor de tamanho 3

Listas:
O código tem um vetor de tamanho 5


Estruturas Dinâmica:

Pilha Dinâmica:
As Pilhas Dinâmicas são uma estrutura do tipo LIFO (Last-in First-out), ou seja o último valor inserido será o primeiro a ser removido. Além disso, uma estrutura dinâmica tem como característica poder conter uma quantidade quase indefinida de valores e não precisar de vetores em sua implementação, já que os dados são organizados por apontamento.

Uma das minhas principais dificuldades na implementação foi justamente entender e implementar o apontamento, principalmente na função inserir. Demorou um tempo até eu entender que a variável "novo" criava uma struct nova, pode parecer bobo, mas eu realmente não entendia como o valor e o ponteiro anterior eram armazenados na memória, mas isso é feito com uma struct que armazenam ambos em um mesmo bloco, e a cada "inserir" uma nova struct é criada e apontada para a anterior.

Fila Dinâmica:
O código é muito parecido com o da Pilha Dinâmica, tanto que a função inserir é essencialmente igual, mudando apenas as variáveis
