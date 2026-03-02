#ifndef MERGE_H
#define MERGE_H
#include "lista_dinamica.h"
#include "estatica.h"

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
