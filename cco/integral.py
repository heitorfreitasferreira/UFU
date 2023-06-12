from math import *


def aproximar_integral(
    funcao: callable,
    intervalo: tuple[float, float],
    num_trapezios: int = 1000
):

    inicio_intervalo = min(intervalo)
    fim_intervalo = max(intervalo)
    h = (fim_intervalo - inicio_intervalo) / num_trapezios
    soma = 0
    while inicio_intervalo < fim_intervalo:
        soma += funcao(inicio_intervalo)
        inicio_intervalo += h
    return (h / 2) * (funcao(inicio_intervalo) +
                      2 * soma + funcao(fim_intervalo))


def ler_lambda() -> callable:
    while True:
        try:
            return eval(f"lambda x:{input('Insira a f(x): ')}")
        except:
            print("Função inválida!")


def main():
    f = ler_lambda()
    a = float(input("Digite INICIO o do intervalo: "))
    b = float(input("Digite FIM o do intervalo: "))

    integral_aproximada = aproximar_integral(
        funcao=f,
        intervalo=(a, b)
    )
    print("Integral aproximada:", integral_aproximada)


if __name__ == "__main__":
    main()
