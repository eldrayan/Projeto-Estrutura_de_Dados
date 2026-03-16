#!/usr/bin/env python3
"""
Script para análise de performance dos algoritmos de ordenação
Lê os arquivos CSV gerados e gera estatísticas e gráficos
"""

import pandas as pd
import matplotlib.pyplot as plt
import os
import sys

def carregar_resultados(arquivo):
    """Carrega os resultados de um arquivo CSV"""
    try:
        df = pd.read_csv(arquivo)
        return df
    except FileNotFoundError:
        print(f"❌ Erro: arquivo '{arquivo}' não encontrado")
        return None

def mostrar_estatisticas(df, algoritmo):
    """Mostra estatísticas descritivas dos testes"""
    print(f"\n{'='*60}")
    print(f" ESTATÍSTICAS - {algoritmo}")
    print(f"{'='*60}\n")
    
    for tipo_dados in df['Tipo_Dados'].unique():
        dados = df[df['Tipo_Dados'] == tipo_dados]['Tempo_ms']
        
        print(f"📊 {tipo_dados:15} | Count: {len(dados):3} | "
              f"Min: {dados.min():8.4f}ms | "
              f"Max: {dados.max():8.4f}ms | "
              f"Mean: {dados.mean():8.4f}ms | "
              f"Std: {dados.std():8.4f}ms")

def gerar_grafico_boxplot(df, algoritmo):
    """Gera gráfico boxplot dos dados"""
    plt.figure(figsize=(10, 6))
    
    # Preparar dados para boxplot
    dados_por_tipo = [df[df['Tipo_Dados'] == tipo]['Tempo_ms'].values 
                      for tipo in ['Aleatório', 'Ordenado', 'Invertido']]
    
    # Criar boxplot
    bp = plt.boxplot(dados_por_tipo, labels=['Aleatório', 'Ordenado', 'Invertido'],
                     patch_artist=True)
    
    # Colorir os boxes
    cores = ['#FF9999', '#66B2FF', '#99FF99']
    for patch, cor in zip(bp['boxes'], cores):
        patch.set_facecolor(cor)
    
    plt.ylabel('Tempo (ms)', fontsize=12)
    plt.xlabel('Tipo de Dados', fontsize=12)
    plt.title(f'Distribuição de Tempos - {algoritmo}', fontsize=14, fontweight='bold')
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    
    filename = f'grafico_boxplot_{algoritmo.lower().replace(" ", "_")}.png'
    plt.savefig(filename, dpi=100)
    print(f"✅ Gráfico salvo: {filename}")
    plt.close()

def gerar_grafico_comparativo(df, algoritmo):
    """Gera gráfico de tempos médios por tipo de dados"""
    plt.figure(figsize=(10, 6))
    
    # Calcular médias
    medias = df.groupby('Tipo_Dados')['Tempo_ms'].mean()
    
    # Reordenar para a ordem desejada
    medias = medias.reindex(['Aleatório', 'Ordenado', 'Invertido'])
    
    # Criar gráfico de barras
    cores = ['#FF9999', '#66B2FF', '#99FF99']
    bars = plt.bar(range(len(medias)), medias.values, color=cores, alpha=0.7, edgecolor='black')
    
    # Adicionar valores nas barras
    for i, (tipo, valor) in enumerate(medias.items()):
        plt.text(i, valor + valor*0.05, f'{valor:.4f}ms', ha='center', fontweight='bold')
    
    plt.ylabel('Tempo Médio (ms)', fontsize=12)
    plt.xlabel('Tipo de Dados', fontsize=12)
    plt.title(f'Tempo Médio de Execução - {algoritmo}', fontsize=14, fontweight='bold')
    plt.xticks(range(len(medias)), medias.index)
    plt.grid(True, alpha=0.3, axis='y')
    plt.tight_layout()
    
    filename = f'grafico_comparativo_{algoritmo.lower().replace(" ", "_")}.png'
    plt.savefig(filename, dpi=100)
    print(f"✅ Gráfico salvo: {filename}")
    plt.close()

