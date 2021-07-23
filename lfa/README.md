# Linguagens formais e automatos

## Automatos ou Máquinas abstratas

- Estado inicial
  - Normalmente denotado por Q0
  - Pode ter
- Estado final (de aceitação)
  - Normamente denotado por Q1

## Definição de automato finito (deterministico)

## Forma de representação em grafo

- Um nó pra cada estádo
- Uma seta para indicar quem é o estado inicial
- Um circulo duplo para indicar quem é o estado de aceitação
## Formalismo operacional
## Formalismo axiomatico
## Formalismo denotacional (ou gerador)

> Expressões regulares

### Associam-se regras às componetes da linguagem

> Regras

- Permitem afirmar o que será verdadeiro após a ocorrência de cada cláusula


## Capitulo 1

### Simbolo

> Entidade básica que escolhemos para escrever nossa linguagem

- Unidade mais básica da palavra

### Alfabeto

> Conjunto finito de simbolos

- Exemplo:
  - Σ¹ = {a,b,c}
  - Σ² = {0,1,2,3,...,9}
  - Σ³ = {}
    - Especial, conjunto vazio, linguagem sem simbolo
    - É usado para gerar a palavra vazia (ε)

### Palavra/cadeia de caracteres

> Qualquer sequência *finita* de simbolos justapostos

- Exemplos
  - 31156 palavra usando o alfabeto Σ³
  - abba palavra usando o alfabeto Σ²

#### Tamanho de palavras

- Denotado entre "pipes"
- Exemplos:
  - |31156| = 5
  - |abba| = 4

#### Concatenação

> Justaposição de duas palavras

- v = **ab**, w = _cd_
  - vw = **ab**_cd_
  - wv = _cd_**ab**
  - vv = **abab**
  - ww = _cdcd_

> Propriedades

- Assosietividade
- Elemento neutro = palavra vazia (εw) = w

> Prefixo: qualquer sequência de simbolos iniciais de uma palavra

- Toda palavra é prefixo dela mesma
- Palavra vazia é prefixo de qualquer palavra

> Sufixo: qualquer sequência de simbolos finais de uma palavra

- Toda palavra é sufixo dela mesma
- Palavra vazia é sufixo de qualquer palavra

> Subpalavra: qualquer sequência de simbolos dentro de uma palavra

#### Concatenação sucetiva

- w³ = www
- w¹ = w
- a^5 = aaaaa
- w^0 = ε, para w != ε

> Não confundir com **potenciação**

- Para distinguir se o que estiver abaixo for uma palavra é concatenação sucetiva

#### Produto de conjunto de palavras

> V e W é o conjunto de palavras sobre Σ
> VW = {vw/v ∈ V, w ∈ W}

- Exemplo
  - Σ = {0,1,2,3}  V = {00,11}  W = {222,333}
  - VW = {00222,00333,11222,11333}
  - VV = V² = {0000,0011,1100,1111}
  - V^0 = {ε}, por definição

#### Fechamento de Kleene

> Seja W um conjunto de palavras qualquer sobre um alfabeto Σ
> W* = ∪Wi -> i>=**0**
> W* = W0 ∪ W1 ∪ W2 ∪ W3 ∪...

- Exemplos:
  - V = {00,11}
    - V* = {ε,00,11,0000,0011,1100,1111,0011111,...}
  - Σ = {0,1}
    - Σ* = {ε,0,1,01,10,00,11,...}
      - Ou seja, Σ* = qualquer palavra binária

#### Fechamento Positivo

> Seja W um conjunto de palavras qualquer sobre um alfabeto Σ
> W* = ∪Wi -> i>=**1**
> W* = W0 ∪ W1 ∪ W2 ∪ W3 ∪...

- A única diferença é que o fechamento positivo começa em 1, logo não teremos o **ε**

## Definição de linguagem formal

> Uma linguagem L é um conjunto  de palavras sobre um alfabeto Σ, ou seja L ⊂ Σ*

- Exemplo sendo Σ = {a,b}
  - conjunto vazio
  - conjunto formado pela ε
    - Note que {ε} != {}
  
> A definição de linguagem só faz sentido ao conhecer o alfabeto

### Como representar uma linguagem formal L

- Se L é finito basta listar todas as palavras
- Se L é infinito, existem 2 formalismos
  - Formalismo __Gerador__: ***Gramática***
  - Formalismo __Reconhecedor__: ***Autômato***

## Definição de gramática

> G = {V,T,P,S}

- V = conjunto __finito__ de símbolos
  - _Váriaveis_ ou _não-terminais_
- T = conjunto __finito de símbolos__
  - _terminais_
  - disjunto de V
- P = conjunto finito de pares ordenados (α,β)
  - Regra de produção
  - α é a palavra de __V ∪ T__+
  - β é a palavra de __V ∪ T__*
    - Aqui pode aparecer ε
- S = elemento de V
  - variável inicial

### Notação (α,β)

- α -> β
- Notação abreviada para ```α -> β1, ..., α -> βn```
  - ```α -> β1|```

### Exemplo de gramática: números naturais

- G = {V,T,P,S}
  - V = {S,D}
  - T = {0,1,2,3,4,5,6,7,8,9}
  - P = {S -> D, S-> DS, D -> 0|1|2|3|4|5|6|7|8|9}
- Uma derivação do número 234
  - S => DS => 2S => 2DS => 23S => 23D => 234
- Portanto
  - S =>* 234
  - S =>+ 234
  - S =>6 234

### Derivação

> Partir do símbolo inicial e ir aplicando as regras quantas vezes for necessário

- Par da relação denotada por =>
  - Com domínio em __V ∪ T__+
  - contra-domínio em __V ∪ T__*
  - representado de forma infixa α => β

#### Sucessivos passos de derivação
- =>* 
  - fecho transitivo e reflexivo da relação =>
  - zero ou mais passos de derivação sucessivos
- =>+ 
  - fecho transitivo da relação =>
  - zero ou mais passos de derivação sucessivos
- =>i
  - fecho transitivo da relação =>
  - zero ou mais passos de derivação sucessivos
