#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

/**
 * Função que cria uma matriz de inteiros, alocada dinamicamente. Se a alocação falhar, o programa é encerrado.
 * 
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz. 
 * @return Ponteiro para a matriz alocada.
*/
int **CriaMatriz(int linhas, int colunas)
{
    // 1. Aloca o vetor de ponteiros para as linhas
    int **v = (int **) malloc(linhas * sizeof(int *));

    // 2. Aloca cada uma das linhas
    for (int i = 0; i < linhas; i++) {
        v[i] = (int *) malloc(colunas * sizeof(int));
    }

    return v;
}

/**
 * Função que libera a memória alocada para uma matriz de inteiros.
 * 
 * @param matriz Ponteiro para a matriz a ser liberada.
 * @param linhas Número de linhas da matriz.
*/

void LiberaMatriz(int **matriz, int linhas)
{
    if (matriz == NULL) return; // Proteção caso a matriz já seja nula

    // 1. Libera cada uma das linhas individuais (colunas)
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }

    // 2. Libera o vetor de ponteiros principal
    free(matriz);
}


/**
 * Função que lê uma matriz de inteiros da entrada padrão.
 * 
 * @param matriz Ponteiro para a matriz a ser lida.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void LeMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
            
        }
        
    }
    
}

/**
 * Imprime a matriz transposta da matriz dada.
 * 
 * @param matriz Ponteiro para a matriz.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < colunas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
        
    }
    
}
