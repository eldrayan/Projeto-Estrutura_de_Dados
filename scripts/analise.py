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
    col_entrada = _resolver_coluna(df, ["Tipo_Entrada", "Tipo_Dados", "Entrada", "Cenario", "Caso"])
    col_estrutura = _resolver_coluna(df, ["Estrutura", "Tipo_Estrutura", "Tipo_Lista", "Lista", "Implementacao"])

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
            lambda s: "Dinamica" if "dinam" in s else ("Estatica" if "estat" in s else ("Vetor" if "vetor" in s else "Outra"))
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


def _gerar_grafico_auxiliar_tempos_baixos(
    resumo,
    x,
    y,
    hue,
    pasta_saida,
    nome_arquivo,
    titulo,
    xlabel,
    ylabel,
    titulo_legenda=None,
):
    """Gera um grafico auxiliar apenas com a faixa de tempos baixos."""
    tempos_baixos = resumo.loc[resumo[y] <= 10, y]
    if tempos_baixos.empty:
        return None

    limite_zoom = max(tempos_baixos.max() * 1.25, 1)
    fig, ax = plt.subplots(figsize=(10, 5), constrained_layout=True)
    sns.barplot(data=resumo, x=x, y=y, hue=hue, ax=ax)
    ax.set_ylim(0, limite_zoom)
    ax.set_title(titulo)
    ax.set_xlabel(xlabel)
    ax.set_ylabel(ylabel)
    if titulo_legenda is not None:
        ax.legend(title=titulo_legenda, bbox_to_anchor=(1.02, 1), loc="upper left")
    else:
        legenda = ax.get_legend()
        if legenda is not None:
            legenda.remove()

    destino = pasta_saida / nome_arquivo
    fig.savefig(destino, dpi=200)
    plt.close(fig)
    return destino


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

    fig, ax = plt.subplots(figsize=(11, 6), constrained_layout=True)
    sns.barplot(data=resumo, x="Algoritmo", y="Tempo_Medio_ms", hue="Algoritmo", legend=False, ax=ax)
    ax.set_title("Comparacao Geral - Tempo x Algoritmo (N=10.000)")
    ax.set_xlabel("Algoritmo")
    ax.set_ylabel("Tempo medio (ms)")

    destino = pasta_saida / "grafico_1_comparacao_geral_10k.png"
    fig.savefig(destino, dpi=200)
    plt.close(fig)
    auxiliar = _gerar_grafico_auxiliar_tempos_baixos(
        resumo,
        "Algoritmo",
        "Tempo_Medio_ms",
        "Algoritmo",
        pasta_saida,
        "grafico_1_comparacao_geral_10k_zoom.png",
        "Comparacao Geral - Tempos Ate 10 ms (N=10.000)",
        "Algoritmo",
        "Tempo medio (ms)",
    )
    return [destino] + ([auxiliar] if auxiliar else [])


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

    fig, ax = plt.subplots(figsize=(11, 6), constrained_layout=True)
    sns.barplot(data=resumo, x="Tamanho", y="Tempo_Medio_ms", hue="Estrutura", ax=ax)
    ax.set_title(f"Comparativo Estrutural - {algoritmo_escolhido} (Dinamica vs Estatica)")
    ax.set_xlabel("Tamanho do vetor")
    ax.set_ylabel("Tempo medio (ms)")

    destino = pasta_saida / "grafico_3_comparativo_estrutural.png"
    fig.savefig(destino, dpi=200)
    plt.close(fig)
    auxiliar = _gerar_grafico_auxiliar_tempos_baixos(
        resumo,
        "Tamanho",
        "Tempo_Medio_ms",
        "Estrutura",
        pasta_saida,
        "grafico_3_comparativo_estrutural_zoom.png",
        f"Comparativo Estrutural - Tempos Ate 10 ms ({algoritmo_escolhido})",
        "Tamanho do vetor",
        "Tempo medio (ms)",
        "Estrutura",
    )
    return [destino] + ([auxiliar] if auxiliar else [])


