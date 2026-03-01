#include "quick.h"
#include <stddef.h>
#include "lista_dinamica.h"
#include "estatica.h"

/* ===================================================== */
/* FUNÇÕES AUXILIARES - VETOR                           */
/* ===================================================== */

static void trocar(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

static int particionar(Aluno v[], int inicio, int fim) {

    float pivo = v[fim].nota;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j].nota <= pivo) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }

    trocar(&v[i + 1], &v[fim]);
    return i + 1;
}

static void quick_rec(Aluno v[], int inicio, int fim) {

    while (inicio < fim) {

        int pivo = particionar(v, inicio, fim);

        int tam_esq = pivo - inicio;
        int tam_dir = fim - pivo;

        /* recursa sempre no menor lado */
        if (tam_esq < tam_dir) {

            quick_rec(v, inicio, pivo - 1);
            inicio = pivo + 1;

        } else {

            quick_rec(v, pivo + 1, fim);
            fim = pivo - 1;
        }
    }
}


/* ===================================================== */
/* QUICK SORT - VETOR                 */
/* ===================================================== */

void quick_sort(Aluno v[], int n) {

    if (n < 2)
        return;

    quick_rec(v, 0, n - 1);
}


/* ===================================================== */
/* FUNÇÕES AUXILIARES - LISTA DINÂMICA                  */
/* ===================================================== */

static void trocar_dados_dinamico(NoDinamico *a, NoDinamico *b) {

    int temp_id = a->id;
    float temp_nota = a->nota;

    a->id = b->id;
    a->nota = b->nota;

    b->id = temp_id;
    b->nota = temp_nota;
}

static NoDinamico* particao_dinamica(NoDinamico *inicio, NoDinamico *fim) {

    float pivo = fim->nota;
    NoDinamico *i = inicio->ant;

    for (NoDinamico *j = inicio; j != fim; j = j->prox) {

        if (j->nota <= pivo) {

            i = (i == NULL) ? inicio : i->prox;
            trocar_dados_dinamico(i, j);
        }
    }

    i = (i == NULL) ? inicio : i->prox;
    trocar_dados_dinamico(i, fim);

    return i;
}

static int tamanho_intervalo(NoDinamico *inicio, NoDinamico *fim) {

    int tam = 0;

    while (inicio != NULL) {
        tam++;
        if (inicio == fim)
            break;
        inicio = inicio->prox;
    }

    return tam;
}

static void quick_rec_dinamica(NoDinamico *inicio, NoDinamico *fim) {

    while (fim != NULL && inicio != fim && inicio != fim->prox) {

        NoDinamico *pivo = particao_dinamica(inicio, fim);

        int tam_esq = 0;
        int tam_dir = 0;

        if (pivo->ant != NULL)
            tam_esq = tamanho_intervalo(inicio, pivo->ant);

        if (pivo->prox != NULL)
            tam_dir = tamanho_intervalo(pivo->prox, fim);

        if (tam_esq < tam_dir) {

            if (pivo->ant != NULL)
                quick_rec_dinamica(inicio, pivo->ant);

            inicio = pivo->prox;

        } else {

            if (pivo->prox != NULL)
                quick_rec_dinamica(pivo->prox, fim);

            fim = pivo->ant;
        }
    }
}


/* ===================================================== */
/* QUICK SORT - LISTA DINÂMICA          */
/* ===================================================== */

void quick_sort_dinamica(ListaDinamica *l) {

    if (l == NULL || l->quantidade < 2)
        return;

    quick_rec_dinamica(l->inicio, l->fim);
}


/* ===================================================== */
/* FUNÇÕES AUXILIARES - LISTA ESTÁTICA                  */
/* ===================================================== */

static void trocar_dados_estatica(ListaEstatica *l, int a, int b) {

    int temp_id = l->dados[a].id;
    float temp_nota = l->dados[a].nota;

    l->dados[a].id = l->dados[b].id;
    l->dados[a].nota = l->dados[b].nota;

    l->dados[b].id = temp_id;
    l->dados[b].nota = temp_nota;
}

static int particao_estatica(ListaEstatica *l, int inicio, int fim) {

    float pivo = l->dados[fim].nota;
    int i = -1;
    int atual = inicio;

    while (atual != fim) {

        if (l->dados[atual].nota <= pivo) {

            i = (i == -1) ? inicio : l->dados[i].prox;
            trocar_dados_estatica(l, i, atual);
        }

        atual = l->dados[atual].prox;
    }

    i = (i == -1) ? inicio : l->dados[i].prox;
    trocar_dados_estatica(l, i, fim);

    return i;
}

static int tamanho_intervalo_estatica(ListaEstatica *l, int inicio, int fim) {

    int tam = 0;

    while (inicio != -1) {
        tam++;
        if (inicio == fim)
            break;
        inicio = l->dados[inicio].prox;
    }

    return tam;
}

static void quick_rec_estatica(ListaEstatica *l, int inicio, int fim) {

    while (inicio != -1 && fim != -1 && inicio != fim) {

        int pivo = particao_estatica(l, inicio, fim);

        int tam_esq = 0;
        int tam_dir = 0;

        if (l->dados[pivo].ant != -1)
            tam_esq = tamanho_intervalo_estatica(l, inicio, l->dados[pivo].ant);

        if (l->dados[pivo].prox != -1)
            tam_dir = tamanho_intervalo_estatica(l, l->dados[pivo].prox, fim);

        if (tam_esq < tam_dir) {

            if (l->dados[pivo].ant != -1)
                quick_rec_estatica(l, inicio, l->dados[pivo].ant);

            inicio = l->dados[pivo].prox;

        } else {

            if (l->dados[pivo].prox != -1)
                quick_rec_estatica(l, l->dados[pivo].prox, fim);

            fim = l->dados[pivo].ant;
        }
    }
}


/* ===================================================== */
/* QUICK SORT - LISTA ESTÁTIC           */
/* ===================================================== */

void quick_sort_estatica(ListaEstatica *l) {

    if (l == NULL || l->quantidade < 2)
        return;

    int fim = l->inicio;

    while (l->dados[fim].prox != -1)
        fim = l->dados[fim].prox;

    quick_rec_estatica(l, l->inicio, fim);
}