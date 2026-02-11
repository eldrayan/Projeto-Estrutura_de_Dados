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
    } else {
        (lista->fim)->prox = novo_no;
    }
    lista->fim = novo_no;
    
    lista->quantidade++;
}

int busca_elemento(Lista *lista, int id_alvo) {
    No *atual = lista->inicio;
    int contador = 0;

    while (atual != NULL && atual->id != id_alvo) {
        atual = atual->prox;
        contador++;
    }
    return (atual == NULL) ? -1 : contador;
}

void remove_elemento(Lista *lista, int id_alvo) {
    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->id != id_alvo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Elemento nao encontrado!\n");
        return;
    }

    printf("Elemento encontrado\n");

    // Quando é o primeiro elemento da lista
    if (anterior == NULL) {
        
        // Se a lista tiver apenas um elemento
        if (lista->inicio == lista->fim) {
            lista->fim = atual->prox;
        }

        // Se a lista tiver mais de um elemento
        lista->inicio = atual->prox;
    } else { // Quando não é o primeiro da lista
        
        // Se for o último da lista
        if (atual->prox == NULL) {
            lista->fim = anterior;
        }
        anterior->prox = atual->prox;

    }
    free(atual);
    lista->quantidade--;
    
}

void imprimir_lista(Lista *lista) {
    if (lista->quantidade == 0) {
        printf("Lista vazia.\n");
    }
    
    No *no_aux = lista->inicio;
    while (no_aux != NULL) {
        printf("ID: %d | Nota: %.2f\n", no_aux->id, no_aux->nota);
        no_aux = no_aux->prox;
    }
}

void libera_lista(Lista *lista) {
    No *atual = lista->inicio;
    No *no_aux = NULL;

    while (atual != NULL) {
        no_aux = atual->prox;
        free(atual);
        atual = no_aux;
    }

    free(lista);
}