#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gerar_matriz(dados_matriz *flood){
	
	srand(time(NULL));
	
	int linha, coluna;
	for (linha=0; linha < flood->tamanho ; linha++){
		for (coluna = 0 ; coluna < flood->tamanho ; coluna++){
			flood->matriz[linha][coluna] = rand() % 6;
		}
	}
	
	for (linha=0; linha < flood->tamanho ; linha++){
		for (coluna = 0 ; coluna < flood->tamanho ; coluna++){
			printf("%i ", flood->matriz[linha][coluna]);
		}
		printf("\n");
	}
}
