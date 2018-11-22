#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define NAO_EXISTE_ESTRUTURA 0
#define EXISTE_ESTRUTURA 1
#define POSICAO_INVALIDA -1
#define TAM_INVALIDO 0

typedef struct principal{
	int *ponteiro;
	int tamanho;
	int quantidade;
}PRINCIPAL;

int menu();
void iniciar_estrutura(PRINCIPAL *vetor);
int ler_posicao();
int verifica_estrutura(PRINCIPAL *vetor, int posicao);
int alocar_estrutura(PRINCIPAL *vetor, int posicao);
void inserir_elemento(PRINCIPAL *vetor, int posicao);
void realocar_estrutura(PRINCIPAL *vetor, int posicao);
void listar(PRINCIPAL *vetor);
void listar_todos_ordenado(PRINCIPAL *vetor);
void listar_estrutura_ordenada(PRINCIPAL *vetor, PRINCIPAL *vetor_aux);
void excluir(PRINCIPAL *vetor, int posicao);
void destroi(PRINCIPAL *vetor);

int main(){
	PRINCIPAL vetor[TAM];
	PRINCIPAL vetor_aux[TAM];
    int opcao = 0, opArquivo = 0, sair = 0, pos;
	iniciar_estrutura(vetor);
	iniciar_estrutura(vetor_aux);
	

	while (!sair){
		opcao = menu();
        switch (opcao){
        	case 0:{
					destroi(vetor);
                	sair = 1;
                	break;
            }
            case 1:{
            		inserir_elemento(vetor, pos);
                	break;
            }	
            case 2:{ 
					listar(vetor);
                	break;
            }
            case 3:{
            		listar_estrutura_ordenada(vetor, vetor_aux);
               		break;
           	}
            case 4:{
					listar_todos_ordenado(vetor);
                	break;
            }
            case 5:{
					excluir(vetor, pos);
                	break;
            }
            case 6:{
                	realocar_estrutura(vetor, pos);
               	 	break;
            }
            default:{
                	printf("\nopcao invalida\n");
            }
		}
    }
    return 0;
}


int menu(){
    int op;
    printf("########## M E N U ##########\n");
    printf("\nInforme a opcao desejada: ");
    printf("\n0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Listar todas as estruturas\n");
    printf("3 - Listar os elementos da estrutura auxiliar de forma ordenada\n");
    printf("4 - Listar todos os elementos de forma ordenada\n");
    printf("5 - Excluir elemento\n");
    printf("6 - Realocar\n");
    scanf("%d", &op);
    return op;
}

void iniciar_estrutura(PRINCIPAL *vetor){
	int i;
	for(i = 0; i < TAM; i++){
		vetor[i].ponteiro = NULL;
		vetor[i].tamanho = 0;
		vetor[i].quantidade = 0;
	}
}

int ler_posicao(){
	int posicao;
	printf("Informe a posicao da estrutura principal: ");
	scanf("%d", &posicao);
	if((posicao > 0 && posicao < 11) && !((posicao >= 'a' && posicao <= 'z') && (posicao >= 'A' && posicao <= 'Z'))){
		return posicao;
	}
	else{
		return POSICAO_INVALIDA;
	}	
}

int verifica_estrutura(PRINCIPAL *vetor, int posicao){
	if(vetor[posicao].ponteiro != NULL){
		return EXISTE_ESTRUTURA;	
	}
	else{
		return NAO_EXISTE_ESTRUTURA;
	}
}

int alocar_estrutura(PRINCIPAL *vetor, int posicao){
	int tam_aux;
	printf("Informe o tamanho para a estrutura auxiliar: ");
	scanf("%d", &tam_aux);
	if(tam_aux > 0 && !((posicao >= 'a' && posicao <= 'z') && (posicao >= 'A' && posicao <= 'Z'))){
		vetor[posicao].ponteiro = (int*)malloc(tam_aux * sizeof(int));
		vetor[posicao].tamanho = tam_aux;
		return tam_aux;
	}
	else{
		return TAM_INVALIDO;
	}
}

void inserir_elemento(PRINCIPAL *vetor, int posicao){
	int alocar = 0, verifica = 0, i, numero;	
	posicao = ler_posicao();
	posicao = posicao - 1;
	if(posicao == POSICAO_INVALIDA){
		printf("\nPosicao informada eh invalida!!\n\n");
	}
	else{
		verifica = verifica_estrutura(vetor, posicao);
		if(verifica == NAO_EXISTE_ESTRUTURA){
			alocar = alocar_estrutura(vetor, posicao);
			if(alocar != TAM_INVALIDO){
				printf("\nEstrutura auxiliar foi criada!!!\n\n");
			}
			else{
				printf("\nTamanho informado nao eh valido!!\n\n");
			}
		}
		else{
			for(i = 0; i < TAM; i++){
				if(vetor[posicao].quantidade < vetor[posicao].tamanho){
					printf("Informe o valor da posicao %d: ", vetor[posicao].quantidade + 1);
					scanf("%d", &numero);
					vetor[posicao].ponteiro[vetor[posicao].quantidade] = numero;
					vetor[posicao].quantidade++;
					printf("\nNumero cadastrado com sucesso!\n\n");
					break;
			     }
			     else{
					printf("\nEstrutura auxiliar cheia!!!\n\n");
					break;
			     }
			}
		}
	}	
}

