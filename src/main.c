#include "lista_dinamica.h"

int main() {

    // Fluxo para testar implementações
    Lista *lista = inicializa_lista();

    insere_elemento(lista, 1, 8.5);
    insere_elemento(lista, 2, 9.0);
    insere_elemento(lista, 3, 7.5);

    imprimir_lista(lista);
    return 0;
}