#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

Lista* inicializa_lista(void) {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;

    return lista;
}

void insere_elemento(Lista *lista, int id, float nota) {
    No *novo_no = (No*)malloc(sizeof(No));
    novo_no->id = id;
    novo_no->nota = nota;
    novo_no->prox = NULL;

    if (lista->quantidade == 0) {
        lista->inicio = novo_no;
        lista->fim = novo_no;
    } else {
        (lista->fim)->prox = novo_no;
        lista->fim = novo_no;
    }

    lista->quantidade++;
}

void imprimir_lista(Lista *lista) {
    No *no_aux = lista->inicio;
    while (no_aux != NULL) {
        printf("ID: %d | Nota: %.2f\n", no_aux->id, no_aux->nota);
        no_aux = no_aux->prox;
    }
}