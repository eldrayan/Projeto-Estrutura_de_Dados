# Projeto: Ranking de Alunos e Análise de Algoritmos

> Trabalho da disciplina de Estrutura de Dados do curso de Engenharia de Software da UFCA.

Este repositório reúne a implementação, a experimentação e a documentação de um sistema de ranking de alunos usado para comparar algoritmos de ordenação em diferentes estruturas de dados. O projeto combina código em C, scripts de análise em Python e um artigo final em LaTeX no formato IEEE.

## Visão geral

O problema central do trabalho é ordenar registros de alunos contendo ID e nota, medindo o impacto da escolha do algoritmo e da estrutura de dados no tempo de execução.

O projeto considera:

- 5 algoritmos: Bubble Sort, Selection Sort, Insertion Sort, Quick Sort e Merge Sort
- 3 estruturas: vetor, lista duplamente encadeada dinâmica e lista duplamente encadeada estática
- 3 tamanhos de entrada: 100, 1.000 e 10.000 elementos
- 3 cenários: aleatório, ordenado e invertido
- 100 repetições por configuração

Esse conjunto permite comparar melhor, médio e pior caso, além de fundamentar a escolha do algoritmo ideal para a aplicação proposta.

## Equipe e responsabilidades

| Integrante | Algoritmo principal | Responsabilidade extra |
|------------|---------------------|------------------------|
| Elder Rayan | Bubble Sort | Implementação da lista estática |
| Samuel Wagner | Selection Sort | Implementação da lista dinâmica |
| Diogo Gomes | Insertion Sort | Gerador de dados, menu e integração |
| Manoel Junio | Quick Sort | Análise teórica e complexidade |
| Pedro Yan | Merge Sort | Scripts de análise de dados |
| Antonio Neto | Quick Sort (suporte) | Benchmarking, documentação e slides |

## Tecnologias utilizadas

- C para estruturas de dados, algoritmos e benchmarking
- Python para geração de dados e análise dos resultados
- LaTeX para o artigo final no padrão IEEE
- GCC e Make para compilação

## Estrutura do projeto

```text
.
├── src/
│   ├── main.c
│   ├── algoritmos/
│   │   ├── bubble.c
│   │   ├── insertion.c
│   │   ├── merge.c
│   │   ├── quick.c
│   │   └── selection.c
│   ├── listas/
│   │   ├── dinamica.c
│   │   └── estatica.c
│   └── utils/
│       ├── csv_io.c
│       ├── gerador.c
│       ├── merge_utils.c
│       └── timer.c
├── include/
├── tests/
├── scripts/
│   ├── analise.py
│   ├── analise_performance.py
│   ├── analise_performance_simples.py
│   ├── csv_io.py
│   ├── menu.py
│   └── requirements.txt
├── docs/
│   ├── Artigo_Finalizado.tex
│   ├── Artigo_Estrutura_de_dados.pdf
│   ├── Trabalho.md
│   └── graficos/
├── GUIA_RAPIDO.md
├── makefile
├── performance.md
└── README.md
```

## Funcionalidades

### Estruturas de dados

- Lista dinâmica com alocação sob demanda usando `malloc` e `free`
- Lista estática com vetor pré-alocado e gerenciamento manual de índices livres
- Vetor convencional para comparação de desempenho

### Algoritmos de ordenação

- Bubble Sort
- Selection Sort
- Insertion Sort
- Quick Sort
- Merge Sort

Todos são avaliados em três cenários:

- Melhor caso: dados ordenados
- Caso médio: dados aleatórios
- Pior caso: dados inversamente ordenados

### Sistema de medição

- Medição de tempo com `clock()`
- 100 repetições por configuração
- Exportação automática de resultados em CSV
- Execução por algoritmo, por estrutura ou de forma completa

### Documentação e análise

- Artigo acadêmico final em [docs/Artigo_Finalizado.tex](docs/Artigo_Finalizado.tex)
- Gráficos finais em [docs/graficos](docs/graficos)
- Especificação do trabalho em [docs/Trabalho.md](docs/Trabalho.md)
- Documentação complementar em [performance.md](performance.md)

## Compilação

### Usando Make

Se você tiver `make` disponível:

```bash
make clean
make
```

O alvo principal gera o executável `programa` na raiz do projeto.

### Compilação manual

Para compilar diretamente com GCC:

```bash
gcc -Wall -Wextra -g -I./include -o programa.exe src/main.c src/algoritmos/*.c src/listas/*.c src/utils/*.c tests/*.c
```

## Execução

### Executar o programa

No Windows:

```bash
./programa.exe
```

Se tiver compilado pelo `make`, dependendo do ambiente:

```bash
./programa
```

### Opção recomendada: teste completo do trabalho

No menu principal, use a opção `99`.

Ela executa:

- 5 algoritmos
- 3 estruturas
- 3 tamanhos
- 3 tipos de dados
- 100 repetições por configuração

Total aproximado: 13.500 execuções.

Esse processo pode levar bastante tempo, especialmente nos algoritmos quadráticos com `N = 10.000`.

