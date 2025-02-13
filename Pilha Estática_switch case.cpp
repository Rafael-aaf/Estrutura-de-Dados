// Programa Pilha em C

#include<stdio.h>
#include<conio.h>

//#define tamVetor 3
//int vetor[tamVetor];


int main(){
	int cont = 0; //contador
	int vetor[3];
	
	while (true){
		int n;
		
		printf("\n\tPrograma Pilha em C++\n\n");
		printf("Para inserir digite\t 1\n");
		printf("Para remover digite\t 2\n");
		printf("Para exibir digite\t 3\n\n");
		printf("Para sair\t\t 4\n\n");
		scanf("%d", &n);
		
		switch (n){
			case 1:
			if (cont >= 3){
				printf("\nA pilha esta cheia\n");
				continue;
			}
			printf("\nDigite um numero para ser inserido: ");
			scanf("%d", &vetor[cont]);
			
			cont++;
			break;
		
		case 2:
			cont--;
			break;
		
		case 3:
			if (cont < 1){
				printf("\nA pilha esta vazia\n");
			}else{
			printf("\nO numero exibido: \t");
			for (int i = 0; i < cont; i++){
				printf("\n%d", vetor[i]);
			}
			}//printf("%d\n\n", vetor[cont - 1]);}
			break;
		
		case 4:
			return 0;
		}
	}
}
