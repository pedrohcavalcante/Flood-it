#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alterar_matriz( int primeirocont, int segundocont,int valornovo,int valorinicial, dados_matriz *flood)
{
	if ( flood->matriz[primeirocont][segundocont] == valorinicial)
	{
		flood->matriz[primeirocont][segundocont] = valornovo;
		if (primeirocont + 1 < flood->tamanho){
			alterar_matriz( primeirocont + 1, segundocont,valornovo,valorinicial,flood);
		} 
		if (primeirocont - 1 > 0){
			alterar_matriz( primeirocont - 1, segundocont,valornovo,valorinicial,flood);
		}
		if (segundocont + 1 < flood->tamanho){
			alterar_matriz( primeirocont, segundocont + 1,valornovo,valorinicial,flood);
		} 
		if (segundocont - 1 > 0 ){
		alterar_matriz( primeirocont, segundocont - 1,valornovo,valorinicial,flood);
		}
		
	}	
}

void salvar (dados_matriz *flood1){
	FILE *jogo = fopen("jogo.txt", "w");
	int i, j;
	for (i=0;i<flood1->tamanho;i++){
		for (j=0;j<flood1->tamanho;j++){
			fprintf(jogo, " %i", flood1->matriz[i][j]);
		}
		fprintf(jogo, "\n");
	}
	fclose(jogo);
}

void carregar (dados_matriz *flood1){
	FILE *jogo = fopen("jogo.txt", "r");
	int i, j;
	int subzero;
	for (i=0;i<flood1->tamanho;i++){
		for (j=0;j<flood1->tamanho;j++){
			fscanf(jogo, "%i", &subzero);
			flood1->matriz[i][j] = subzero;
		}
		fscanf(jogo, "\n");
	}
	fclose(jogo);
}
