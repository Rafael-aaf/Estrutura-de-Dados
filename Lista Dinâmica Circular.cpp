//Programa Lista Dinâmica Simples

#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct lista{
	int valor;
	lista* proximo;
};

lista *inicio;

void listavazia(){
	inicio = NULL;
}

void inserir(int pvalor){
	lista *novo;
	novo = (lista*)malloc(sizeof(lista));
	novo -> valor = pvalor;
	novo -> proximo = NULL;
	if (inicio == NULL){ // Insere para lista vazia
		inicio = novo;
		inicio -> proximo = inicio;
	}else{ // Insere para lista nao vazia
		lista *aux = inicio;
		while(aux -> proximo != inicio){
			aux = aux -> proximo;
		}
		aux -> proximo = novo;
		novo -> proximo = inicio;
	}
}

//while aux -> valor != i

void remover(){
	int i;
	lista *aux = inicio;

	printf("\nDigite o valor que quer remover\n\n");
	scanf("%d", &i);
	if (aux -> proximo == aux){ // Lista com 1 elemento
		free(inicio);
		inicio = NULL;
		printf("\nValor removido\n");
		return;
	}
	else if (inicio->valor == i){ // Remove o primeiro elemento
		lista *aux = inicio;
		while (aux->proximo != inicio){
			aux = aux->proximo;
		}
		aux->proximo = inicio->proximo;
		free(inicio);
		inicio = aux->proximo;
		printf("\nValor removido\n");
		return;
	}

	else if(aux -> proximo -> valor == i){ // Remove o segundo elemento
		lista *aux2 = aux -> proximo;
		aux -> proximo = aux -> proximo -> proximo;
		free(aux2);
		printf("\nValor removido\n");
		return;
	}
	else{ // Remove os outros elementos
		while (aux -> valor != i && aux -> proximo != inicio){ // A segunda condição faz com que o while pare depois de percorer a lista inteira
			aux = aux -> proximo;
		
			if (aux -> proximo -> valor == i){
				lista *aux2 = aux -> proximo;
				aux -> proximo = aux -> proximo -> proximo;
				free(aux2);
				printf("\nValor removido\n");
				return;
			}
		}
		printf("\nValor nao encontrado!\n");
	}
}

void editar(){
	int a, b;
	lista *aux = inicio, *no1 = NULL, *no2 = NULL;
	
	printf("\nDigite os dois valores que quer trocar:\n");
	scanf("%d %d", &a, &b);

	if (inicio == NULL) {
		printf("\nA lista esta vazia!\n");
		return;
	}


	do {
		if (aux->valor == a) no1 = aux;
		else if (aux->valor == b) no2 = aux;
		aux = aux->proximo;
	} while (aux != inicio && (no1 == NULL || no2 == NULL));

	if (no1 && no2) {
		int aux2 = no1->valor;
		no1->valor = no2->valor;
		no2->valor = aux2;
		printf("\nValores trocados com sucesso!\n");
	} else {
		printf("\nPelo menos um dos valores nao foi encontrado na lista\n");
	}
}


void exibir(){
	if (inicio == NULL){
		printf("\nA lista esta vazia!\n");
	}else{
		lista *aux = inicio -> proximo;
		printf("\n%d\n", inicio -> valor);
		while(aux != inicio){
			printf("\n%d\n", aux -> valor);
			aux = aux -> proximo;
		}
	}
}

void removertudo(){
	if (inicio == NULL) return;
	
	lista *aux = inicio -> proximo;
	while (aux != inicio) {
		lista *aux2 = aux;
		aux = aux -> proximo;
		free(aux2);
	}
	free(inicio);
	inicio = NULL;
	printf("\nLista removida com sucesso!\n");
}

int main(){
	printf("\n\t\t\t Programa Lista Dinamica Simples em C++\n\n");
	listavazia();
	
	while(true){
		int n, Valor;
		
		printf("\nPara inserir digite\t 1\n");
		printf("Para remover digite\t 2\n");
		printf("Para editar digite\t 3\n");
		printf("Para exibir digite\t 4\n");
		printf("Remover toda a lista\t 5\n\n");
		printf("Para sair\t\t 6\n\n");
		scanf("%d", &n);
		
		switch(n){
			case 1:
				printf("\nDigite o valor que quer inserir\n\n");
				scanf("%d", &Valor);
				inserir(Valor);
				break;
				
			case 2:
				if (inicio == NULL){
					printf("\nA lista ja esta vazia!\n");
				}else{
					remover();
				}
				break;
				
			case 3:
				editar();
				break;
				
			case 4:
				exibir();
				break;
				
			case 5:
				removertudo();
				break;
				
			case 6:
				return 0;
		}
	}
}