#include "merge.h"
#include "merge_utils.h"
#include "lista_dinamica.h"
#include "estatica.h"
#include <stddef.h>
#include <stdlib.h>

// ==================== MERGE SORT - VETOR ====================

/**
 * @brief Função de intercalação (merge) - Mescla dois subarrays ordenados
 */
static void merge(Aluno *arr, int esq, int meio, int dir, Aluno *temp) {
    int i = esq;
    int j = meio + 1;
    int k = esq;

    while (i <= meio && j <= dir) {
        if (arr[i].nota <= arr[j].nota) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= meio) temp[k++] = arr[i++];
    while (j <= dir) temp[k++] = arr[j++];

    for (i = esq; i <= dir; i++) {
        arr[i] = temp[i];
    }
}

static void merge_sort_recursivo(Aluno *arr, int esq, int dir, Aluno *temp) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        merge_sort_recursivo(arr, esq, meio, temp);
        merge_sort_recursivo(arr, meio + 1, dir, temp);
        merge(arr, esq, meio, dir, temp);
    }
}

void merge_sort(Aluno *arr, int n) {
    if (arr == NULL || n <= 1) return;
    Aluno *temp = (Aluno*)malloc(n * sizeof(Aluno));
    if (temp == NULL) return;
    merge_sort_recursivo(arr, 0, n - 1, temp);
    free(temp);
}

// ==================== MERGE SORT - LISTA DINÂMICA ====================

/**
 * @brief Divide a lista dinâmica em duas metades
 */
static NoDinamico* split_dinamico(NoDinamico *head, int n) {
    NoDinamico *meio = head;
    for (int i = 0; i < (n / 2) - 1; i++) {
        meio = meio->prox;
    }
    NoDinamico *segunda_metade = meio->prox;
    meio->prox = NULL;
    if (segunda_metade) segunda_metade->ant = NULL;
    return segunda_metade;
}

/**
 * @brief Mescla duas sublistas dinâmicas ordenadas (Iterativo)
 */
static NoDinamico* merge_listas_dinamicas(NoDinamico *a, NoDinamico *b) {
    if (!a) return b;
    if (!b) return a;

    NoDinamico dummy;
    NoDinamico *cauda = &dummy;
    NoDinamico *anterior = NULL;

    while (a && b) {
        if (a->nota <= b->nota) {
            cauda->prox = a;
            a->ant = anterior;
            anterior = a;
            a = a->prox;
        } else {
            cauda->prox = b;
            b->ant = anterior;
            anterior = b;
            b = b->prox;
        }
        cauda = cauda->prox;
    }

    if (a) {
        cauda->prox = a;
        a->ant = anterior;
    } else {
        cauda->prox = b;
        b->ant = anterior;
    }

    // Garante que o primeiro nó real tenha ant = NULL
    if (dummy.prox) dummy.prox->ant = NULL;

    return dummy.prox;
}

/**
 * @brief Função recursiva para Merge Sort na lista dinâmica
 */
static NoDinamico* merge_sort_rec_dinamica(NoDinamico *head, int n) {
    if (!head || !head->prox) return head;

    int n1 = n / 2;
    int n2 = n - n1;

    NoDinamico *segunda = split_dinamico(head, n);

    head = merge_sort_rec_dinamica(head, n1);
    segunda = merge_sort_rec_dinamica(segunda, n2);

    return merge_listas_dinamicas(head, segunda);
}

void merge_sort_dinamica(ListaDinamica *lista) {
    if (lista == NULL || lista->quantidade <= 1) return;

    lista->inicio = merge_sort_rec_dinamica(lista->inicio, lista->quantidade);

    // Atualiza o ponteiro 'fim' percorrendo a lista (O(n))
    NoDinamico *atual = lista->inicio;
    while (atual && atual->prox) {
        atual = atual->prox;
    }
    lista->fim = atual;
}

// ==================== MERGE SORT - LISTA ESTÁTICA ====================

/**
 * @brief Divide a lista estática em duas metades
 */
static int split_estatico(ListaEstatica *l, int head, int n) {
    int meio = head;
    for (int i = 0; i < (n / 2) - 1; i++) {
        meio = l->dados[meio].prox;
    }
    int segunda_metade = l->dados[meio].prox;
    l->dados[meio].prox = -1;
    if (segunda_metade != -1) l->dados[segunda_metade].ant = -1;
    return segunda_metade;
}

/**
 * @brief Mescla duas sublistas estáticas ordenadas
 */
static int merge_listas_estaticas(ListaEstatica *l, int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;

    int inicio_resultado = -1;
    int cauda = -1;
    int anterior = -1;

    if (l->dados[a].nota <= l->dados[b].nota) {
        inicio_resultado = a;
        a = l->dados[a].prox;
    } else {
        inicio_resultado = b;
        b = l->dados[b].prox;
    }

    cauda = inicio_resultado;
    l->dados[cauda].ant = -1;
    anterior = cauda;

    while (a != -1 && b != -1) {
        if (l->dados[a].nota <= l->dados[b].nota) {
            l->dados[cauda].prox = a;
            l->dados[a].ant = anterior;
            a = l->dados[a].prox;
        } else {
            l->dados[cauda].prox = b;
            l->dados[b].ant = anterior;
            b = l->dados[b].prox;
        }
        cauda = l->dados[cauda].prox;
        anterior = cauda;
    }

    if (a != -1) {
        l->dados[cauda].prox = a;
        l->dados[a].ant = anterior;
    } else {
        l->dados[cauda].prox = b;
        l->dados[b].ant = anterior;
    }

    return inicio_resultado;
}

/**
 * @brief Função recursiva para Merge Sort na lista estática
 */
static int merge_sort_rec_estatica(ListaEstatica *l, int head, int n) {
    if (head == -1 || l->dados[head].prox == -1) return head;

    int n1 = n / 2;
    int n2 = n - n1;

    int segunda = split_estatico(l, head, n);

    head = merge_sort_rec_estatica(l, head, n1);
    segunda = merge_sort_rec_estatica(l, segunda, n2);

    return merge_listas_estaticas(l, head, segunda);
}

void merge_sort_estatica(ListaEstatica *lista) {
    if (lista == NULL || lista->quantidade <= 1) return;

    lista->inicio = merge_sort_rec_estatica(lista, lista->inicio, lista->quantidade);
}
