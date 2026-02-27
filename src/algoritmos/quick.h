#ifndef QUICK_H
#define QUICK_H

typedef struct {
    int id;
    float nota;
} Aluno;

// ordena vetor de alunos por nota (crescente)
void quick_sort(Aluno v[], int n);

#endif