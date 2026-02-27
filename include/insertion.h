#ifndef INSERTION_H
#define INSERTION_H

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

// 1) Insertion Sort em vetor (ordena por nota crescente)
void insertion_sort(Aluno v[], int n);

// 2) Insertion Sort na lista dinâmica (in-place, por nota crescente)
// Reconecta os ponteiros (->prox) para inserir o nó na posição correta
void insertion_sort_dinamica(ListaDinamica *lista);

// 3) Insertion Sort na lista estática (in-place, por nota crescente)
// Ajusta os índices .prox para simular a inserção na posição correta
void insertion_sort_estatica(ListaEstatica *l);

#endif
