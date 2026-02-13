#include <stdio.h>
#include "lista_dinamica.h"
#include "../include/estatica.h"

int main() {
    ListaEstatica lista;
    
    printf("=== TESTE DA LISTA DUPLAMENTE ENCADEADA ESTATICA ===\n\n");
    
    // 1. Inicializa a lista
    printf("1. Inicializando a lista...\n");
    inicializa_lista(&lista);
    printf("   Lista inicializada!\n\n");
    
    // 2. Testa tamanho inicial (deve ser 0)
    printf("2. Tamanho inicial da lista: %d\n\n", tamanho_lista(&lista));
    
    // 3. Insere elementos
    printf("3. Inserindo elementos...\n");
    insere_elemento(&lista, 101, 8.5);
    printf("   Inserido: ID=101, Nota=8.5\n");
    
    insere_elemento(&lista, 102, 7.0);
    printf("   Inserido: ID=102, Nota=7.0\n");
    
    insere_elemento(&lista, 103, 9.5);
    printf("   Inserido: ID=103, Nota=9.5\n");
    
    insere_elemento(&lista, 104, 6.5);
    printf("   Inserido: ID=104, Nota=6.5\n");
    
    insere_elemento(&lista, 105, 8.0);
    printf("   Inserido: ID=105, Nota=8.0\n\n");
    
    // 4. Imprime a lista
    printf("4. ");
    imprime_lista(&lista);
    printf("\n");
    
    // 5. Testa tamanho após inserções
    printf("5. Tamanho atual da lista: %d\n\n", tamanho_lista(&lista));
    
    // 6. Busca elementos
    printf("6. Buscando elementos...\n");
    int pos = busca_elemento(&lista, 103);
    if (pos != -1) {
        printf("   Elemento ID=103 encontrado na posicao %d (Nota: %.2f)\n", 
               pos, lista.dados[pos].nota);
    } else {
        printf("   Elemento ID=103 nao encontrado\n");
    }
    
    pos = busca_elemento(&lista, 999);
    if (pos != -1) {
        printf("   Elemento ID=999 encontrado na posicao %d\n", pos);
    } else {
        printf("   Elemento ID=999 nao encontrado\n");
    }
    printf("\n");
    
    // 7. Remove elementos
    printf("7. Removendo elementos...\n");
    
    printf("   Removendo ID=102 (meio da lista)...\n");
    remove_elemento(&lista, 102);
    imprime_lista(&lista);
    printf("\n");
    
    printf("   Removendo ID=101 (inicio da lista)...\n");
    remove_elemento(&lista, 101);
    imprime_lista(&lista);
    printf("\n");
    
    printf("   Removendo ID=105 (fim da lista)...\n");
    remove_elemento(&lista, 105);
    imprime_lista(&lista);
    printf("\n");
    
    // 8. Tamanho final
    printf("8. Tamanho final da lista: %d\n\n", tamanho_lista(&lista));
    
    // 9. Tenta remover elemento inexistente
    printf("9. Tentando remover elemento inexistente (ID=999)...\n");
    remove_elemento(&lista, 999);
    printf("   Remocao concluida (sem efeito se nao existir)\n\n");
    
    // 10. Lista final
    printf("10. ");
    imprime_lista(&lista);
    
    printf("\n=== TESTE CONCLUIDO ===\n");
    
    // Fluxo para testar implementações
    ListaDinamica *lista = inicializa_lista();

    printf("--- Teste de Insercao ---\n");
    insere_elemento(lista, 1, 8.5);
    insere_elemento(lista, 2, 9.0);
    insere_elemento(lista, 3, 7.5);
    insere_elemento(lista, 4, 10.0);
    imprimir_lista(lista);
    imprimir_inverso(lista);
    
    printf("\n--- Teste de Busca ---\n");
    int idx = busca_elemento(lista, 3);
    printf("Busca ID 3: Posicao %d\n", idx);
    printf("Busca ID 99: Posicao %d\n", busca_elemento(lista, 99));
    
    printf("\n--- Teste de Remocao (Meio: ID 2) ---\n");
    remove_elemento(lista, 2);
    imprimir_lista(lista);
    imprimir_inverso(lista);
    
    printf("\n--- Teste de Remocao (Inicio: ID 1) ---\n");
    remove_elemento(lista, 1);
    imprimir_lista(lista);
    imprimir_inverso(lista);
    
    printf("\n--- Teste de Remocao (Fim: ID 4) ---\n");
    remove_elemento(lista, 4);
    imprimir_lista(lista);
    imprimir_inverso(lista);
    
    printf("\n--- Teste de Remocao (Unico: ID 3) ---\n");
    remove_elemento(lista, 3);
    imprimir_lista(lista);
    imprimir_inverso(lista);
    
    remove_elemento(lista, 99);
    insere_elemento(lista, 5, 3.0);
    insere_elemento(lista, 6, 4.0);
    insere_elemento(lista, 7, 2.5);
    imprimir_lista(lista);
    imprimir_inverso(lista);
    
    libera_lista(lista);
    return 0;
}
