#include <stdio.h>
#include <stdlib.h>
#include "testes_manuais.h"
#include "teste_performance.h"

void exibir_menu() {
    printf("\n");
    
    printf("========================================\n");
    printf("      PROJETO - ESTRUTURA DE DADOS     \n");
    printf("========================================\n");
    printf("\n");
    printf("TESTES BÁSICOS:\n");
    printf("[1] Executar testes da Lista Estatica\n");
    printf("[2] Executar testes da Lista Dinamica\n");
    printf("[3] Executar testes do Bubble Sort\n");
    printf("[4] Executar testes do Selection Sort\n");
    printf("[5] Executar testes do Insertion Sort\n");
    printf("[6] Executar testes do Merge Sort\n");
    printf("[7] Executar todos os testes\n");
    
    printf("\nTESTES PERFORMANCE - SIMPLES (1000 elem):\n");
    printf("[8] Performance Bubble Sort\n");
    printf("[9] Performance Selection Sort\n");
    printf("[10] Performance Insertion Sort\n");
    printf("[11] Performance Merge Sort\n");
    printf("[12] Performance Quick Sort\n");
    
    printf("\nTESTES COMPLETOS - VETOR (100/1k/10k):\n");
    printf("[13] Bubble Sort - Completo\n");
    printf("[14] Selection Sort - Completo\n");
    printf("[15] Insertion Sort - Completo\n");
    printf("[16] Merge Sort - Completo\n");
    printf("[17] Quick Sort - Completo\n");
    printf("[18] TODOS os algoritmos - Completo\n");
    
    printf("\nTESTES LISTA DINÂMICA (100/1k/10k):\n");
    printf("[19] Bubble Sort - Dinâmica\n");
    printf("[20] Selection Sort - Dinâmica\n");
    printf("[21] Insertion Sort - Dinâmica\n");
    printf("[22] Merge Sort - Dinâmica\n");
    printf("[23] Quick Sort - Dinâmica\n");
    printf("[24] TODOS os algoritmos - Dinâmica\n");
    
    printf("\nTESTES LISTA ESTÁTICA (100/1k/10k):\n");
    printf("[25] Bubble Sort - Estática\n");
    printf("[26] Selection Sort - Estática\n");
    printf("[27] Insertion Sort - Estática\n");
    printf("[28] Merge Sort - Estática\n");
    printf("[29] Quick Sort - Estática\n");
    printf("[30] TODOS os algoritmos - Estática\n");
    
    printf("\nTESTE COMPLETO DO TRABALHO:\n");
    printf("[99] EXECUTAR TODOS OS TESTES (COMPLETO)\n");
    
    printf("\n[0] Sair\n");
}

