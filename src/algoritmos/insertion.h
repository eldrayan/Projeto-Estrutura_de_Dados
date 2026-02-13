#ifndef INSERTION_H
#define INSERTION_H

typedef struct {
    int id;
    float nota;
} Aluno;

// ordena vetor de alunos por nota (crescente)
void insertion_sort(Aluno v[], int n);

#endif
