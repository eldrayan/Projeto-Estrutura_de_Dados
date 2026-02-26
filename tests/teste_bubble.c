#include <stdio.h>
#include "bubble.h"
#include "testes_manuais.h"

// Função auxiliar para imprimir o array de alunos
void imprimir_alunos(Aluno v[], int n) {
    printf("   [");
    for (int i = 0; i < n; i++) {
        printf(" ID:%d Nota:%.1f", v[i].id, v[i].nota);
        if (i < n - 1) printf(" |");
    }
    printf(" ]\n");
}

// Função auxiliar para imprimir lista dinâmica compacta
void imprimir_lista_dinamica_compacta(ListaDinamica *l) {
    printf("   [");
    NoDinamico *atual = l->inicio;
    while (atual != NULL) {
        printf(" ID:%d Nota:%.1f", atual->id, atual->nota);
        if (atual->prox != NULL) printf(" |");
        atual = atual->prox;
    }
    printf(" ]\n");
}

// Função auxiliar para imprimir lista estática compacta
void imprimir_lista_estatica_compacta(ListaEstatica *l) {
    printf("   [");
    int atual = l->inicio;
    while (atual != -1) {
        printf(" ID:%d Nota:%.1f", l->dados[atual].id, l->dados[atual].nota);
        if (l->dados[atual].prox != -1) printf(" |");
        atual = l->dados[atual].prox;
    }
    printf(" ]\n");
}

