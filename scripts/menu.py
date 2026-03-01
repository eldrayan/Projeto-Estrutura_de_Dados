from gerador import (
    configurar_seed,
    gerar_dados_aleatorios,
    gerar_dados_ordenados,
    gerar_dados_invertidos
)

from csv_io import salvar_csv


def escolher_tamanho():
    print("\nEscolha o tamanho da entrada:")
    print("1 - 100")
    print("2 - 1000")
    print("3 - 10000")

    escolha = input("")

    return {
        "1": 100,
        "2": 1000,
        "3": 10000
    }.get(escolha)


def escolher_tipo():
    print("\nTipo de entrada:")
    print("1 - Aleatório (caso médio)")
    print("2 - Ordenado (melhor caso)")
    print("3 - Invertido (pior caso)")

    return input("")


def menu():
    configurar_seed()

    while True:
        print("\n==============================")
        print(" GERADOR DE MASSA DE DADOS")
        print("==============================")
        print("1 - Gerar dados")
        print("2 - Sair")

        op = input("")

        if op == "2":
            print("Encerrado.")
            break

        if op != "1":
            continue

        n = escolher_tamanho()
        if not n:
            print("Opção inválida.")
            continue

        tipo = escolher_tipo()

        if tipo == "1":
            dados = gerar_dados_aleatorios(n)
            nome = f"dados_aleatorio_{n}.csv"

        elif tipo == "2":
            dados = gerar_dados_ordenados(n)
            nome = f"dados_ordenado_{n}.csv"

        elif tipo == "3":
            dados = gerar_dados_invertidos(n)
            nome = f"dados_invertido_{n}.csv"

        else:
            print("Tipo inválido.")
            continue

        salvar_csv(nome, dados)


if __name__ == "__main__":
    menu()
