#include "utils_merge.h"
#include "lista_dinamica.h"
#include "estatica.h"
#include <stdlib.h>

// ==================== FUNÇÕES DE CONVERSÃO - LISTA DINÂMICA ====================

/**
 * @brief Converte uma lista dinâmica em um vetor de alunos
 * Aloca memória para o vetor e copia os dados da lista
 * 
 * @param lista Lista dinâmica de origem
 * @param vetor Ponteiro para o array onde os dados serão copiados
 * @return int Quantidade de elementos convertidos
 */
int lista_dinamica_para_vetor(ListaDinamica *lista, Aluno **vetor) {
    if (lista == NULL || lista->quantidade == 0) {
        *vetor = NULL;
        return 0;
    }

    // Aloca memória para o vetor
    *vetor = (Aluno*)malloc(lista->quantidade * sizeof(Aluno));
    if (*vetor == NULL) {
        return 0;
    }

    // Copia dados da lista para o vetor
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
 * Remove elementos antigos da lista e insere novos elementos do vetor
 * 
 * @param vetor Array de alunos a serem inseridos
 * @param tamanho Quantidade de elementos no vetor
 * @param lista Lista dinâmica de destino
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

// ==================== FUNÇÕES DE CONVERSÃO - LISTA ESTÁTICA ====================

/**
 * @brief Converte uma lista estática em um vetor de alunos
 * Aloca memória para o vetor e copia os dados da lista
 * 
 * @param lista Lista estática de origem
 * @param vetor Ponteiro para o array onde os dados serão copiados
 * @return int Quantidade de elementos convertidos
 */
int lista_estatica_para_vetor(ListaEstatica *lista, Aluno **vetor) {
    if (lista == NULL || lista->quantidade == 0) {
        *vetor = NULL;
        return 0;
    }

    // Aloca memória para o vetor
    *vetor = (Aluno*)malloc(lista->quantidade * sizeof(Aluno));
    if (*vetor == NULL) {
        return 0;
    }

    // Copia dados da lista para o vetor
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
 * Reinicializa a lista e insere elementos do vetor
 * 
 * @param vetor Array de alunos a serem inseridos
 * @param tamanho Quantidade de elementos no vetor
 * @param lista Lista estática de destino
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
