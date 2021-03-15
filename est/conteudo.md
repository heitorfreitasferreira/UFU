# Estatística

## Estatística descritiva

>Lida com organização, resumo e apresentação de dados

- Tabelas;
- Gráficos;
- Medidas Descritivas (média, variância, entre outras).

### Variáveis Qualitativas

>Atributos

- Exemplos:
  - Sexo
  - Religião
  - Naturalizade
  - Sabor
  - Altura
- Nominal
  - Ex.: região
- Ordinal
  - Ex.: classe social

- Primeiro passo -> Criar uma tabela de frequências
  - Frequência
    - Quantifica a ocorrência de valores de uma variável
      - Podem ser:
        - Absoluta(**fa**) - contagem das observações de uma variável
        - Relativa(**fr**) - divisão da frequência absoluta pelo total de observações
          - fr = fa/n
        - Percentual(**fp**) - frequência relativa multiplicado por 100
          - fp = fr * 100
        - Acumulada (**fa**) - soma das frequências absolutas
        - Percentual Acumulada (**fp**) - soma de frenquências percentuais

### Variáveis Quantitativas discretas

- Podem ser resumidos por tabelas de frequências
- É em geral é bem semelhante a variáveis qualitativas

### Variáveis Quantitativas contínuas

- Para construir tabelas envolve os seguintes passos
  - Decidir sobre o número de classes *k*. Para não ser arbitrário pode-se se usar a *raiz quadrada do total de valores* como número de classes
    - k ~= sqrt(n)
  - Determinar a amplitude de dados
    - A = Max - Min
  - Determinar a amplitude de classe c
    - c = A/(k-1)
  - Determinar o limite *inferior* da primeira classe LI¹:
    - LI¹ = Min - (c/2)
  - Determinar o limite *superior* da primeira classe LS¹:
    - LS¹ = LI¹ + c

## Amostras de população

### Média

>Soma dos valores divididos pela soma dos pesos

### Mediana

>Deixa metade da frequência abaixo e metade acima

- Caso a amostra tenha tamanho ímpar é só ordenar e pegar o do meio
- Caso a amostra tenha tamanho par pegamos os 2 valores do meio e tiramos a média deles

### Moda

>Valor mais recorrente na frequência

- Caso não aja moda, falamos que o conjunto é *amodal*
- Caso exista 2 modas o conjunto é *bimodal*

### Simetria

- Caso um em uma amostra, a média, mediana e a moda sejam iguais, dizemos que o conjunto é **simétrico**
- Caso não seja o conjunto é **assimétrico**
  - Assimetria a *direita*: ***Média>Mediana>Móda***
  - Assimetria a *esquerda*: ***Média<Mediana<Móda***

### Quantis

- Quartil
  - Valores de uma série que a divide em quatro partes *iguais*
  - Fórmula
    - EQi = [ i(n+1) ]/2
    - i = número de quartis
    - n = número de observações

### Percentis

>Mesma ideia do quartil, porém dividido em 4

### Boxplot

- Desenho esquemático
- Análise gráfica que oferece ideia de:
  - posição
  - dispersão
  - assimetria
  - caudas
  - dados discrepantes
- Como construír
  - desenhar uma "caixa"com o nível superior dado pelo terceiro quartil e inferior pelo primeiro quartil
  - mediana (Quartil 2) é representada por um traço no interior da caixa
  - Limites:
    - LI = Q1 − 1, 5dq
    - LS = Q3 + 1, 5dq
      - dq = Q3 − Q1 denominando diferença quartílica.
- Etapas de construção de um boxplot
  1. Contruir um retângulo de tal maneira que os lados menores correspondem aos primeiro e terceiro quartis da distribuição.
  1. Cortar o retângulo por um segmento paralelo aos lados menores, na altura correspondente à mediana;
  1. Traçar um segmento paralelo ao eixo, partindo do ponto médio até o maior valor observado que NÃO supere LS;
  1. Traçar um segmento paralelo ao eixo, partindo do ponto médio até o menor valor que NÃO é menor LI;
  1. Caso tenha valores superiores a LS ou inferiores a LI, marcar os pontos, este valores são considerados observações discrepantes.
