#include <stdio.h>
#include "lista_dinamica.h"

int main() {

    // Fluxo para testar implementações
    ListaDinamica *lista = inicializa_lista();

    printf("--- Teste de Insercao ---\n");
    insere_elemento(lista, 1, 8.5);
    insere_elemento(lista, 2, 9.0);
    insere_elemento(lista, 3, 7.5);
    insere_elemento(lista, 4, 10.0);
    imprimir_lista(lista);
    
    printf("\n--- Teste de Busca ---\n");
    int idx = busca_elemento(lista, 3);
    printf("Busca ID 3: Posicao %d\n", idx);
    printf("Busca ID 99: Posicao %d\n", busca_elemento(lista, 99));
    
    printf("\n--- Teste de Remocao (Meio: ID 2) ---\n");
    remove_elemento(lista, 2);
    imprimir_lista(lista);
    
    printf("\n--- Teste de Remocao (Inicio: ID 1) ---\n");
    remove_elemento(lista, 1);
    imprimir_lista(lista);
    
    printf("\n--- Teste de Remocao (Fim: ID 4) ---\n");
    remove_elemento(lista, 4);
    imprimir_lista(lista);
    
    printf("\n--- Teste de Remocao (Unico: ID 3) ---\n");
    remove_elemento(lista, 3);
    imprimir_lista(lista);

    libera_lista(lista);
    return 0;
}