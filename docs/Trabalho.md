# Trabalho: Listas, Ordenação e Análise de Desempenho

> **OBS1:** IMPLEMENTAÇÃO DO CÓDIGO DEVE SER EM **C**  
> **OBS2:** Gráficos podem ser gerados utilizando outra linguagem ou LaTeX

---

## Introdução

Este trabalho tem como objetivo analisar o impacto da escolha de estruturas de dados e algoritmos de ordenação no desempenho de aplicações reais, por meio da:

- Implementação prática
- Análise teórica de complexidade
- Avaliação empírica baseada em diferentes cenários de entrada e volume de dados

**O trabalho deve ser desenvolvido em grupos de 5 a 6 alunos.**

Espera-se divisão equilibrada das atividades e envolvimento de todos os integrantes.

---

## Artigos de Referência

Serão disponibilizados artigos científicos como referência. Esses artigos têm como objetivo servir de exemplo de:
- Estrutura e organização textual
- Apresentação de gráficos
- Discussão de resultados

**Não devem ser copiados.** Os alunos podem utilizá-los como inspiração para a escrita do artigo final.

### Orientações para Leitura dos Artigos

Ao analisar os artigos disponibilizados, observe especialmente:

- ✅ Como o problema é introduzido e contextualizado
- ✅ Como os gráficos são apresentados e discutidos
- ✅ Como os resultados experimentais são interpretados
- ✅ Como a conclusão retoma os objetivos do trabalho

---

## Implementação e Experimentação (Base Prática)

### Escolha uma Aplicação Real

**Exemplo: Aplicativos de Entrega**

**Problema:** Mostrar uma lista de restaurantes disponíveis para o usuário. O número de restaurantes ativos muda a cada minuto.

**Necessidades:**
- Criar uma estrutura de dados com as informações de estabelecimentos (Nome, localização, distância até a residência, tipo de comida, frete, etc.)
- Ordenar a lista de restaurantes considerando que novos estabelecimentos podem ser inseridos ou removidos ao longo do tempo, simulando um ambiente dinâmico
- A lista deve permitir ordenação por diferentes critérios: "Menor Tempo de Entrega", "Preço do Frete" ou "Avaliação"

### Algoritmos a Implementar

- **Bubble Sort**
- **Insertion Sort**
- **Selection Sort**
- **Quick Sort**
- **Merge Sort**

### Estruturas de Dados a Implementar

#### 1. **Lista Encadeada Dinâmica**
Utilizando alocação dinâmica (malloc/free)

**Implementar suas principais funções:**
- `Inicializa`
- `Insere`
- `Imprime`
- `Busca`
- `Remove`
- `Libera`

#### 2. **Lista Encadeada Estática**
Implementar a lista utilizando um vetor pré-alocado e gerenciamento manual de posições livres

---

## Análise Teórica

### Análise de Desempenho

Análise do desempenho no **melhor**, **médio** e **pior caso** para todos os algoritmos.

#### Variáveis de Teste

**Volumes de Dados (N):**
- **Pequeno:** 100 elementos
- **Médio:** 1.000 elementos
- **Grande:** 10.000 elementos ou mais

> Alguns algoritmos e estruturas funcionam bem com poucos elementos, mas se tornam lentos ou ineficientes quando o volume cresce.

**Tipos de Entradas:**
- 🔀 **Aleatório** (Caso Médio)
- ⬇️ **Inversamente Ordenado** (Pior Caso)
- ⬆️ **Ordenado** (Melhor Caso)

#### Métricas a Coletar

**Principal:**
- **Tempo de Execução** em ms ou ns
  - O tempo de execução deve considerar **apenas** o trecho de código correspondente ao algoritmo de ordenação, **excluindo** operações de entrada/saída e geração dos dados de teste

**Adicional (opcional):**
- Número de comparações (quando possível)

### Escolha do Algoritmo Ideal

Seleção e justificativa do algoritmo mais adequado para o caso real, com base na análise teórica e nos dados empíricos coletados.

**Importante:**
- Todos os algoritmos listados devem ser implementados e avaliados experimentalmente
- **Apenas um deles** deverá ser selecionado e defendido como o algoritmo ideal para o caso real proposto
- Sempre que possível, os mesmos algoritmos de ordenação devem ser testados sobre diferentes estruturas de dados, permitindo analisar o impacto da estrutura no desempenho do algoritmo

### Geração dos Gráficos

Para geração dos gráficos (resultados), deve-se executar cada experimento **pelo menos 100 vezes** (ou um número menor desde que devidamente justificado), utilizando a **média dos tempos** obtidos para análise.

> Isso fará com que as curvas fiquem suaves.

---

## Escrita do Artigo (Documento Final)

O artigo deve ter de **2 a 4 páginas** e conter:

### Estrutura do Artigo

1. **Introdução (Motivação)**
   - Apresentação do problema e do caso real escolhido

2. **Desenvolvimento**
   - Descrição do algoritmo ideal escolhido
   - Pseudo-código
   - Complexidade teórica no pior, médio e melhor caso

3. **Resultados**
   - Metodologia utilizada
   - Apresentação gráfica
   - Discussão dos resultados empíricos (comparando o algoritmo ideal com os demais)
   - A análise deve discutir **não apenas o algoritmo**, mas também o impacto da estrutura de dados utilizada (lista encadeada dinâmica vs. lista encadeada estática) no desempenho observado

4. **Conclusão**
   - Síntese dos achados
   - Reafirmação da escolha justificada

### Links com Templates

- **Word ou LaTeX:** https://www.ieee.org/conferences/publishing/templates
- **LaTeX:** Link Overleaf
- **Word:** Link Word

---
## Critérios de Avaliação

| Critério | Peso |
|----------|------|
| **Implementação correta das estruturas e algoritmos** | 25% |
| **Análise teórica (complexidade e casos)** | 25% |
| **Experimentos e análise dos resultados** | 25% |
| **Qualidade do artigo e apresentação** | 25% |

### Aspectos Avaliados na Qualidade
- Clareza
- Organização
- Uso adequado de gráficos
- Argumentação técnica

---