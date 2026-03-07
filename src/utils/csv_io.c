#include <stdio.h>
#include <stdlib.h>
#include "csv_io.h"

/**
 * Salva os resultados de tempo em um arquivo CSV
 */
void salvar_resultados_csv(const char *nome_arquivo, ResultadoTempo *resultados, int quantidade) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita: %s\n", nome_arquivo);
        return;
    }
    
    // Escreve o cabeçalho
    fprintf(arquivo, "Algoritmo,Tipo_Lista,Tipo_Dados,Tamanho,Tempo_ms\n");
    
    // Escreve cada resultado
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s,%s,%s,%d,%.4f\n",
                resultados[i].algoritmo,
                resultados[i].tipo_lista,
                resultados[i].tipo_dados,
                resultados[i].tamanho,
                resultados[i].tempo_ms);
    }
    
    fclose(arquivo);
    printf("\n✅ Resultados salvos em: %s\n", nome_arquivo);
}

/**
 * Salva um único resultado em um arquivo CSV (append mode)
 * Se o arquivo não existe, cria com cabeçalho
 */
void adicionar_resultado_csv(const char *nome_arquivo, ResultadoTempo resultado) {
    FILE *arquivo = fopen(nome_arquivo, "a");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo: %s\n", nome_arquivo);
        return;
    }
    
    // Verifica se o arquivo está vazio para adicionar cabeçalho
    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);
    
    if (tamanho_arquivo == 0) {
        fprintf(arquivo, "Algoritmo,Tipo_Lista,Tipo_Dados,Tamanho,Tempo_ms\n");
    }
    
    // Escreve o resultado
    fprintf(arquivo, "%s,%s,%s,%d,%.4f\n",
            resultado.algoritmo,
            resultado.tipo_lista,
            resultado.tipo_dados,
            resultado.tamanho,
            resultado.tempo_ms);
    
    fclose(arquivo);
}
