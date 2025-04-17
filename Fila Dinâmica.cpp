//Programa Fila Dinâmica

#include<stdio.h>
#include<conio.h>
#include<windows.h>


struct fila{
	int valor;
	fila* proximo;
};

fila *fim;

void filavazia(){
	fim = NULL;
}


void inserir(int pvalor){
	fila *novo;
	novo = (fila*)malloc(sizeof(fila));
	novo -> valor = pvalor;
	novo -> proximo = fim;
	fim = novo;
		
}

void remover(){
		
	if (fim == NULL){
		printf("\nA Fila ja esta vazia!\n");
		return;
	}
	if (fim -> proximo == NULL){
		free(fim);
		fim = NULL;
		return;
	}
		
	fila *aux = fim;	
	
	while(aux -> proximo -> proximo != NULL){ //Explicacao abaixo
		aux = aux -> proximo;
	}                  
	free(aux -> proximo);
	aux -> proximo = NULL;
}
//Explicacao: Para chegar no inicio deve-se chegar no penultimo elemento e fazer com que ele entre no loop while. Essa condicao faz exatamente isso!

void exibir(){
	fila *aux = fim;
	if (fim == NULL){
		printf("\nA fila esta vazia!\n");
	}else{
		while(fim != NULL){
			printf("\n%d\n", fim -> valor);
			fim = fim -> proximo;
		}
	}
	fim = aux;	
}

void removertudo(){
	while (fim != NULL){
		remover();
	}
}


int main(){
	printf("\n\t\t\t Programa Fila Dinamica em C++\n\n");
	
	while(true){
		int n, Valor;
		
		printf("\nPara inserir digite\t 1\n");
		printf("Para remover digite\t 2\n");
		printf("Para exibir digite\t 3\n");
		printf("Remover toda a fila\t 4\n\n");
		printf("Para sair\t\t 5\n\n");
		scanf("%d", &n);
		
		if(n < 1 || n > 5){
			printf("\nDigite um operacao valida!\n");
			continue;
		}
		
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