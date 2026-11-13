#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesao.h"

struct Lesao
{
    char id[MAX_ID_LES];
    char diagnostico[MAX_DIAG_LES];
    char regiao[MAX_REG_LES];
    int porc_malignidade;
    char cartao_sus[MAX_CARTAO_LES];
};

/*
Função que cria uma lesão a partir dos parâmetros fornecidos.
@param cartaoSus: Cartão SUS do paciente associado à lesão.
@param id: Identificador único da lesão.
@param diagnostico: Diagnóstico da lesão.
@param regiao: Região do corpo onde a lesão está localizada.
@param malignidade: Indicador de malignidade (1 para maligna, 0 para benigna).
@return Ponteiro para a lesão criada.
*/
Lesao *criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade)
{
    Lesao *l = (Lesao *) calloc(1, sizeof(Lesao));

    strcpy(l->id, id);
    strcpy(l->diagnostico, diagnostico);
    strcpy(l->regiao, regiao);
    l->porc_malignidade = malignidade;
    strcpy(l->cartao_sus, cartaoSus);

    return l;
}

/*
Função que lê os dados de uma lesão a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para a lesão lida.
*/
Lesao *lerLesao()
{
    Lesao *l = (Lesao *) calloc(1, sizeof(Lesao));

    scanf("%[^\n]\n", l->cartao_sus);
    scanf("%[^\n]\n", l->id);
    scanf("%[^\n]\n", l->diagnostico);
    scanf("%[^\n]\n", l->regiao);
    scanf("%d", &l->porc_malignidade);

    return l;

}

/*
Função que obtém o cartão SUS associado a uma lesão.
@param l: Ponteiro para a lesão da qual se deseja obter o cartão SUS.
@param cartaoSus: String onde o cartão SUS será armazenado.
*/
char *getCartaoSusLesao(Lesao *l)
{
    return l->cartao_sus;
}

/*
Função que verifica se uma lesão é cirúrgica (maligna).
@param l: Ponteiro para a lesão a ser verificada.
@return 1 se a lesão for cirúrgica (maligna), 0 caso contrário.
*/
int verificaCirurgicaLesao(Lesao *l)
{
    if(l->porc_malignidade > 50) return 1;

    return 0;
}

/*
Função que imprime o identificador de uma lesão.
@param l: Ponteiro para a lesão cuja identificação será impressa.
*/
void imprimeIdLesao(Lesao *l);

/*
Função que libera a memória alocada para uma lesão.
@param l: Ponteiro para a lesão a ser liberada.
*/
void liberaLesao(Lesao *l);