void executar_teste_bubble_sort() {
    printf("=== TESTE DO BUBBLE SORT ===\n\n");
    
    printf("===========================\n");
    printf("PARTE 1: TESTE COM VETOR\n");
    printf("===========================\n\n");
    
    // Teste 1: Array desordenado
    printf("1. Teste com array desordenado:\n");
    Aluno teste1[] = {
        {105, 8.0},
        {101, 8.5},
        {104, 6.5},
        {103, 9.5},
        {102, 7.0}
    };
    int n1 = 5;
    
    printf("   Antes:  ");
    imprimir_alunos(teste1, n1);
    
    bubble_sort(teste1, n1);
    
    printf("   Depois: ");
    imprimir_alunos(teste1, n1);
    printf("\n");
    
    // Teste 2: Array já ordenado
    printf("2. Teste com array já ordenado:\n");
    Aluno teste2[] = {
        {104, 6.5},
        {102, 7.0},
        {105, 8.0},
        {101, 8.5},
        {103, 9.5}
    };
    int n2 = 5;
    
    printf("   Antes:  ");
    imprimir_alunos(teste2, n2);
    
    bubble_sort(teste2, n2);
    
    printf("   Depois: ");
    imprimir_alunos(teste2, n2);
    printf("\n");
    
    // Teste 3: Array em ordem decrescente
    printf("3. Teste com array em ordem decrescente:\n");
    Aluno teste3[] = {
        {103, 9.5},
        {101, 8.5},
        {105, 8.0},
        {102, 7.0},
        {104, 6.5}
    };
    int n3 = 5;
    
    printf("   Antes:  ");
    imprimir_alunos(teste3, n3);
    
    bubble_sort(teste3, n3);
    
    printf("   Depois: ");
    imprimir_alunos(teste3, n3);
    printf("\n");
    
    // Teste 4: Array com elementos iguais
    printf("4. Teste com notas iguais:\n");
    Aluno teste4[] = {
        {201, 7.5},
        {202, 7.5},
        {203, 7.5}
    };
    int n4 = 3;
    
    printf("   Antes:  ");
    imprimir_alunos(teste4, n4);
    
    bubble_sort(teste4, n4);
    
    printf("   Depois: ");
    imprimir_alunos(teste4, n4);
    printf("\n");
    
    // Teste 5: Array com 1 elemento
    printf("5. Teste com um único elemento:\n");
    Aluno teste5[] = {
        {301, 10.0}
    };
    int n5 = 1;
    
    printf("   Antes:  ");
    imprimir_alunos(teste5, n5);
    
    bubble_sort(teste5, n5);
    
    printf("   Depois: ");
    imprimir_alunos(teste5, n5);
    printf("\n");
    
    printf("===========================\n");
    printf("PARTE 2: TESTE COM LISTA DINAMICA\n");
    printf("===========================\n\n");
    
    // Teste 6: Lista Dinâmica - desordenada
    printf("6. Teste Lista Dinâmica desordenada:\n");
    ListaDinamica *lista_din = lista_dinamica_inicializa();
    lista_dinamica_insere(lista_din, 105, 8.0);
    lista_dinamica_insere(lista_din, 101, 8.5);
    lista_dinamica_insere(lista_din, 104, 6.5);
    lista_dinamica_insere(lista_din, 103, 9.5);
    lista_dinamica_insere(lista_din, 102, 7.0);
    
    printf("   Antes:  ");
    imprimir_lista_dinamica_compacta(lista_din);
    
    bubble_sort_dinamica(lista_din);
    
    printf("   Depois: ");
    imprimir_lista_dinamica_compacta(lista_din);
    printf("\n");
    lista_dinamica_libera(lista_din);
    
    // Teste 7: Lista Dinâmica - já ordenada (melhor caso)
    printf("7. Teste Lista Dinâmica já ordenada:\n");
    ListaDinamica *lista_din2 = lista_dinamica_inicializa();
    lista_dinamica_insere(lista_din2, 104, 6.5);
    lista_dinamica_insere(lista_din2, 102, 7.0);
    lista_dinamica_insere(lista_din2, 105, 8.0);
    lista_dinamica_insere(lista_din2, 101, 8.5);
    lista_dinamica_insere(lista_din2, 103, 9.5);
    
    printf("   Antes:  ");
    imprimir_lista_dinamica_compacta(lista_din2);
    
    bubble_sort_dinamica(lista_din2);
    
    printf("   Depois: ");
    imprimir_lista_dinamica_compacta(lista_din2);
    printf("\n");
    lista_dinamica_libera(lista_din2);
    
    // Teste 8: Lista Dinâmica - ordem inversa (pior caso)
    printf("8. Teste Lista Dinâmica ordem inversa:\n");
    ListaDinamica *lista_din3 = lista_dinamica_inicializa();
    lista_dinamica_insere(lista_din3, 103, 9.5);
    lista_dinamica_insere(lista_din3, 101, 8.5);
    lista_dinamica_insere(lista_din3, 105, 8.0);
    lista_dinamica_insere(lista_din3, 102, 7.0);
    lista_dinamica_insere(lista_din3, 104, 6.5);
    
    printf("   Antes:  ");
    imprimir_lista_dinamica_compacta(lista_din3);
    
    bubble_sort_dinamica(lista_din3);
    
    printf("   Depois: ");
    imprimir_lista_dinamica_compacta(lista_din3);
    printf("\n");
    lista_dinamica_libera(lista_din3);
    
    printf("===========================\n");
    printf("PARTE 3: TESTE COM LISTA ESTATICA\n");
    printf("===========================\n\n");
    
    // Teste 9: Lista Estática - desordenada
    printf("9. Teste Lista Estática desordenada:\n");
    ListaEstatica lista_est;
    lista_estatica_inicializa(&lista_est);
    lista_estatica_insere(&lista_est, 105, 8.0);
    lista_estatica_insere(&lista_est, 101, 8.5);
    lista_estatica_insere(&lista_est, 104, 6.5);
    lista_estatica_insere(&lista_est, 103, 9.5);
    lista_estatica_insere(&lista_est, 102, 7.0);
    
    printf("   Antes:  ");
    imprimir_lista_estatica_compacta(&lista_est);
    
    bubble_sort_estatica(&lista_est);
    
    printf("   Depois: ");
    imprimir_lista_estatica_compacta(&lista_est);
    printf("\n");
    
    // Teste 10: Lista Estática - já ordenada (melhor caso)
    printf("10. Teste Lista Estática já ordenada:\n");
    ListaEstatica lista_est2;
    lista_estatica_inicializa(&lista_est2);
    lista_estatica_insere(&lista_est2, 104, 6.5);
    lista_estatica_insere(&lista_est2, 102, 7.0);
    lista_estatica_insere(&lista_est2, 105, 8.0);
    lista_estatica_insere(&lista_est2, 101, 8.5);
    lista_estatica_insere(&lista_est2, 103, 9.5);
    
    printf("   Antes:  ");
    imprimir_lista_estatica_compacta(&lista_est2);
    
    bubble_sort_estatica(&lista_est2);
    
    printf("   Depois: ");
    imprimir_lista_estatica_compacta(&lista_est2);
    printf("\n");
    
    // Teste 11: Lista Estática - ordem inversa (pior caso)
    printf("11. Teste Lista Estática ordem inversa:\n");
    ListaEstatica lista_est3;
    lista_estatica_inicializa(&lista_est3);
    lista_estatica_insere(&lista_est3, 103, 9.5);
    lista_estatica_insere(&lista_est3, 101, 8.5);
    lista_estatica_insere(&lista_est3, 105, 8.0);
    lista_estatica_insere(&lista_est3, 102, 7.0);
    lista_estatica_insere(&lista_est3, 104, 6.5);
    
    printf("   Antes:  ");
    imprimir_lista_estatica_compacta(&lista_est3);
    
    bubble_sort_estatica(&lista_est3);
    
    printf("   Depois: ");
    imprimir_lista_estatica_compacta(&lista_est3);
    printf("\n");
    
    printf("=== TESTE CONCLUIDO ===\n");
}
