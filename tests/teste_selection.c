#include <stdio.h>
#include "lista_dinamica.h"
#include "testes_manuais.h"
#include "selection.h"

void executar_testes_selection_sort() {
    // Fluxo para testar implementações
    ListaDinamica *lista_dinamica = lista_dinamica_inicializa();
    
    printf("\n<<< TESTE - SELECTION SORT - LISTA DINAMICA >>>\n");
    
    // Inserção de elementos com dados desordenados
    lista_dinamica_insere(lista_dinamica, 1, 8.5);
    lista_dinamica_insere(lista_dinamica, 2, 4.0);
    lista_dinamica_insere(lista_dinamica, 3, 7.5);
    lista_dinamica_insere(lista_dinamica, 4, 10.0);
    lista_dinamica_insere(lista_dinamica, 5, 3.7);
    lista_dinamica_insere(lista_dinamica, 6, 5.8);
    lista_dinamica_insere(lista_dinamica, 7, 6.2);
    lista_dinamica_insere(lista_dinamica, 8, 9.5);
    
    printf("--- CASO 1: Teste com Lista Desordenada ---\n");
    printf("\t--- Antes:\n");
    lista_dinamica_imprimir(lista_dinamica);
    printf("\n");
    dinamica_selection_sort(lista_dinamica);
    printf("\t--- Depois:\n");
    lista_dinamica_imprimir(lista_dinamica);
    
    
    printf("\n\n--- CASO 2: Teste com Lista Ordenada ---\n");
    printf("\t--- Antes:\n");
    lista_dinamica_imprimir(lista_dinamica);
    printf("\n");
    dinamica_selection_sort(lista_dinamica);
    printf("\t--- Depois:\n");
    lista_dinamica_imprimir(lista_dinamica);
    
    for (size_t i = 1; i <= 8; i++) {
        lista_dinamica_remove(lista_dinamica, i);
    }
    
    // ListaDinamica *lista_dinamica = lista_dinamica_inicializa();
    lista_dinamica_insere(lista_dinamica, 1, 10.0);
    lista_dinamica_insere(lista_dinamica, 2, 9.5);
    lista_dinamica_insere(lista_dinamica, 3, 8.5);
    lista_dinamica_insere(lista_dinamica, 4, 7.5);
    lista_dinamica_insere(lista_dinamica, 5, 6.2);
    lista_dinamica_insere(lista_dinamica, 6, 5.8);
    lista_dinamica_insere(lista_dinamica, 7, 4.0);
    lista_dinamica_insere(lista_dinamica, 8, 3.7);
    
    printf("\n\n--- CASO 3: Teste com Lista Inversamente Ordenada ---\n");
    printf("\t--- Antes:\n");
    lista_dinamica_imprimir(lista_dinamica);
    printf("\n");
    dinamica_selection_sort(lista_dinamica);
    printf("\t--- Depois:\n");
    lista_dinamica_imprimir(lista_dinamica);
    
    lista_dinamica_libera(lista_dinamica);
}