#include "merge.h"
#include "lista_dinamica.h"
#include "estatica.h"
#include <stddef.h>
#include <stdlib.h>

//Lista Dinâmica

/**
 * Divide a lista encadeada em duas metades
 * Usa two-pointers (slow e fast) para encontrar o meio
 */
static void split_dinamica(NoDinamico *inicio, NoDinamico **esq, NoDinamico **dir) {
    NoDinamico *slow = inicio;
    NoDinamico *fast = inicio->prox;

    while (fast != NULL && fast->prox != NULL) {
        slow = slow->prox;
        fast = fast->prox->prox;
    }

    *esq = inicio;
    *dir = slow->prox;
    slow->prox = NULL;  // Quebra a ligação
    if (*dir != NULL) {
        (*dir)->ant = NULL;
    }
}

/**
 * Mescla duas listas dinâmicas ordenadas
 * Reutiliza nós existentes sem alocar novos
 */
static NoDinamico* merge_dinamica(NoDinamico *esq, NoDinamico *dir) {
    if (esq == NULL) return dir;
    if (dir == NULL) return esq;

    NoDinamico *resultado = NULL;
    NoDinamico *cauda = NULL;

    while (esq != NULL && dir != NULL) {
        NoDinamico *proximo;

        if (esq->nota <= dir->nota) {
            proximo = esq;
            esq = esq->prox;
        } else {
            proximo = dir;
            dir = dir->prox;
        }

        proximo->prox = NULL;
        proximo->ant = cauda;

        if (cauda == NULL) {
            resultado = proximo;
        } else {
            cauda->prox = proximo;
        }
        cauda = proximo;
    }

    if (esq != NULL) {
        esq->ant = cauda;
        cauda->prox = esq;
    } else if (dir != NULL) {
        dir->ant = cauda;
        cauda->prox = dir;
    }

    return resultado;
}

/**
 * Merge Sort recursivo para lista dinâmica
 */
static NoDinamico* merge_sort_recursivo(NoDinamico *inicio) {
    if (inicio == NULL || inicio->prox == NULL) {
        return inicio;
    }

    NoDinamico *esq, *dir;
    split_dinamica(inicio, &esq, &dir);

    esq = merge_sort_recursivo(esq);
    dir = merge_sort_recursivo(dir);

    return merge_dinamica(esq, dir);
}

/**
 * Merge Sort para lista dinâmica
 * Ordena os elementos pelo campo 'nota' em ordem crescente
 */
void merge_sort_dinamica(ListaDinamica *lista) {
    if (lista == NULL || lista->inicio == NULL || lista->quantidade <= 1) {
        return;
    }

    lista->inicio = merge_sort_recursivo(lista->inicio);

    // Encontra o fim da lista
    NoDinamico *atual = lista->inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    lista->fim = atual;
}


// Lista Estática

/**
 * Mescla dois subarrays de índices ordenados
 * Coloca o resultado em um array auxiliar
 */
static void merge_estatica(ListaEstatica *l, int *arr, int esq, int meio, int dir, int *aux) {
    int i = esq;
    int j = meio + 1;
    int k = esq;

    while (i <= meio && j <= dir) {
        if (l->dados[arr[i]].nota <= l->dados[arr[j]].nota) {
            aux[k++] = arr[i++];
        } else {
            aux[k++] = arr[j++];
        }
    }

    while (i <= meio) {
        aux[k++] = arr[i++];
    }

    while (j <= dir) {
        aux[k++] = arr[j++];
    }

    for (i = esq; i <= dir; i++) {
        arr[i] = aux[i];
    }
}

/**
 * Merge Sort recursivo com array auxiliar para lista estática
 */
static void merge_sort_auxiliar(ListaEstatica *l, int *arr, int esq, int dir, int *aux) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;

        merge_sort_auxiliar(l, arr, esq, meio, aux);
        merge_sort_auxiliar(l, arr, meio + 1, dir, aux);
        merge_estatica(l, arr, esq, meio, dir, aux);
    }
}

/**
 * Merge Sort para lista estática
 * Ordena os elementos pelo campo 'nota' em ordem crescente
 * Mantém a integridade da estrutura estática (ponteiros prox/ant)
 */
void merge_sort_estatica(ListaEstatica *lista) {
    if (lista == NULL || lista->quantidade <= 1) {
        return;
    }

    // Cria array com os índices dos elementos válidos
    int *indices = (int*)malloc(lista->quantidade * sizeof(int));
    int *aux = (int*)malloc(lista->quantidade * sizeof(int));

    // Coleta os índices partindo do início da lista
    int indice = 0;
    int pos = lista->inicio;

    while (pos != -1 && indice < lista->quantidade) {
        indices[indice++] = pos;
        pos = lista->dados[pos].prox;
    }

    // Ordena o array de índices
    merge_sort_auxiliar(lista, indices, 0, lista->quantidade - 1, aux);

    // Reconstrói os ponteiros da lista com a nova ordem
    if (lista->quantidade > 0) {
        lista->inicio = indices[0];

        for (int i = 0; i < lista->quantidade - 1; i++) {
            lista->dados[indices[i]].prox = indices[i + 1];
            lista->dados[indices[i + 1]].ant = indices[i];
        }

        lista->dados[indices[lista->quantidade - 1]].prox = -1;
        lista->dados[indices[0]].ant = -1;
    }

    free(indices);
    free(aux);
}