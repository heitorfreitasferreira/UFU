# Análise de Algoritmo

> "All models are wrong... but some are usefull" George E.P.Box

## Modelo computacional 

- Trabalharemos com uma máquina suposta chamada Random Access Machine - RAM
- Operações aritméticas (+,-,*,/) com tempo constante
- Desvio e computação condicional
- Descreve bem o computador que você está lendo isso (diferente da máquina de turing)

## Ozão

### Problema: Vetor Maioria

> Dado um vetor V de tamanho n, o elemento x é chamado de **maioria** de V se x ocorre em pelo menos (n/2)+1 posições de V. Se tal elemento x existe então é dito que V possui um elemento maioria

Forma ingenua de implementação: 

```lua
function vetorMaioria(V)
    tamanho = table.getn(V)
    for i,v1 in pairs(V) do
        votos = 1
        for j,v2 in pairs(V) do
            if v1 == v2 then votos+=1 end
        end
        if votos > tamanho/2 then return true end
    end
    return false
end
```
Vários problemas com essa implementação, mas compilar e executar não diz o real tempo que ele demora, pois existem vários fatores que influênciam esse tempo fora do algoritmo (poder do processador por exemplo)

### Como saber então o tempo de execussão?

#### Contar as execussões

- Forma demorada de contar isso
- Complexidade de execussão da tarefa diretamente proporcional ao tamanho do algoritmo
- Alguns algoritmos não é possível saber quantos passos ele demora pra executar certa parte de um algoritmo

#### Modelo matemático

Iremos criar um modelo(fórmula) matemático que represente o tempo de execução de um algoritmo

Então iremos considerar o crescimento da função que representa o modelo 

> Avaliaremos a "cara" do gráfico da função

### Considerando tamanhos de entrada (n) muito grandes

- n e n+1 são "iguais"
- n/2, n e 2n são "iguais"

Logo consideramos apenas a escala de grandeza

### Definição da notação Ozão (Big O Notation)

> Para uma funçao *g(n)*, définimos *O(g(n))* como:
> *O(g(n))* = *f(n)*: existem constantes positivas *c* e *n0* tal que *0*<=*f(n)*<=*cg(n)* para todo n>*n0*

![gráficos de f(n) e g(n)](./images/f(n)%2Cg(n).png)

#### Exemplo

> *f(n) = 3n²+20n+2*

Então f(n) = O(n²), pois cn²>3n²+20n+2 para c = 4 e n0 = 5

Existem vários valores de c e n0 que satisfazem a equação

### Como cálcular na prática

- Jogue fora constantes aditivas e multiplicativas
  - 3n + 15 = n
- Pegar o termo com o maior expoente
  - n = linear
  - n²+n = quadratica
  - n³+n²+n = cúbica

### Nomeclaturas

- O(1) = constante
- O(log n) = logaritmica
- O(n) = linear
- O(n²) = quadratica
- O(2^n) = exponencial
- O(n!) = fatorial
- ...

![Gráfico complexidade](images/big%20o%20complex.png)

### Notação Ω (omega)

> Dá o valor mínimo de custo

### Notação Θ (tetha)

> Dá o valor máximo (O) e minimo (Ω)

### Formas de pensar as notações

- *f(n)* = *O(g(n))* é "semelhante" à *f(n)```<=```O(g(n))*
- *f(n)* = *Ω(g(n))* é "semelhante" à *f(n)```=>```Ω(g(n))*
- *f(n)* = *Θ(g(n))* é "semelhante" à *f(n) ```=``` Θ(g(n))*

## Ordenação por comparação

- Para tomar decisão sobre determinado elemento do vetor eu preciso comparar com outros
  - Cada 2 elementos se gasta uma comparação de <
- Entrada tamanho *n* eu tenho *n!* entradas diferentes
- Com *k* comparações é possível distinguir **não mais** ***2^n*** entradas
  - k = 1 diferencio [v1,v2]
  - k = 2 **NÃO diferencio** [v1,v2,v3]
- Para distinguir um vetor de **n posições** eu preciso ce um k tal que *n! < 2^k*
- Stirling: n! ~= c * sqrt(n)* (n/e)^n
  - log(c) + 1/2 * log(n) *   n * log(n) - n * log (*e*)
  - Jogando fora as constantes
- Logo para ordenar um vetor eu preciso Ω(n*lg(n)) comparações para ordenar um vetor