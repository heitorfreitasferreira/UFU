import glob
import os
import ast
import json
import pandas as pd
import matplotlib.pyplot as plt


def quadrante(i, j) -> str:
    return f'q{i}_{j}'


os.chdir(r'/home/ubuntu_heitor/UFU/ic/analise_multiplos_estados/data')
my_files = glob.glob('*.txt')
data = {}
for file in my_files:
    key_name: str
    if "3veg" in file:
        key_name = f"3_{file[10:-5]}"
    elif "2veg" in file:
        key_name = f"2_{file[10:-5]}"
    else:
        key_name = f"2_{file[5:-5]}"
    data[key_name] = []
    with open(file, 'r') as f:
        f = f.read()
        data[key_name] = ast.literal_eval(f)
mean = {}
for chave in data.keys():
    length = len(data[chave])
    mean[chave] = {}

    for i in range(3):
        for j in range(3):
            mean[chave][quadrante(i, j)] = 0

    for i in range(length):
        for j in range(3):
            for k in range(3):
                mean.get(chave)[quadrante(j, k)
                                ] += (data[chave][i][j][k])/length

df = pd.DataFrame.from_dict(mean).transpose()

print(df)

df.plot()

plt.show()
