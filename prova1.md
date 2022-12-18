# Questão 1

Descreva o comportamento do código abaixo

```js
  let a = 10;
  let b = 20;
  let c = 30;
  if (a > b && a > c) {
    console.log(a);
  }
  else if (b > a && b > c) {
    console.log(b);
  }
  else {
    console.log(c);
  }
```
# Questão 2

Descreva o comportamento do código abaixo

```js
  let a = 10;
  let i = 0;
  while (i <= a) {
    console.log(i);
    i++;
  }
```
# Questão 3

Descreva o comportamento do código abaixo

```js
  let a = 10;
  let i = 0;
  while (i <= a) {
    if (i % 2 == 0) {
      console.log(i);
    }
    i++;
  }
```

# Questão 4

Reescreva o código acima sem utilizar if/else ou switch/case

# Questão 5

Faça uma função que receba um número $n$ inteiro, e retorne verdadeiro caso o número seja primo, e falso caso contrário.

# Questão 6

Faça uma função que receba um número $n$ inteiro, e retorne uma lista com todos os primos até o mesmo

# Questão 7

Faça uma função que receba um valor $T$ e retorne um vetor $N[1000]$ com a sequência de valores de 0 até $T-1$ repetidas vezes, conforme exemplo abaixo. Imprima o vetor $N$.

```js
N[0] = 0
N[1] = 1
N[2] = 2
N[3] = 0
N[4] = 1
N[5] = 2
N[6] = 0
N[7] = 1
N[8] = 2
//....
```

# Questão 8

Faça um programa que busque um pokemon e mostre imagem de toda sua cadeia de evolução

# Questão 9

Faça um site que mude de tema de acordo com a hora do dia, de dia tema claro (fundo branco, fonte preta) e de noite tema escuro (fundo preto, fonte branca)

O site terá um input que se o usuário mexer, altera a preferencia de tema do site que sobrescreve a lógica de hora do dia, essa preferencia deve ser salva no localStorage