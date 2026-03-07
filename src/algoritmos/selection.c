#include "selection.h"
#include "lista_dinamica.h"
#include "estatica.h"
#include <stddef.h>

// Selection Sort = ordena as notas dos alunos de maneira crescente

// Selection Sort para vetor
void selection_sort(Aluno v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        
        // Encontra o índice do elemento menor
        for (int j = i + 1; j < n; j++) {
            if (v[j].nota < v[menor].nota) {
                menor = j;
            }
        }
        
        // Troca o elemento atual com o menor encontrado
        if (menor != i) {
            Aluno temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
        }
    }
}

void selection_sort_dinamica(ListaDinamica *lista) {
    if (lista->inicio == NULL || lista->quantidade == 1) return;

    NoDinamico *atual, *busca, *menor;
    int aux_id;
    float aux_nota;

    atual = lista->inicio;

    while (atual->prox != NULL) {
        menor = atual;

        busca = atual->prox;

        while (busca != NULL) {
            if (busca->nota < menor->nota) {
                menor = busca;
            }
            busca = busca->prox;
        }

        if (menor != atual) {
            aux_id = atual->id;
            aux_nota = atual->nota;

            atual->id = menor->id;
            atual->nota = menor->nota;

            menor->id = aux_id;
            menor->nota = aux_nota;
        }

        atual = atual->prox;
    }
}

void selection_sort_estatica(ListaEstatica *lista) {
    if (lista->inicio == -1 || lista->quantidade == 1) return;

    int atual, busca, menor, aux_id;
    float aux_nota;
    atual = lista->inicio;

    while (lista->dados[atual].prox != -1) {
        menor = atual;
        busca = lista->dados[atual].prox;

        while (busca != -1) {
            if (lista->dados[busca].nota < lista->dados[menor].nota) {
                menor = busca;
            }
            busca = lista->dados[busca].prox;
        }

        if (menor != atual) {
            aux_id = lista->dados[atual].id;
            aux_nota = lista->dados[atual].nota;

            lista->dados[atual].id = lista->dados[menor].id;
            lista->dados[atual].nota = lista->dados[menor].nota;

            lista->dados[menor].id = aux_id;
            lista->dados[menor].nota = aux_nota;
        }

        atual = lista->dados[atual].prox;
    }
}