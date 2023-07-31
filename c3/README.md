# Informações gerais sobre 

## Avaliações

Prova | Data | Matérias | Valor | Obtido
-|-|-|-|-
1 | 06/09/2023 | Equações diferenciais ordinárias de 1ª ordem<br> Equações diferenciais ordinárias de 2ª ordem | 100/3 | ?
2 | 11/10/2023 | Transformada de Laplace | 100/3 | ?
3 | 16/11/2023 | Séries de Fourier<br> Integrais de Fourier| 100/3 | ?
Rec | 22/11/2023 | Matéria toda | 100/3 | ?


Nota caso pegue  sub =(Nota total final + sub)/2

10pts de trabalho no moodle


# Preambulo: Equação diferencial

> Equação que envolva derivada

Exemplo: $y' = x^2$

Uma equação diferencial é uma equação que envolve derivadas e da qual se requer uma solução

## Terminologia e definições

No Cálculo 1, foi aprendido que dada a função $y = f(x)$, a sua derivada $\frac{dy}{dx} = f'(x)$, é também uma função de x e é calculada através de regras apropriadas. Por exemplo se $y = e^(x^2)$, então $\frac{dy}{dx} = 2xe^(x^2)$ ou $\frac{dy}{dx} = 2xy$

Pense agora no seguinte problema: dada a equação $\frac{dy}{dx} = 2xy$, encontrar, de algum modo, uma função $y = f(x)$ que satisfaça a equação.

Def.: Uma equação que contem as derivadas (ou diferencias) de uma ou mais variáveis dependentes, em relação a umaou mais variáveis independentes, é chamada de equações diferencial (ED).

Estas equações podem ser classificadas de acordo com o tipo, ordem, e linearidade.

- Tipo:
    - Se uma equação também contém sua derivadas ordinárias de uma ou mais variáveis dependentes, com relação a uma única variável independente, ela é chamada equação diferencial ordinária (EDO)
        - Exemplos: 
            - $\frac{dy}{dx} - 5y = 1$
            - $(y-x){dx} + 4x*{dy} = 0$
            - $\frac{du}{dx} - \frac{dv}{dx} = x$
        - $y'' - 2y'- + 6y = 0, y = f(x)$
    - Uma equação que envolve as derivadas parciais de uma ou mais variáveis dependentes com relação a duas ou mais vairáveis independentes é chamada equação diferencial parcial (EDP)
        - Exemplos: 
            - $\frac{\partial u}{\partial y} = -\frac{\partial v}{\partial x}$
            - $x\frac{\partial u}{\partial u} + y\frac{\partial u}{\partial y} = u$
            - $\frac{\partial ^2u}{\partial x^3} = \frac{\partial ^2u}{\partial ^2x} ...$
- Ordem: 
    - Pela ordem de uma equação diferencial é a ordem da mais alta derivada presente na equação
        - Exemplos: 
            - $\frac{dy}{dx} = 5x + 3$ é yna EDO de 1ª ordem
            - $e^y \frac{d^2y}{dx^2} + 2(\frac{dy}{dx})^3 = 1$ é uma EDO de 2ª ordem
            - $4 \frac{d^3x}{dx^3}+ \sin x \frac{d^2y}{dx^2} + 5xy = 0$ é uma EDO de 3ª ordem
            - Em geral uma equação diferencial ordinária de ordem $n$ é dada pelo símbolo $F(x,y,\frac{dx}{dy},\frac{d^2y}{dx^2}, ..., \frac{d^n y}{dx^n}) = 0$, ou $F(x, y, y', y'', ..., y^(n))$
- Linearidade
    - Uma equação diferencial é chamada linear se pode ser escrita na forma $$  TODO: ANOTAR A FORMA 
        - i) A variável dependente $y$ e todas as suas defivadas são do primeiro grau, isto é, a ptência de cada termo envolvendo $y$ é 1 (e também não aparece produto das derivadas)
        - ii) Cada função $a_0, a_1, a_2, ..., a_n$ depende apenas da variável x.
        - Exemplos:
            - $x{dy} + y{dx} = 0$ é linear de 1ª ordem
            - $y'' - 2y'' + y = 0$, eqlinear de 2ª ordem
            - $x^3\frac{d^3y}{dx^3} - x^2\frac{d^2y}{dx^2} + 3x\frac{dy}{dx} + 5y = e^x$, eq linear de 3ª ordem
            - $yy''-2y' = x$, não é linear, pos o coeficiente de $y''$ depende de $y$
            - $\frac{d³y}{dx^3} + y^2 = 0$, naõ é linear pois a potência de $y$ no segundo termo é $2$

Soluções de uma EDO

Def: Qualquer função f definida em algum intervalo $I$, que quando substituída na equação diferencial reduz a equação a umaidentidade, é chamada de **solução** para a equação naquele intervalo.

Exemplo: Verifique que $y = \frac{x^4}{16}$ é uma solução para a equação $\frac{dy}{dx} = xy^\frac{1}{2}$ no intervalo $(-\infty, + \infty)$

Solução:

$y = \frac{x^4}{16}$ temos $\frac{dy}{dx} = \frac{4x³}{16} = \frac{x^3}{4}$

$y^\frac{1}{2} = x (\frac{x ^4}{16})^\frac{1}{2} - \frac{ x^2}{4},\forall x \real$

$xy^\frac {1}{2} = x \frac{x^2}{4} = \frac{x^3}{4}$

$\frac{dy}{dx} = xy^\frac{1}{2}$ e portanto $y = \frac{x^4}{16}$ é uma solução da EDO




# Equações diferenciais ordinárias de 1ª ordem

# Equações diferenciais ordinárias de 2ª ordem

# Transformada de Laplace

# Séries de Fourier

# Integrais de Fourier