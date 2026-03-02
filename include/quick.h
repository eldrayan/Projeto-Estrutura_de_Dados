#ifndef QUICK_H
#define QUICK_H

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

// ordena vetor de alunos por nota (crescente)
void quick_sort(Aluno v[], int n);

// ordena lista dinâmica por nota (crescente) - troca apenas dados
void quick_sort_dinamica(ListaDinamica *l);

// ordena lista estática por nota (crescente) - troca apenas dados
void quick_sort_estatica(ListaEstatica *l);

#endif