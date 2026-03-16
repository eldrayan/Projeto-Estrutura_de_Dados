#!/usr/bin/env python3
"""
Script para análise de performance dos algoritmos de ordenação (Versão Simplificada)
Lê os arquivos CSV gerados e gera estatísticas
Não requer pandas, apenas bibliotecas padrão do Python
"""

import csv
import os
import sys
from collections import defaultdict
from statistics import mean, stdev, median

def carregar_csv(arquivo):
    """Carrega os dados de um arquivo CSV"""
    if not os.path.exists(arquivo):
        return None
    
    dados = []
    try:
        with open(arquivo, 'r') as f:
            reader = csv.DictReader(f)
            for linha in reader:
                dados.append({
                    'algoritmo': linha['Algoritmo'],
                    'tipo_lista': linha['Tipo_Lista'],
                    'tipo_dados': linha['Tipo_Dados'],
                    'tamanho': int(linha['Tamanho']),
                    'tempo': float(linha['Tempo_ms'])
                })
    except Exception as e:
        print(f"❌ Erro ao ler {arquivo}: {e}")
        return None
    
    return dados if dados else None

def calcular_estatisticas(tempos):
    """Calcula estatísticas descritivas"""
    if not tempos:
        return None
    
    tempos_sorted = sorted(tempos)
    n = len(tempos)
    minimo = min(tempos)
    maximo = max(tempos)
    media = mean(tempos)
    mediana_val = median(tempos)
    
    try:
        desvio = stdev(tempos) if n > 1 else 0
    except:
        desvio = 0
    
    return {
        'count': n,
        'min': minimo,
        'max': maximo,
        'mean': media,
        'median': mediana_val,
        'std': desvio
    }

def analisar_arquivo(arquivo):
    """Analisa um arquivo CSV de resultados"""
    dados = carregar_csv(arquivo)
    
    if dados is None:
        return None
    
    print(f"\n{'='*80}")
    print(f" {arquivo}")
    print(f"{'='*80}\n")
    
    # Agrupar por tipo de dados
    por_tipo = defaultdict(list)
    for item in dados:
        por_tipo[item['tipo_dados']].append(item['tempo'])
    
    # Mostrar estatísticas
    print(f"{'Tipo de Dados':<20} {'Execuções':<12} {'Mín (ms)':<12} {'Máx (ms)':<12} {'Média (ms)':<12} {'Mediana':<12} {'Desvio':<12}")
    print(f"{'-'*92}")
    
    stats_por_tipo = {}
    for tipo in ['Aleatório', 'Ordenado', 'Invertido']:
        if tipo in por_tipo:
            tempos = por_tipo[tipo]
            stats = calcular_estatisticas(tempos)
            stats_por_tipo[tipo] = stats
            
            print(f"{tipo:<20} {stats['count']:<12} {stats['min']:<12.4f} {stats['max']:<12.4f} "
                  f"{stats['mean']:<12.4f} {stats['median']:<12.4f} {stats['std']:<12.4f}")
    
    # Tempo total
    todos_tempos = [item['tempo'] for item in dados]
    stats_geral = calcular_estatisticas(todos_tempos)
    print(f"{'-'*92}")
    print(f"{'TOTAL':<20} {stats_geral['count']:<12} {stats_geral['min']:<12.4f} {stats_geral['max']:<12.4f} "
          f"{stats_geral['mean']:<12.4f} {stats_geral['median']:<12.4f} {stats_geral['std']:<12.4f}")
    
    return stats_por_tipo, stats_geral

