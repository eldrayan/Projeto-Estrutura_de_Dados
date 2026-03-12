#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "lista_dinamica.h"
#include "estatica.h"
#include "timer.h"
#include "csv_io.h"
#include "teste_performance.h"

#define NUM_REPETICOES 100
#define TAMANHO_PEQUENO 100
#define TAMANHO_MEDIO 1000
#define TAMANHO_GRANDE 10000

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
    printf("=============================================\n");
    printf("|  TESTES DE PERFORMANCE - BUBBLE SORT      |\n");
    printf("|  (100 execuções por configuração)        |\n");
    printf("=============================================\n\n");
    
    ResultadoTempo resultados[300];  // 3 tipos de dados x 100 repetições
    int indice = 0;
    
    srand(time(NULL));
    
    // ===== TESTE COM DADOS ALEATÓRIOS =====
    printf("Executando testes com dados ALEATÓRIOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_aleatorios(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        bubble_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Bubble Sort",
            "Vetor",
            "Aleatório",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_ordenados(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        bubble_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Bubble Sort",
            "Vetor",
            "Ordenado",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_invertidos(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        bubble_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Bubble Sort",
            "Vetor",
            "Invertido",
            TAMANHO_MEDIO,
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
    
    printf("\n=============================================\n");
    printf("|  TESTE DO BUBBLE SORT CONCLUÍDO!          |\n");
    printf("=============================================\n");
}

void executar_testes_performance_selection_sort(void) {
    printf("\n");
    printf("=============================================\n");
    printf("| TESTES DE PERFORMANCE - SELECTION SORT    |\n");
    printf("|  (100 execuções por configuração)        |\n");
    printf("=============================================\n\n");
    
    ResultadoTempo resultados[300];
    int indice = 0;
    
    srand(time(NULL));
    
    // ===== TESTE COM DADOS ALEATÓRIOS =====
    printf("Executando testes com dados ALEATÓRIOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_aleatorios(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        selection_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Selection Sort",
            "Vetor",
            "Aleatório",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_ordenados(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        selection_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Selection Sort",
            "Vetor",
            "Ordenado",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_invertidos(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        selection_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Selection Sort",
            "Vetor",
            "Invertido",
            TAMANHO_MEDIO,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    salvar_resultados_csv("resultados_selection_sort.csv", resultados, indice);
    
    printf("\n=============================================\n");
    printf("| TESTE DO SELECTION SORT CONCLUÍDO!        |\n");
    printf("=============================================\n");
}

void executar_testes_performance_insertion_sort(void) {
    printf("\n");
    printf("=============================================\n");
    printf("| TESTES DE PERFORMANCE - INSERTION SORT    |\n");
    printf("|  (100 execuções por configuração)        |\n");
    printf("=============================================\n\n");
    
    ResultadoTempo resultados[300];
    int indice = 0;
    
    srand(time(NULL));
    
    // ===== TESTE COM DADOS ALEATÓRIOS =====
    printf("Executando testes com dados ALEATÓRIOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_aleatorios(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        insertion_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Insertion Sort",
            "Vetor",
            "Aleatório",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_ordenados(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        insertion_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Insertion Sort",
            "Vetor",
            "Ordenado",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_invertidos(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        insertion_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Insertion Sort",
            "Vetor",
            "Invertido",
            TAMANHO_MEDIO,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    salvar_resultados_csv("resultados_insertion_sort.csv", resultados, indice);
    
    printf("\n=============================================\n");
    printf("| TESTE DO INSERTION SORT CONCLUÍDO!        |\n");
    printf("=============================================\n");
}

void executar_testes_performance_merge_sort(void) {
    printf("\n");
    printf("=============================================\n");
    printf("|  TESTES DE PERFORMANCE - MERGE SORT       |\n");
    printf("|  (100 execuções por configuração)        |\n");
    printf("=============================================\n\n");
    
    ResultadoTempo resultados[300];
    int indice = 0;
    
    srand(time(NULL));
    
    // ===== TESTE COM DADOS ALEATÓRIOS =====
    printf("Executando testes com dados ALEATÓRIOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_aleatorios(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        merge_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Merge Sort",
            "Vetor",
            "Aleatório",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_ordenados(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        merge_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Merge Sort",
            "Vetor",
            "Ordenado",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_invertidos(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        merge_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Merge Sort",
            "Vetor",
            "Invertido",
            TAMANHO_MEDIO,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    salvar_resultados_csv("resultados_merge_sort.csv", resultados, indice);
    
    printf("\n=============================================\n");
    printf("|  TESTE DO MERGE SORT CONCLUÍDO!           |\n");
    printf("=============================================\n");
}

// ==================== QUICK SORT ====================

void executar_testes_performance_quick_sort(void) {
    printf("\n");
    printf("=============================================\n");
    printf("|  TESTES DE PERFORMANCE - QUICK SORT       |\n");
    printf("|  (100 execuções por configuração)        |\n");
    printf("=============================================\n\n");
    
    ResultadoTempo resultados[300];  // 3 tipos de dados x 100 repetições
    int indice = 0;
    
    // ===== TESTE COM DADOS ALEATÓRIOS =====
    printf("Executando testes com dados ALEATÓRIOS...\n");
    for (int rep = 0; rep < NUM_REPETICOES; rep++) {
        Aluno *alunos = gerar_alunos_aleatorios(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        quick_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Quick Sort",
            "Vetor",
            "Aleatório",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_ordenados(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        quick_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Quick Sort",
            "Vetor",
            "Ordenado",
            TAMANHO_MEDIO,
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
        Aluno *alunos = gerar_alunos_invertidos(TAMANHO_MEDIO);
        if (alunos == NULL) continue;
        
        clock_t inicio = iniciar_timer();
        quick_sort(alunos, TAMANHO_MEDIO);
        double tempo = parar_timer(inicio);
        
        resultados[indice] = criar_resultado(
            "Quick Sort",
            "Vetor",
            "Invertido",
            TAMANHO_MEDIO,
            tempo
        );
        indice++;
        
        free(alunos);
        
        if ((rep + 1) % 10 == 0) {
            printf("  Progresso: %d/%d execuções concluídas\n", rep + 1, NUM_REPETICOES);
        }
    }
    
    salvar_resultados_csv("resultados_quick_sort.csv", resultados, indice);
    
    printf("\n=============================================\n");
    printf("|  TESTE DO QUICK SORT CONCLUÍDO!           |\n");
    printf("=============================================\n");
}

// ==================== FUNÇÕES AUXILIARES PARA MÚLTIPLOS TAMANHOS ====================

/**
 * Testa um algoritmo com múltiplos tamanhos
 */
void testar_algoritmo_multiplos_tamanhos(
    const char *nome_algoritmo,
    void (*funcao_sort)(Aluno[], int),
    const char *nome_arquivo
) {
    int tamanhos[] = {TAMANHO_PEQUENO, TAMANHO_MEDIO, TAMANHO_GRANDE};
    int num_tamanhos = 3;
    
    printf("\n");
    printf("=============================================\n");
    printf("|  TESTES COMPLETOS - %-21s|\n", nome_algoritmo);
    printf("|  Tamanhos: 100, 1.000, 10.000            |\n");
    printf("|  (100 execuções por configuração)        |\n");
    printf("=============================================\n\n");
    
    // Calcula total de resultados: 3 tamanhos x 3 tipos x 100 repetições
    ResultadoTempo *resultados = malloc(sizeof(ResultadoTempo) * num_tamanhos * 3 * NUM_REPETICOES);
    if (resultados == NULL) {
        printf(" Erro ao alocar memória para resultados\n");
        return;
    }
    int indice = 0;
    
    srand(time(NULL));
    
    for (int t = 0; t < num_tamanhos; t++) {
        int tamanho = tamanhos[t];
        printf("\n Testando com %d elementos:\n", tamanho);
        printf("===========================================\n");
        
        // ===== TESTE COM DADOS ALEATÓRIOS =====
        printf("  → Dados ALEATÓRIOS...\n");
        for (int rep = 0; rep < NUM_REPETICOES; rep++) {
            Aluno *alunos = gerar_alunos_aleatorios(tamanho);
            if (alunos == NULL) continue;
            
            clock_t inicio = iniciar_timer();
            funcao_sort(alunos, tamanho);
            double tempo = parar_timer(inicio);
            
            resultados[indice] = criar_resultado(
                nome_algoritmo,
                "Vetor",
                "Aleatório",
                tamanho,
                tempo
            );
            indice++;
            free(alunos);
        }
        printf("    ✓ 100 execuções concluídas\n");
        
        // ===== TESTE COM DADOS ORDENADOS =====
        printf("  → Dados ORDENADOS...\n");
        for (int rep = 0; rep < NUM_REPETICOES; rep++) {
            Aluno *alunos = gerar_alunos_ordenados(tamanho);
            if (alunos == NULL) continue;
            
            clock_t inicio = iniciar_timer();
            funcao_sort(alunos, tamanho);
            double tempo = parar_timer(inicio);
            
            resultados[indice] = criar_resultado(
                nome_algoritmo,
                "Vetor",
                "Ordenado",
                tamanho,
                tempo
            );
            indice++;
            free(alunos);
        }
        printf("    ✓ 100 execuções concluídas\n");
        
        // ===== TESTE COM DADOS INVERTIDOS =====
        printf("  → Dados INVERTIDOS...\n");
        for (int rep = 0; rep < NUM_REPETICOES; rep++) {
            Aluno *alunos = gerar_alunos_invertidos(tamanho);
            if (alunos == NULL) continue;
            
            clock_t inicio = iniciar_timer();
            funcao_sort(alunos, tamanho);
            double tempo = parar_timer(inicio);
            
            resultados[indice] = criar_resultado(
                nome_algoritmo,
                "Vetor",
                "Invertido",
                tamanho,
                tempo
            );
            indice++;
            free(alunos);
        }
        printf("    ✓ 100 execuções concluídas\n");
    }
    
    salvar_resultados_csv(nome_arquivo, resultados, indice);
    free(resultados);
    
    printf("\n=============================================\n");
    printf("|  TESTES COMPLETOS CONCLUÍDOS!             |\n");
    printf("|  Resultados salvos em: %-18s|\n", nome_arquivo);
    printf("=============================================\n");
}

// ==================== FUNÇÕES DE TESTE COMPLETO POR ALGORITMO ====================

void executar_testes_completos_bubble_sort(void) {
    testar_algoritmo_multiplos_tamanhos("Bubble Sort", bubble_sort, "resultados_bubble_completo.csv");
}

void executar_testes_completos_selection_sort(void) {
    testar_algoritmo_multiplos_tamanhos("Selection Sort", selection_sort, "resultados_selection_completo.csv");
}

void executar_testes_completos_insertion_sort(void) {
    testar_algoritmo_multiplos_tamanhos("Insertion Sort", insertion_sort, "resultados_insertion_completo.csv");
}

void executar_testes_completos_merge_sort(void) {
    testar_algoritmo_multiplos_tamanhos("Merge Sort", merge_sort, "resultados_merge_completo.csv");
}

void executar_testes_completos_quick_sort(void) {
    testar_algoritmo_multiplos_tamanhos("Quick Sort", quick_sort, "resultados_quick_completo.csv");
}

// ==================== FUNÇÕES PARA TESTES COM LISTAS ====================

/**
 * Cria lista dinâmica a partir de array de alunos
 */
ListaDinamica* criar_lista_dinamica_de_array(Aluno *alunos, int n) {
    ListaDinamica *lista = lista_dinamica_inicializa();
    if (lista == NULL) return NULL;
    
    for (int i = 0; i < n; i++) {
        lista_dinamica_insere(lista, alunos[i].id, alunos[i].nota);
    }
    return lista;
}

/**
 * Cria lista estática a partir de array de alunos
 */
void criar_lista_estatica_de_array(ListaEstatica *lista, Aluno *alunos, int n) {
    lista_estatica_inicializa(lista);
    for (int i = 0; i < n; i++) {
        lista_estatica_insere(lista, alunos[i].id, alunos[i].nota);
    }
}

/**
 * Testa algoritmos com lista dinâmica em múltiplos tamanhos
 */
void testar_algoritmo_lista_dinamica(
    const char *nome_algoritmo,
    void (*funcao_sort_dinamica)(ListaDinamica*),
    const char *nome_arquivo
) {
    int tamanhos[] = {TAMANHO_PEQUENO, TAMANHO_MEDIO, TAMANHO_GRANDE};
    int num_tamanhos = 3;
    
    printf("\n");
    printf("=============================================\n");
    printf("|  TESTES LISTA DINÂMICA - %-16s|\n", nome_algoritmo);
    printf("|  Tamanhos: 100, 1.000, 10.000            |\n");
    printf("|  (100 execuções por configuração)        |\n");
    printf("=============================================\n\n");
    
    ResultadoTempo *resultados = malloc(sizeof(ResultadoTempo) * num_tamanhos * 3 * NUM_REPETICOES);
    if (resultados == NULL) {
        printf(" Erro ao alocar memória para resultados\n");
        return;
    }
    int indice = 0;
    
    srand(time(NULL));
    
    for (int t = 0; t < num_tamanhos; t++) {
        int tamanho = tamanhos[t];
        printf("\n Testando com %d elementos:\n", tamanho);
        printf("===========================================\n");
        
        // TESTE COM DADOS ALEATÓRIOS
        printf("  → Dados ALEATÓRIOS...\n");
        for (int rep = 0; rep < NUM_REPETICOES; rep++) {
            Aluno *alunos = gerar_alunos_aleatorios(tamanho);
            if (alunos == NULL) continue;
            
            ListaDinamica *lista = criar_lista_dinamica_de_array(alunos, tamanho);
            if (lista == NULL) {
                free(alunos);
                continue;
            }
            
            clock_t inicio = iniciar_timer();
            funcao_sort_dinamica(lista);
            double tempo = parar_timer(inicio);
            
            resultados[indice] = criar_resultado(
                nome_algoritmo,
                "Lista Dinâmica",
                "Aleatório",
                tamanho,
                tempo
            );
            indice++;
            
            // Libera memória da lista
            NoDinamico *atual = lista->inicio;
            while (atual != NULL) {
                NoDinamico *prox = atual->prox;
                free(atual);
                atual = prox;
            }
            free(lista);
            free(alunos);
        }
        printf("    ✓ 100 execuções concluídas\n");
        
        // TESTE COM DADOS ORDENADOS
        printf("  → Dados ORDENADOS...\n");
        for (int rep = 0; rep < NUM_REPETICOES; rep++) {
            Aluno *alunos = gerar_alunos_ordenados(tamanho);
            if (alunos == NULL) continue;
            
            ListaDinamica *lista = criar_lista_dinamica_de_array(alunos, tamanho);
            if (lista == NULL) {
                free(alunos);
                continue;
            }
            
            clock_t inicio = iniciar_timer();
            funcao_sort_dinamica(lista);
            double tempo = parar_timer(inicio);
            
            resultados[indice] = criar_resultado(
                nome_algoritmo,
                "Lista Dinâmica",
                "Ordenado",
                tamanho,
                tempo
            );
            indice++;
            
            NoDinamico *atual = lista->inicio;
            while (atual != NULL) {
                NoDinamico *prox = atual->prox;
                free(atual);
                atual = prox;
            }
            free(lista);
            free(alunos);
        }
        printf("    ✓ 100 execuções concluídas\n");
        
        // TESTE COM DADOS INVERTIDOS
        printf("  → Dados INVERTIDOS...\n");
        for (int rep = 0; rep < NUM_REPETICOES; rep++) {
            Aluno *alunos = gerar_alunos_invertidos(tamanho);
            if (alunos == NULL) continue;
            
            ListaDinamica *lista = criar_lista_dinamica_de_array(alunos, tamanho);
            if (lista == NULL) {
                free(alunos);
                continue;
            }
            
            clock_t inicio = iniciar_timer();
            funcao_sort_dinamica(lista);
            double tempo = parar_timer(inicio);
            
            resultados[indice] = criar_resultado(
                nome_algoritmo,
                "Lista Dinâmica",
                "Invertido",
                tamanho,
                tempo
            );
            indice++;
            
            NoDinamico *atual = lista->inicio;
            while (atual != NULL) {
                NoDinamico *prox = atual->prox;
                free(atual);
                atual = prox;
            }
            free(lista);
            free(alunos);
        }
        printf("    ✓ 100 execuções concluídas\n");
    }
    
    salvar_resultados_csv(nome_arquivo, resultados, indice);
    free(resultados);
    
    printf("\n=============================================\n");
    printf("|  TESTES LISTA DINÂMICA CONCLUÍDOS!        |\n");
    printf("|  Resultados salvos em: %-18s|\n", nome_arquivo);
    printf("=============================================\n");
}

/**
 * Testa algoritmos com lista estática em múltiplos tamanhos
 */
void testar_algoritmo_lista_estatica(
    const char *nome_algoritmo,
    void (*funcao_sort_estatica)(ListaEstatica*),
    const char *nome_arquivo
) {
    int tamanhos[] = {TAMANHO_PEQUENO, TAMANHO_MEDIO, TAMANHO_GRANDE};
    int num_tamanhos = 3;
    
    printf("\n");
    printf("=============================================\n");
    printf("|  TESTES LISTA ESTÁTICA - %-16s|\n", nome_algoritmo);
    printf("|  Tamanhos: 100, 1.000, 10.000            |\n");
    printf("|  (100 execuções por configuração)        |\n");
    printf("=============================================\n\n");
    
    ResultadoTempo *resultados = malloc(sizeof(ResultadoTempo) * num_tamanhos * 3 * NUM_REPETICOES);
    if (resultados == NULL) {
        printf(" Erro ao alocar memória para resultados\n");
        return;
    }
    int indice = 0;
    
    srand(time(NULL));
    
    for (int t = 0; t < num_tamanhos; t++) {
        int tamanho = tamanhos[t];
        printf("\n Testando com %d elementos:\n", tamanho);
        printf("===========================================\n");
        
        // TESTE COM DADOS ALEATÓRIOS
        printf("  → Dados ALEATÓRIOS...\n");
        for (int rep = 0; rep < NUM_REPETICOES; rep++) {
            Aluno *alunos = gerar_alunos_aleatorios(tamanho);
            if (alunos == NULL) continue;
            
            ListaEstatica lista;
            criar_lista_estatica_de_array(&lista, alunos, tamanho);
            
            clock_t inicio = iniciar_timer();
            funcao_sort_estatica(&lista);
            double tempo = parar_timer(inicio);
            
            resultados[indice] = criar_resultado(
                nome_algoritmo,
                "Lista Estática",
                "Aleatório",
                tamanho,
                tempo
            );
            indice++;
            free(alunos);
        }
        printf("    ✓ 100 execuções concluídas\n");
        
        // TESTE COM DADOS ORDENADOS
        printf("  → Dados ORDENADOS...\n");
        for (int rep = 0; rep < NUM_REPETICOES; rep++) {
            Aluno *alunos = gerar_alunos_ordenados(tamanho);
            if (alunos == NULL) continue;
            
            ListaEstatica lista;
            criar_lista_estatica_de_array(&lista, alunos, tamanho);
            
            clock_t inicio = iniciar_timer();
            funcao_sort_estatica(&lista);
            double tempo = parar_timer(inicio);
            
            resultados[indice] = criar_resultado(
                nome_algoritmo,
                "Lista Estática",
                "Ordenado",
                tamanho,
                tempo
            );
            indice++;
            free(alunos);
        }
        printf("    ✓ 100 execuções concluídas\n");
        
        // TESTE COM DADOS INVERTIDOS
        printf("  → Dados INVERTIDOS...\n");
        for (int rep = 0; rep < NUM_REPETICOES; rep++) {
            Aluno *alunos = gerar_alunos_invertidos(tamanho);
            if (alunos == NULL) continue;
            
            ListaEstatica lista;
            criar_lista_estatica_de_array(&lista, alunos, tamanho);
            
            clock_t inicio = iniciar_timer();
            funcao_sort_estatica(&lista);
            double tempo = parar_timer(inicio);
            
            resultados[indice] = criar_resultado(
                nome_algoritmo,
                "Lista Estática",
                "Invertido",
                tamanho,
                tempo
            );
            indice++;
            free(alunos);
        }
        printf("    ✓ 100 execuções concluídas\n");
    }
    
    salvar_resultados_csv(nome_arquivo, resultados, indice);
    free(resultados);
    
    printf("\n=============================================\n");
    printf("|  TESTES LISTA ESTÁTICA CONCLUÍDOS!        |\n");
    printf("|  Resultados salvos em: %-18s|\n", nome_arquivo);
    printf("=============================================\n");
}

// ==================== FUNÇÕES PÚBLICAS PARA LISTAS ====================

void executar_testes_bubble_lista_dinamica(void) {
    testar_algoritmo_lista_dinamica("Bubble Sort", bubble_sort_dinamica, "resultados_bubble_dinamica.csv");
}

void executar_testes_bubble_lista_estatica(void) {
    testar_algoritmo_lista_estatica("Bubble Sort", bubble_sort_estatica, "resultados_bubble_estatica.csv");
}

void executar_testes_selection_lista_dinamica(void) {
    testar_algoritmo_lista_dinamica("Selection Sort", selection_sort_dinamica, "resultados_selection_dinamica.csv");
}

void executar_testes_selection_lista_estatica(void) {
    testar_algoritmo_lista_estatica("Selection Sort", selection_sort_estatica, "resultados_selection_estatica.csv");
}

void executar_testes_insertion_lista_dinamica(void) {
    testar_algoritmo_lista_dinamica("Insertion Sort", insertion_sort_dinamica, "resultados_insertion_dinamica.csv");
}

void executar_testes_insertion_lista_estatica(void) {
    testar_algoritmo_lista_estatica("Insertion Sort", insertion_sort_estatica, "resultados_insertion_estatica.csv");
}

void executar_testes_merge_lista_dinamica(void) {
    testar_algoritmo_lista_dinamica("Merge Sort", merge_sort_dinamica, "resultados_merge_dinamica.csv");
}

void executar_testes_merge_lista_estatica(void) {
    testar_algoritmo_lista_estatica("Merge Sort", merge_sort_estatica, "resultados_merge_estatica.csv");
}

void executar_testes_quick_lista_dinamica(void) {
    testar_algoritmo_lista_dinamica("Quick Sort", quick_sort_dinamica, "resultados_quick_dinamica.csv");
}

void executar_testes_quick_lista_estatica(void) {
    testar_algoritmo_lista_estatica("Quick Sort", quick_sort_estatica, "resultados_quick_estatica.csv");
}
