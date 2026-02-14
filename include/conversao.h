#ifndef CONVERSAO_H
#define CONVERSAO_H

#include <stdbool.h>
#include "lista_dinamica.h"
#include "estatica.h"
#include "../src/algoritmos/insertion.h"

/**
 * @brief Converte uma Lista Dinâmica para um vetor de Aluno.
 * Copia os elementos da lista encadeada para um vetor alocado dinamicamente.
 * 
 * @param lista Ponteiro para a lista dinâmica
 * @return Aluno* Vetor alocado dinamicamente com os elementos da lista, ou NULL se falha
 */
Aluno* lista_dinamica_para_vetor(Lista *lista);

/**
 * @brief Converte um vetor de Aluno para uma Lista Dinâmica.
 * Cria uma lista encadeada a partir dos elementos do vetor.
 * 
 * @param vetor Vetor de alunos
 * @param n Tamanho do vetor
 * @return Lista* Ponteiro para a nova lista dinâmica criada, ou NULL se falha
 */
Lista* vetor_para_lista_dinamica(Aluno vetor[], int n);

/**
 * @brief Converte uma Lista Estática para um vetor de Aluno.
 * Copia os elementos da lista estática para um vetor alocado dinamicamente.
 * 
 * @param lista Ponteiro para a lista estática
 * @return Aluno* Vetor alocado dinamicamente com os elementos da lista, ou NULL se falha
 */
Aluno* lista_estatica_para_vetor(ListaEstatica *lista);

/**
 * @brief Converte um vetor de Aluno para uma Lista Estática.
 * Reconstrói uma lista estática a partir dos elementos do vetor ordenado.
 * 
 * @param lista Ponteiro para a lista estática (será inicializada)
 * @param vetor Vetor de alunos ordenado
 * @param n Tamanho do vetor
 * @return bool true se a conversão foi bem-sucedida, false caso contrário
 */
bool vetor_para_lista_estatica(ListaEstatica *lista, Aluno vetor[], int n);

#endif
