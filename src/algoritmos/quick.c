#include "quick.h"

// função para trocar dois alunos
static void trocar(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

// função de partição
static int particionar(Aluno v[], int inicio, int fim) {
    float pivo = v[fim].nota;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j].nota <= pivo) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }

    trocar(&v[i + 1], &v[fim]);
    return i + 1;
}

// quicksort recursivo
static void quick_sort_rec(Aluno v[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(v, inicio, fim);
        quick_sort_rec(v, inicio, pivo - 1);
        quick_sort_rec(v, pivo + 1, fim);
    }
}

// função principal (mesmo padrão do insertion_sort)
void quick_sort(Aluno v[], int n) {
    quick_sort_rec(v, 0, n - 1);
}