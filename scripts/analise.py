"""Utilitarios para gerar massas de dados e criar graficos de desempenho.

Este modulo concentra:
- geracao de dados sinteticos (aleatorio, ordenado e invertido);
- carregamento robusto de resultados CSV com nomes de colunas flexiveis;
- geracao automatica de graficos para comparacao de algoritmos.
"""

import random
from pathlib import Path
import unicodedata

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

SEED = None

def configurar_seed():
    """Configura a semente global do modulo, quando definida.

    Se `SEED` estiver como `None`, mantem o comportamento pseudoaleatorio
    padrao do Python.
    """
    if SEED is not None:
        random.seed(SEED)


def gerar_dados_aleatorios(n):
    """Gera pares (id, nota) com notas aleatorias no intervalo [0, 100].

    Args:
        n: quantidade de registros.

    Returns:
        Lista de tuplas no formato (id, nota).
    """
    dados = []
    for i in range(1, n + 1):
        nota = round(random.uniform(0, 100), 2)
        dados.append((i, nota))
    return dados


def gerar_dados_ordenados(n):
    """Gera pares (id, nota) em ordem crescente de nota.

    Args:
        n: quantidade de registros.

    Returns:
        Lista de tuplas ordenadas por nota crescente.
    """
    dados = []
    passo = 100 / max(n, 1)

    for i in range(1, n + 1):
        nota = round(i * passo, 2)
        dados.append((i, nota))

    return dados


def gerar_dados_invertidos(n):
    """Gera pares (id, nota) em ordem decrescente de nota.

    Args:
        n: quantidade de registros.

    Returns:
        Lista de tuplas representando um caso invertido.
    """
    dados = []
    passo = 100 / max(n, 1)

    for i in range(n, 0, -1):
        nota = round(i * passo, 2)
        dados.append((i, nota))

    return dados


def _normalizar_texto(valor):
    """Normaliza texto para comparacoes tolerantes a variacoes.

    Remove espacos extras, converte para minusculas e remove acentos.
    Valores nulos viram string vazia.
    """
    if pd.isna(valor):
        return ""
    texto = str(valor).strip().lower()
    texto = unicodedata.normalize("NFKD", texto)
    texto = "".join(ch for ch in texto if not unicodedata.combining(ch))
    return texto


def _resolver_coluna(df, opcoes):
    """Resolve o nome real de uma coluna a partir de nomes candidatos.

    Args:
        df: DataFrame de entrada.
        opcoes: nomes possiveis para a mesma coluna logica.

    Returns:
        Nome real da coluna em `df` ou `None` se nao encontrada.
    """
    mapa = {_normalizar_texto(col): col for col in df.columns}
    for opcao in opcoes:
        chave = _normalizar_texto(opcao)
        if chave in mapa:
            return mapa[chave]
    return None


