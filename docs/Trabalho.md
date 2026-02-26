Trabalho: Listas, Ordenação e Análise de Desempenho 
OBS1: IMPLEMENTAÇÃO DO CÓDIGO DEVE SER EM C 
OBS2: Gráficos podem ser gerados utilizando outra 
linguagem ou latex 
 
Introdução  
Este trabalho tem como objetivo analisar o impacto da escolha de estruturas 
de dados e algoritmos de ordenação no desempenho de aplicações reais, por 
meio da implementação prática, análise teórica de complexidade e avaliação 
empírica baseada em diferentes cenários de entrada e volume de dados. 
 
O trabalho deve ser desenvolvido em grupos de 5 a 6 alunos. 
 
Espera-se  divisão  equilibrada  das  atividades  e  envolvimento  de  todos  os 
integrantes. 
 
Artigos de Referência: 
Serão disponibilizados artigos científicos como referência. Esses artigos têm 
como  objetivo  servir  de  exemplo  de  estrutura,  organização  textual, 
apresentação  de  gráficos  e  discussão  de  resultados,  não  devendo  ser 
copiados. Os alunos podem utilizá-los como inspiração para a escrita do artigo 
final. Além disso, a apresentação os slides da apresentação de um dos artigos 
também será disponibilizada. 
 
Orientações para Leitura dos Artigos: 
Ao analisar os artigos disponibilizados, observe especialmente: 
●  Como o problema é introduzido e contextualizado 
●  Como os gráficos são apresentados e discutidos 
●  Como os resultados experimentais são interpretados 
●  Como a conclusão retoma os objetivos do trabalho. 
 
 
1. Implementação e Experimentação (Base Prática) 
●  Escolha uma aplicação real  
Exemplo:  Aplicativos de Entrega  
Problema: Mostrar uma lista de restaurantes disponíveis para o usuário. O número de restaurantes 
ativos muda a cada minuto. 
É necessário criar uma estrutura de dados com as informações de estabelecimentos (Nome, 
localização, distância até a residência, tipo de comida, frete, etc).  
É necessário ordenar a lista de restaurantes considerando que novos estabelecimentos podem ser 
inseridos ou removidos ao longo do tempo, simulando um ambiente dinâmico. Além disso, a lista 
deve permitir ordenação por diferentes critérios, como "Menor Tempo de Entrega", "Preço do Frete" 
ou "Avaliação". 
●  Algoritmos a Implementar: Bubble Sort, Insertion Sort, Selection Sort, Quick Sort e Merge 
Sort 
●  Estrutura de dados a implementar : 
○  Lista encadeada dinamicamente - Utilizando alocação dinâmica  
■  Implementar suas principais funções: Inicializa, Insere, Imprime, Busca, 
Remove, Libera 
○  Lista Encadeada Estática - implementar a lista utilizando um vetor pré-alocado e 
gerenciamento manual de posições livres 
2. Análise Teórica  
●  Análise de desempenho: Análise do desempenho no melhor, médio e pior caso para todos 
os algoritmos. 
○  Variáveis de Teste: 
■  Volumes de Dados (N):  
●  Pequeno: 100 elementos 
●  Médio: 1000 elementos 
●  Grande: 10.000 elementos ou mais 
●  Alguns algoritmos e estruturas funcionam bem com poucos 
elementos, mas se tornam lentos ou ineficientes quando o volume 
cresce. 
■  Tipos de Entradas: Aleatório, Inversamente Ordenado (Pior Caso) e 
ordenado. 
○  Métricas a Coletar:  
■  Tempo de Execução em ms ou ns  
●  O tempo de execução deve considerar apenas o trecho de código 
correspondente ao algoritmo de ordenação, excluindo operações de 
entrada/saída e geração dos dados de teste 
■  Outras métricas podem ser adicionadas, desde que justificadas. 
●  Exemplo - Número de comparações (quando possível) 
●  Sempre que possível, os mesmos algoritmos de ordenação devem ser testados sobre 
diferentes estruturas de dados, permitindo analisar o impacto da estrutura no desempenho 
do algoritmo. 
●  Escolha do Algoritmo Ideal: Seleção e justificativa do algoritmo mais adequado para o 
caso real, com base na análise teórica e nos dados empíricos coletados. 
○  Todos os algoritmos listados devem ser implementados e avaliados 
experimentalmente. No entanto, apenas um deles deverá ser selecionado e 
defendido como o algoritmo ideal para o caso real proposto. 
●  Para Geração dos gráficos (resultados), deve-se executar cada experimento pelo menos 
100 vezes (ou um número menor desde que devidamente justificado), utilizando a média 
dos tempos obtidos para análise. Isso fará com que as curvas fiquem suaves. 
3. Escrita do Artigo (Documento Final) 
O artigo deve ter de 2 a 4 páginas e conter: 
●  Introdução (Motivação): Apresentação do problema e do caso real escolhido. 
●  Desenvolvimento: Descrição do algoritmo ideal escolhido, seu pseudo-código e sua 
complexidade teórica no pior, médio e melhor caso. 
●  Resultados: Metodologia utilizada, apresentação gráfica e discussão dos resultados 
empíricos (comparando o algoritmo ideal com os demais). 
○  A análise deve discutir não apenas o algoritmo, mas também o impacto da estrutura 
de dados utilizada (lista encadeada dinâmica vs. lista encadeada estática) no 
desempenho observado. 
●  Conclusão: Síntese dos achados e reafirmação da escolha justificada. 
Links com Templates: 
●  Word ou Latex - https://www.ieee.org/conferences/publishing/templates 
●  Latex - Link Overleaf 
●  Word - Link Word 
4. Apresentação Oral do Artigo (Defesa) 
●  Duração: 10 a 15 minutos. 
●  Foco: Deve ser um resumo dos pontos chave do artigo, com ênfase nos gráficos de 
desempenho (comparação entre os algoritmos) e na justificativa da escolha do algoritmo 
ideal para o caso real. 
●  Estrutura Sugerida: Introdução, Metodologia de Teste, Análise dos Resultados (Gráficos), e 
Conclusão. 
5. Critérios de avaliação 
●  Implementação correta das estruturas e algoritmos: 25% 
●  Análise teórica (complexidade e casos): 25% 
●  Experimentos e análise dos resultados: 25% 
●  Qualidade do artigo e apresentação: 25%  
○  clareza, organização, uso adequado de gráficos e argumentação técnica