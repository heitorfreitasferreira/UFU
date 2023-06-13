import numpy as np
import matplotlib.pyplot as plt


def ajustar_curva(x_valores, y_valores, grau):
    def matriz_coefientes(x_valores, y_valores, grau):
        n = len(x_valores)
        A = [[x**i for i in range(grau + 1)] for x in x_valores]
        print(f"A = {A}")
        # Calcular a transposta de A
        A_T = [[A[j][i] for j in range(n)] for i in range(grau + 1)]
        print(f"A transposta = {A_T}")
        # Calcular o produto A_T * A
        A_T_A = [[sum(A_T_row[k] * A_col[k] for k in range(n))
                  for A_col in A_T] for A_T_row in A_T]
        print(f"A transposta * A = {A_T_A}")
        # Calcular o produto A_T * y_valores
        A_T_y = [sum(A_T_row[i] * y_valores[i] for i in range(n))
                 for A_T_row in A_T]
        print(f"A transposta * y = {A_T_y}")
        # Resolver o sistema linear utilizando a eliminação de Gauss
        coeficientes = eliminacao_gauss(A_T_A, A_T_y)

        return coeficientes

    def eliminacao_gauss(A, b):
        n = len(A)

        # Etapa de eliminação
        for i in range(n):
            pivo = A[i][i]

            # Dividir a linha i pela diagonal principal (pivô)
            for j in range(i, n):
                A[i][j] /= pivo
            b[i] /= pivo

            # Zerar elementos abaixo do pivô
            for k in range(i + 1, n):
                fator = A[k][i]
                for j in range(i, n):
                    A[k][j] -= fator * A[i][j]
                b[k] -= fator * b[i]

        # Etapa de retrosubstituição
        coeficientes = [0] * n
        for i in range(n - 1, -1, -1):
            coeficientes[i] = b[i]
            for j in range(i + 1, n):
                coeficientes[i] -= A[i][j] * coeficientes[j]

        return coeficientes


def ler_lista_floats() -> list[float]:
    lista = []
    while True:
        try:
            valor = float(input("Digite um número (ou 'q' para sair): "))
            lista.append(valor)
        except ValueError:
            break
    return lista


# Exemplo de uso:
# Valores conhecidos: x e y
x_valores = ler_lista_floats()  # [1, 2, 3, 4, 5]
y_valores = ler_lista_floats()  # [3, 6, 9, 12, 15]

# Grau do polinômio a ser ajustado
grau = int(input("Digite o grau do polinomio a ser ajustado"))  # 2

# Ajustar a curva utilizando o método dos quadrados mínimos
coeficientes = ajustar_curva(x_valores, y_valores, grau)

# Imprimir os coeficientes encontrados
print("Coeficientes ajustados:", coeficientes)

# Gerar pontos para plotar a curva ajustada
x_plot = np.linspace(min(x_valores), max(x_valores), 100)
y_plot = np.polyval(coeficientes, x_plot)

# Plotar os pontos conhecidos e a curva ajustada
plt.scatter(x_valores, y_valores, color='red', label='Pontos Conhecidos')
plt.plot(x_plot, y_plot, label='Curva Ajustada')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid(True)
plt.show()
