#ifndef TIMER_H
#define TIMER_H

#include <time.h>

/**
 * Estrutura para armazenar informações de tempo de execução
 */
typedef struct {
    char algoritmo[50];    // Nome do algoritmo (ex: "Bubble Sort")
    char tipo_lista[20];   // Tipo da lista (Vetor, Dinâmica, Estática)
    char tipo_dados[30];   // Tipo dos dados (Aleatório, Ordenado, Invertido)
    int tamanho;           // Tamanho dos dados
    double tempo_ms;       // Tempo em milissegundos
} ResultadoTempo;

/**
 * Inicia a medição de tempo
 */
clock_t iniciar_timer(void);

/**
 * Para a medição e retorna o tempo em milissegundos
 */
double parar_timer(clock_t inicio);

/**
 * Cria uma estrutura de resultado com as informações fornecidas
 */
ResultadoTempo criar_resultado(const char *algoritmo, const char *tipo_lista,
                               const char *tipo_dados, int tamanho, double tempo_ms);

#endif