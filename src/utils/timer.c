#include <time.h>
#include <string.h>
#include "timer.h"

/**
 * Inicia a medição de tempo usando clock()
 */
clock_t iniciar_timer(void) {
    return clock();
}

/**
 * Para a medição e retorna o tempo em milissegundos
 */
double parar_timer(clock_t inicio) {
    clock_t fim = clock();
    double tempo_segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
    return tempo_segundos * 1000.0;  // Converte para milissegundos
}

/**
 * Cria uma estrutura de resultado com as informações fornecidas
 */
ResultadoTempo criar_resultado(const char *algoritmo, const char *tipo_lista, 
                                const char *tipo_dados, int tamanho, double tempo_ms) {
    ResultadoTempo resultado;
    
    strncpy(resultado.algoritmo, algoritmo, sizeof(resultado.algoritmo) - 1);
    resultado.algoritmo[sizeof(resultado.algoritmo) - 1] = '\0';
    
    strncpy(resultado.tipo_lista, tipo_lista, sizeof(resultado.tipo_lista) - 1);
    resultado.tipo_lista[sizeof(resultado.tipo_lista) - 1] = '\0';
    
    strncpy(resultado.tipo_dados, tipo_dados, sizeof(resultado.tipo_dados) - 1);
    resultado.tipo_dados[sizeof(resultado.tipo_dados) - 1] = '\0';
    
    resultado.tamanho = tamanho;
    resultado.tempo_ms = tempo_ms;
    
    return resultado;
}
