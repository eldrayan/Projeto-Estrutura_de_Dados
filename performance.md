# Sistema de Medição de Tempo e Exportação CSV

## Visão Geral

Este documento descreve o novo sistema de medição de tempo de execução implementado no projeto, que permite coletar dados de performance dos algoritmos de ordenação e exportá-los em formato CSV compatível com Excel e Python.

## Funcionalidades

✅ *Medição Precisa de Tempo*: Utiliza clock() da biblioteca time.h para medir apenas a execução do algoritmo de ordenação
✅ *100 Repetições Automáticas*: Cada configuração é executada 100 vezes para obter uma média confiável
✅ *3 Tipos de Dados*:

- *Aleatório* (caso médio)
- *Ordenado* (melhor caso)
- *Invertido* (pior caso)

✅ *Exportação CSV*: Os resultados são automaticamente salvos em formato CSV com as colunas:

- Algoritmo
- Tipo_Lista (Vetor)
- Tipo_Dados (Aleatório, Ordenado, Invertido)
- Tamanho (número de elementos)
- Tempo_ms (tempo em milissegundos com 4 casas decimais)

## Arquivos Criados/Modificados

### Headers (include/)

- *timer.h*: Interface para medição de tempo
- *csv_io.h*: Interface para exportação CSV
- *teste_performance.h*: Interface para testes de performance

### Implementações (src/ e tests/)

- *src/utils/timer.c*: Implementação de timer usando clock()
- *src/utils/csv_io.c*: Implementação de exportação para CSV
- *tests/teste_performance.c*: Testes de performance dos 4 algoritmos

### Modificações

- *src/main.c*: Adicionadas opções 8-12 para testes de performance
- *include/testes_manuais.h*: Adicionadas declarações das funções de performance
- *include/selection.h*: Adicionada função selection_sort() para vetores
- *include/merge.h*: Adicionada função merge_sort() para vetores
- *src/algoritmos/selection.c*: Implementação de selection_sort() para vetores
- *src/algoritmos/merge.c*: Implementação de merge_sort() para vetores

## Como Usar

### Menu do Programa

Ao compilar e executar o programa:

```bash
make clean && make && ./programa
```

Você verá as novas opções no menu:

```text
TESTES DE PERFORMANCE (100 repetições + CSV):
[8] Performance Bubble Sort
[9] Performance Selection Sort
[10] Performance Insertion Sort
[11] Performance Merge Sort
[12] Executar todos os testes de performance
```

### Exemplo de Uso

1. *Executar um teste específico:*
Escolha uma opção: 8

Isso executará 100 repetições do Bubble Sort com os 3 tipos de dados e gerará o arquivo
resultados_bubble_sort.csv

2. *Executar todos os testes de performance:*
Escolha uma opção: 12

Isso executará testes de todos os 4 algoritmos e criará os arquivos:

- resultados_bubble_sort.csv
- resultados_selection_sort.csv
- resultados_insertion_sort.csv
- resultados_merge_sort.csv

## Formato do Arquivo CSV

Cada arquivo CSV gerado possui o seguinte formato:

```csv
Algoritmo,Tipo_Lista,Tipo_Dados,Tamanho,Tempo_ms
Bubble Sort,Vetor,Aleatório,1000,1.6460
Bubble Sort,Vetor,Aleatório,1000,1.6710
Bubble Sort,Vetor,Aleatório,1000,1.6970
...
Bubble Sort,Vetor,Ordenado,1000,0.0030
Bubble Sort,Vetor,Ordenado,1000,0.0030
...
Bubble Sort,Vetor,Invertido,1000,1.9130
Bubble Sort,Vetor,Invertido,1000,1.9200
...
```

### Características do CSV:

- *Cabeçalho*: Linha descritiva com nomes das colunas
- *Dados*: 300 linhas (100 repetições × 3 tipos de dados)
- *Precisão*: 4 casas decimais para tempos
- *Separador*: Vírgula (compatível com Excel e Python)

## Análise dos Dados

Os arquivos CSV podem ser facilmente importados em:

### Excel

1. Abra Excel
2. Vá em Arquivo → Abrir
3. Selecione o arquivo .csv
4. Excel abrirá uma janela de importação (deixe as configurações padrão)
5. Clique em OK

### Python

```python
import pandas as pd
```

#### Ler o arquivo CSV

```python
df = pd.read_csv('resultados_bubble_sort.csv')
```

