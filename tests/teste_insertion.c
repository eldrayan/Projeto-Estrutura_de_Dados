#include <stdio.h>
#include "lista_dinamica.h"
#include "estatica.h"
#include "testes_manuais.h"
#include "insertion.h"

void testes_insertion_dinamica() {
    // Fluxo para testar implementações
    ListaDinamica *lista_dinamica = lista_dinamica_inicializa();
    
    printf("\n<<< TESTE - INSERTION SORT - LISTA DINAMICA >>>\n");
    
    // Inserção de elementos com dados desordenados
    lista_dinamica_insere(lista_dinamica, 1, 8.5);
    lista_dinamica_insere(lista_dinamica, 2, 4.0);
    lista_dinamica_insere(lista_dinamica, 3, 7.5);
    lista_dinamica_insere(lista_dinamica, 4, 10.0);
    lista_dinamica_insere(lista_dinamica, 5, 3.7);
    lista_dinamica_insere(lista_dinamica, 6, 5.8);
    lista_dinamica_insere(lista_dinamica, 7, 6.2);
    lista_dinamica_insere(lista_dinamica, 8, 9.5);
    
    printf("--- CASO 1: Teste com Lista Dinamica Desordenada ---\n");
    printf("   Antes:  ");
    lista_dinamica_imprimir(lista_dinamica);
    printf("\n");
    insertion_sort_dinamica(lista_dinamica);
    printf("   Depois: ");
    lista_dinamica_imprimir(lista_dinamica);
    
    
    printf("\n\n--- CASO 2: Teste com Lista Dinamica Ordenada ---\n");
    printf("   Antes:  ");
    lista_dinamica_imprimir(lista_dinamica);
    printf("\n");
    insertion_sort_dinamica(lista_dinamica);
    printf("   Depois: ");
    lista_dinamica_imprimir(lista_dinamica);
    
    for (size_t i = 1; i <= 8; i++) {
        lista_dinamica_remove(lista_dinamica, i);
    }
    
    lista_dinamica_insere(lista_dinamica, 1, 10.0);
    lista_dinamica_insere(lista_dinamica, 2, 9.5);
    lista_dinamica_insere(lista_dinamica, 3, 8.5);
    lista_dinamica_insere(lista_dinamica, 4, 7.5);
    lista_dinamica_insere(lista_dinamica, 5, 6.2);
    lista_dinamica_insere(lista_dinamica, 6, 5.8);
    lista_dinamica_insere(lista_dinamica, 7, 4.0);
    lista_dinamica_insere(lista_dinamica, 8, 3.7);
    
    printf("\n\n--- CASO 3: Teste com Lista Dinamica Inversamente Ordenada ---\n");
    printf("   Antes:  ");
    lista_dinamica_imprimir(lista_dinamica);
    printf("\n");
    insertion_sort_dinamica(lista_dinamica);
    printf("   Depois: ");
    lista_dinamica_imprimir(lista_dinamica);
    
    lista_dinamica_libera(lista_dinamica);
}

void testes_insertion_estatica() {
    ListaEstatica lista_estatica;
    lista_estatica_inicializa(&lista_estatica);
    
    printf("\n<<< TESTE - INSERTION SORT - LISTA ESTATICA >>>\n");
    
    lista_estatica_insere(&lista_estatica, 1, 9.7);
    lista_estatica_insere(&lista_estatica, 2, 8.8);
    lista_estatica_insere(&lista_estatica, 3, 5.2);
    lista_estatica_insere(&lista_estatica, 4, 4.8);
    lista_estatica_insere(&lista_estatica, 5, 5.8);
    lista_estatica_insere(&lista_estatica, 6, 3.6);
    lista_estatica_insere(&lista_estatica, 7, 7.0);
    lista_estatica_insere(&lista_estatica, 8, 6.5);
    
    printf("--- CASO 1: Teste com Lista Estatica Desordenada ---\n");
    printf("   Antes:  ");
    lista_estatica_imprime(&lista_estatica);
    printf("\n");
    insertion_sort_estatica(&lista_estatica);
    printf("   Depois: ");
    lista_estatica_imprime(&lista_estatica);
    
    printf("\n\n--- CASO 2: Teste com Lista Estatica Ordenada ---\n");
    printf("   Antes:  ");
    lista_estatica_imprime(&lista_estatica);
    printf("\n");
    insertion_sort_estatica(&lista_estatica);
    printf("   Depois: ");
    lista_estatica_imprime(&lista_estatica);
    
    for (size_t i = 1; i <= 8; i++) {
        lista_estatica_remove(&lista_estatica, i);
    }
    
    lista_estatica_insere(&lista_estatica, 1, 9.7);
    lista_estatica_insere(&lista_estatica, 2, 8.8);
    lista_estatica_insere(&lista_estatica, 3, 7.0);
    lista_estatica_insere(&lista_estatica, 4, 6.5);
    lista_estatica_insere(&lista_estatica, 5, 5.8);
    lista_estatica_insere(&lista_estatica, 6, 5.2);
    lista_estatica_insere(&lista_estatica, 7, 4.8);
    lista_estatica_insere(&lista_estatica, 8, 3.6);
    
    printf("\n\n--- CASO 3: Teste com Lista Estatica Inversamente Ordenada ---\n");
    printf("   Antes:  ");
    lista_estatica_imprime(&lista_estatica);
    printf("\n");
    insertion_sort_estatica(&lista_estatica);
    printf("   Depois: ");
    lista_estatica_imprime(&lista_estatica);
}

void executar_teste_insertion_sort() {
    testes_insertion_dinamica();
    printf("\n-----------------------------------------\n");
    testes_insertion_estatica();
    printf("\n=== TESTE FINALIZADO ===");
}
