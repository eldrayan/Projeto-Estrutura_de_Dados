#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"
#include "estatica.h"
#include "merge.h"

/**
 * Teste do Merge Sort para Lista Dinâmica
 */
void teste_merge_sort_dinamica() {
    printf("\n===== TESTE MERGE SORT - LISTA DINÂMICA =====\n");
    
    ListaDinamica *lista = lista_dinamica_inicializa();
    
    // Insere dados desordenados
    printf("Inserindo dados desordenados...\n");
    lista_dinamica_insere(lista, 1, 7.5);
    lista_dinamica_insere(lista, 2, 3.2);
    lista_dinamica_insere(lista, 3, 9.1);
    lista_dinamica_insere(lista, 4, 1.8);
    lista_dinamica_insere(lista, 5, 5.4);
    
    printf("\nAntes do Merge Sort:\n");
    lista_dinamica_imprimir(lista);
    
    // Executa Merge Sort
    merge_sort_dinamica(lista);
    
    printf("\nDepois do Merge Sort:\n");
    lista_dinamica_imprimir(lista);
    
    // Libera memória
    lista_dinamica_libera(lista);
    free(lista);
    
    printf("\n✓ Teste da lista dinâmica completado!\n");
}

/**
 * Teste do Merge Sort para Lista Estática
 */
void teste_merge_sort_estatica() {
    printf("\n===== TESTE MERGE SORT - LISTA ESTÁTICA =====\n");
    
    ListaEstatica lista;
    lista_estatica_inicializa(&lista);
    
    // Insere dados desordenados
    printf("Inserindo dados desordenados...\n");
    lista_estatica_insere(&lista, 1, 7.5);
    lista_estatica_insere(&lista, 2, 3.2);
    lista_estatica_insere(&lista, 3, 9.1);
    lista_estatica_insere(&lista, 4, 1.8);
    lista_estatica_insere(&lista, 5, 5.4);
    
    printf("\nAntes do Merge Sort:\n");
    lista_estatica_imprime(&lista);
    
    // Executa Merge Sort
    merge_sort_estatica(&lista);
    
    printf("\nDepois do Merge Sort:\n");
    lista_estatica_imprime(&lista);
    
    printf("\n✓ Teste da lista estática completado!\n");
}

/**
 * Executa todos os testes do Merge Sort
 */
void executar_testes_merge_sort() {
    printf("\n");
    printf("╔═══════════════════════════════════╗\n");
    printf("║   TESTES DO MERGE SORT            ║\n");
    printf("╚═══════════════════════════════════╝\n");
    
    teste_merge_sort_dinamica();
    teste_merge_sort_estatica();
    
    printf("\n");
    printf("╔═══════════════════════════════════╗\n");
    printf("║   TODOS OS TESTES COMPLETADOS!    ║\n");
    printf("╚═══════════════════════════════════╝\n");
}
