//Programa Pilha Dinâmica

#include<stdio.h>
#include<conio.h>
#include<windows.h>


struct no{
	int valor;
	no* anterior;
};

no *topo;

void pilhavazia(){
	topo = NULL;
}

//Cada vez que roda o inserir() um novo nó é criado
void inserir(int pvalor){
	no *novo;
	novo = (no*)malloc(sizeof(no));
	novo -> valor = pvalor;
	novo -> anterior = topo;
	topo = novo;
	
}

void remover(){
	if (topo == NULL){
		printf("\nA pilha ja esta vazia!\n");
		return;
	}
	no *aux = topo;
	topo = aux -> anterior;
	free(aux);
	aux = topo;
}

void exibir(){
	no *aux = topo;
	int i = 0;
	if (topo == NULL){
		printf("\nA pilha esta vazia!\n");
	}else{
		while(topo != NULL){
			if (i == 0){
				printf("\nTopo: %d\n", topo -> valor);
				topo = topo -> anterior;
				i++;
			}else{
				printf("%d\n", topo -> valor);
				topo = topo -> anterior;
			}
		}
	}
	topo = aux;	
}

void removertudo(){
	while (topo != NULL){
		remover();
	}
}


int main(){
	printf("\n\t\t\t Programa Pilha Dinamica em C++\n\n");
	
	while(true){
		int n, Valor;
		
		printf("\nPara inserir digite\t 1\n");
		printf("Para remover digite\t 2\n");
		printf("Para exibir digite\t 3\n");
		printf("Remover toda a pilha\t 4\n\n");
		printf("Para sair\t\t 5\n\n");
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
				exibir();
				break;
				
			case 4:
				removertudo();
				break;
				
			case 5:
				return 0;
		}
	}
}