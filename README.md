# Estrutura-de-Dados

Aqui estão alguns projetos feitos para a disciplina Estrutura de Dados Lineares. Todos os códigos foram feitos no Dev C++ e eu disponibilizei tanto o código fonte como o executável.

(WIP)

## **Estruturas estáticas:**

### **Pilhas:**


### **Filas:**
O código tem um vetor de tamanho 3

### **Listas:**
O código tem um vetor de tamanho 5


## **Estruturas Dinâmicas:**
Uma estrutura dinâmica tem como característica poder conter uma quantidade quase indefinida de valores e não precisar de vetores em sua implementação, já que os dados são organizados por apontamento. Isso é muito útil, já que não é necessário declarar o tamanho dos vetores e alocar uma quantidade de memória desnecessária ou pequena.

### **Pilha Dinâmica:**
As Pilhas Dinâmicas são uma estrutura do tipo LIFO (Last-in First-out), ou seja o último valor inserido será o primeiro a ser removido. Foi utilizado a struct "no" que possui as variáveis "valor" e "anterior", e a variável de controle "topo".

Uma das minhas principais dificuldades na implementação foi justamente entender e implementar o apontamento, principalmente na função inserir. Demorou um tempo até eu entender que a variável "novo" criava uma struct nova, pode parecer bobo, mas eu realmente não entendia como o valor e o ponteiro anterior eram armazenados na memória, mas isso é feito com uma struct que armazenam ambos em um mesmo bloco, e a cada "inserir" uma nova struct é criada e apontada para a anterior.

### **Fila Dinâmica:**
As Filas Dinâmicas são estruturas do tipo FIFO (First-in First-out), ou seja o primeiro valor inserido será o primeiro a ser removido. Além disso, foram utilizadas as variáveis "valor" e "proximo" dentro da struct "fila", e a variável de controle "fim"

O código é muito parecido com o da Pilha Dinâmica, tanto que a função inserir é essencialmente igual, mudando apenas as variáveis. A função exibir é levemente diferente, já que na Pilha Dinâmica eu deixei claro qual era o topo, enquanto aqui isso não foi necessário. O principal problema foi acessar e remover o início da fila, a ideia é que o início é o único elemento que aponta para NULL e isso foi muito difícil de se fazer! Tanto que, dentro do código tem uma explicação sobre isso. Mas eu basicamente tive que criar um loop while que avança o "aux" (auxiliar) para o próximo elemento e fazer com que quando estivesse no penúltimo elemento ele ainda entrasse no loop. Para isso, foi necessário criar uma condição onde o auxiliar aponta para o próximo que aponta para o próximo e verifica se ele é NULL, assim, quando chegar no penúltimo elemento, ele apontará para o último (que é o início) que apontará para o próximo e verá que ele é NULL, parando, assim, o loop while e liberando o "aux" (que é o último elemento) com a função free() e deixando ele NULL, para que o novo início aponte para NULL e tudo funcione!

### **Lista Dinâmica Simples**
O inserir é ainda de pilha, onde o inicio está no fim.

### **Lista Dinâmica Circular**
Consertei o inserir.

### **Lista de Encadeamento Duplo Circular e não Circular**
Esse tipo de lista se caracteriza por possuir 2 ponteiros dentro de cada struct criada, que eu chamei de "anterior" e "proximo", eles fazem o apontamento das structs e permitem que o programa funcione adequadamente. Para exemplificar, imagine 3 structs chamadas **A, B e C**, o ponteiro **anterior** da struct B aponta para A e o ponteiro **proximo** aponta para C, além disso o ponteiro **proximo** da struct A aponta para B e o ponteiro **anterior** da struct C aponta para B. Assim, cada struct aponta para a struct posterior e a anterior, e há 2 structs apontando para ela, sem contar o "início" e o "fim". No "início" e o "fim" é onde há diferença e determina se a lista é **Circular** ou não. Para uma lista circular, o padrão é o mesmo, mas o ponteiro **anterior** do "início" aponta para o "fim" e o ponteiro **proximo** do "fim" aponta para "início". Em uma lista **não Circular**, o ponteiro de "início" e "fim" apontam para **NULL**, assim, ambas variáveis tem apenas 3 ponteiros nelas ou apontando para elas.

Esta é a estrutura mais difícil de ser feita, mas para mim não foi tão difícil quanto as outras, já que eu usei 2 ponteiros e 2 variáveis, enquanto nas outras estruturas eu utilizei apenas 1 ponteiro e 1 variável. Isso facilitou muito, pois as condições dos loops são mais simples, já que eu posso saber facilmente onde é o fim e o início da lista, já que eles estão armazenados em suas próprias variáveis.

A lista não lida muito bem com repetição, além da função **inserir_meio**, e a função **editar** foi corrigida para essa estrutura.
