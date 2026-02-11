#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

struct no {
    int id;
    float nota;
    struct no *prox;
};

typedef struct no No;

struct lista {
    No *inicio;
    No *fim;
    int quantidade;
};

typedef struct lista Lista;

Lista* inicializa_lista(void);
void insere_elemento(Lista *lista, int id, float nota);
void imprimir_lista(Lista *lista);

#endif