def carregar_resultados(caminho_csv="resultados.csv"):
    """Carrega e padroniza o CSV de resultados de performance.

    A funcao aceita variantes de nomes de colunas e retorna um DataFrame
    com esquema padrao para consumo dos graficos.

    Args:
        caminho_csv: caminho para o arquivo CSV.

    Returns:
        DataFrame com colunas padronizadas, incluindo normalizacoes auxiliares.

    Raises:
        FileNotFoundError: quando o arquivo nao existe.
        ValueError: quando faltam colunas obrigatorias.
    """
    caminho = Path(caminho_csv)
    if not caminho.exists():
        raise FileNotFoundError(f"Arquivo nao encontrado: {caminho_csv}")

    df = pd.read_csv(caminho)

    col_algoritmo = _resolver_coluna(df, ["Algoritmo", "Sort", "Metodo"])
    col_tamanho = _resolver_coluna(df, ["Tamanho", "N", "Quantidade", "Qtd"])
    col_tempo = _resolver_coluna(
        df,
        [
            "Tempo_Medio_ms",
            "Tempo_ms",
            "Tempo",
            "Tempo_Execucao_ms",
            "Tempo_Execucao",
            "Media_Tempo_ms",
        ],
    )
    col_entrada = _resolver_coluna(df, ["Tipo_Entrada", "Entrada", "Cenario", "Caso"])
    col_estrutura = _resolver_coluna(df, ["Estrutura", "Tipo_Estrutura", "Lista", "Implementacao"])

    obrigatorias = [col_algoritmo, col_tamanho, col_tempo]
    if any(col is None for col in obrigatorias):
        raise ValueError(
            "CSV sem colunas obrigatorias. Esperado: Algoritmo, Tamanho e Tempo (ou equivalentes)."
        )

    colunas = {
        col_algoritmo: "Algoritmo",
        col_tamanho: "Tamanho",
        col_tempo: "Tempo_Medio_ms",
    }
    if col_entrada is not None:
        colunas[col_entrada] = "Tipo_Entrada"
    if col_estrutura is not None:
        colunas[col_estrutura] = "Estrutura"

    dados = df[list(colunas.keys())].rename(columns=colunas).copy()
    dados["Tamanho"] = pd.to_numeric(dados["Tamanho"], errors="coerce")
    dados["Tempo_Medio_ms"] = pd.to_numeric(dados["Tempo_Medio_ms"], errors="coerce")
    dados = dados.dropna(subset=["Algoritmo", "Tamanho", "Tempo_Medio_ms"])
    dados["Tamanho"] = dados["Tamanho"].astype(int)

    if "Tipo_Entrada" in dados.columns:
        dados["Tipo_Entrada_norm"] = dados["Tipo_Entrada"].map(_normalizar_texto)
    else:
        dados["Tipo_Entrada_norm"] = ""

    if "Estrutura" in dados.columns:
        estrutura_norm = dados["Estrutura"].map(_normalizar_texto)
        dados["Estrutura"] = estrutura_norm.map(
            lambda s: "Dinamica" if "dinam" in s else ("Estatica" if "estat" in s else "Outra")
        )

    return dados


def _filtro_aleatorio(df):
    """Prioriza registros de caso medio/aleatorio quando disponiveis.

    Se nenhum rotulo equivalente for encontrado, retorna o DataFrame original.
    """
    if "Tipo_Entrada_norm" not in df.columns:
        return df

    candidatos = ["aleatorio", "random", "medio", "caso medio"]
    for entrada in candidatos:
        filtrado = df[df["Tipo_Entrada_norm"] == entrada]
        if not filtrado.empty:
            return filtrado
    return df


def gerar_grafico_1_comparacao_geral(df, pasta_saida):
    """Gera o grafico de barras com comparacao geral para N=10.000.

    Args:
        df: DataFrame padronizado com resultados.
        pasta_saida: diretorio onde o arquivo sera salvo.

    Returns:
        Caminho do arquivo PNG gerado.
    """
    dados = df[df["Tamanho"] == 10000]
    dados = _filtro_aleatorio(dados)
    if dados.empty:
        raise ValueError("Sem dados para o Grafico 1 (N=10000).")

    resumo = (
        dados.groupby("Algoritmo", as_index=False)["Tempo_Medio_ms"]
        .mean()
        .sort_values("Tempo_Medio_ms")
    )

    plt.figure(figsize=(11, 6))
    sns.barplot(data=resumo, x="Algoritmo", y="Tempo_Medio_ms", hue="Algoritmo", legend=False)
    plt.title("Comparacao Geral - Tempo x Algoritmo (N=10.000)")
    plt.xlabel("Algoritmo")
    plt.ylabel("Tempo medio (ms)")
    plt.tight_layout()

    destino = pasta_saida / "grafico_1_comparacao_geral_10k.png"
    plt.savefig(destino, dpi=200)
    plt.close()
    return destino


