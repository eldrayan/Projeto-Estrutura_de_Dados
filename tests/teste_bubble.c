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

void executar_teste_bubble_sort() {
    printf("=== TESTE DO BUBBLE SORT ===\n\n");
    
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
    
    printf("=== TESTE CONCLUIDO ===\n");
}
