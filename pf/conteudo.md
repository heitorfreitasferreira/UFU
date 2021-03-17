# Provas
Prova|Primeira aplicação|Segunda aplicação
-----|------------------|-----------------
P1|14/04|16/04
P2|25/05|28/05

# Emails para entregas

Dono|e-mail
-----|----
Claudiney|claudineyrt@gmail.com
Gina|progfuncionalufu@gmail.com

<hr>

**Assunto email de envio de trabalho:** 11921BCC026_heitor-freitas-ferreira_trab02pf  
**Assunto email de envio de duvidas:** 11921BCC026_heitor-freitas-ferreira_duvida  

<hr>

>https://conferenciaweb.rnp.br/webconf/gina-maira-barbosa-de-oliveira

# Aula 1

- Apresentação do conteúdo programático e [vídeo 1](https://www.youtube.com/watch?v=_lxyfCni9wY&feature=youtu.be&ab_channel=Bio-InspiredComputingLab)

# Aula 2

>Em Haskell ***tudo*** é função

- A função que já conhecemos em C é na verdade uma co-rotina
- A função calcula um valor (saída) que depende dos valores de entrada
- Não existe desvios de código (goto, label)
- Não utilizar variáveis (locais e globais)

## Exemplo de função de soma

```haskell
  soma x y = x + y
```

Generalização: nome_da_função arg1 arg2 argN = operação  
- [Vídeo aula](https://youtu.be/J9WrVk796bk)

# Aula 3

>Tipos

- Haskell infere tipos, no exemplo acima como somamos x+y, ele já infere que como está sendo feita uma operação matemática os tipos são numéricos
- Os tipos primitivos em Haskell são
  - Bool
  - Int
  - Float
  - Char
  - String
    - Essa é internamente uma lista de Char
- Podemos e devemos ao criar uma função, falar os tipos da mesma, de todos os argumentos e da saída

```haskell
  soma :: Float -> Float -> Float
  soma x y = x + y
```

# Aula 4

>## Tuplas

- Forma de estruturar dados
- Tamanho fixo
- Dados heterogéneos 
- Exemplo:
  - ("Hello World", 1.0,True, 42)
- Duplas são tuplas com 2 elementos
- Triplas são tuplas com 3 elementos
- fst("primeiro", "segundo")
  - retorna "primeiro"
- snd("primeiro", "segundo")
  - retorna "segundo"
- snd("primeiro", "segundo","terceiro")
  - Gera um erro pois só pode fazer com duplas

## Type

- Modo de criar um tipo composto
- Similar a Struct do C
- type Aluno = (String, Int, String)

## Guardas

>São ramificações de teste, caso o primeiro falhe ele passa pro segundo, assim em diante

```haskell  
  maior3 :: Float -> Float -> Float -> Float
  maior3 x y z
    |x>=y && x>=z = x --retorna x
    |y>=z = z -- como já sei que x não é o maior, testo só entre y e z
    |otherwise = z -- caso nenhuma guarda de true, usamos o otherwise como se fosse o default do switch case
```

# Aula 5

## Pattern Match

>Entre constantes

Dado|Dado|Match?
-|-|-
"V"|"V"|Sim
"V"|"F"|Não
"V"|6|Erro de tipo
"7"|7|Erro de tipo

>Entre constante e variável

Dado|Dado|Match?|Resultado
-|-|-|-
atomo|"V"|Sim|atomo -> "V"
nome|"Heitor"|Sim|nome -> "Heitor"
nome|atomo|Não

>Tuplas

Dado|Dado|Match?|Resultado
-|-|-|-
(18,True)|(18,True)|Sim|
(18,True)|(19,True)|Não|
(18,True)|("18",True)|Erro de tipo|
(18,True)|(18,True,"Nome")|Não|
(18,atomo)|(19,True)|Sim|atomo -> True
(True,("Heitor",19),199)|tupla|Sim|tupla -> (True("Heitor",19),199)
(True,("Heitor",19),199)|(matriculado,(nome,idade),saldo)|Sim|matriculado -> True / nome -> "Heitor" / idade -> 19 / saldo -> 199
(True,("Heitor",19),199)|( \_,(nome,idade),\_ )|Sim|nome -> "Heitor" / idade -> 19

## Var anônima

>Para usarmos uma variável anonima é só usar um \_ no pattern match

## Pattern Match em funções

- No caso de funções é similar ao Prolog porem sem Backtrack

```haskell
  not :: Bool -> Bool
  not True = False
  not False = True
```

- Com a chamada da função "not" primeiro ele tenta casar o parametro da mesma com True, caso o pattern match de sucesso, retorna False
- Caso o parametro seja False ele vai falhar no pattern match com a primeira definição da função e vai pular pra segunda, essa sim da Match e o retorno vai ser True
