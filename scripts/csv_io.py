import csv


def salvar_csv(nome, dados):
    with open(nome, "w", newline="") as f:
        writer = csv.writer(f)

        # cabeçalho
        writer.writerow(["id", "nota"])

        for linha in dados:
            writer.writerow(linha)

    print(f"\n✅ Dados salvos em: {nome}")