#### Ver estatísticas

```python
print(df.groupby('Tipo_Dados')['Tempo_ms'].describe())
```

#### Gerar gráficos

```python
import matplotlib.pyplot as plt

df.groupby('Tipo_Dados')['Tempo_ms'].mean().plot(kind='bar')
plt.xlabel('Tipo de Dados')
plt.ylabel('Tempo Médio (ms)')
plt.title('Performance do Bubble Sort')
plt.tight_layout()
plt.show()
```

## Parametrizando os Testes

Se quiser alterar:

### Número de Repetições

Edite [teste_performance.c](tests/teste_performance.c):

```c
#define NUM_REPETICOES 100 // Altere para o desejado
```

### Tamanho do Vetor

Edite [teste_performance.c](tests/teste_performance.c):

```c
#define TAMANHO_VETOR 1000 // Altere para o desejado
```

## Estrutura de Dados Utilizadas

### ResultadoTempo (include/timer.h)

```c
typedef struct {
    char algoritmo[50];    // Nome do algoritmo
    char tipo_lista[20];   // Tipo da lista (Vetor)
    char tipo_dados[30];   // Tipo dos dados (Aleatório, Ordenado, Invertido)
    int tamanho;           // Tamanho dos dados
    double tempo_ms;       // Tempo em milissegundos
} ResultadoTempo;
```

## Funções Principais

### timer.c

- clock_t iniciar_timer(void): Inicia a medição de tempo
- double parar_timer(clock_t inicio): Para a medição e retorna tempo em ms
- ResultadoTempo criar_resultado(...): Cria estrutura com dados do teste

### csv_io.c

- void salvar_resultados_csv(...): Salva array de resultados em CSV
- void adicionar_resultado_csv(...): Adiciona resultado individual (append)

## Notas Importantes

1. *Precisão*: A medição usa clock() que mede tempo de CPU. Em sistemas com múltiplas tarefas, pode haver variação.
2. *Tamanho Fixo*: Todos os testes usam vetores de 1000 elementos. Para testar escalabilidade, modifique TAMANHO_VETOR.
3. *Random*: Um srand(time(NULL)) é executado no início dos testes, então dados aleatórios serão diferentes a cada execução.
4. *Performance*: Os testes podem levar alguns minutos para completar (600 ordenações × múltiplos algoritmos).
5. *Melhor Caso*: O Bubble Sort e Selection Sort mostram tempos muito pequenos (< 0.01ms) no melhor caso (dados ordenados).
6. *Pior Caso*: O Bubble Sort mostra os maiores tempos no pior caso (dados invertidos).

## Compilação

```bash
# Compilar tudo
make

# Compilar com otimizações
make release

# Limpar arquivos compilados
make clean

# Compilar e executar
make run
```

## Saída Esperada

Durante a execução dos testes, você verá:

╔═══════════════════════════════════════════╗
║ TESTES DE PERFORMANCE - BUBBLE SORT       ║
║ (100 execuções por configuração)          ║
╚═══════════════════════════════════════════╝
Executando testes com dados ALEATÓRIOS...
  Progresso: 10/100 execuções concluídas
  Progresso: 20/100 execuções concluídas
  ...
Executando testes com dados ORDENADOS...
  ...
Executando testes com dados INVERTIDOS...
  ...
✅ Resultados salvos em: resultados_bubble_sort.csv

╔═══════════════════════════════════════════╗
║ TESTE DO BUBBLE SORT CONCLUÍDO!           ║
╚═══════════════════════════════════════════╝

## Troubleshooting

*P: O arquivo CSV não foi criado*

- R: Verifique se o diretório está com permissão de escrita. O arquivo é salvo no diretório corrente.

*P: Os tempos estão muito pequenos (< 0.001ms)*

- R: Isso é normal para vetores pequenos. Aumente TAMANHO_VETOR em teste_performance.c

*P: Como comparar múltiplos algoritmos?*

- R: Execute a opção 12 para rodar todos os testes e compare os arquivos CSV resultantes em Excel ou Python.

## Próximas Melhorias Possíveis

- [ ] Adicionar testes para listas dinâmicas e estáticas
- [ ] Permitir escolher tamanho do vetor via menu
- [ ] Exportar as 100 repetições em colunas separadas (para análise estatística avançada)
- [ ] Adicionar gráficos automáticos usando Python
- [ ] Implementar testes multithread para avaliar acesso concorrente
