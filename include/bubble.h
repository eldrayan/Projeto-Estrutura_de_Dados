#ifndef BUBBLE_H
#define BUBBLE_H

#include "lista_dinamica.h"
#include "estatica.h"

typedef struct {
    int id;
    float nota;
} Aluno;

// ordena vetor de alunos por nota (crescente)
void bubble_sort(Aluno v[], int n);

// ordena lista dinâmica por nota (crescente) - troca apenas dados, não ponteiros
void bubble_sort_dinamica(ListaDinamica *l);

// ordena lista estática por nota (crescente) - troca apenas dados, não índices
void bubble_sort_estatica(ListaEstatica *l);

#endif
