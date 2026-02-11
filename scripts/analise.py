import random

SEED = None

def configurar_seed():
    if SEED is not None:
        random.seed(SEED)


def gerar_dados_aleatorios(n):
    dados = []
    for i in range(1, n + 1):
        nota = round(random.uniform(0, 100), 2)
        dados.append((i, nota))
    return dados


def gerar_dados_ordenados(n):
    dados = []
    passo = 100 / max(n, 1)

    for i in range(1, n + 1):
        nota = round(i * passo, 2)
        dados.append((i, nota))

    return dados


def gerar_dados_invertidos(n):
    dados = []
    passo = 100 / max(n, 1)

    for i in range(n, 0, -1):
        nota = round(i * passo, 2)
        dados.append((i, nota))

    return dados
