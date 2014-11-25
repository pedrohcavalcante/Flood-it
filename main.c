#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "type.h"
#include "sub1.c"
#include "sub2.c"
//Caso o usuário esteja usando o linux, desabilitar essa biblioteca conio.h
#include <conio.h>


int main (void){
	int teste, valorinicial, valornovo=0, linha, coluna, cont_jogada=0, conta2;
	//system( "color fc");
	dados_matriz flood1;
	srand( time(NULL) );
	printf(" =================================================================\n");
	printf("||000000   00        0000     0000    00000       000000   000000||\n");
	printf("||00       00       00  00   00  00   00  00        00       00  ||\n");
	printf("||0000     00       00  00   00  00   00  00        00       00  ||\n");
	printf("||00       00       00  00   00  00   00  00        00       00  ||\n");
	printf("||00       000000    0000     0000    00000       000000     00  ||\n");
	printf(" =================================================================\n");
	printf("Pedro Henrique & Yan Savio\n");
	printf("Digite a dificuldade do seu jogo: 4 - facil\t 10 - medio\t 14 - dificil \n");
	
	scanf("%i", &teste);
	while (valornovo != 9){
	int num_jogadas=0;
	switch(teste){
                 case 4 : 
					teste = 4; 
					num_jogadas = 10;
                 break;
                 case 10 : 
					teste = 10; 
					num_jogadas = 20;
                 break;
                 case 14 : 
					teste = 14; 
					num_jogadas = 25;
                 break;
    }
    //Caso o usuário esteja usando o Windows, habilitar esse comando
	system("cls");
	//Caso o usuário esteja usando o Linux, habilitar esse comando
	//system("clear");
	flood1.tamanho = teste;
	
	gerar_matriz(&flood1);
	
	while (cont_jogada < num_jogadas){  
        int aux=0;
		for (linha=0; linha < flood1.tamanho ; linha++){
			for (coluna = 0 ; coluna < flood1.tamanho ; coluna++){

				if ( flood1.matriz[linha][coluna] == valornovo){
					aux = aux + 1;
				if ( aux == teste*teste){
					printf("voce ganhou!\n");
				}
				}
			}
        }
          
    if ( aux != teste*teste){
		printf("Digite sua jogada (0 a 5). Digite 7 para SALVAR. 8 para CARREGAR. 9 para SAIR\n\n\n");
		scanf("%i", &valornovo);
    }
	//Caso o usuário esteja usando o Windows, habilitar esse comando
	system("cls");
	//Caso o usuário esteja usando o Linux, habilitar esse comando
	//system("clear");
	switch (valornovo){
		case 7:
			salvar(&flood1);
		case 8:
			carregar(&flood1);
		case 9:
			if (valornovo != 7 && valornovo != 8 ){
				goto fim;
		}
		default:
			if ( valornovo !=7 && valornovo !=9 && valornovo !=8 && valornovo <= 5){
				valorinicial = flood1.matriz[0][0];}
				alterar_matriz( 0, 0, valornovo, valorinicial, &flood1);
	
				for (linha=0; linha < flood1.tamanho ; linha++){
					for (coluna = 0 ; coluna < flood1.tamanho ; coluna++){
						printf("%i ", flood1.matriz[linha][coluna]);
					}
					printf("\n");

				}
				if ( valornovo !=7 && valornovo !=9 && valornovo !=8 && valornovo <= 5){
					cont_jogada++;
				}
				if ( num_jogadas - cont_jogada == 0 ){
					printf("Voce nao possui mais jogadas !");
					goto fim;
				}
				if ( aux != teste*teste){
					conta2 = num_jogadas - cont_jogada;
					printf("Faltam %i jogadas\n", conta2);
				}
						  
		}
	}
	
}
	fim:
	return 0;
}