def gerar_grafico_4_por_tipo_entrada(df, pasta_saida):
    """Gera grafico agrupado comparando algoritmos em cada tipo de entrada.

    Mostra barras agrupadas por tipo de entrada (Aleatorio, Ordenado, Invertido)
    para N=10.000, permitindo ver qual algoritmo se beneficia ou sofre em cada cenario.
    """
    if "Tipo_Entrada" not in df.columns:
        raise ValueError("Sem coluna Tipo_Entrada para o Grafico 4.")

    dados = df[df["Tamanho"] == 10000].copy()
    if dados.empty:
        raise ValueError("Sem dados N=10000 para o Grafico 4.")

    resumo = (
        dados.groupby(["Tipo_Entrada", "Algoritmo"], as_index=False)["Tempo_Medio_ms"]
        .mean()
        .sort_values(["Tipo_Entrada", "Tempo_Medio_ms"])
    )

    fig, ax = plt.subplots(figsize=(13, 6), constrained_layout=True)
    sns.barplot(data=resumo, x="Tipo_Entrada", y="Tempo_Medio_ms", hue="Algoritmo", ax=ax)
    plt.title("Comparacao por Tipo de Entrada (N=10.000)")
    plt.xlabel("Tipo de Entrada")
    plt.ylabel("Tempo medio (ms)")
    plt.legend(title="Algoritmo", bbox_to_anchor=(1.02, 1), loc="upper left")

    destino = pasta_saida / "grafico_4_por_tipo_entrada.png"
    fig.savefig(destino, dpi=200)
    plt.close(fig)
    auxiliar = _gerar_grafico_auxiliar_tempos_baixos(
        resumo,
        "Tipo_Entrada",
        "Tempo_Medio_ms",
        "Algoritmo",
        pasta_saida,
        "grafico_4_por_tipo_entrada_zoom.png",
        "Comparacao por Tipo de Entrada - Tempos Ate 10 ms",
        "Tipo de Entrada",
        "Tempo medio (ms)",
        "Algoritmo",
    )
    return [destino] + ([auxiliar] if auxiliar else [])


