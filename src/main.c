#include <stdio.h>
#include "lista_dinamica.h"
#include "estatica.h"

int main() {
    ListaEstatica lista;
    
    printf("=== TESTE DA LISTA DUPLAMENTE ENCADEADA ESTATICA ===\n\n");
    
    // 1. Inicializa a lista
    printf("1. Inicializando a lista...\n");
    lista_estatica_inicializa(&lista);
    printf("   Lista inicializada!\n\n");
    
    // 2. Testa tamanho inicial (deve ser 0)
    printf("2. Tamanho inicial da lista: %d\n\n", lista_estatica_tamanho(&lista));
    
    // 3. Insere elementos
    printf("3. Inserindo elementos...\n");
    lista_estatica_insere(&lista, 101, 8.5);
    printf("   Inserido: ID=101, Nota=8.5\n");
    
    lista_estatica_insere(&lista, 102, 7.0);
    printf("   Inserido: ID=102, Nota=7.0\n");
    
    lista_estatica_insere(&lista, 103, 9.5);
    printf("   Inserido: ID=103, Nota=9.5\n");
    
    lista_estatica_insere(&lista, 104, 6.5);
    printf("   Inserido: ID=104, Nota=6.5\n");
    
    lista_estatica_insere(&lista, 105, 8.0);
    printf("   Inserido: ID=105, Nota=8.0\n\n");
    
    // 4. Imprime a lista
    printf("4. ");
    lista_estatica_imprime(&lista);
    printf("\n");
    
    // 5. Testa tamanho após inserções
    printf("5. Tamanho atual da lista: %d\n\n", lista_estatica_tamanho(&lista));
    
    // 6. Busca elementos
    printf("6. Buscando elementos...\n");
    int pos = lista_estatica_busca(&lista, 103);
    if (pos != -1) {
        printf("   Elemento ID=103 encontrado na posicao %d (Nota: %.2f)\n",
               pos, lista.dados[pos].nota);
    } else {
        printf("   Elemento ID=103 nao encontrado\n");
    }
    
    pos = lista_estatica_busca(&lista, 999);
    if (pos != -1) {
        printf("   Elemento ID=999 encontrado na posicao %d\n", pos);
    } else {
        printf("   Elemento ID=999 nao encontrado\n");
    }
    printf("\n");
    
    // 7. Remove elementos
    printf("7. Removendo elementos...\n");
    
    printf("   Removendo ID=102 (meio da lista)...\n");
    lista_estatica_remove(&lista, 102);
    lista_estatica_imprime(&lista);
    printf("\n");
    
    printf("   Removendo ID=101 (inicio da lista)...\n");
    lista_estatica_remove(&lista, 101);
    lista_estatica_imprime(&lista);
    printf("\n");
    
    printf("   Removendo ID=105 (fim da lista)...\n");
    lista_estatica_remove(&lista, 105);
    lista_estatica_imprime(&lista);
    printf("\n");
    
    // 8. Tamanho final
    printf("8. Tamanho final da lista: %d\n\n", lista_estatica_tamanho(&lista));
    
    // 9. Tenta remover elemento inexistente
    printf("9. Tentando remover elemento inexistente (ID=999)...\n");
    lista_estatica_remove(&lista, 999);
    printf("   Remocao concluida (sem efeito se nao existir)\n\n");
    
    // 10. Lista final
    printf("10. ");
    lista_estatica_imprime(&lista);
    
    printf("\n=== TESTE CONCLUIDO ===\n");
    
    // Fluxo para testar implementações
    ListaDinamica *lista_dinamica = lista_dinamica_inicializa();

    printf("--- Teste de Insercao ---\n");
    lista_dinamica_insere(lista_dinamica, 1, 8.5);
    lista_dinamica_insere(lista_dinamica, 2, 9.0);
    lista_dinamica_insere(lista_dinamica, 3, 7.5);
    lista_dinamica_insere(lista_dinamica, 4, 10.0);
    lista_dinamica_imprimir(lista_dinamica);
    lista_dinamica_imprimir_inverso(lista_dinamica);
    
    printf("\n--- Teste de Busca ---\n");
    int idx = lista_dinamica_busca(lista_dinamica, 3);
    printf("Busca ID 3: Posicao %d\n", idx);
    printf("Busca ID 99: Posicao %d\n", lista_dinamica_busca(lista_dinamica, 99));
    
    printf("\n--- Teste de Remocao (Meio: ID 2) ---\n");
    lista_dinamica_remove(lista_dinamica, 2);
    lista_dinamica_imprimir(lista_dinamica);
    lista_dinamica_imprimir_inverso(lista_dinamica);
    
    printf("\n--- Teste de Remocao (Inicio: ID 1) ---\n");
    lista_dinamica_remove(lista_dinamica, 1);
    lista_dinamica_imprimir(lista_dinamica);
    lista_dinamica_imprimir_inverso(lista_dinamica);
    
    printf("\n--- Teste de Remocao (Fim: ID 4) ---\n");
    lista_dinamica_remove(lista_dinamica, 4);
    lista_dinamica_imprimir(lista_dinamica);
    lista_dinamica_imprimir_inverso(lista_dinamica);
    
    printf("\n--- Teste de Remocao (Unico: ID 3) ---\n");
    lista_dinamica_remove(lista_dinamica, 3);
    lista_dinamica_imprimir(lista_dinamica);
    lista_dinamica_imprimir_inverso(lista_dinamica);
    
    lista_dinamica_remove(lista_dinamica, 99);
    lista_dinamica_insere(lista_dinamica, 5, 3.0);
    lista_dinamica_insere(lista_dinamica, 6, 4.0);
    lista_dinamica_insere(lista_dinamica, 7, 2.5);
    lista_dinamica_imprimir(lista_dinamica);
    lista_dinamica_imprimir_inverso(lista_dinamica);
    
    lista_dinamica_libera(lista_dinamica);
    return 0;
}
