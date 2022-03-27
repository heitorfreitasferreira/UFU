from email.mime import base
import pandas as pd
import matplotlib.pyplot as plt
# Coef = 1
print("BASE")
base_df = pd.read_csv('coefmeio.csv')
base_df = base_df.loc[base_df['quantidade_quadrante_a'] > 0, ['quantidade_quadrante_a',
                                                              'quantidade_quadrante_b', 'quantidade_quadrante_c', 'quantidade_quadrante_d']]
base_df.plot()
base_df['queima_total'] = base_df['quantidade_quadrante_a'] + base_df['quantidade_quadrante_b'] + \
    base_df['quantidade_quadrante_c'] + base_df['quantidade_quadrante_d']
# print(base_df.to_csv('b
# Coef = 0.5
print("COEF = 0.5")
meio_df = pd.read_csv('coefmeio.csv')
meio_df = meio_df.loc[meio_df['quantidade_quadrante_a'] > 0, ['quantidade_quadrante_a',
                                                              'quantidade_quadrante_b', 'quantidade_quadrante_c', 'quantidade_quadrante_d']]

meio_df['queima_total'] = meio_df['quantidade_quadrante_a'] + meio_df['quantidade_quadrante_b'] + \
    meio_df['quantidade_quadrante_c'] + meio_df['quantidade_quadrante_d']


# Coef = 1.5
print("COEF = 1.5")
umemeio_df = pd.read_csv('umemeio.csv')
umemeio_df = umemeio_df.loc[umemeio_df['quantidade_quadrante_a'] > 0, ['quantidade_quadrante_a',
                                                                       'quantidade_quadrante_b', 'quantidade_quadrante_c', 'quantidade_quadrante_d']]

umemeio_df['queima_total'] = umemeio_df['quantidade_quadrante_a'] + umemeio_df['quantidade_quadrante_b'] + \
    umemeio_df['quantidade_quadrante_c'] + umemeio_df['quantidade_quadrante_d']


# Base Até a borda
print("COEF = 1 até borda")
base_borda_df = pd.read_csv('base_ate_borda.csv')
base_borda_df = base_borda_df.loc[base_borda_df['quantidade_quadrante_a'] > 0]

base_borda_df['queima_total'] = base_borda_df['quantidade_quadrante_a'] + base_borda_df['quantidade_quadrante_b'] + \
    base_borda_df['quantidade_quadrante_c'] + \
    base_borda_df['quantidade_quadrante_d']


# Coef = 0.5 Até a borda
print("COEF = 0.5 até borda")
meio_borda_df = pd.read_csv('meio_ate_borda.csv')
meio_borda_df = meio_borda_df.loc[meio_borda_df['quantidade_quadrante_a'] > 0]

meio_borda_df['queima_total'] = meio_borda_df['quantidade_quadrante_a'] + meio_borda_df['quantidade_quadrante_b'] + \
    meio_borda_df['quantidade_quadrante_c'] + \
    meio_borda_df['quantidade_quadrante_d']


# Coef = 1.5 Até a borda
print("COEF = 1.5 até borda")
umemeio_borda_df = pd.read_csv('umemeio_ate_borda.csv')
umemeio_borda_df = umemeio_borda_df.loc[umemeio_borda_df['quantidade_quadrante_a'] > 0]

umemeio_borda_df['queima_total'] = umemeio_borda_df['quantidade_quadrante_a'] + umemeio_borda_df['quantidade_quadrante_b'] + \
    umemeio_borda_df['quantidade_quadrante_c'] + \
    umemeio_borda_df['quantidade_quadrante_d']


# Oeste Leste
print("Oeste Leste")
oeste_leste_df = pd.read_csv('oesteleste.csv')
oeste_leste_df = oeste_leste_df.loc[oeste_leste_df['quantidade_quadrante_a'] > 0, ['quantidade_quadrante_a',
                                                                                   'quantidade_quadrante_b', 'quantidade_quadrante_c', 'quantidade_quadrante_d']]
oeste_leste_df.plot()
oeste_leste_df['queima_total'] = oeste_leste_df['quantidade_quadrante_a'] + oeste_leste_df['quantidade_quadrante_b'] + \
    oeste_leste_df['quantidade_quadrante_c'] + \
    oeste_leste_df['quantidade_quadrante_d']


# Sudeste Noroeste
print("Sudeste Noroeste")
sudeste_noroeste_df = pd.read_csv('sudestenoroeste.csv')
sudeste_noroeste_df = sudeste_noroeste_df.loc[sudeste_noroeste_df['quantidade_quadrante_a'] > 0, ['quantidade_quadrante_a',
                                                                                                  'quantidade_quadrante_b', 'quantidade_quadrante_c', 'quantidade_quadrante_d']]
sudeste_noroeste_df.plot()
sudeste_noroeste_df['queima_total'] = sudeste_noroeste_df['quantidade_quadrante_a'] + sudeste_noroeste_df['quantidade_quadrante_b'] + \
    sudeste_noroeste_df['quantidade_quadrante_c'] + \
    sudeste_noroeste_df['quantidade_quadrante_d']


print("MEAN")
print(oeste_leste_df.mean())
print("MIN")
print(oeste_leste_df.min())
print("MAX")
print(oeste_leste_df.max())
print("DP")
print(oeste_leste_df.std())
# x = oeste_leste_df['iteracoes_ate_apagar'].to_list()
# y = oeste_leste_df['queima_total'].to_list()

# xy = []

# for i in range(len(x)):
#     xy.append(x[i])
#     xy.append(y[i])
# print(xy)
