#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

int *CriaVetor(int tamanho)
{
    int *v = (int*) malloc(tamanho * sizeof(int));
    return v;

}

/**
 * Lê um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
}

/**
 * Calcula a média dos valores de um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
float CalculaMedia(int *vetor, int tamanho)
{
    float media = 0.0;

    for (int i = 0; i < tamanho; i++)
    {
        media += vetor[i];
    }
    
    media/=tamanho;

    return media;
}

/**
 * Libera a memória alocada para um vetor de inteiros.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(int *vetor)
{
    free(vetor);
}