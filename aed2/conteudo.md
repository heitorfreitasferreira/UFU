# AED2

## Análise de algoritmos

### Complexidade computacional

> Custo = memória + tempo

- Memória é mais barato que tempo
- Memória pode ser elástica (malloc)
- Outros custos
  - tráfego de rede
- Sempre o tempo de execução e memória é relacionado ao tamanho da entrada

### Tipos de Analises

- Análise empírica
  - Comparação entre programas
  - Avalia o custo de um algoritmo avaliando a execução
  - Cronometrar o tempo de execução e monitorar quanto de memória é utilizado
  - Vantagens
    - Permite avaliar o programa no computador/linguagem especifico
    - Considera custos que a análise matemática não considera, exemplo custo de alocação
    - Permite comparar linguagens
    - Permite comparar computadores
  - Desvantagens
    - Necessita implementar o código
      - Depende da habilidade do programador
    - Resultado pode variar muito
      - Computador utilizado
      - Processos em paralelo no momento da avaliação
    - Depende da natureza dos dados
      - Dados reais,
      - Dados aleatórios
        - Desempenho médio
      - Dados perversos
        - Sempre força o pior caso do algoritmo
- Análise matemática
  - Estudo das propriedades do algoritmo
  - Estudar como o algoritmo se comporta a medida que a entrada cresce em volume
  - Independente de variáveis de máquina
  - Estudo em um computador idealizado (simplificado)
    - Ex.: soma tem um custo maior que a multiplicação, porém para simplificar ignoramos
  - Só considera custos dominates do algoritmo
  - Para *n* entradas, o custo aumenta em *n*, *n²*, *n!*, etc...
  - Vejamos o seguinte algoritmo
  
      ```c
      int M = A[0];
      for(i = 0; i<n; i++){
        if(A[i] >=M){
          M = A[i];
        }
      }
      ```

  - Ignorando dentro do for, o algoritmo executara 3 + 2n instruções
    - *n* = tamanho array
  - Logo, considerando um laço vazio, podemos criar uma função matemática
  - f(n) = 3+2n
  - Considerando agora dentro do if e os seguintes arrays
  
      ```c
      int A1[4] = {1,2,3,4}
      int A2[4] = {4,3,2,1}
      ```

  - A1: comando if sempre testa **positivo**
  - A2: comando if sempre testa **negativo**
  - **Sempre devemos considerar o *MAIOR* número de instruções**
  - No pior caso o algoritmo será
    - f(n) = 3+2n+2n

### Comportamento assintótico

- Se um algoritmo é mais rápido para um grande conjunto, ele vai ser mais rápido que o outro pra um pequeno conjunto
- A função f(n) = 4n+3
  - 3 é uma *constante de inicialização*, logo desconsideramos

### Notação Grande-O

- O pior que o algoritmo pode ser é o Big-O
