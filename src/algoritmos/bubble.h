#ifndef BUBBLE_H
#define BUBBLE_H

typedef struct {
    int id;
    float nota;
} Aluno;

// ordena vetor de alunos por nota (crescente)
void bubble_sort(Aluno v[], int n);

#endif
