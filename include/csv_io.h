#ifndef CSV_IO_H
#define CSV_IO_H

#include "timer.h"

/**
 * Salva os resultados de tempo em um arquivo CSV
 *
 * Formato do arquivo:
 * Algoritmo,Tipo_Lista,Tipo_Dados,Tamanho,Tempo_ms
 * Bubble Sort,Vetor,Aleatório,1000,15.234
 * ...
 *
 * @param nome_arquivo Nome do arquivo CSV a ser criado
 * @param resultados Array de estruturas ResultadoTempo
 * @param quantidade Número de elementos no array
 */
void salvar_resultados_csv(const char *nome_arquivo, ResultadoTempo *resultados, int quantidade);

/**
 * Salva um único resultado em um arquivo CSV (append mode)
 * Se o arquivo não existe, cria com cabeçalho
 *
 * @param nome_arquivo Nome do arquivo CSV
 * @param resultado Estrutura com dados do teste
 */
void adicionar_resultado_csv(const char *nome_arquivo, ResultadoTempo resultado);

#endif