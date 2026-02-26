#ifndef INSERTION_H
#define INSERTION_H

// Define Aluno aqui (somente se ainda não tiver sido definido)
#ifndef ALUNO_TYPE_DEFINED
#define ALUNO_TYPE_DEFINED
typedef struct {
    int id;
    float nota;
} Aluno;
#endif

// Forward declarations para evitar include circular
typedef struct ListaDinamica ListaDinamica;
typedef struct ListaEstatica ListaEstatica;

// 1) Insertion Sort em vetor (ordena por nota crescente)
void insertion_sort(Aluno v[], int n);

// 2) Insertion Sort na lista dinâmica (in-place, por nota crescente)
void lista_dinamica_insertion_sort(ListaDinamica *lista);

// 3) Insertion Sort na lista estática (in-place, por nota crescente)
void lista_estatica_insertion_sort(ListaEstatica *l);

#endif