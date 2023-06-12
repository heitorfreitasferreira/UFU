import numpy as np
import matplotlib.pyplot as plt


def ajustar_curva(x_valores, y_valores, grau):
    # Criar uma matriz de Vandermonde
    A = np.vander(x_valores, grau + 1)

    # Calcular a solução do sistema linear utilizando a decomposição QR
    Q, R = np.linalg.qr(A)
    coeficientes = np.linalg.solve(R, Q.T @ y_valores)

    return coeficientes


# Exemplo de uso:
# Valores conhecidos: x e y
x_valores = [1, 2, 3, 4, 5]
y_valores = [3, 6, 9, 12, 15]

# Grau do polinômio a ser ajustado
grau = 2

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
