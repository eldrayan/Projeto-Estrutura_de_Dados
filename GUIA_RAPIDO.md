# Guia Rápido

Este guia resume o fluxo mais direto para compilar o projeto, gerar os CSVs e atualizar os gráficos usados no artigo.

## 1. Compilar o projeto

Compilação manual no Windows:

```bash
gcc -Wall -Wextra -g -I./include -o programa.exe src/main.c src/algoritmos/*.c src/listas/*.c src/utils/*.c tests/*.c
```

Se você tiver `make` disponível:

```bash
make clean
make
```

## 2. Gerar todos os dados do trabalho

Execute o programa:

```bash
./programa.exe
```

No menu principal, use a opção `99`.

Essa opção roda:

- 5 algoritmos
- 3 estruturas: vetor, lista dinâmica e lista estática
- 3 tamanhos: 100, 1.000 e 10.000
- 3 tipos de entrada: aleatório, ordenado e invertido
- 100 repetições por configuração

Total aproximado: 13.500 execuções.

Esse teste completo pode levar bastante tempo, principalmente nos algoritmos quadráticos com `N = 10.000`.

## 3. CSVs esperados

Ao final dos testes completos, o projeto deve gerar 15 arquivos CSV.

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

## 4. Gerar os gráficos finais

O script mais adequado para o conjunto completo de resultados é o [scripts/analise.py](scripts/analise.py).

Ele concatena automaticamente os arquivos `resultados_*.csv` da raiz do projeto e grava as imagens em [docs/graficos](docs/graficos).

Comando:

```bash
python scripts/analise.py
```

Se quiser gerar a partir de um CSV específico:

```bash
python scripts/analise.py caminho_do_csv.csv
```

## 5. Fluxo alternativo por partes

Se a opção `99` for pesada demais, rode por blocos:

1. Opção `18`: todos os algoritmos com vetor
2. Opção `24`: todos os algoritmos com lista dinâmica
3. Opção `30`: todos os algoritmos com lista estática

Isso gera os mesmos grupos de CSV, mas em etapas separadas.

## 6. Scripts Python auxiliares

Os scripts [scripts/analise_performance.py](scripts/analise_performance.py) e [scripts/analise_performance_simples.py](scripts/analise_performance_simples.py) continuam úteis para cenários simples, mas eles trabalham com arquivos no formato `resultados_*_sort.csv`.

Para os gráficos finais do projeto, prefira [scripts/analise.py](scripts/analise.py).

## 7. Para validar a entrega final

Antes de considerar a entrega pronta, confira:

- os 15 CSVs foram gerados
- os arquivos não estão vazios
- os gráficos finais foram atualizados em [docs/graficos](docs/graficos)
- o artigo final está em [docs/Artigo_Finalizado.tex](docs/Artigo_Finalizado.tex)
- o algoritmo ideal foi justificado com base teórica e empírica

## 8. Problemas comuns

### Demora muito tempo

- execute por partes usando as opções 18, 24 e 30
- faça primeiro um bloco menor para estimar duração

### Erro ao compilar

- verifique a instalação do GCC com `gcc --version`
- confirme que os arquivos `.c` e `.h` estão presentes

### CSV não foi gerado

- confirme permissão de escrita na pasta do projeto
- confira se a execução chegou ao fim sem interrupção

## Resultado esperado

Com esse fluxo, você termina com:

- base experimental completa para o trabalho
- CSVs organizados por algoritmo e estrutura
- gráficos finais atualizados em [docs/graficos](docs/graficos)
- material pronto para conferência final em [docs/Artigo_Finalizado.tex](docs/Artigo_Finalizado.tex)