def gerar_grafico_2_curva_crescimento(df, pasta_saida):
    """Gera o grafico de linha da curva de crescimento dos algoritmos.

    Usa os tamanhos 100, 1000 e 10000 para comparar evolucao de tempo.

    Args:
        df: DataFrame padronizado com resultados.
        pasta_saida: diretorio onde o arquivo sera salvo.

    Returns:
        Caminho do arquivo PNG gerado.
    """
    tamanhos_alvo = [100, 1000, 10000]
    dados = df[df["Tamanho"].isin(tamanhos_alvo)]
    dados = _filtro_aleatorio(dados)

    if dados.empty:
        raise ValueError("Sem dados para o Grafico 2 (100, 1k, 10k).")

    resumo = (
        dados.groupby(["Algoritmo", "Tamanho"], as_index=False)["Tempo_Medio_ms"]
        .mean()
        .sort_values(["Algoritmo", "Tamanho"])
    )

    plt.figure(figsize=(11, 6))
    sns.lineplot(
        data=resumo,
        x="Tamanho",
        y="Tempo_Medio_ms",
        hue="Algoritmo",
        style="Algoritmo",
        markers=True,
        dashes=False,
    )
    plt.title("Curva de Crescimento - Tempo x Tamanho do Vetor")
    plt.xlabel("Tamanho do vetor")
    plt.ylabel("Tempo medio (ms)")
    plt.xticks(tamanhos_alvo, ["100", "1k", "10k"])
    plt.tight_layout()

    destino = pasta_saida / "grafico_2_curva_crescimento.png"
    plt.savefig(destino, dpi=200)
    plt.close()
    return destino


def gerar_grafico_3_comparativo_estrutural(df, pasta_saida):
    """Gera comparativo Dinamica vs Estatica para um algoritmo elegivel.

    Seleciona automaticamente o primeiro algoritmo (ordem alfabetica) que
    possua resultados para as duas estruturas.

    Args:
        df: DataFrame padronizado com resultados.
        pasta_saida: diretorio onde o arquivo sera salvo.

    Returns:
        Caminho do arquivo PNG gerado.
    """
    if "Estrutura" not in df.columns:
        raise ValueError("CSV sem coluna de estrutura para o Grafico 3.")

    dados = _filtro_aleatorio(df)
    pares = (
        dados.groupby("Algoritmo")["Estrutura"]
        .nunique()
        .reset_index(name="qtd")
    )
    elegiveis = pares[pares["qtd"] >= 2]["Algoritmo"].tolist()

    if not elegiveis:
        raise ValueError("Nao ha algoritmo com as duas estruturas (Dinamica e Estatica).")

    algoritmo_escolhido = sorted(elegiveis)[0]
    comparativo = dados[dados["Algoritmo"] == algoritmo_escolhido].copy()

    resumo = (
        comparativo.groupby(["Tamanho", "Estrutura"], as_index=False)["Tempo_Medio_ms"]
        .mean()
        .sort_values(["Tamanho", "Estrutura"])
    )

    plt.figure(figsize=(11, 6))
    sns.barplot(data=resumo, x="Tamanho", y="Tempo_Medio_ms", hue="Estrutura")
    plt.title(f"Comparativo Estrutural - {algoritmo_escolhido} (Dinamica vs Estatica)")
    plt.xlabel("Tamanho do vetor")
    plt.ylabel("Tempo medio (ms)")
    plt.tight_layout()

    destino = pasta_saida / "grafico_3_comparativo_estrutural.png"
    plt.savefig(destino, dpi=200)
    plt.close()
    return destino


def gerar_todos_graficos(caminho_csv="resultados.csv", pasta_saida="docs/graficos"):
    """Executa a geracao de todos os graficos e reporta sucessos/erros.

    Args:
        caminho_csv: caminho do CSV com os resultados.
        pasta_saida: pasta de destino dos arquivos de imagem.
    """
    sns.set_theme(style="whitegrid")

    df = carregar_resultados(caminho_csv)
    saida = Path(pasta_saida)
    saida.mkdir(parents=True, exist_ok=True)

    gerados = []
    erros = []

    for gerar in [
        gerar_grafico_1_comparacao_geral,
        gerar_grafico_2_curva_crescimento,
        gerar_grafico_3_comparativo_estrutural,
    ]:
        try:
            gerados.append(gerar(df, saida))
        except Exception as e:
            erros.append(f"{gerar.__name__}: {e}")

    if gerados:
        print("Graficos gerados com sucesso:")
        for arquivo in gerados:
            print(f"- {arquivo}")

    if erros:
        print("Graficos nao gerados:")
        for erro in erros:
            print(f"- {erro}")


if __name__ == "__main__":
    gerar_todos_graficos()