int main() {
    int opcao;

    do {
       exibir_menu();
       scanf("%d", &opcao);
       
       switch (opcao) {
            case 1:
                printf("\n");
                executar_testes_lista_estatica();
                break;
            
            case 2:
                printf("\n");
                executar_testes_lista_dinamica();
                break;
            
            case 3:
                printf("\n");
                executar_teste_bubble_sort();
                break;
            
            case 4:
                printf("\n");
                executar_teste_selection_sort();
                break;
            
            case 5:
                printf("\n");
                executar_teste_insertion_sort();
                break;

            case 6:
                printf("\n");
                executar_testes_merge_sort();
                break;

            case 7:
                printf("\n");
                executar_testes_lista_estatica();
                printf("\n\n");
                executar_testes_lista_dinamica();
                printf("\n\n");
                executar_teste_bubble_sort();
                printf("\n\n");
                executar_teste_selection_sort();
                printf("\n\n");
                executar_teste_insertion_sort();
                printf("\n\n");
                executar_testes_merge_sort();
                break;

            case 8:
                printf("\n");
                executar_testes_performance_bubble_sort();
                break;

            case 9:
                printf("\n");
                executar_testes_performance_selection_sort();
                break;

            case 10:
                printf("\n");
                executar_testes_performance_insertion_sort();
                break;

            case 11:
                printf("\n");
                executar_testes_performance_merge_sort();
                break;

            case 12:
                printf("\n");
                executar_testes_performance_quick_sort();
                break;

            // ===== TESTES COMPLETOS - VETOR =====
            case 13:
                printf("\n");
                executar_testes_completos_bubble_sort();
                break;

            case 14:
                printf("\n");
                executar_testes_completos_selection_sort();
                break;

            case 15:
                printf("\n");
                executar_testes_completos_insertion_sort();
                break;

            case 16:
                printf("\n");
                executar_testes_completos_merge_sort();
                break;

            case 17:
                printf("\n");
                executar_testes_completos_quick_sort();
                break;

            case 18:
                printf("\n");
                printf(" Executando TODOS os algoritmos com VETOR...\n");
                executar_testes_completos_bubble_sort();
                printf("\n");
                executar_testes_completos_selection_sort();
                printf("\n");
                executar_testes_completos_insertion_sort();
                printf("\n");
                executar_testes_completos_merge_sort();
                printf("\n");
                executar_testes_completos_quick_sort();
                break;

            // ===== TESTES LISTA DINÂMICA =====
            case 19:
                printf("\n");
                executar_testes_bubble_lista_dinamica();
                break;

            case 20:
                printf("\n");
                executar_testes_selection_lista_dinamica();
                break;

            case 21:
                printf("\n");
                executar_testes_insertion_lista_dinamica();
                break;

            case 22:
                printf("\n");
                executar_testes_merge_lista_dinamica();
                break;

            case 23:
                printf("\n");
                executar_testes_quick_lista_dinamica();
                break;

            case 24:
                printf("\n");
                printf(" Executando TODOS os algoritmos com LISTA DINÂMICA...\n");
                executar_testes_bubble_lista_dinamica();
                printf("\n");
                executar_testes_selection_lista_dinamica();
                printf("\n");
                executar_testes_insertion_lista_dinamica();
                printf("\n");
                executar_testes_merge_lista_dinamica();
                printf("\n");
                executar_testes_quick_lista_dinamica();
                break;

            // ===== TESTES LISTA ESTÁTICA =====
            case 25:
                printf("\n");
                executar_testes_bubble_lista_estatica();
                break;

            case 26:
                printf("\n");
                executar_testes_selection_lista_estatica();
                break;

            case 27:
                printf("\n");
                executar_testes_insertion_lista_estatica();
                break;

            case 28:
                printf("\n");
                executar_testes_merge_lista_estatica();
                break;

            case 29:
                printf("\n");
                executar_testes_quick_lista_estatica();
                break;

            case 30:
                printf("\n");
                printf(" Executando TODOS os algoritmos com LISTA ESTÁTICA...\n");
                executar_testes_bubble_lista_estatica();
                printf("\n");
                executar_testes_selection_lista_estatica();
                printf("\n");
                executar_testes_insertion_lista_estatica();
                printf("\n");
                executar_testes_merge_lista_estatica();
                printf("\n");
                executar_testes_quick_lista_estatica();
                break;

            // ===== TESTE COMPLETO DO TRABALHO =====
            case 99:
                printf("\n");
                printf("==============================================\n");
                printf("|  EXECUTANDO BATERIA COMPLETA DE TESTES    |\n");
                printf("|  5 Algoritmos x 3 Estruturas x 3 Tamanhos |\n");
                printf("|  ISSO PODE LEVAR MUITO TEMPO!             |\n");
                printf("==============================================\n\n");
                
                printf("=== PARTE 1/3: TESTES COM VETOR ===\n");
                executar_testes_completos_bubble_sort();
                printf("\n");
                executar_testes_completos_selection_sort();
                printf("\n");
                executar_testes_completos_insertion_sort();
                printf("\n");
                executar_testes_completos_merge_sort();
                printf("\n");
                executar_testes_completos_quick_sort();
                
                printf("\n\n=== PARTE 2/3: TESTES COM LISTA DINÂMICA ===\n");
                executar_testes_bubble_lista_dinamica();
                printf("\n");
                executar_testes_selection_lista_dinamica();
                printf("\n");
                executar_testes_insertion_lista_dinamica();
                printf("\n");
                executar_testes_merge_lista_dinamica();
                printf("\n");
                executar_testes_quick_lista_dinamica();
                
                printf("\n\n=== PARTE 3/3: TESTES COM LISTA ESTÁTICA ===\n");
                executar_testes_bubble_lista_estatica();
                printf("\n");
                executar_testes_selection_lista_estatica();
                printf("\n");
                executar_testes_insertion_lista_estatica();
                printf("\n");
                executar_testes_merge_lista_estatica();
                printf("\n");
                executar_testes_quick_lista_estatica();
                
                printf("\n\n==============================================\n");
                printf("|   TODOS OS TESTES CONCLUÍDOS!           |\n");
                printf("|  Verifique os arquivos CSV gerados        |\n");
                printf("==============================================\n");
                break;

            case 0:
                printf("\nEncerrando programa\n");
                break;

            default:
            printf("\nOpcao invalida! Tente novamente.\n");
       }

       if (opcao != 0) {
        printf("\n\nPressione ENTER para continuar...");
        getchar();
        getchar();
       }

    } while (opcao != 0);
    
    return 0;
}
