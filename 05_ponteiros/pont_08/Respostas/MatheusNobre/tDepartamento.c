#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"
#include <stdlib.h>


/*typedef struct departamento {
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    char nome[STRING_MAX];
    int m1, m2, m3;
} tDepartamento;*/

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor )
                                {
                                    tDepartamento d;
                                    strcpy(d.curso1, *curso1);
                                    strcpy(d.curso2, *curso2);
                                    strcpy(d.curso3, *curso3);
                                    strcpy(d.diretor, *diretor);
                                    strcpy(d.nome, *nome);
                                    d.m1 = m1;
                                    d.m2 = m2;
                                    d.m3 = m3;

                                    return d;


                                }

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

float CalculaMedia(tDepartamento d){

    float media = abs(d.m1 + d.m2 + d.m3)/3;

    return media;
}

void ImprimeAtributosDepartamento(tDepartamento depto)
{
    printf("Departamento: %s\n", depto.nome);
    printf("    Diretor: %s\n", depto.diretor);
    printf("    1o curso: %s\n", depto.curso1);
    printf("    Media do 1o curso: %d\n", depto.m1);
    printf("    2o curso: %s\n", depto.curso2);
    printf("    Media do 2o curso: %d\n", depto.m2);
    printf("    3o curso: %s\n", depto.curso3);
    printf("    Media do 3o curso: %d\n", depto.m3);
    printf("    Media dos cursos: %.2f\n", CalculaMedia(depto));
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos)
{
    tDepartamento aux;
    for (int i = 0; i < num_deptos -1; i++)
    {
        for (int j = 0; j < num_deptos -i -1; j++)
        {
            if(CalculaMedia(vetor_deptos[j]) < CalculaMedia(vetor_deptos[j+1]))
            {
                aux = vetor_deptos[j];
                vetor_deptos[j] = vetor_deptos[j+1];
                vetor_deptos[j+1] = aux;

            }
        }
        
    }
    
}

/*
 vetor de 3 departamentos com media 2, 3 ,1 e 4
 1 iteração do de dentro
 3 2 1 0



*/

/*
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos)
{
    tDepartamento d[num_deptos];
    float maior_media = CalculaMedia(vetor_deptos[0]);
    int id = 0;

    for (int j = 0; j < num_deptos; j++)
    {
        for (int i = 1; i < num_deptos; i++)
        {
        float m = CalculaMedia(vetor_deptos[i]);
        if(m > maior_media)
        {
            maior_media = m;
            id = i;

        }
        }

        d[j]= vetor_deptos[id];

    }
    
    
    
}*/


