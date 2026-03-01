#ifndef MERGE_UTILS_H
#define MERGE_UTILS_H

#include "lista_dinamica.h"
#include "estatica.h"

/**
 * @brief Estrutura para armazenar dados de aluno em array
 * Usada para conversão de listas para vetores
 */
#ifndef ALUNO_TYPE_DEFINED
#define ALUNO_TYPE_DEFINED
typedef struct {
    int id;
    float nota;
} Aluno;
#endif

/**
 * @brief Converte uma lista dinâmica em um vetor de alunos
 * 
 * @param lista Lista dinâmica de origem
 * @param vetor Ponteiro para o array onde os dados serão copiados
 * @return int Quantidade de elementos convertidos
 */
int lista_dinamica_para_vetor(ListaDinamica *lista, Aluno **vetor);

/**
 * @brief Converte um vetor de alunos de volta para uma lista dinâmica
 * 
 * @param vetor Array de alunos a serem inseridos
 * @param tamanho Quantidade de elementos no vetor
 * @param lista Lista dinâmica de destino
 */
void vetor_para_lista_dinamica(Aluno *vetor, int tamanho, ListaDinamica *lista);

/**
 * @brief Converte uma lista estática em um vetor de alunos
 * 
 * @param lista Lista estática de origem
 * @param vetor Ponteiro para o array onde os dados serão copiados
 * @return int Quantidade de elementos convertidos
 */
int lista_estatica_para_vetor(ListaEstatica *lista, Aluno **vetor);

/**
 * @brief Converte um vetor de alunos de volta para uma lista estática
 * 
 * @param vetor Array de alunos a serem inseridos
 * @param tamanho Quantidade de elementos no vetor
 * @param lista Lista estática de destino
 */
void vetor_para_lista_estatica(Aluno *vetor, int tamanho, ListaEstatica *lista);

#endif
