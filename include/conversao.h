#ifndef CONVERSAO_H
#define CONVERSAO_H

#include "lista_dinamica.h"
#include "estatica.h"
#include "algoritmos/insertion.h"
#include <stdlib.h>

/**
 * @brief Converte uma Lista Dinâmica para um vetor de Aluno.
 * 
 * @param lista Ponteiro para a lista dinâmica
 * @return Aluno* Vetor alocado dinamicamente com os elementos da lista
 */
Aluno* lista_dinamica_para_vetor(Lista *lista);

/**
 * @brief Converte uma Lista Estática para um vetor de Aluno.
 * 
 * @param lista Ponteiro para a lista estática
 * @return Aluno* Vetor alocado dinamicamente com os elementos da lista
 */
Aluno* lista_estatica_para_vetor(ListaEstatica *lista);

/**
 * @brief Converte um vetor de Aluno para uma Lista Dinâmica.
 * 
 * @param vetor Vetor de alunos
 * @param n Tamanho do vetor
 * @return Lista* Ponteiro para a nova lista dinâmica criada
 */
Lista* vetor_para_lista_dinamica(Aluno vetor[], int n);

/**
 * @brief Converte um vetor de Aluno para uma Lista Estática.
 * 
 * @param lista Ponteiro para a lista estática (deve estar inicializada)
 * @param vetor Vetor de alunos
 * @param n Tamanho do vetor
 * @return bool true se a conversão foi bem-sucedida, false caso contrário
 */
 bool vetor_para_lista_estatica(ListaEstatica *lista, Aluno vetor[], int n);

#endif

