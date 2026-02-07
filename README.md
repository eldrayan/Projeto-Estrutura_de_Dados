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
