#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

ListaDinamica* inicializa_lista(void) {
    ListaDinamica *lista = (ListaDinamica*)malloc(sizeof(ListaDinamica));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;

    return lista;
}

void insere_elemento(ListaDinamica *lista, int id, float nota) {
    No *novo_no = (No*)malloc(sizeof(No));
    novo_no->ant = NULL;
    novo_no->id = id;
    novo_no->nota = nota;
    novo_no->prox = NULL;

    if (lista->quantidade == 0) {
        lista->inicio = novo_no;
    } else {
        novo_no->ant = lista->fim;
        (lista->fim)->prox = novo_no;
    }
    lista->fim = novo_no;
    
    lista->quantidade++;
}

int busca_elemento(ListaDinamica *lista, int id_alvo) {
    No *atual = lista->inicio;
    int contador = 0;

    while (atual != NULL && atual->id != id_alvo) {
        atual = atual->prox;
        contador++;
    }
    return (atual == NULL) ? -1 : contador;
}

void remove_elemento(ListaDinamica *lista, int id_alvo) {
    No *atual = lista->inicio;

    // Busca do elemento
    while (atual != NULL && atual->id != id_alvo) {
        atual = atual->prox;

    }
    
    if (atual == NULL) {
        printf("Elemento nao encontrado!\n");
        return;
    }
    
    printf("Elemento encontrado\n");
    
    // Verifica se tem elemento à esquerda do atual
    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    } else {
        lista->inicio = atual->prox;
    }

    // Verifica se tem elemento à direita do atual
    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    } else {
        lista->fim = atual->ant;
    }
    free(atual);
    lista->quantidade--;
    
}

void imprimir_lista(ListaDinamica *lista) {
    if (lista->quantidade == 0) printf("Lista vazia.\n");
    printf("--- Imprimindo de INICIO para FIM ---\n");
    
    No *no_aux = lista->inicio;
    while (no_aux != NULL) {
        printf("ID: %d | Nota: %.2f\n", no_aux->id, no_aux->nota);
        no_aux = no_aux->prox;
    }
}

void imprimir_inverso(ListaDinamica *lista) {
    if (lista->quantidade == 0) printf("Lista vazia.\n");
    printf("--- Imprimindo de FIM para INICIO ---\n");
    
    No *no_aux = lista->fim;
    while (no_aux != NULL) {
        printf("ID: %d | Nota: %.2f\n", no_aux->id, no_aux->nota);
        no_aux = no_aux->ant;
    }
    
}

void libera_lista(ListaDinamica *lista) {
    No *atual = lista->inicio;
    No *no_aux = NULL;

    while (atual != NULL) {
        no_aux = atual->prox;
        free(atual);
        atual = no_aux;
    }

    free(lista);
}