#include <stdlib.h>
#include "selection.h"
#include "lista_dinamica.h"
#include "estatica.h"

void dinamica_selection_sort(ListaDinamica* lista) {
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