#include <stdio.h>
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
    
    return 0;
}
