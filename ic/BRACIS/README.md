# Mudanças do antigo

## Tipos de vegetação:

Antes era apenas uma vegetação, que tinha $probQueima = x$.  
Agora temos 3 tipos de vegetação:

- Campestre
- Florestal
- Savânica

E a regra de probabilidade agora é:

$$
probQueimaSavanica = x;
$$
$$
probQueimaFlorestal = x*0.8
$$
$$
probQueimaCampestre = x*0.6
$$

## Formação da matriz de probabilidade (vento)

Antes:

```gml
coef = 1
inicialColaterais =	[	
							[coef*0.16,	coef*0.12,	coef*0.08],
							[coef*0.12,	0,			coef*0.04],
							[coef*0.08,	coef*0.04,	coef*0.002]
						];
```

Depois:

```gml
coef = 1
decaimento = 0.04
var mult_base = 0.16
var inicialColaterais =	[	
							[coef*(mult_base-(decaimento*0)),	coef*(mult_base-(decaimento*1)),	coef*(mult_base-(decaimento*2))],
							[coef*(mult_base-(decaimento*1)),	0,			coef*(mult_base-(decaimento*3))],
							[coef*(mult_base-(decaimento*2)),	coef*(mult_base-(decaimento*3)),	coef*(mult_base-(decaimento*4))]
						];
```
## Umidade d'água

[Artigo útil](https://www.scielo.br/j/rarv/a/WqbxMcGB5c3Dm3LYjtPhMHw/?lang=pt#)

Não consegui pensar em uma forma de implementar a umidade do ar, pode ser um multiplicador como os parâmetros anteriores mas não parece refletir a realidade.

## Ideias de experimentos

1. Todo o reticulado savanico variando o decaimento da matriz
2. Parâmetros padrões variando a totalidade do reticulado (campestre, florestal, savanica (base))
3. Fogo no centro, influência 0 de vento (decaimento == 0) e ao redor diferentes vegetações

## TODO 

- Definir breakpoints umidades para definir a influência da umidade na queima
- Umidade influênciar no tempo de renascimento, em caso de tempo "molhado" e em caso de tempo "seco" diminuir o tempo de queima, além da prob de queima, feita em intervalos
  - Ver com Dermes
- Tempo de "renascer" com as diferentes vegetações
  - Ver com Dermes


