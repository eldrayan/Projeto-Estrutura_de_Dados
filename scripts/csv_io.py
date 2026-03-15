"""Funcoes auxiliares para exportacao simples de dados em CSV."""

import csv


def salvar_csv(nome, dados):
    """Salva uma lista de tuplas (id, nota) em arquivo CSV.

    Args:
        nome: caminho/nome do arquivo de destino.
        dados: iteravel de linhas no formato (id, nota).
    """
    with open(nome, "w", newline="") as f:
        writer = csv.writer(f)

        # cabeçalho
        writer.writerow(["id", "nota"])

        for linha in dados:
            writer.writerow(linha)

    print(f"\n✅ Dados salvos em: {nome}")
