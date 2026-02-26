#include <stdlib.h>
#include "selection.h"
#include "lista_dinamica.h"
#include "estatica.h"

void selection_sort_dinamica(ListaDinamica* lista) {
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

void selection_sort_estatica(ListaEstatica* lista) {
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