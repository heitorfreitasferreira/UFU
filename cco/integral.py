import numpy as np


def aproximar_integral(funcao, a, b, num_trapezios=1000):
    h = (b - a) / num_trapezios

    soma = 0
    for i in range(1, num_trapezios):
        x = a + i * h
        soma += funcao(x)

    integral = (h / 2) * (funcao(a) + 2 * soma + funcao(b))
    return integral

# Exemplo de uso:
# Definindo a função f(x) = x^2


def ler_coefs_functs() -> list[float]:
    lista = []
    while True:
        try:
            valor = float(
                input(f"Digite o coeficiente de x^{len(lista)} (ou 'q' para sair): "))
            lista.append(valor)
        except ValueError:
            break
    return lista


def criar_funcao(coeficientes: list[float]):
    def funcao(x):
        # Elevar cada termo à potência correspondente
        termos = [coef * x ** i for i, coef in enumerate(coeficientes)]
        # Somar todos os termos
        resultado = np.sum(termos)
        return resultado

    return funcao


# Definindo o intervalo [a, b]
print("Digite os coeficientes da função:")
funcao = criar_funcao(ler_coefs_functs())
a = float(input("Digite INICIO o do intervalo: "))  # 0
b = float(input("Digite FIM o do intervalo: "))  # 1
# Aproximando a integral da função no intervalo [a, b] usando 1000 trapézios
integral_aproximada = aproximar_integral(funcao, a, b, num_trapezios=1000)

print("Integral aproximada:", integral_aproximada)
