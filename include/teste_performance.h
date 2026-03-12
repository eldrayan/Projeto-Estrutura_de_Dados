#ifndef TESTE_PERFORMANCE_H
#define TESTE_PERFORMANCE_H

/**
 * Executa testes de performance dos algoritmos de ordenação
 * Faz 100 repetições para cada configuração e exporta resultados para CSV
 */

// Testes básicos (apenas tamanho médio - 1000 elementos + Vetor)
void executar_testes_performance_bubble_sort(void);
void executar_testes_performance_selection_sort(void);
void executar_testes_performance_insertion_sort(void);
void executar_testes_performance_merge_sort(void);
void executar_testes_performance_quick_sort(void);

// Testes completos com VETOR (múltiplos tamanhos: 100, 1.000, 10.000)
void executar_testes_completos_bubble_sort(void);
void executar_testes_completos_selection_sort(void);
void executar_testes_completos_insertion_sort(void);
void executar_testes_completos_merge_sort(void);
void executar_testes_completos_quick_sort(void);

// Testes com LISTA DINÂMICA (múltiplos tamanhos: 100, 1.000, 10.000)
void executar_testes_bubble_lista_dinamica(void);
void executar_testes_selection_lista_dinamica(void);
void executar_testes_insertion_lista_dinamica(void);
void executar_testes_merge_lista_dinamica(void);
void executar_testes_quick_lista_dinamica(void);

// Testes com LISTA ESTÁTICA (múltiplos tamanhos: 100, 1.000, 10.000)
void executar_testes_bubble_lista_estatica(void);
void executar_testes_selection_lista_estatica(void);
void executar_testes_insertion_lista_estatica(void);
void executar_testes_merge_lista_estatica(void);
void executar_testes_quick_lista_estatica(void);

#endif