### Execução por partes

Se a opção `99` for pesada demais, rode em blocos:

- Opção `18`: todos os algoritmos com vetor
- Opção `24`: todos os algoritmos com lista dinâmica
- Opção `30`: todos os algoritmos com lista estática

### Outras opções relevantes do menu

- `1` a `7`: testes básicos e manuais
- `8` a `12`: testes simples de performance
- `13` a `18`: testes completos com vetor
- `19` a `24`: testes completos com lista dinâmica
- `25` a `30`: testes completos com lista estática
- `99`: execução completa do trabalho

## Fluxo recomendado

Para o fluxo completo de geração de dados e atualização dos gráficos do projeto, consulte [GUIA_RAPIDO.md](GUIA_RAPIDO.md).

Em alto nível, o processo é:

1. Compilar o executável.
2. Rodar a opção `99` para gerar a base completa.
3. Conferir os arquivos `resultados_*.csv` na raiz.
4. Atualizar os gráficos com `python scripts/analise.py`.
5. Validar o entregável final em [docs/Artigo_Finalizado.tex](docs/Artigo_Finalizado.tex).

## Arquivos gerados

Os testes completos geram 15 arquivos CSV, organizados por estrutura.

### Vetor

- `resultados_bubble_completo.csv`
- `resultados_selection_completo.csv`
- `resultados_insertion_completo.csv`
- `resultados_merge_completo.csv`
- `resultados_quick_completo.csv`

### Lista dinâmica

- `resultados_bubble_dinamica.csv`
- `resultados_selection_dinamica.csv`
- `resultados_insertion_dinamica.csv`
- `resultados_merge_dinamica.csv`
- `resultados_quick_dinamica.csv`

### Lista estática

- `resultados_bubble_estatica.csv`
- `resultados_selection_estatica.csv`
- `resultados_insertion_estatica.csv`
- `resultados_merge_estatica.csv`
- `resultados_quick_estatica.csv`

Alguns fluxos de teste simples também podem gerar arquivos no formato `resultados_*_sort.csv`, usados pelos scripts de análise básica.

## Análise dos resultados

### Instalar dependências Python

```bash
pip install -r scripts/requirements.txt
```

### Scripts disponíveis

- `python scripts/analise.py`: gera os gráficos finais a partir dos arquivos `resultados_*.csv` e salva em [docs/graficos](docs/graficos)
- `python scripts/analise_performance.py`: análise pontual com `pandas` e `matplotlib` para arquivos no formato `resultados_*_sort.csv`
- `python scripts/analise_performance_simples.py`: análise em modo texto para arquivos no formato `resultados_*_sort.csv`
- `python scripts/menu.py`: gerador de massas de dados em CSV

### Script recomendado para atualização dos gráficos

Para o conjunto completo de resultados do projeto, use:

```bash
python scripts/analise.py
```

Os detalhes operacionais desse fluxo estão resumidos em [GUIA_RAPIDO.md](GUIA_RAPIDO.md).

### O que observar nos resultados

- Comparação entre melhor, médio e pior caso
- Diferença entre algoritmos `O(n^2)` e `O(n log n)`
- Impacto da estrutura de dados no tempo de execução
- Estabilidade e previsibilidade do algoritmo escolhido para o artigo

## Metodologia de avaliação

A métrica principal do trabalho é o tempo de execução em milissegundos, medido apenas no trecho de ordenação, excluindo:

- Geração dos dados
- Entrada e saída
- Impressão de resultados

Cada experimento é repetido 100 vezes, e a média é utilizada para reduzir variações externas.

## Entregável final

O artigo final do projeto está em [docs/Artigo_Finalizado.tex](docs/Artigo_Finalizado.tex).

Esse arquivo reúne:

- Motivação e aplicação real
- Fundamentação teórica e complexidade
- Metodologia experimental
- Escolha do algoritmo ideal
- Análise dos gráficos e discussão dos resultados

Os gráficos utilizados no artigo estão em [docs/graficos](docs/graficos), e o PDF de referência original está em [docs/Artigo_Estrutura_de_dados.pdf](docs/Artigo_Estrutura_de_dados.pdf).

## Dicas práticas

- Rode os testes completos quando puder deixar a máquina executando por bastante tempo
- Não interrompa o terminal durante os testes longos
- Teste primeiro um bloco menor para estimar tempo de execução
- Bubble, Selection e Insertion com `N = 10.000` tendem a ser os cenários mais demorados
- Se o objetivo for validar a versão final, confirme primeiro os CSVs e depois regenere os gráficos com `python scripts/analise.py`

## Documentação relacionada

- [GUIA_RAPIDO.md](GUIA_RAPIDO.md)
- [docs/Trabalho.md](docs/Trabalho.md)
- [docs/Artigo_Finalizado.tex](docs/Artigo_Finalizado.tex)
- [performance.md](performance.md)

## Licença

Projeto desenvolvido para fins acadêmicos na Universidade Federal do Cariri.
