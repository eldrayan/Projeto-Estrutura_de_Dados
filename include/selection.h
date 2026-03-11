#ifndef SELECTION_H
#define SELECTION_H

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

// Selection Sort para vetor - ordena as notas dos alunos de maneira crescente
void selection_sort(Aluno v[], int n);

// Selection Sort para lista dinâmica
void selection_sort_dinamica(ListaDinamica *lista);

// Selection Sort para lista estática
void selection_sort_estatica(ListaEstatica *lista);

#endif