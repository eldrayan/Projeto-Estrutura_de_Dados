#include "merge.h"
#include "utils_merge.h"
#include "lista_dinamica.h"
#include "estatica.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// ==================== FUNÇÕES DE CONVERSÃO ====================

/**
 * @brief Converte uma lista dinâmica em um vetor de alunos
 * Aloca memória para o vetor e copia os dados
 */
int lista_dinamica_para_vetor(ListaDinamica *lista, Aluno **vetor) {
    if (lista == NULL || lista->quantidade == 0) {
        *vetor = NULL;
        return 0;
    }

    *vetor = (Aluno*)malloc(lista->quantidade * sizeof(Aluno));
    if (*vetor == NULL) {
        return 0;
    }

    NoDinamico *atual = lista->inicio;
    int i = 0;

    while (atual != NULL && i < lista->quantidade) {
        (*vetor)[i].id = atual->id;
        (*vetor)[i].nota = atual->nota;
        atual = atual->prox;
        i++;
    }

    return lista->quantidade;
}

/**
 * @brief Converte um vetor de alunos de volta para uma lista dinâmica
 * Remove elementos antigos e insere novos elementos do vetor
 */
void vetor_para_lista_dinamica(Aluno *vetor, int tamanho, ListaDinamica *lista) {
    if (lista == NULL || vetor == NULL) {
        return;
    }

    // Limpa a lista existente
    while (lista->inicio != NULL) {
        NoDinamico *temp = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(temp);
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;

    // Insere elementos do vetor
    for (int i = 0; i < tamanho; i++) {
        lista_dinamica_insere(lista, vetor[i].id, vetor[i].nota);
    }
}

/**
 * @brief Converte uma lista estática em um vetor de alunos
 * Aloca memória para o vetor e copia os dados
 */
int lista_estatica_para_vetor(ListaEstatica *lista, Aluno **vetor) {
    if (lista == NULL || lista->quantidade == 0) {
        *vetor = NULL;
        return 0;
    }

    *vetor = (Aluno*)malloc(lista->quantidade * sizeof(Aluno));
    if (*vetor == NULL) {
        return 0;
    }

    int pos = lista->inicio;
    int i = 0;

    while (pos != -1 && i < lista->quantidade) {
        (*vetor)[i].id = lista->dados[pos].id;
        (*vetor)[i].nota = lista->dados[pos].nota;
        pos = lista->dados[pos].prox;
        i++;
    }

    return lista->quantidade;
}

/**
 * @brief Converte um vetor de alunos de volta para uma lista estática
 * Reinsere elementos na lista mantendo a ordem do vetor
 */
void vetor_para_lista_estatica(Aluno *vetor, int tamanho, ListaEstatica *lista) {
    if (lista == NULL || vetor == NULL) {
        return;
    }

    // Reinicializa a lista
    lista_estatica_inicializa(lista);

    // Insere elementos do vetor
    for (int i = 0; i < tamanho; i++) {
        lista_estatica_insere(lista, vetor[i].id, vetor[i].nota);
    }
}

// ==================== MERGE SORT - VETOR ====================

/**
 * @brief Função de intercalação (merge) - Mescla dois subarrays ordenados
 * Combina dois subarrays [esq...meio] e [meio+1...dir] em ordem
 * Usa vetor auxiliar para armazenar resultados temporários
 */
static void merge(Aluno *arr, int esq, int meio, int dir, Aluno *temp) {
    int i = esq;          // Índice do primeiro subarray
    int j = meio + 1;     // Índice do segundo subarray
    int k = esq;          // Índice do array auxiliar

    // Mescla os dois subarrays em ordem crescente
    while (i <= meio && j <= dir) {
        if (arr[i].nota <= arr[j].nota) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copia elementos restantes do primeiro subarray
    while (i <= meio) {
        temp[k++] = arr[i++];
    }

    // Copia elementos restantes do segundo subarray
    while (j <= dir) {
        temp[k++] = arr[j++];
    }

    // Copia elementos ordenados de volta para o array original
    for (i = esq; i <= dir; i++) {
        arr[i] = temp[i];
    }
}

/**
 * @brief Função recursiva de divisão (split) - Divide o vetor e ordena recursivamente
 * Implementa o padrão divide-and-conquer do merge sort
 */
static void merge_sort_recursivo(Aluno *arr, int esq, int dir, Aluno *temp) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;

        // Divide e ordena a primeira metade
        merge_sort_recursivo(arr, esq, meio, temp);

        // Divide e ordena a segunda metade
        merge_sort_recursivo(arr, meio + 1, dir, temp);

        // Mescla as duas metades
        merge(arr, esq, meio, dir, temp);
    }
}

// ==================== MERGE SORT - LISTA DINÂMICA ====================

/**
 * Merge Sort para lista dinâmica
 * Converte para vetor, ordena e reconverte para lista
 */
void merge_sort_dinamica(ListaDinamica *lista) {
    if (lista == NULL || lista->quantidade <= 1) {
        return;
    }

    // Converte lista para vetor
    Aluno *vetor = NULL;
    int tamanho = lista_dinamica_para_vetor(lista, &vetor);

    if (tamanho <= 1 || vetor == NULL) {
        free(vetor);
        return;
    }

    // Aloca vetor auxiliar para o merge
    Aluno *temp = (Aluno*)malloc(tamanho * sizeof(Aluno));
    if (temp == NULL) {
        free(vetor);
        return;
    }

    // Executa merge sort
    merge_sort_recursivo(vetor, 0, tamanho - 1, temp);

    // Reconverte para lista dinâmica
    vetor_para_lista_dinamica(vetor, tamanho, lista);

    // Libera memória auxiliar
    free(temp);
    free(vetor);
}

// ==================== MERGE SORT - LISTA ESTÁTICA ====================

/**
 * Merge Sort para lista estática
 * Converte para vetor, ordena e reconverte para lista
 */
void merge_sort_estatica(ListaEstatica *lista) {
    if (lista == NULL || lista->quantidade <= 1) {
        return;
    }

    // Converte lista para vetor
    Aluno *vetor = NULL;
    int tamanho = lista_estatica_para_vetor(lista, &vetor);

    if (tamanho <= 1 || vetor == NULL) {
        free(vetor);
        return;
    }

    // Aloca vetor auxiliar para o merge
    Aluno *temp = (Aluno*)malloc(tamanho * sizeof(Aluno));
    if (temp == NULL) {
        free(vetor);
        return;
    }

    // Executa merge sort
    merge_sort_recursivo(vetor, 0, tamanho - 1, temp);

    // Reconverte para lista estática
    vetor_para_lista_estatica(vetor, tamanho, lista);

    // Libera memória auxiliar
    free(temp);
    free(vetor);
}