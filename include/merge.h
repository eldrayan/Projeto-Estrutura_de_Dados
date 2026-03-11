#ifndef MERGE_H
#define MERGE_H

#include "lista_dinamica.h"
#include "estatica.h"

// Define Aluno aqui (somente se ainda não tiver sido definido)
#ifndef ALUNO_TYPE_DEFINED
#define ALUNO_TYPE_DEFINED
typedef struct {
    int id;
    float nota;
} Aluno;
#endif

/**
 * @brief Merge Sort para vetor
 * Ordena um vetor de Alunos por nota em ordem crescente
 *
 * @param arr Vetor de alunos a ser ordenado
 * @param n Número de elementos no vetor
 */
void merge_sort(Aluno *arr, int n);

/**
 * @brief Merge Sort para lista dinâmica
 * Converte para vetor, ordena usando merge sort e reconverte para lista
 *
 * @param lista Lista dinâmica a ser ordenada
 */
void merge_sort_dinamica(ListaDinamica *lista);

/**
 * @brief Merge Sort para lista estática
 * Converte para vetor, ordena usando merge sort e reconverte para lista
 *
 * @param lista Lista estática a ser ordenada
 */
void merge_sort_estatica(ListaEstatica *lista);

#endif