def comparar_algoritmos():
    """Compara todos os algoritmos"""
    algoritmos = ['bubble', 'selection', 'insertion', 'merge']
    dados_comparacao = {}
    
    print(f"\n{'='*80}")
    print(f" COMPARAÇÃO ENTRE ALGORITMOS")
    print(f"{'='*80}\n")
    
    for algo in algoritmos:
        arquivo = f'resultados_{algo}_sort.csv'
        if os.path.exists(arquivo):
            df = pd.read_csv(arquivo)
            nome = df['Algoritmo'].iloc[0]
            media_geral = df['Tempo_ms'].mean()
            dados_comparacao[nome] = media_geral
            status = "✅"
        else:
            status = "❌"
        
        print(f"{status} {arquivo:40} - Média: {dados_comparacao.get(nome, 'N/A')}")
    
    # Gráfico comparativo
    if dados_comparacao:
        plt.figure(figsize=(10, 6))
        nomes = list(dados_comparacao.keys())
        valores = list(dados_comparacao.values())
        
        cores = ['#FF6B6B', '#4ECDC4', '#45B7D1', '#FFA07A']
        bars = plt.bar(nomes, valores, color=cores, alpha=0.7, edgecolor='black')
        
        for bar, valor in zip(bars, valores):
            height = bar.get_height()
            plt.text(bar.get_x() + bar.get_width()/2., height,
                    f'{valor:.4f}ms', ha='center', va='bottom', fontweight='bold')
        
        plt.ylabel('Tempo Médio (ms)', fontsize=12)
        plt.title('Comparação de Tempo Médio Entre Algoritmos', fontsize=14, fontweight='bold')
        plt.xticks(rotation=15)
        plt.grid(True, alpha=0.3, axis='y')
        plt.tight_layout()
        
        plt.savefig('comparacao_algoritmos.png', dpi=100)
        print(f"\n✅ Gráfico comparativo salvo: comparacao_algoritmos.png")
        plt.close()

def main():
    """Função principal"""
    print("\n" + "="*60)
    print(" ANALISADOR DE PERFORMANCE DE ALGORITMOS")
    print("="*60)
    
    algoritmos = ['bubble', 'selection', 'insertion', 'merge']
    
    # Analisar cada algoritmo
    for algo in algoritmos:
        arquivo = f'resultados_{algo}_sort.csv'
        df = carregar_resultados(arquivo)
        
        if df is not None:
            nome_algo = df['Algoritmo'].iloc[0]
            mostrar_estatisticas(df, nome_algo)
            gerar_grafico_boxplot(df, nome_algo)
            gerar_grafico_comparativo(df, nome_algo)
    
    # Comparar algoritmos
    comparar_algoritmos()
    
    print(f"\n{'='*60}")
    print(" ✅ Análise concluída!")
    print("="*60 + "\n")

if __name__ == "__main__":
    # Verificar se os arquivos CSV existem
    arquivos = ['resultados_bubble_sort.csv', 'resultados_selection_sort.csv',
                'resultados_insertion_sort.csv', 'resultados_merge_sort.csv']
    
    arquivos_faltantes = [f for f in arquivos if not os.path.exists(f)]
    
    if arquivos_faltantes:
        print(f"\n⚠️  Aviso: Os seguintes arquivos não foram encontrados:")
        for arquivo in arquivos_faltantes:
            print(f"   - {arquivo}")
        print(f"\nExecute os testes de performance no programa principal")
        print(f"(opção 12 no menu) para gerar estes arquivos.\n")
        sys.exit(1)
    
    # Verificar pandas e matplotlib
    try:
        import pandas
        import matplotlib
    except ImportError as e:
        print(f"\n❌ Erro: Pacotes obrigatórios não instalados")
        print(f"   Instale com: pip install pandas matplotlib\n")
        sys.exit(1)
    
    main()
