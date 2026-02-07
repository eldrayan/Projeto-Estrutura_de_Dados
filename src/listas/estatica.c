#include <stdio.h>
#include "../../include/estatica.h" 

void inicializa_lista(ListaEstatica *l) {
    int i;
    l->inicio = -1;
    l->dispo = 0;
    for (i = 0; i < MAX - 1; i++) {
        l->dados[i].prox = i + 1;
    }
    l->dados[MAX - 1].prox = -1;
    l->quantidade = 0;
}

#TODO restante