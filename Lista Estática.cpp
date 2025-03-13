// Lista Estática

#include<stdio.h>
#include<conio.h>

int main(){
	int vetor[5];
	for (int i; i < 5; i++){ // Sem isso o vetor[2] é igual a 54 por algum motivo
		vetor[i] = 0;
	}
	int cont;
	int k;
	
	while (true){
		int n;
		
		printf("\n\tPrograma Lista em C++\n\n");
		printf("Para inserir digite\t 1\n");
		printf("Para remover digite\t 2\n");
		printf("Para editar digite\t 3\n");
		printf("Para exibir digite\t 4\n\n");
		printf("Para sair\t\t 5\n\n");
		scanf("%d", &n);
		
		switch (n){
			case 1:
				printf("\nDigite a posicao do vetor que voce quer inserir: ");
				scanf("%d", &cont);
				
				if(cont > 4){
					printf("\nO vetor tem tamanho 5, tente novamente.\n");
					break;
				}else{
					printf("\nDigite um numero para ser inserido: ");
					scanf("%d", &vetor[cont]);
					break;
				}
			
			case 2:
				printf("\nOs numeros sao: \t");
				for (int i = 0; i < 5; i++){
					printf("\n%d", vetor[i]);
				}
				printf("\n\nDigite a posicao que voce quer remover: ");
				scanf("%d", &cont);
				vetor[cont] = 0;
				break;
				
			case 3:
				printf("\nOs numeros sao: \t");
				for (int i = 0; i < 5; i++){
					printf("\n%d", vetor[i]);
				}
				printf("\nQual posicao voce quer editar: ");
				scanf("%d", &cont);
				if (cont > 4){
					printf("\nA posicao maxima e 4\n");
				}else{
	
					printf("\nPara qual posicao voce quer editar: ");
					scanf("%d", &k);
					vetor[k] = vetor[cont];
					vetor[cont] = 0;
				}
				break;
				
			case 4:
				printf("\nLista: \t");
				for (int i = 0; i < 5; i++){
					printf("\n%d", vetor[i]);
				}
				break;
				
			case 5:
				return 0;
		}
	}
}

