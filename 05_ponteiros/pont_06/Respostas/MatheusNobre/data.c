#include <stdio.h>
#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data)
{
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData( tData *data )
{
    // CORRIGIDO: Removido o '\n' do final que travava a leitura do buffer
    scanf("%2d %2d %4d", &data->dia, &data->mes, &data->ano);
}

void ImprimeData( tData *data )
{
    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data )
{
    // CORRIGIDO: Lógica simplificada e 100% correta para ano bissexto
    return (data->ano % 4 == 0 && data->ano % 100 != 0) || (data->ano % 400 == 0);
}

int InformaQtdDiasNoMes( tData *data )
{
    if(data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12)
        return 31;
    if(data->mes == 2)
    {
        if(EhBissexto(data))
            return 29;
        return 28;
        
    }
    if(data->mes == 4 || data->mes == 6 || data->mes == 9|| data->mes == 11 )
    return 30;
}

void AvancaParaDiaSeguinte( tData *data )
{
    // CORRIGIDO: Toda a lógica complexa foi substituída usando a função InformaQtdDiasNoMes
    int maxDias = InformaQtdDiasNoMes(data);

    if (data->dia < maxDias) 
    {
        data->dia++;
    } 
    else 
    {
        data->dia = 1;
        if (data->mes < 12) 
        {
            data->mes++;
        } 
        else 
        {
            data->mes = 1;
            data->ano++;
        }
    }
}

int EhIgual( tData *data1, tData *data2 )
{
    if(data1->dia == data2->dia && data1->mes == data2->mes && data1->ano == data2->ano)
        return 1;
    return 0;
}