def gerar_grafico_5_por_algoritmo(df, pasta_saida):
    """Gera um grafico individual por algoritmo mostrando tempo x tamanho x tipo de entrada.

    Produz um subplot para cada algoritmo encontrado no DataFrame.
    """
    if "Tipo_Entrada" not in df.columns:
        raise ValueError("Sem coluna Tipo_Entrada para o Grafico 5.")

    algoritmos = sorted(df["Algoritmo"].unique())
    n_alg = len(algoritmos)
    if n_alg == 0:
        raise ValueError("Sem algoritmos para o Grafico 5.")

    cols = min(n_alg, 3)
    rows = (n_alg + cols - 1) // cols

    fig, axes = plt.subplots(rows, cols, figsize=(7 * cols, 5 * rows), squeeze=False)

    tamanhos_alvo = [100, 1000, 10000]

    for idx, algo in enumerate(algoritmos):
        ax = axes[idx // cols][idx % cols]
        dados_algo = df[(df["Algoritmo"] == algo) & (df["Tamanho"].isin(tamanhos_alvo))]

        resumo = (
            dados_algo.groupby(["Tamanho", "Tipo_Entrada"], as_index=False)["Tempo_Medio_ms"]
            .mean()
            .sort_values("Tamanho")
        )

        for entrada in resumo["Tipo_Entrada"].unique():
            sub = resumo[resumo["Tipo_Entrada"] == entrada]
            ax.plot(sub["Tamanho"], sub["Tempo_Medio_ms"], marker="o", label=entrada)

        ax.set_title(algo, fontweight="bold")
        ax.set_xlabel("Tamanho")
        ax.set_ylabel("Tempo medio (ms)")
        ax.set_xticks(tamanhos_alvo)
        ax.set_xticklabels(["100", "1k", "10k"])
        ax.legend(fontsize=8)
        ax.grid(True, alpha=0.3)

    for idx in range(n_alg, rows * cols):
        axes[idx // cols][idx % cols].set_visible(False)

    fig.suptitle("Desempenho Individual por Algoritmo", fontsize=16, fontweight="bold")
    fig.tight_layout(rect=[0, 0, 1, 0.96])

    destino = pasta_saida / "grafico_5_por_algoritmo.png"
    fig.savefig(destino, dpi=200)
    plt.close(fig)
    return destino


def gerar_grafico_6_vetor_x_dinamica_x_estatica(df, pasta_saida):
    """Gera comparativo das 3 estruturas (Vetor, Dinamica, Estatica) para todos os algoritmos.

    Usa N=10.000 e dados aleatorios como referencia.
    """
    if "Estrutura" not in df.columns:
        raise ValueError("Sem coluna Estrutura para o Grafico 6.")

    dados = df[df["Tamanho"] == 10000]
    dados = _filtro_aleatorio(dados)

    estruturas_presentes = dados["Estrutura"].nunique()
    if estruturas_presentes < 2:
        raise ValueError("Menos de 2 estruturas disponiveis para o Grafico 6.")

    resumo = (
        dados.groupby(["Algoritmo", "Estrutura"], as_index=False)["Tempo_Medio_ms"]
        .mean()
        .sort_values(["Algoritmo", "Tempo_Medio_ms"])
    )

    fig, ax = plt.subplots(figsize=(13, 6), constrained_layout=True)
    sns.barplot(data=resumo, x="Algoritmo", y="Tempo_Medio_ms", hue="Estrutura", ax=ax)
    ax.set_title("Vetor x Lista Dinamica x Lista Estatica (N=10.000, Aleatorio)")
    ax.set_xlabel("Algoritmo")
    ax.set_ylabel("Tempo medio (ms)")
    ax.legend(title="Estrutura")

    destino = pasta_saida / "grafico_6_vetor_x_dinamica_x_estatica.png"
    fig.savefig(destino, dpi=200)
    plt.close(fig)
    auxiliar = _gerar_grafico_auxiliar_tempos_baixos(
        resumo,
        "Algoritmo",
        "Tempo_Medio_ms",
        "Estrutura",
        pasta_saida,
        "grafico_6_vetor_x_dinamica_x_estatica_zoom.png",
        "Vetor x Dinamica x Estatica - Tempos Ate 10 ms",
        "Algoritmo",
        "Tempo medio (ms)",
        "Estrutura",
    )
    return [destino] + ([auxiliar] if auxiliar else [])


def gerar_grafico_7_boxplot_distribuicao(df, pasta_saida):
    """Gera boxplot da distribuicao de tempos por algoritmo em N=10.000.

    Mostra dispersao, mediana, quartis e outliers para cada algoritmo.
    """
    dados = df[df["Tamanho"] == 10000]
    dados = _filtro_aleatorio(dados)

    if dados.empty:
        raise ValueError("Sem dados N=10000 para o Grafico 7.")

    ordem = (
        dados.groupby("Algoritmo")["Tempo_Medio_ms"]
        .median()
        .sort_values()
        .index.tolist()
    )

    plt.figure(figsize=(12, 6))
    sns.boxplot(data=dados, x="Algoritmo", y="Tempo_Medio_ms", order=ordem, hue="Algoritmo", legend=False)
    plt.title("Distribuicao de Tempos por Algoritmo (N=10.000, Aleatorio)")
    plt.xlabel("Algoritmo")
    plt.ylabel("Tempo (ms)")
    plt.tight_layout()

    destino = pasta_saida / "grafico_7_boxplot_distribuicao.png"
    plt.savefig(destino, dpi=200)
    plt.close()
    return destino


def gerar_grafico_8_heatmap(df, pasta_saida):
    """Gera heatmap de tempo medio: algoritmo x tamanho.

    Usa dados aleatorios e estrutura Vetor como referencia principal.
    """
    dados = _filtro_aleatorio(df)

    if "Estrutura" in dados.columns:
        vetor = dados[dados["Estrutura"] == "Vetor"]
        if not vetor.empty:
            dados = vetor

    if dados.empty:
        raise ValueError("Sem dados para o Grafico 8 (heatmap).")

    tabela = dados.pivot_table(
        values="Tempo_Medio_ms",
        index="Algoritmo",
        columns="Tamanho",
        aggfunc="mean",
    )

    tabela = tabela.sort_index()

    plt.figure(figsize=(10, 6))
    sns.heatmap(tabela, annot=True, fmt=".4f", cmap="YlOrRd", linewidths=0.5)
    plt.title("Heatmap - Tempo Medio (ms): Algoritmo x Tamanho")
    plt.xlabel("Tamanho")
    plt.ylabel("Algoritmo")
    plt.tight_layout()

    destino = pasta_saida / "grafico_8_heatmap_algoritmo_tamanho.png"
    plt.savefig(destino, dpi=200)
    plt.close()
    return destino


def gerar_grafico_9_ranking(df, pasta_saida):
    """Gera tabela/grafico de ranking medio por cenario.

    Para cada combinacao (tamanho, tipo_entrada), classifica os algoritmos
    do mais rapido ao mais lento e calcula a posicao media de cada um.
    """
    if "Tipo_Entrada" not in df.columns:
        raise ValueError("Sem coluna Tipo_Entrada para o Grafico 9.")

    if "Estrutura" in df.columns:
        vetor = df[df["Estrutura"] == "Vetor"]
        if not vetor.empty:
            dados = vetor.copy()
        else:
            dados = df.copy()
    else:
        dados = df.copy()

    resumo = (
        dados.groupby(["Tamanho", "Tipo_Entrada", "Algoritmo"], as_index=False)["Tempo_Medio_ms"]
        .mean()
    )

    resumo["Ranking"] = resumo.groupby(["Tamanho", "Tipo_Entrada"])["Tempo_Medio_ms"].rank(method="min")

    ranking_medio = (
        resumo.groupby("Algoritmo", as_index=False)["Ranking"]
        .mean()
        .sort_values("Ranking")
    )

    plt.figure(figsize=(10, 6))
    cores = sns.color_palette("viridis", len(ranking_medio))
    bars = plt.barh(ranking_medio["Algoritmo"], ranking_medio["Ranking"], color=cores)

    for bar, val in zip(bars, ranking_medio["Ranking"]):
        plt.text(bar.get_width() + 0.05, bar.get_y() + bar.get_height() / 2,
                 f"{val:.2f}", va="center", fontweight="bold")

    plt.xlabel("Posicao Media no Ranking (menor = melhor)")
    plt.ylabel("Algoritmo")
    plt.title("Ranking Medio por Cenario (Vetor)")
    plt.gca().invert_yaxis()
    plt.tight_layout()

    destino = pasta_saida / "grafico_9_ranking_medio.png"
    plt.savefig(destino, dpi=200)
    plt.close()
    return destino


def carregar_todos_resultados(pasta="."):
    """Concatena todos os CSVs resultados_*.csv encontrados na pasta.

    Args:
        pasta: diretorio onde procurar os arquivos CSV.

    Returns:
        DataFrame unificado com todos os resultados.

    Raises:
        FileNotFoundError: quando nenhum CSV e encontrado.
    """
    arquivos = sorted(Path(pasta).glob("resultados_*.csv"))
    if not arquivos:
        raise FileNotFoundError(f"Nenhum arquivo resultados_*.csv encontrado em {pasta}")

    frames = []
    for arq in arquivos:
        try:
            frames.append(carregar_resultados(str(arq)))
        except Exception as e:
            print(f"Aviso: ignorando {arq.name}: {e}")

    if not frames:
        raise FileNotFoundError("Nenhum CSV valido encontrado.")

    return pd.concat(frames, ignore_index=True)


def gerar_todos_graficos(caminho_csv=None, pasta_saida="docs/graficos"):
    """Executa a geracao de todos os graficos e reporta sucessos/erros.

    Args:
        caminho_csv: caminho de um CSV especifico, ou None para concatenar
                     todos os resultados_*.csv da raiz do projeto.
        pasta_saida: pasta de destino dos arquivos de imagem.
    """
    sns.set_theme(style="whitegrid")

    if caminho_csv is not None:
        df = carregar_resultados(caminho_csv)
    else:
        df = carregar_todos_resultados()
    saida = Path(pasta_saida)
    saida.mkdir(parents=True, exist_ok=True)

    gerados = []
    erros = []

    for gerar in [
        gerar_grafico_1_comparacao_geral,
        gerar_grafico_2_curva_crescimento,
        gerar_grafico_3_comparativo_estrutural,
        gerar_grafico_4_por_tipo_entrada,
        gerar_grafico_5_por_algoritmo,
        gerar_grafico_6_vetor_x_dinamica_x_estatica,
        gerar_grafico_7_boxplot_distribuicao,
        gerar_grafico_8_heatmap,
        gerar_grafico_9_ranking,
    ]:
        try:
            resultado = gerar(df, saida)
            if isinstance(resultado, (list, tuple)):
                gerados.extend(resultado)
            else:
                gerados.append(resultado)
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
    import sys
    if len(sys.argv) > 1:
        gerar_todos_graficos(caminho_csv=sys.argv[1])
    else:
        gerar_todos_graficos()