void realocar_estrutura(PRINCIPAL *vetor, int posicao){
	int verifica = 0, tam_realloc;
	posicao = ler_posicao();
	posicao = posicao - 1;
	verifica = verifica_estrutura(vetor, posicao);
	if(verifica == NAO_EXISTE_ESTRUTURA){
		printf("\nNao existe estrutura auxiliar criada!!\n\n");
	}
	else{
		printf("\nInforme o tamanho da estrutura para realocacao: ");
		scanf("%d", &tam_realloc);
		if(tam_realloc > 0){
			vetor[posicao].ponteiro = (int*)realloc(vetor[posicao].ponteiro, (vetor[posicao].tamanho + tam_realloc) * sizeof (int));
        		vetor[posicao].tamanho = vetor[posicao].tamanho + tam_realloc;
        printf("\nMemoria realocada com sucesso!!!\n\n");
		}
		else{
			printf("\nTamanho informado para realocacao nao eh valido!!\n\n");
		}
	}
}

void listar(PRINCIPAL *vetor){
  	int i, j;
	for(i = 0; i < TAM; i++){
    	if(vetor[i].tamanho == NAO_EXISTE_ESTRUTURA){
        	printf("\nA posicao [%d] do vetor principal nao aponta para estrutura auxiliar\n", i + 1);
        }
        else{
        	printf("\nA posicao [%d] do vetor principal aponta para %d posicoes auxiliares\n", i + 1, vetor[i].tamanho);
            for(j = 0; j < vetor[i].tamanho; j++){
            	printf("Posicao [%d]: %d\n", j, vetor[i].ponteiro[j]);
            }
        }
	}
    printf("\n");	
}

void listar_todos_ordenado(PRINCIPAL *vetor){
	int i, j, k = 0, aux = 0, total = 0;
	for(i = 0; i < TAM; i++){
		if(vetor[i].quantidade > 0){
			total = total + vetor[i].quantidade;
		}	
	}
	if(total > 0){
		int vet_aux[total];
		for(i = 0; i < TAM; i++){
			for(j = 0, k = 0; j < vetor[i].quantidade; j++, k++){
				vet_aux[k] = vetor[i].ponteiro[j];		
			}
		}
		for(i = 0; i < k; i++){
			for(j = i + 1; j < k; j++){
				if(vet_aux[i] > vet_aux[j]){
					aux = vet_aux[i];
					vet_aux[i] = vet_aux[j];
					vet_aux[j] = aux;
				}
			}
		}
		for(i = 0; i < k; i++){
			printf("Posicao[%d] = %d\n", i + 1, vet_aux[i]);
		}
	}
	else{
		printf("\nNao existem elementos!!!\n\n");	
	}
}

void listar_estrutura_ordenada(PRINCIPAL *vetor, PRINCIPAL *vetor_aux){
	int i, j, k, aux = 0;
	for(i = 0; i < TAM; i++){
		if(vetor[i].ponteiro != NULL){
			for(j = 0; j < vetor[i].quantidade; j++){
				vetor_aux[i].tamanho = vetor[i].tamanho;
				vetor_aux[i].quantidade = vetor[i].quantidade;
				vetor_aux[i].ponteiro = (int*)malloc(vetor_aux[i].tamanho * sizeof(int));
			}	
		}
	}
	for(i = 0; i < TAM; i++){
		if(vetor_aux[i].ponteiro != NULL){
			for(j = 0; j < vetor_aux[i].quantidade; j++){
				vetor_aux[i].ponteiro[j] = vetor[i].ponteiro[j];
			}
		}
	}
	for(i = 0; i < TAM; i++){
		if(vetor_aux[i].ponteiro != NULL){
			for(j = 0; j < vetor_aux[i].quantidade; j++){
				for(k = j + 1; k < vetor_aux[i].quantidade; k++){
					if(vetor_aux[i].ponteiro[j] > vetor_aux[i].ponteiro[k]){
						aux = vetor_aux[i].ponteiro[j];	
						vetor_aux[i].ponteiro[j] = vetor_aux[i].ponteiro[k];
						vetor_aux[i].ponteiro[k] = aux;
					}
				}
			}
		}
	}
	listar(vetor_aux);
	destroi(vetor_aux);
}

void excluir(PRINCIPAL *vetor, int posicao){
	int elemento, i, j, k, sair = 0, achou = 0, verifica = 0;
	posicao = ler_posicao();
	posicao = posicao - 1;
	verifica = verifica_estrutura(vetor, posicao);
	if(verifica != EXISTE_ESTRUTURA){
		printf("\nNao existe estrutura auxiliar criada!!\n\n");
	}
	else{
		if(vetor[posicao].quantidade == 0){
			printf("\nEstrutura auxiliar nao possui elementos!!\n\n");	
		}
		else{
			printf("Informe o elemento que deseja retirar da estrutura: ");
       		scanf("%d", &elemento);
			for(i = 0; i < vetor[posicao].quantidade && !sair; i++){
				if(elemento == vetor[posicao].ponteiro[i]){
					achou = i;
					sair = 1;
				}
			}
			if(sair == 1){
				for(j = achou, k = i; k < vetor[posicao].quantidade; j++, k++){
					vetor[posicao].ponteiro[j] = vetor[posicao].ponteiro[k];
				}
				vetor[posicao].quantidade--;
				printf("\nElemento excluido com sucesso!!!\n\n");	
			}
			else{
				printf("\nElemento nao existe!!\n\n");
			}
		}
	}
}

void destroi(PRINCIPAL *vetor){
	int i;
	for(i = 0; i < TAM; i++){
		if(vetor[i].ponteiro != NULL){
			free(vetor[i].ponteiro);
		}
	}
}


