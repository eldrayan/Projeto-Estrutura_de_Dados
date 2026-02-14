#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"
#include "estatica.h"
#include "../src/algoritmos/insertion.h"

// ============ LISTA DINAMICA PARA VETOR ============

Aluno* lista_dinamica_para_vetor(Lista *lista) {
    // Validação: lista vazia ou nula
    if (lista == NULL || lista->quantidade == 0) {
        return NULL;
    }

    // Aloca vetor com o tamanho da lista
    Aluno *vetor = (Aluno *)malloc(lista->quantidade * sizeof(Aluno));
    if (vetor == NULL) {
        return NULL; // Falha na alocação
    }

    // Percorre a lista encadeada e copia para o vetor
    No *atual = lista->inicio;
    for (int i = 0; i < lista->quantidade && atual != NULL; i++) {
        vetor[i].id = atual->id;
        vetor[i].nota = atual->nota;
        atual = atual->prox;
    }

    return vetor;
}

// ============ VETOR PARA LISTA DINAMICA ============

Lista* vetor_para_lista_dinamica(Aluno vetor[], int n) {
    // Validação: vetor vazio ou nulo
    if (vetor == NULL || n <= 0) {
        return NULL;
    }

    // Inicializa a lista dinâmica
    Lista *lista = inicializa_lista();
    if (lista == NULL) {
        return NULL; // Falha na alocação
    }

    // Insere cada aluno do vetor na lista
    for (int i = 0; i < n; i++) {
        insere_elemento(lista, vetor[i].id, vetor[i].nota);
    }

    return lista;
}

// ============ LISTA ESTATICA PARA VETOR ============

Aluno* lista_estatica_para_vetor(ListaEstatica *lista) {
    // Validação: lista vazia ou nula
    if (lista == NULL || lista->quantidade == 0) {
        return NULL;
    }

    // Aloca vetor com o tamanho da lista
    Aluno *vetor = (Aluno *)malloc(lista->quantidade * sizeof(Aluno));
    if (vetor == NULL) {
        return NULL; // Falha na alocação
    }

    // Percorre a lista estática através dos índices e copia para o vetor
    int i = 0;
    int atual = lista->inicio;
    while (atual != -1 && i < lista->quantidade) {
        vetor[i].id = lista->dados[atual].id;
        vetor[i].nota = lista->dados[atual].nota;
        atual = lista->dados[atual].prox;
        i++;
    }

    return vetor;
}

// ============ VETOR PARA LISTA ESTATICA ============

bool vetor_para_lista_estatica(ListaEstatica *lista, Aluno vetor[], int n) {
    // Validação: parâmetros nulos ou inválidos
    if (lista == NULL || vetor == NULL || n <= 0) {
        return false;
    }

    // Validação: vetor maior que o limite da lista estática
    if (n > MAX) {
        return false;
    }

    // Inicializa a lista estática
    inicializa_lista(lista);

    // Insere cada aluno do vetor na lista estática
    for (int i = 0; i < n; i++) {
        if (!insere_elemento(lista, vetor[i].id, vetor[i].nota)) {
            return false; // Falha na inserção
        }
    }

    return true;
}
