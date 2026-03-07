#include <stdio.h>
#include <stdlib.h>
#include "testes_manuais.h"
#include "teste_performance.h"

void exibir_menu() {
    printf("\n");
    
    printf("================================\n");
    printf("   PROJETO - ESTRUTURA DE DADOS\n");
    printf("================================\n");
    printf("\n");
    printf("TESTES BÁSICOS:\n");
    printf("[1] Executar testes da Lista Estatica\n");
    printf("[2] Executar testes da Lista Dinamica\n");
    printf("[3] Executar testes do Bubble Sort\n");
    printf("[4] Executar testes do Selection Sort\n");
    printf("[5] Executar testes do Insertion Sort\n");
    printf("[6] Executar testes do Merge Sort\n");
    printf("[7] Executar todos os testes\n");
    printf("\nTESTES DE PERFORMANCE (100 repetições + CSV):\n");
    printf("[8] Performance Bubble Sort\n");
    printf("[9] Performance Selection Sort\n");
    printf("[10] Performance Insertion Sort\n");
    printf("[11] Performance Merge Sort\n");
    printf("[12] Executar todos os testes de performance\n");
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
                executar_testes_performance_bubble_sort();
                printf("\n");
                executar_testes_performance_selection_sort();
                printf("\n");
                executar_testes_performance_insertion_sort();
                printf("\n");
                executar_testes_performance_merge_sort();
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
