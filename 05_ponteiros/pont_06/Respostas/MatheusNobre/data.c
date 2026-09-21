#include <stdio.h>
#include "data.h"

/**
 * @brief Inicializa uma data com os valores passados como parâmetro.
 * 
 * Esta função recebe como parâmetro o dia, mês e ano de uma data e inicializa a estrutura tData correspondente com esses valores.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @param data Ponteiro para a estrutura tData que será inicializada.
 */
void InicializaDataParam( int dia, int mes, int ano, tData *data)
{
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

/**
 * @brief Lê uma data do usuário.
 * 
 * Esta função lê do usuário o dia, mês e ano de uma data e armazena esses valores na estrutura tData correspondente.
 * 
 * @param data Ponteiro para a estrutura tData que será preenchida com os valores lidos.
 */
void LeData( tData *data )
{
    scanf("%2d %2d %4d\n", &data->dia, &data->mes, &data->ano);
}

/**
 * @brief Imprime uma data na tela.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e imprime na tela o dia, mês e ano correspondentes.
 * 
 * @param data Ponteiro para a estrutura tData que será impressa.
 */
void ImprimeData( tData *data )
{
    printf("'%02d/%02d/%04d'\n", data->dia, data->mes, data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e verifica se o ano correspondente é bissexto.
 * 
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return 1 se o ano é bissexto, 0 caso contrário.
 */
int EhBissexto( tData *data )
{
    if(!(data->ano % 4))
    {
        if (data->ano % 100 == 00)
        {
            if (!(data->ano % 400))
            {
                return 1;
            }
            else
                return 0;
            
        }
        
        if (!((data->ano % 100) % 4))
        {
            return 1;
        }
        else
            return 0;
        
        
    }
    else
        return 0;
}

/**
 * @brief Informa a quantidade de dias no mês de uma data.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e informa a quantidade de dias no mês correspondente.
 * 
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return Quantidade de dias no mês correspondente.
 */
int InformaQtdDiasNoMes( tData *data )
{
    switch (data->mes)
    {
    case 1:
        return 31;
        break;
    case 2:
        if(EhBissexto(data))
            return 29;
        return 28;
        break;
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;
    default:
        break;
    }
}

/**
 * @brief Avança uma data para o dia seguinte.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e avança a data correspondente para o dia seguinte.
 * 
 * @param data Ponteiro para a estrutura tData que será avançada.
 */
void AvancaParaDiaSeguinte( tData *data )
{
    switch (data->mes)
    {
    case 1:
        if (data->dia == 31)
        {
            data->dia = 1;
            data->mes++;
        }
        else
        {
            data->dia++;
        }
        break;
    case 2:
        if (EhBissexto(data))
        {
            if(data->dia == 29)
            {
                data->dia = 1;
                data->mes++;
            }
        }
        else
        {
            if(data->dia == 28)
            {
                data->dia = 1;
                data->mes++;
            }
        }
        break;
    case 3:
        if (data->dia == 31)
        {
            data->dia = 1;
            data->mes++;
        }
    case 4:
        if (data->dia == 30)
        {
            data->dia = 1;
            data->mes++;
        }
        break;
    case 5:
        if (data->dia == 31)
        {
            data->dia = 1;
            data->mes++;
        }
        break;
    case 6:
        if (data->dia == 30)
        {
            data->dia = 1;
            data->mes++;
        }
        break;
    case 7:
        if (data->dia == 31)
        {
            data->dia = 1;
            data->mes++;
        }
        break;
    case 8:
        if (data->dia == 31)
        {
            data->dia = 1;
            data->mes++;
        }
        break;
    case 9:
        if (data->dia == 30)
        {
            data->dia = 1;
            data->mes++;
        }
        break;
    case 10:
        if (data->dia == 31)
        {
            data->dia = 1;
            data->mes++;
        }
        break;
    case 11:
        if (data->dia == 30)
        {
            data->dia = 1;
            data->mes++;
        }
        break;
    case 12:
        if (data->dia == 31)
        {
            data->dia = 1;
            data->mes = 1;
            data->ano++;
        }
        break;
    default:
        data->dia++;
        break;
    }
}

/**
 * @brief Verifica se duas datas são iguais.
 * 
 * Esta função recebe como parâmetro duas estruturas tData e verifica se elas representam a mesma data.
 * 
 * @param data1 Ponteiro para a primeira estrutura tData que será comparada.
 * @param data2 Ponteiro para a segunda estrutura tData que será comparada.
 * @return 1 se as datas são iguais, 0 caso contrário.
 */
int EhIgual( tData *data1, tData *data2 )
{
    if(data1->dia == data2->dia && data1->mes == data2->mes && data1->ano == data2->ano)
        return 1;
    return 0;
}