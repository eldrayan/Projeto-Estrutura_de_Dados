# 📊 Projeto: Ranking de Alunos e Análise de Algoritmos

> Trabalho da disciplina de Estrutura de Dados - Engenharia de Software (UFCA).

Este projeto consiste na implementação e análise comparativa de desempenho de **5 Algoritmos de Ordenação** aplicados sobre duas estruturas de dados distintas: **Lista Encadeada Dinâmica** e **Lista Encadeada Estática**.

O objetivo é gerenciar um ranking de alunos (ID e Nota) e medir o tempo de execução (em ms/ns) para diferentes volumes de dados e cenários de ordenação.

## 👥 Equipe e Responsabilidades

| Integrante | Algoritmo (Core) | Responsabilidade Extra |
| :--- | :--- | :--- |
| **Rayan** | Bubble Sort | Implementação da **Lista Estática** |
| **Samuel** | Selection Sort | Implementação da **Lista Dinâmica** |
| **Diogo** | Insertion Sort | Gerador de Dados, Menu e Integração |
| **Junio** | Quick Sort | Análise Teórica e Complexidade |
| **Pedro** | Merge Sort | Script de Análise de Dados (Python) |
| **Lucas** | Merge Sort (Support) | Sistema de Benchmarking, Documentação e Slides |

## 🛠️ Tecnologias Utilizadas

* **Linguagem C:** Implementação das estruturas de dados e algoritmos de ordenação.
* **Python (Pandas/Matplotlib):** Geração de gráficos a partir dos logs de execução (.csv).
* **GCC:** Compilador padrão utilizado.

## 📂 Estrutura do Projeto

```text
├── src/
│   ├── main.c           # Menu principal e loop de testes
│   ├── listas/
│   │   ├── dinamica.c   # Implementação com ponteiros (malloc/free)
│   │   └── estatica.c   # Implementação com vetor pré-alocado
│   ├── algoritmos/
│   │   ├── bubble.c
│   │   ├── insertion.c
│   │   ├── selection.c
│   │   ├── quick.c
│   │   └── merge.c
│   └── utils/
│       ├── gerador.c    # Gera dados (Aleatório, Ordenado, Inverso)
│       └── timer.c      # Medição de tempo e exportação CSV
├── include/             # Arquivos de cabeçalho (.h)
├── scripts/
│   └── analise.py       # Script Python para gerar os gráficos
├── docs/                # Documentação, Artigo IEEE e Slides
├── resultados.csv       # Arquivo gerado automaticamente após execução
└── README.md
```

## ⚙️ Funcionalidades

1. **Estruturas de Dados**
   * **Lista Dinâmica:** Alocação de memória sob demanda.
   * **Lista Estática:** Vetor com gerenciamento manual de índices livres.

2. **Algoritmos de Ordenação**
   * Todos os algoritmos abaixo foram testados nos cenários de **Melhor Caso** (já ordenado), **Caso Médio** (aleatório) e **Pior Caso** (inversamente ordenado):
     * Bubble Sort
     * Insertion Sort
     * Selection Sort
     * Quick Sort
     * Merge Sort

3. **Cenários de Teste**
   * Volumes de dados testados: `100`, `1.000` e `10.000` registros.

---

## 🚀 Como Executar

### Pré-requisitos
* Compilador C (GCC)
* Python 3 + Bibliotecas (para os gráficos):

```bash
pip install pandas matplotlib seaborn
```

# Passo 1: Compilar e Rodar (Linguagem C)

No terminal, navegue até a raiz do projeto e compile:
```bash
# Compilação simples (exemplo)
gcc src/main.c src/listas/*.c src/algoritmos/*.c src/utils/*.c -I include -o ranking_app

# Executar
./ranking_app
```

Ao executar, selecione a opção "Rodar Benchmarking Completo". O programa executará os 100 testes exigidos e gerará o arquivo `resultados.csv` na raiz.

# Passo 2: Gerar Gráficos (Python)

Após gerar o CSV, execute o script de análise:
```bash
python scripts/analise.py
```

Os gráficos comparativos serão salvos na pasta `docs/graficos/`.

# 📈 Metodologia de Avaliação

A métrica principal é o **Tempo de Execução**, excluindo o tempo de geração dos dados e input/output. Cada experimento é repetido 100 vezes, e a média aritmética é utilizada para os gráficos finais, garantindo confiabilidade estatística.

# 📄 Entregáveis

* Código Fonte em C.
* Artigo formatado (IEEE) com análise teórica e empírica.
* Apresentação de slides para defesa.

Projeto desenvolvido para a **Universidade Federal do Cariri (UFCA)**.

---
