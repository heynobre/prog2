#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

struct Locadora {
    tFilme** filme; // Vetor dinâmico de ponteiros para tFilme (ou tFilme* filme[100])
    int numFilmes;  // Quantidade de filmes atualmente cadastrados
    int lucro;      // Lucro acumulado das devoluções
};
/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora ()
{
    tLocadora *l = (tLocadora *) malloc(sizeof(tLocadora));
    if(l == NULL) exit(1);

    l->filme = (tFilme **) malloc(100 * sizeof(tFilme *));
    if(l->filme == NULL)
    {
        free(l);
        exit(1);
    }

    for (int i = 0; i < 100; i++)
    {
        l->filme[i] = NULL;
    }
     

    l->numFilmes = 0;
    l->lucro = 0;

    return l;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora)
{
    if(locadora != NULL)
    {
        for (int i = 0; i < locadora->numFilmes; i++)
        {
            if(locadora->filme[i] != NULL) DestruirFilme(locadora->filme[i]);
        }
        free(locadora->filme);
        free(locadora);
    }
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo)
{
    for (int i = 0; i < locadora->numFilmes; i++)
    {
        if(ObterCodigoFilme(locadora->filme[i]) == codigo)
        {
            printf("Filme ja cadastrado no estoque\n");
            return 1;
        }
    }

    return 0;
    
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme)
{
    if(!(VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))))
    {
        locadora->filme[locadora->numFilmes] = filme;
        (locadora->numFilmes)++;
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora)
{
    
    
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
    
    for (int i = 0; i < quantidadeCodigos; i++)
    {
        int flag = 0;
        for (int j = 0; j < locadora->numFilmes; j++)
        {
            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i]))
            {
                flag = 1;
                if(ObterQtdEstoqueFilme(locadora->filme[j]) > 0)
                {
                    AlugarFilme(locadora->filme[j]);
                    
                }
                else{
                    printf("Filme ");
                    ImprimirNomeFilme(locadora->filme[j]);
                    printf(" - %d nao disponivel no estoque. Volte mais tarde.\n", ObterCodigoFilme(locadora->filme[j]));
                }
                
            }
        }
        if(flag == 0) printf("Filme %d nao cadastrado\n", codigos[i]);
        
    }

    
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora)
{


}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
    for (int i = 0; i < quantidadeCodigos; i++)
    {
        for (int j = 0; j < locadora->numFilmes; j++)
        {
            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i]))
            {
                DevolverFilme(locadora->filme[j]);
            }
        } 
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora);

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora)
{
    for (int i = 0; i < locadora->numFilmes -1; i++)
    {
        for (int j = 0; j < locadora->numFilmes -i -1; j++)
        {
            if(CompararNomesFilmes(locadora->filme[j], locadora->filme[j+1]))
            {
                tFilme* temp = locadora->filme[j];
                locadora->filme[j] = locadora->filme[j+1];
                locadora->filme[j+1] = temp;
            }
        }
        
    }
    
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora)
{

}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora)
{
    
}