#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"
#include "estatica.h"
#include "../algoritmos/insertion.h"

// LISTA DINAMICA PARA VETOR E VICE-VERSA

Aluno* lista_dinamica_para_vetor(Lista *lista) {
    if (lista == NULL || lista->quantidade == 0) {
        return NULL;
    }

    Aluno *vetor = (Aluno *)malloc(lista->quantidade * sizeof(Aluno));
    if (vetor == NULL) {
        return NULL; // Falha na alocação
    }

    No *atual = lista->inicio;
    for (int i = 0; i < lista->quantidade && atual != NULL; i++) {
        vetor[i].id = atual->id;
        vetor[i].nota = atual->nota;
        atual = atual->prox;
    }

    return vetor;
}

Lista* vetor_para_lista_dinamica(Aluno *vetor, int tamanho) {
    if (vetor == NULL || tamanho <= 0) {
        return NULL;
    }

    Lista *lista = inicializa_lista();
    if (lista == NULL) {
        return NULL; // Falha na alocação
    }

    for (int i = 0; i < tamanho; i++) {
        insere_elemento(lista, vetor[i].id, vetor[i].nota);
    }

    return lista;
}

// LISTA ESTATICA PARA VETOR E VICE-VERSA

Aluno* lista_estatica_para_vetor(ListaEstatica *lista) {
    if (lista == NULL || lista->quantidade == 0) {
        return NULL;
    }

    Aluno *vetor = (Aluno *)malloc(lista->quantidade * sizeof(Aluno));
    if (vetor == NULL) {
        return NULL; // Falha na alocação
    }

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

bool vetor_para_lista_estatica(ListaEstatica *lista, Aluno *vetor, int n) {
    if (lista == NULL || vetor == NULL || n <= 0) {
        return false;
    }

    inicializa_lista(lista);

    for (int i = 0; i < n; i++) {
        if (!insere_elemento(lista, vetor[i].id, vetor[i].nota)) {
            return false; // Falha na inserção
        }
    }

    return true;
}

