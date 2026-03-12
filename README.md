# Projeto: Ranking de Alunos e Análise de Algoritmos

> Trabalho da disciplina de Estrutura de Dados - Engenharia de Software (UFCA).

Este projeto consiste na implementação e análise comparativa de desempenho de **5 Algoritmos de Ordenação** aplicados sobre duas estruturas de dados distintas: **Lista Encadeada Dinâmica** e **Lista Encadeada Estática**.

O objetivo é gerenciar um ranking de alunos (ID e Nota) e medir o tempo de execução (em milissegundos) para diferentes volumes de dados e cenários de ordenação.

## Equipe e Responsabilidades

| Integrante | Algoritmo Principal | Responsabilidade Extra |
|------------|---------------------|------------------------|
| **Elder Rayan** | Bubble Sort | Implementação da **Lista Estática** |
| **Samuel Wagner** | Selection Sort | Implementação da **Lista Dinâmica** |
| **Diogo Gomes** | Insertion Sort | Gerador de Dados, Menu e Integração |
| **Manoel Junio** | Quick Sort | Análise Teórica e Complexidade |
| **Pedro Yan** | Merge Sort | Script de Análise de Dados (Python) |
| **Antonio Neto** | Quick Sort (Suporte) | Sistema de Benchmarking, Documentação e Slides |

## Tecnologias Utilizadas

* **Linguagem C:** Implementação das estruturas de dados e algoritmos de ordenação
* **Python:** Scripts para análise de dados e geração de gráficos (pandas, matplotlib)
* **LaTeX:** Documentação acadêmica no formato IEEE
* **GCC/Make:** Sistema de compilação

## Estrutura do Projeto

```text
├── src/
│   ├── main.c                  # Menu principal e sistema de testes
│   ├── listas/
│   │   ├── dinamica.c          # Lista encadeada com alocação dinâmica
│   │   └── estatica.c          # Lista encadeada com vetor pré-alocado
│   ├── algoritmos/
│   │   ├── bubble.c
│   │   ├── insertion.c
│   │   ├── selection.c
│   │   ├── quick.c
│   │   └── merge.c
│   └── utils/
│       ├── gerador.c           # Gerador de dados de teste
│       ├── timer.c             # Sistema de medição de tempo
│       ├── csv_io.c            # Exportação de resultados em CSV
│       └── merge_utils.c       # Funções auxiliares do Merge Sort
├── include/                    # Headers (.h)
├── tests/                      # Testes unitários e de performance
│   ├── teste_performance.c     # Sistema de benchmarking
│   ├── teste_bubble.c
│   ├── teste_insertion.c
│   ├── teste_selection.c
│   ├── teste_merge.c
│   └── testes_manuais.c
├── scripts/                    # Scripts Python
│   ├── menu.py                 # Interface de menu Python
│   ├── analise.py              # Gerador de dados
│   └── analise_performance_simples.py  # Análise estatística básica
├── docs/
│   ├── Trabalho.md             # Especificação do trabalho
│   └── artigo_desenvolvimento_analise.tex  # Artigo IEEE em LaTeX
├── makefile                    # Sistema de build
├── performance.md              # Documentação do sistema de medição
└── README.md
```

## Funcionalidades

1. **Estruturas de Dados**
   * **Lista Dinâmica:** Alocação de memória sob demanda usando malloc/free
   * **Lista Estática:** Vetor pré-alocado com gerenciamento manual de índices livres

2. **Algoritmos de Ordenação**
   
   Implementação completa de 5 algoritmos testados em três cenários:
   * **Melhor Caso:** Dados já ordenados
   * **Caso Médio:** Dados aleatórios
   * **Pior Caso:** Dados inversamente ordenados
   
   Algoritmos implementados:
   * Bubble Sort
   * Insertion Sort
   * Selection Sort
   * Quick Sort
   * Merge Sort

3. **Sistema de Medição de Performance**
   * Medição precisa de tempo usando clock()
   * 100 repetições por configuração para garantir confiabilidade estatística
   * Exportação automática de resultados em formato CSV
   * Suporte a múltiplos tamanhos de entrada: 100, 1.000, 10.000 elementos

4. **Análise e Documentação**
   * Artigo acadêmico em LaTeX (formato IEEE)
   * Análise teórica de complexidade Big-O
   * Scripts Python para análise estatística

## Como Executar

### Pré-requisitos

* **Compilador C:** GCC ou compatível
* **Make:** Para usar o sistema de build automatizado
* **Python 3.x:** (Opcional) Para análise estatística
  ```bash
  pip install pandas matplotlib
  ```

### Compilação

#### Usando Make (Recomendado)

```bash
# Compilar o programa principal
make

# Executar
./programa.exe
```

#### Compilação Manual

```bash
gcc src/main.c src/listas/*.c src/algoritmos/*.c src/utils/*.c -I include -o programa.exe

# Executar
./programa.exe
```

### Uso do Programa

O programa oferece as seguintes opções principais:

1. **Testes Manuais:** Testa algoritmos individualmente com dados pequenos
2. **Testes de Performance:** Executa benchmarking completo com 100 repetições
3. **Exportação CSV:** Gera arquivos de resultados para análise posterior

Exemplo de uso:
```
Menu Principal:
1. Testar Bubble Sort
2. Testar Selection Sort
...
8. Performance: Bubble Sort (100 execuções)
12. Performance: Todos os Algoritmos
...
```

### Análise de Resultados (Opcional)

Após executar os testes de performance, você pode usar os scripts Python para análise:

```bash
# Análise estatística simples
python scripts/analise_performance_simples.py

# Menu interativo Python
python scripts/menu.py
```

Os arquivos CSV gerados seguem o formato:
```
Algoritmo,Tipo_Lista,Tipo_Dados,Tamanho,Tempo_ms
Bubble Sort,Vetor,Aleatório,1000,15.2345
...
```

## Metodologia de Avaliação

A métrica principal é o **Tempo de Execução** medido em milissegundos, excluindo o tempo de:
* Geração dos dados
* Operações de entrada/saída
* Impressão de resultados

Cada experimento é repetido **100 vezes**, e a **média aritmética** é calculada para garantir confiabilidade estatística e minimizar variações causadas por fatores externos.

### Cenários de Teste

| Tamanho | Tipo de Dados | Propósito |
|---------|---------------|-----------|
| 100 elementos | Aleatório, Ordenado, Invertido | Caso pequeno |
| 1.000 elementos | Aleatório, Ordenado, Invertido | Caso médio |
| 10.000 elementos | Aleatório, Ordenado, Invertido | Caso grande |

## Documentação Adicional

* **performance.md:** Detalhes do sistema de medição de tempo
* **docs/Trabalho.md:** Especificação completa do trabalho
* **docs/artigo_desenvolvimento_analise.tex:** Artigo acadêmico com análise teórica e complexidade Big-O

## Entregáveis

* Código-fonte completo em C
* Artigo formatado no padrão IEEE com análise teórica e empírica
* Apresentação de slides para defesa
* Resultados experimentais em formato CSV

## Licença

Este projeto foi desenvolvido para fins acadêmicos na **Universidade Federal do Cariri (UFCA)**.

---

**Disciplina:** Estrutura de Dados  
**Curso:** Engenharia de Software  
**Instituição:** UFCA
