#include <stdio.h>
#include <stdlib.h>
#include "testes_manuais.h"

void exibir_menu() {
    printf("\n");
    
    printf("================================\n");
    printf("   PROJETO - ESTRUTURA DE DADOS\n");
    printf("================================\n");
    printf("\n");
    printf("Escolha uma opcao:\n");
    printf("[1] Executar testes da Lista Estatica\n");
    printf("[2] Executar testes da Lista Dinamica\n");
    printf("[3] Executar todos os testes\n");
    printf("[0] Sair\n");
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
                executar_testes_lista_estatica();
                printf("\n\n");
                executar_testes_lista_dinamica();
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
