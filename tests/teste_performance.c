#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "merge.h"
#include "timer.h"
#include "csv_io.h"
#include "teste_performance.h"

#define NUM_REPETICOES 100
#define TAMANHO_VETOR 1000

// ==================== BUBBLE SORT ====================

/**
 * Cria uma cópia de um array de Alunos
 */
Aluno* copiar_alunos(Aluno v[], int n) {
    Aluno *copia = malloc(n * sizeof(Aluno));
    if (copia == NULL) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    memcpy(copia, v, n * sizeof(Aluno));
    return copia;
}

/**
 * Gera array de alunos com dados aleatórios
 */
Aluno* gerar_alunos_aleatorios(int n) {
    Aluno *alunos = malloc(n * sizeof(Aluno));
    if (alunos == NULL) return NULL;
    
    for (int i = 0; i < n; i++) {
        alunos[i].id = i + 1;
        alunos[i].nota = (float)(rand() % 1001) / 100.0f;  // 0.0 a 10.0
    }
    return alunos;
}

/**
 * Gera array de alunos com dados já ordenados (melhor caso)
 */
Aluno* gerar_alunos_ordenados(int n) {
    Aluno *alunos = malloc(n * sizeof(Aluno));
    if (alunos == NULL) return NULL;
    
    for (int i = 0; i < n; i++) {
        alunos[i].id = i + 1;
        alunos[i].nota = (float)i / n * 10.0f;  // 0.0 a 10.0 em ordem
    }
    return alunos;
}

/**
 * Gera array de alunos com dados em ordem inversa (pior caso)
 */
Aluno* gerar_alunos_invertidos(int n) {
    Aluno *alunos = malloc(n * sizeof(Aluno));
    if (alunos == NULL) return NULL;
    
    for (int i = 0; i < n; i++) {
        alunos[i].id = i + 1;
        alunos[i].nota = 10.0f - ((float)i / n * 10.0f);  // 10.0 a 0.0
    }
    return alunos;
}

void executar_testes_performance_bubble_sort(void) {
    printf("\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║  TESTES DE PERFORMANCE - BUBBLE SORT      ║\n");
    printf("║  (100 execuções por configuração)        ║\n");
    printf("╚═══════════════════════════════════════════╝\n\n");
    
    ResultadoTempo resultados[300];  // 3 tipos de dados × 100 repetições
    int indice = 0;
    
    srand(time(NULL));
    
    // ===== TESTE COM DADOS ALEATÓRIOS =====
    printf("Executando testes com dados ALEATÓRIOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_aleatorios(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        bubble_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Bubble Sort",
            "Vetor",
            "Aleatório",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    // ===== TESTE COM DADOS ORDENADOS =====
    printf("\nExecutando testes com dados ORDENADOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_ordenados(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        bubble_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Bubble Sort",
            "Vetor",
            "Ordenado",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    // ===== TESTE COM DADOS INVERTIDOS =====
    printf("\nExecutando testes com dados INVERTIDOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_invertidos(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        bubble_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Bubble Sort",
            "Vetor",
            "Invertido",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    // Salva os resultados em CSV
    salvar_resultados_csv("resultados_bubble_sort.csv", resultados, indice);
    
    printf("\n╔═══════════════════════════════════════════╗\n");
    printf("║  TESTE DO BUBBLE SORT CONCLUÍDO!          ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
}

void executar_testes_performance_selection_sort(void) {
    printf("\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║ TESTES DE PERFORMANCE - SELECTION SORT    ║\n");
    printf("║  (100 execuções por configuração)        ║\n");
    printf("╚═══════════════════════════════════════════╝\n\n");
    
    ResultadoTempo resultados[300];
    int indice = 0;
    
    srand(time(NULL));
    
    // ===== TESTE COM DADOS ALEATÓRIOS =====
    printf("Executando testes com dados ALEATÓRIOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_aleatorios(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        selection_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Selection Sort",
            "Vetor",
            "Aleatório",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    // ===== TESTE COM DADOS ORDENADOS =====
    printf("\nExecutando testes com dados ORDENADOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_ordenados(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        selection_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Selection Sort",
            "Vetor",
            "Ordenado",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    // ===== TESTE COM DADOS INVERTIDOS =====
    printf("\nExecutando testes com dados INVERTIDOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_invertidos(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        selection_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Selection Sort",
            "Vetor",
            "Invertido",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    salvar_resultados_csv("resultados_selection_sort.csv", resultados, indice);
    
    printf("\n╔═══════════════════════════════════════════╗\n");
    printf("║ TESTE DO SELECTION SORT CONCLUÍDO!        ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
}

void executar_testes_performance_insertion_sort(void) {
    printf("\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║ TESTES DE PERFORMANCE - INSERTION SORT    ║\n");
    printf("║  (100 execuções por configuração)        ║\n");
    printf("╚═══════════════════════════════════════════╝\n\n");
    
    ResultadoTempo resultados[300];
    int indice = 0;
    
    srand(time(NULL));
    
    // ===== TESTE COM DADOS ALEATÓRIOS =====
    printf("Executando testes com dados ALEATÓRIOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_aleatorios(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        insertion_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Insertion Sort",
            "Vetor",
            "Aleatório",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    // ===== TESTE COM DADOS ORDENADOS =====
    printf("\nExecutando testes com dados ORDENADOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_ordenados(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        insertion_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Insertion Sort",
            "Vetor",
            "Ordenado",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    // ===== TESTE COM DADOS INVERTIDOS =====
    printf("\nExecutando testes com dados INVERTIDOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_invertidos(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        insertion_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Insertion Sort",
            "Vetor",
            "Invertido",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    salvar_resultados_csv("resultados_insertion_sort.csv", resultados, indice);
    
    printf("\n╔═══════════════════════════════════════════╗\n");
    printf("║ TESTE DO INSERTION SORT CONCLUÍDO!        ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
}

void executar_testes_performance_merge_sort(void) {
    printf("\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║  TESTES DE PERFORMANCE - MERGE SORT       ║\n");
    printf("║  (100 execuções por configuração)        ║\n");
    printf("╚═══════════════════════════════════════════╝\n\n");
    
    ResultadoTempo resultados[300];
    int indice = 0;
    
    srand(time(NULL));
    
    // ===== TESTE COM DADOS ALEATÓRIOS =====
    printf("Executando testes com dados ALEATÓRIOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_aleatorios(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        merge_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Merge Sort",
            "Vetor",
            "Aleatório",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    // ===== TESTE COM DADOS ORDENADOS =====
    printf("\nExecutando testes com dados ORDENADOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_ordenados(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        merge_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Merge Sort",
            "Vetor",
            "Ordenado",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    // ===== TESTE COM DADOS INVERTIDOS =====
    printf("\nExecutando testes com dados INVERTIDOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_invertidos(TAMANHO_VETOR);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        merge_sort(alunos, TAMANHO_VETOR);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Merge Sort",
            "Vetor",
            "Invertido",
            TAMANHO_VETOR,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    salvar_resultados_csv("resultados_merge_sort.csv", resultados, indice);
    
    printf("\n╔═══════════════════════════════════════════╗\n");
    printf("║  TESTE DO MERGE SORT CONCLUÍDO!           ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
}
