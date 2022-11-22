import ast
import glob
import json
import os

import matplotlib.pyplot as plt
import pandas as pd


def extract_data(path: str) -> dict:
    os.chdir(path)
    my_files = glob.glob('*.txt')
    data = {}
    for file in my_files:
        key_name: str = file[1:-4]

        data[key_name] = []
        with open(file, 'r') as f:
            linhas = f.readlines()
            for linha in linhas:
                arr = linha.split(",")
                for i in range(len(arr)-1):
                    arr[i] = int(arr[i])
                arr.pop()
                data[key_name].append(arr)
    return data


def humidity_vegetation_dicts(data: dict) -> (dict, dict):
    vegetation_mean: dict = {}
    humidity_mean: dict = {}

    vegetation_mean.setdefault("campestre", {})
    vegetation_mean.setdefault("savanica", {})
    vegetation_mean.setdefault("florestal", {})
    vegetation_types = ["campestre", "savanica", "florestal"]
    humiditys = ['80', '60', '40', '20']

    for chave in vegetation_mean.keys():
        for humidity in humiditys:
            vegetation_mean[chave][humidity]: list = []
    amout_of_lines: int
    # Populando as vegetações
    for chave in data.keys():
        amout_of_lines = len(data[chave])
        line_length = len(data[chave][0])
        vegetation_name: str
        humidity: str
        if "100" in chave:
            vegetation_name = chave[:-4]
            humidity = chave[-3:]

        else:
            vegetation_name = chave[:-3]
            humidity = chave[-2:]
        vegetation_mean[vegetation_name][humidity] = [0]*line_length
        for i in range(amout_of_lines):
            for j in range(line_length):
                vegetation_mean[vegetation_name][humidity][j] += data[chave][i][j]

    for humidity in humiditys:
        humidity_mean[humidity]: dict = {}
        for vegetation_type in vegetation_types:
            humidity_mean[humidity][vegetation_type]: list = []

    for vegetation_type in vegetation_types:
        for humidity in humiditys:
            for i in range(len(vegetation_mean[vegetation_type][humidity])):
                humidity_mean[humidity][vegetation_type].append(
                    vegetation_mean[vegetation_type][humidity][i])
    return vegetation_mean, humidity_mean


def normalize_data(vegetation_mean, humidity_mean) -> (dict, dict):
    amout_of_lines: int
    for chave in data.keys():
        amout_of_lines = len(data[chave])
    for vegetacao in vegetation_mean.keys():
        for humidity in vegetation_mean[vegetacao].keys():
            for i in range(len(vegetation_mean[vegetacao][humidity])):
                vegetation_mean[vegetacao][humidity][i] /= amout_of_lines * 256**2

    for humidity in humidity_mean.keys():
        for vegetacao in humidity_mean[humidity].keys():
            for i in range(len(humidity_mean[humidity][vegetacao])):
                humidity_mean[humidity][vegetacao][i] /= amout_of_lines * 256**2

    return vegetation_mean, humidity_mean


translator = {
    "campestre": "Meadow",
    "savanica": "Savannah",
    "florestal": "Florest",
    "Campestre": "Meadow",
    "Savanica": "Savannah",
    "Florestal": "Florest"
}


def plot_humidity_comparison(humidity_mean: dict) -> None:
    dfs = {}
    # Plotagem dos gráficos
    figure, axis = plt.subplots(1, 4, figsize=(15, 5), sharey=True)
    order = {20: 0, 40: 1, 60: 2, 80: 3}

    plt.xlabel("Step")
    plt.ylabel("Burned area (%)")
    for humidity in humidity_mean.keys():
        dfs[humidity] = pd.DataFrame.from_dict(
            humidity_mean[humidity])
        dfs[humidity].rename(
            index={0: 50, 1: 100, 2: 150, 3: 200, 4: 250, 5: 300, 6: 350, 7: 400, 8: 450, 9: 500}, inplace=True)
        dfs[humidity] = dfs[humidity][["savanica",   "florestal", "campestre"]]
        print(humidity, dfs[humidity])
        axis[order[int(humidity)]].plot(dfs[humidity])
        axis[order[int(humidity)]].set_title(f"Humidity: {humidity}%")

    for ax in axis:
        ax.set(xlabel='Steps', ylabel='Burned area (%)')
    figure.legend(
        [f"{translator[vegetacao]}" for vegetacao in dfs[humidity].columns], loc='upper right')

    plt.show()


if __name__ == "__main__":
    data = extract_data('/mnt/j/dadosIC/est')
    vegetation_dicts, humidity_dicts = humidity_vegetation_dicts(data)
    vegetation_mean, humidity_mean = normalize_data(
        vegetation_dicts, humidity_dicts)
    plot_humidity_comparison(humidity_mean)
