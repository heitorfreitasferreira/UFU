import numpy as np
import matplotlib.pyplot as plt


def ajustar_curva(x_valores, y_valores, grau):
    def matriz_coefientes(x_valores, y_valores, dimensao):
        m = len(x_valores)
        A = np.empty((dimensao, dimensao))
        b = np.empty((dimensao))
        # Somatórios de x^i, i = 0, 1, ..., dimensao+1
        somatorios = [sum([x_valores[k]**i for k in range(m)]) for i in range(dimensao+2)]
        # Preenche a matriz de dispersão
        for i in range(dimensao):
            for j in range(i, dimensao):
                A[i,j] = somatorios[i+j]
                if i != j:
                    A[j,i] = A[i,j]
        # Preenche o vetor de resultados da matriz de dispersão * coeficientes
        # Cada posição do vetor é um somatório de x^i * y
        for i in range(dimensao):
            b[i] = sum([y_valores[k]*x_valores[k]**i for k in range(m)])
        return A, b

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
        return coeficientes[::-1]
    
    A, b = matriz_coefientes(x_valores, y_valores, grau+1)
    return eliminacao_gauss(A, b)

def ler_lista_floats() -> np.array:
    lista = []
    while True:
        try:
            valor = float(input("Digite um número (ou 'q' para sair): "))
            lista.append(valor)
        except ValueError:
            break
    return np.array(lista)

def plotar(x_valores, y_valores, coeficientes):
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

def main():
    x_valores = np.array([-1.0, -0.75, -0.6,	-0.5,	-0.3, 0, 0.2, 0.4, 0.5,	0.7, 1])
    y_valores = np.array([2.05, 1.153, 0.45,	0.4,	0.5, 0,	0.2, 0.6, 0.512, 1.2, 2.05])

    # Grau do polinômio a ser ajustado
    grau = 2 # int(input("Digite o grau do polinomio a ser ajustado")) 

    # Ajustar a curva utilizando o método dos quadrados mínimos
    coeficientes = ajustar_curva(x_valores, y_valores, grau)
    print("Coeficientes ajustados:", coeficientes)

    if input("Deseja plotar o gráfico? (s/n) ").lower() == 's':
        plotar(x_valores, y_valores, coeficientes)


if __name__ == "__main__":
    main()