def comparar_algoritmos():
    """Compara todos os algoritmos disponíveis"""
    algoritmos = {
        'bubble': 'resultados_bubble_sort.csv',
        'selection': 'resultados_selection_sort.csv',
        'insertion': 'resultados_insertion_sort.csv',
        'merge': 'resultados_merge_sort.csv'
    }
    
    print(f"\n{'='*80}")
    print(f" COMPARAÇÃO ENTRE ALGORITMOS")
    print(f"{'='*80}\n")
    
    medias_por_algoritmo = {}
    
    for nome_curto, arquivo in algoritmos.items():
        dados = carregar_csv(arquivo)
        if dados:
            tempos = [item['tempo'] for item in dados]
            media = mean(tempos)
            medias_por_algoritmo[nome_curto.replace('_sort', '').title()] = media
            print(f"✅ {arquivo:<40} - Tempo médio: {media:8.4f}ms")
        else:
            print(f"❌ {arquivo:<40} - NÃO ENCONTRADO")
    
    if medias_por_algoritmo:
        print(f"\n{'-'*80}")
        print(f"{'Algoritmo':<20} {'Tempo Médio (ms)':<20} {'Ranking':<20}")
        print(f"{'-'*80}")
        
        # Ordenar por tempo
        ranking = sorted(medias_por_algoritmo.items(), key=lambda x: x[1])
        for rank, (algo, tempo) in enumerate(ranking, 1):
            print(f"{algo:<20} {tempo:<20.4f} #{rank}")

def criar_arquivo_resumo():
    """Cria um arquivo de resumo dos testes"""
    algoritmos = {
        'bubble': 'resultados_bubble_sort.csv',
        'selection': 'resultados_selection_sort.csv',
        'insertion': 'resultados_insertion_sort.csv',
        'merge': 'resultados_merge_sort.csv'
    }
    
    resumo = []
    resumo.append("RESUMO DOS TESTES DE PERFORMANCE\n")
    resumo.append("=" * 80 + "\n\n")
    
    for nome_curto, arquivo in algoritmos.items():
        dados = carregar_csv(arquivo)
        if dados:
            por_tipo = defaultdict(list)
            for item in dados:
                por_tipo[item['tipo_dados']].append(item['tempo'])
            
            resumo.append(f"\n{arquivo}\n")
            resumo.append("-" * 80 + "\n")
            
            for tipo in ['Aleatório', 'Ordenado', 'Invertido']:
                if tipo in por_tipo:
                    tempos = por_tipo[tipo]
                    stats = calcular_estatisticas(tempos)
                    resumo.append(f"  {tipo:<15}: Média={stats['mean']:8.4f}ms  Mín={stats['min']:8.4f}ms  Máx={stats['max']:8.4f}ms  Std={stats['std']:8.4f}ms\n")
    
    with open('resumo_performance.txt', 'w') as f:
        f.writelines(resumo)
    
    print(f"\n✅ Resumo salvo em: resumo_performance.txt")

def main():
    """Função principal"""
    print("\n" + "="*80)
    print(" ANALISADOR DE PERFORMANCE DE ALGORITMOS")
    print("="*80)
    
    # Analisar cada arquivo
    for arquivo in ['resultados_bubble_sort.csv', 'resultados_selection_sort.csv',
                    'resultados_insertion_sort.csv', 'resultados_merge_sort.csv']:
        analisar_arquivo(arquivo)
    
    # Comparar algoritmos
    comparar_algoritmos()
    
    # Criar resumo em arquivo
    criar_arquivo_resumo()
    
    print(f"\n{'='*80}")
    print(" ✅ Análise concluída!")
    print("="*80 + "\n")

if __name__ == "__main__":
    # Verificar se pelo menos um arquivo existe
    arquivos = ['resultados_bubble_sort.csv', 'resultados_selection_sort.csv',
                'resultados_insertion_sort.csv', 'resultados_merge_sort.csv']
    
    arquivos_existentes = [f for f in arquivos if os.path.exists(f)]
    
    if not arquivos_existentes:
        print(f"\n⚠️  AVISO: Nenhum arquivo de resultados encontrado!")
        print(f"\nArquivos esperados:")
        for arquivo in arquivos:
            print(f"   - {arquivo}")
        print(f"\nExecute os testes de performance no programa principal:")
        print(f"   1. Execute: ./programa")
        print(f"   2. Escolha a opção [12] para executar todos os testes de performance")
        print(f"   3. Aguarde a conclusão (pode levar alguns minutos)")
        print(f"   4. Execute este script novamente\n")
        sys.exit(1)
    
    main()
