#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

/**
 * @brief Inicializa uma lista duplamente encadeada dinamica vazia.
 *
 * @return Ponteiro para a lista criada.
 */
ListaDinamica* lista_dinamica_inicializa(void) {
    ListaDinamica *lista = (ListaDinamica*)malloc(sizeof(ListaDinamica));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;

    return lista;
}

/**
 * @brief Insere um novo elemento no final da lista dinamica.
 *
 * @param lista Ponteiro para a lista.
 * @param id Identificador do registro.
 * @param nota Nota associada ao registro.
 */
void lista_dinamica_insere(ListaDinamica *lista, int id, float nota) {
    NoDinamico *novo_no = (NoDinamico*)malloc(sizeof(NoDinamico));
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

/**
 * @brief Busca um elemento pelo ID e retorna sua posicao logica.
 *
 * @param lista Ponteiro para a lista.
 * @param id_alvo ID a ser buscado.
 * @return Indice baseado em zero, ou -1 se nao encontrado.
 */
int lista_dinamica_busca(ListaDinamica *lista, int id_alvo) {
    NoDinamico *atual = lista->inicio;
    int contador = 0;

    while (atual != NULL && atual->id != id_alvo) {
        atual = atual->prox;
        contador++;
    }
    return (atual == NULL) ? -1 : contador;
}

/**
 * @brief Remove da lista o primeiro no com o ID informado.
 *
 * @param lista Ponteiro para a lista.
 * @param id_alvo ID a ser removido.
 */
void lista_dinamica_remove(ListaDinamica *lista, int id_alvo) {
    NoDinamico *atual = lista->inicio;

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

/**
 * @brief Imprime os elementos da lista do inicio para o fim.
 *
 * @param lista Ponteiro para a lista.
 */
void lista_dinamica_imprimir(ListaDinamica *lista) {
    (lista->quantidade == 0) ? printf("Lista vazia.\n") : printf("*** Imprimindo de INICIO para FIM ***\n");
    
    NoDinamico *no_aux = lista->inicio;
    while (no_aux != NULL) {
        printf("ID: %d | Nota: %.2f\n", no_aux->id, no_aux->nota);
        no_aux = no_aux->prox;
    }
}

/**
 * @brief Imprime os elementos da lista do fim para o inicio.
 *
 * @param lista Ponteiro para a lista.
 */
void lista_dinamica_imprimir_inverso(ListaDinamica *lista) {
    (lista->quantidade == 0) ? printf("Lista vazia.\n") : printf("*** Imprimindo de FIM para INICIO ***\n");
    
    NoDinamico *no_aux = lista->fim;
    while (no_aux != NULL) {
        printf("ID: %d | Nota: %.2f\n", no_aux->id, no_aux->nota);
        no_aux = no_aux->ant;
    }
    
}

/**
 * @brief Libera toda a memoria alocada pela lista dinamica.
 *
 * @param lista Ponteiro para a lista.
 */
void lista_dinamica_libera(ListaDinamica *lista) {
    NoDinamico *atual = lista->inicio;
    NoDinamico *no_aux = NULL;

    while (atual != NULL) {
        no_aux = atual->prox;
        free(atual);
        atual = no_aux;
    }

    free(lista);
}