//Programa Lista Dinâmica de Encadeamento Duplo

#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct lista {
	int valor;
	lista *proximo;
	lista *anterior;
};

lista *inicio;
lista *fim;

void listavazia(){
	inicio = NULL;
	fim = NULL;
}

void inserir_inicio(int pvalor){
	lista *novo;
	novo = (lista*)malloc(sizeof(lista));
	novo -> valor = pvalor;
	
	if (inicio == NULL){ //Insere para lista vazia
		inicio = novo;
		fim = novo;
		inicio -> proximo = inicio;
		inicio -> anterior = inicio;
	}else{ //Insere no inicio para lista nao vazia
		novo -> proximo = inicio;
		novo -> anterior = fim;
		inicio -> anterior = novo; // Atualiza os nós antigos
		fim -> proximo = novo;
		inicio = novo;
	}
}

void inserir_fim(int pvalor){
	lista *novo;
	novo = (lista*)malloc(sizeof(lista));
	novo -> valor = pvalor;
	
	if (inicio == NULL){ //Insere para lista vazia
		inicio = novo;
		fim = novo;
		inicio -> proximo = inicio;
		inicio -> anterior = inicio;
	}else{ //Insere no fim para lista nao vazia
		novo -> proximo = inicio;
		novo -> anterior = fim;
		fim -> proximo = novo; // Atualiza os nós antigos
		inicio -> anterior = novo;
		fim = novo;
	}
}

void inserir_meio(int pvalor){
	int a, b;
	lista *aux = inicio;
	
	lista *novo;
	novo = (lista*)malloc(sizeof(lista));
	novo -> valor = pvalor;
	
	printf("\nDigite entre que valores quer inserir:\n");
	scanf("%d %d", &a, &b);
	
	//Verifica se o usuario quer inserir entre o inicio e o fim para lista com mais de 2 valores
	if ((inicio -> valor == a && fim -> valor == b || inicio -> valor == b && fim -> valor == a) && inicio -> proximo != fim){ 
		printf("\nNao e possivel inserir entre o inicio e o fim\n");
		return;
	} else if(inicio -> proximo == fim){ //Insere para lista com 2 elementos
		novo -> proximo = fim;
		novo -> anterior = inicio;
		inicio -> proximo = novo;
		fim -> anterior = novo;
		printf("\nValor inserido!\n");
		return;
	} else{
		do {
			if (aux -> valor == a && aux -> proximo -> valor == b){
				novo -> proximo = aux -> proximo;
				novo -> anterior = aux;
				aux -> proximo -> anterior = novo;
				aux -> proximo = novo;
				printf("\nValor inserido!\n");
				return;
			} else if(aux -> valor == a && aux -> anterior -> valor == b){
				novo -> proximo = aux;
				novo -> anterior = aux -> anterior;
				aux -> anterior -> proximo = novo;
				aux -> anterior = novo;
				printf("\nValor inserido!\n");
				return;
			}
			
			aux = aux -> proximo;
		}while (aux -> proximo != inicio);
	}
}

void editar(){
	int a, b;
	lista *aux = inicio;
	
	printf("\nDigite o valor que quer alterar:\n");
	scanf("%d", &a);
	printf("\nDigite para qual valor quer editar:\n");
	scanf("%d", &b);
	
	do{
		if(aux -> valor == a){
			aux -> valor = b;
			printf("\nValor editado com sucesso!\n");
			return;
		}
		
		aux = aux -> proximo;
	}while(aux != inicio);
	
	printf("\nValor nao existe na lista\n");
}

void excluir(){
	int i;
	lista *aux = inicio;
	
	printf("\nDigite o valor que quer excluir\n\n");
	scanf("%d", &i);
	
	if(aux -> valor == i && aux -> proximo == aux){ //Lista com 1 elemento
		free(aux);
		inicio = NULL;
		fim = NULL;
		printf("\nValor removido\n");
		return;
	} else if (aux -> valor == i){ // Remove o primeiro elemento
		aux = aux -> proximo;
		fim -> proximo = aux;
		aux -> anterior = fim;
		free(inicio);
		inicio = aux;
		printf("\nValor removido\n");
		return;
	}
	else if(aux -> valor != i){
		do{
			if (aux -> valor == i && aux == fim){ //Remove o fim
				aux = aux -> anterior;
				aux -> proximo = inicio;
				inicio -> anterior = aux;
				free(fim);
				fim = aux;
				printf("\nValor removido\n");
				return;
			}
			else if (aux -> valor == i){ //Remove os outros valores
				aux -> proximo -> anterior = aux -> anterior;
				aux -> anterior -> proximo = aux -> proximo;
				free(aux);
				printf("\nValor removido\n");
				return;
			}
			
			aux = aux -> proximo;
		}while (aux != inicio);
	}
	printf("\nValor nao encontrado!\n");
}

void exibir_inicio_fim(){
	if (inicio == NULL){
		printf("\nA lista esta vazia!\n");
		return;
	}

	lista *aux = inicio;
	do {
		printf("\n%d\n ", aux->valor);
		aux = aux->proximo;
	} while (aux != inicio);
}

void exibir_fim_inicio(){
	if (inicio == NULL){
		printf("\nA lista esta vazia!\n");
		return;
	}

	lista *aux = fim;
	do {
		printf("\n%d\n ", aux->valor);
		aux = aux->anterior;
	} while (aux != fim);
}

int main(){
	printf("\n\t\t\t Programa Lista Dinamica de Encadeamento Duplo em C++\n\n");
	listavazia();

	while(true){
		int op, Valor;
		
		printf("\nPara inserir no inicio da lista digite\t\t 1\n");
		printf("Para inserir no fim da lista digite\t\t 2\n");
		printf("Para inserir entre dois valores digite\t\t 3\n");
		printf("Para editar um valor digite\t\t\t 4\n");
		printf("Para excluir digite\t\t\t\t 5\n");
		printf("Para exibir a lista do inicio para o fim digite\t 6\n");
		printf("Para exibir a lista do fim para o inicio digite\t 7\n");
		printf("Para sair\t\t\t\t\t 8\n\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nDigite o valor que quer inserir\n\n");
				scanf("%d", &Valor);
				inserir_inicio(Valor);
				break;
				
			case 2:
				printf("\nDigite o valor que quer inserir\n\n");
				scanf("%d", &Valor);
				inserir_fim(Valor);
				break;
				
			case 3:
				if (inicio == NULL || inicio -> proximo == inicio){
					printf("\nEssa funcao insere entre dois valores. Tente novamente nos outros inserir!\n");
				}else{
					printf("\nDigite o valor que quer inserir\n\n");
					scanf("%d", &Valor);
					inserir_meio(Valor);
				}
				break;
				
			case 4:
				if (inicio == NULL){
					printf("\nNão tem nenhum valor!\n");
				} else{
					editar();
				}
				break;
				
			case 5:
				if (inicio == NULL){
					printf("\nA lista ja esta vazia!\n");
				}else{
					excluir();
				}
				break;
			
			case 6:
				exibir_inicio_fim();
				break;
			
			case 7:
				exibir_fim_inicio();
				break;
				
			case 8:
				return 0;
				
			default:
				printf("\nValor Invalido\n");
		}
	}
}