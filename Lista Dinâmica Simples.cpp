//Programa Lista Dinâmica Simples

#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct lista{
	int valor;
	lista* proximo;
};

lista *fim;

void listavazia(){
	fim = NULL;
}

void inserir(int pvalor){
	lista *novo;
	novo = (lista*)malloc(sizeof(lista));
	novo -> valor = pvalor;
	novo -> proximo = fim;
	fim = novo;
		
}

void remover(){
	int i;
	lista *aux;
	aux = fim;
	
	if (aux == NULL){
		printf("\nA lista ja esta vazia!\n");
	}else{
		printf("\nDigite o valor que quer remover\n\n");
		scanf("%d", &i);
		if(aux -> valor == i && aux -> proximo == NULL){
			free(aux);
			fim = NULL;
		}else{
			while(aux != NULL && aux -> proximo != NULL){
				if(aux -> proximo -> valor == i){
					lista *aux2 = aux -> proximo;
					aux -> proximo = aux -> proximo -> proximo;
					free(aux2);
					return;
				}else if(aux -> valor == i){
					fim = aux -> proximo;
					free(aux);
					return;
				}
				else{
				aux = aux -> proximo;
				}
			}
			printf("\nValor nao encontrado na lista!\n");
		}
	}
}

void editar(){
	int valor_a, valor_b, aux2;
	lista *aux = fim;
	lista *no_a = NULL;
	lista *no_b = NULL;

	printf("\nPara se editar e necessario alterar um valor por outro valor que existam na lista\n\n");
	printf("\nQual valor voce quer editar?\n");
	scanf("%d", &valor_a);
	printf("\nQual o outro valor?\n");
	scanf("%d", &valor_b);

	while (aux != NULL){
		if (aux->valor == valor_a){
			no_a = aux;
		} else if (aux->valor == valor_b){
			no_b = aux;
		}
		aux = aux->proximo;
	}

	if (no_a != NULL && no_b != NULL){
		aux2 = no_a->valor;
		no_a->valor = no_b->valor;
		no_b->valor = aux2;
		printf("\nValores trocados com sucesso!\n");
	} else {
		printf("\nPelo menos um  dos valores nao foi encontrados na lista\n");
	}
}

void exibir(){
	lista *aux = fim;
	if (aux == NULL){
		printf("\nA lista esta vazia!\n");
	}else{
		while(aux != NULL){
			printf("\n%d\n", aux -> valor);
			aux = aux -> proximo;
		}
	}
}

void removertudo(){
	while (fim != NULL) {
		lista *aux = fim;
		fim = fim->proximo;
		free(aux);
	}
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
		printf("Remover toda a fila\t 5\n\n");
		printf("Para sair\t\t 6\n\n");
		scanf("%d", &n);
		
		switch(n){
			case 1:
				printf("\nDigite o valor que quer inserir\n\n");
				scanf("%d", &Valor);
				inserir(Valor);
				break;
				
			case 2:
				remover();
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