from numpy import prod as produtorio


def interpolar_funcao(
        x_valores: list[float],
        y_valores: list[float],
        x_interpolar: float
) -> float:
    grau = len(x_valores)

    def L(i: int, x: float) -> float:
        return produtorio(
            (x - x_valores[j]) / (x_valores[i] - x_valores[j])
            for j in range(grau)
            if j != i
        )

    return sum(
        y_valores[i] * L(i, x_interpolar)
        for i in range(grau)
    )


# Exemplo de uso:
# Valores conhecidos: x e f(x)
def ler_lista_floats() -> list[float]:
    lista = []
    while True:
        try:
            valor = float(input("Digite um número (ou 'q' para sair): "))
            lista.append(valor)
        except ValueError:
            break
    return lista


print("Digite os valores de x:")
x_valores: list[float] = ler_lista_floats()  # [1.3, 1.4, 1.5]
print("Digite os valores de f(x):")
y_valores: list[float] = ler_lista_floats()  # [3.669, 4.055, 4.482]

# Valor a ser interpolado
x_interpolar: float = float(input("Digite o valor a ser interpolado:"))  # 1.32

# Interpolação da função
y_interpolar = interpolar_funcao(x_valores, y_valores, x_interpolar)

print("Valor interpolado:", y_interpolar)
