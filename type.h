#ifndef __A
#define __A

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Caso o usuário esteja usando o linux, desabilitar essa biblioteca conio.h
#include <conio.h>

typedef struct{
	int tamanho;
	int matriz[14][14];
} dados_matriz;


 
void gerar_matriz(dados_matriz *flood);

/**
 * Gera uma matriz.
 * @param tamanho tamanho N da matriz NxN
 * @param count , count1 , count2 são contadores
 * @return void.
 */
void alterar_matriz( int primeirocont, int segundocont,int valornovo,int valorinicial, dados_matriz *flood); 
/**
 * Altera a matriz para que a inundação seja concluída
 * @param primeirocont é parâmetro de contador para fluxo
 * @param segundocont é parâmetro de contador para fluxo
 * @param valornovo é parâmetro para inundação com aquele valor
 * @param valorinicial é parâmetro de comparação com valor inicial
 * @param *flood é ponteiro da matriz.
 */

void salvar (dados_matriz *flood);
/**
 * Salva a matriz em um arquivo .txt
 * @param *flood é ponteiro da matriz
*/

 void carregar (dados_matriz *flood1);
 /**
  * Carrega a matriz a partir de um arquivo .txt
  * @param *flood1 é ponteiro da matriz
  */
 
 #endif
