#include"agencia.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NOME 100

struct Agencia{ 
    int numAgencia,numContas;
    char nomeAgencia[MAX_NOME];
    DataType *contas;
    float saldoMedio;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){
    tAgencia *a=(tAgencia*)calloc(1,sizeof(tAgencia));
    a->contas=(DataType*)calloc(1,sizeof(DataType));
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){
    tAgencia *a=(tAgencia*)agencia;
    if(a!=NULL){
        for(int i=0;i<a->numContas;i++){
            DestroiConta(a->contas[i]);
        }
        free(a->contas);
        free(a);
    }
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    scanf("%d;%[^;];",&agencia->numAgencia,agencia->nomeAgencia);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
    agencia->contas[agencia->numContas]=conta;
    agencia->numContas++;
    realloc(agencia->contas,++agencia->numContas);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    return !(numAgencia-agencia2->numAgencia);
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia){
    for(int i=0;i<agencia->numContas;i++){
        agencia->saldoMedio+=GetSaldoConta((tConta*)agencia->contas[i]);
    }
    return agencia->saldoMedio/agencia->numContas;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia){
    /*
        Lista de agencias:
	Nome: Jardim da Penha
	Numero: 110
	Numero de contas cadastradas: 2
	Saldo médio: R$9543.11
    */
    printf("Lista de agencias:\n");
    printf("\tNome: %s\n",agencia->nomeAgencia);
    printf("\tNumero: %d\n",agencia->numAgencia);
    printf("\tNumero de contas castradas: %d\n",agencia->numContas);
    printf("\tSaldo médio: R$%.2f",agencia->saldoMedio);
}