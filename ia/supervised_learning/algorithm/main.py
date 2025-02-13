"""Implementação do algoritmo KNN para classificação binária de se a pessoa tem diabetes ou não.
Formato do  dataset
--------------------
Pregnancies,Glucose,BloodPressure,SkinThickness,Insulin,BMI,DiabetesPedigreeFunction,Age,Outcome
"""
from argparse import ArgumentParser
from typing import Callable
import pandas as pd
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, confusion_matrix
from sklearn.preprocessing import MinMaxScaler, RobustScaler, StandardScaler
import matplotlib.pyplot as plt
import numpy.typing as npt
from icecream import ic


def get_file_logger(file: str) -> Callable[[str], None]:
    """Retorna uma função que loga mensagens em um arquivo.

    Args:
        file (str): file path

    Returns:
        callable: Função que loga mensagens em um arquivo
    """
    def file_logger(text: str) -> None:
        with open(file=file, mode='a', encoding='utf-8') as f:
            f.write(text + '\n')
    return file_logger


def get_measures(conf_matrix: npt.NDArray) -> dict[str, float]:
    """Calcula as métricas de classificação a partir da matriz de confusão.

    Args:
        confusion_matrix (npt.ArrayLike): Matriz de confusão

    Returns:
        dict[str, float]: Dicionário com as métricas de classificação

    """
    tp = int(conf_matrix[1, 1])
    fp = int(conf_matrix[0, 1])
    fn = int(conf_matrix[1, 0])

    precision = tp / (tp + fp)
    recall = tp / (tp + fn)
    f1_score = 2 * (precision * recall) / (precision + recall)

    return {'precision': precision, 'recall': recall, 'f1_score': f1_score}


def get_metrics(conf_matrix: npt.NDArray) -> dict[str, int]:
    """Calcula as métricas de classificação a partir da matriz de confusão.

    Args:
        confusion_matrix (npt.ArrayLike): Matriz de confusão

    Returns:
        dict[str, int]: Dicionário com as métricas de classificação

    """
    tp = int(conf_matrix[1, 1])
    tn = int(conf_matrix[0, 0])
    fp = int(conf_matrix[0, 1])
    fn = int(conf_matrix[1, 0])

    return {'tp': tp, 'tn': tn, 'fp': fp, 'fn': fn}


def pre_process(data: pd.DataFrame, threshold: float) -> tuple[pd.DataFrame, pd.Series]:
    """Seleciona as variáveis mais relevantes para o modelo.

    Args:
        data (pd.DataFrame): Base de dados

    Returns:
        tuple[pd.DataFrame, pd.Series]: Dataframe com as váriaveis independentes e a série com a
        variável dependente (target column)
    """
    correlation_matrix = data.corr()
    relevant_features = correlation_matrix[abs(
        correlation_matrix['Outcome']) > threshold].index.tolist()
    relevant_features.remove('Outcome')  # Remove the target variable
    ic(relevant_features)
    y = data['Outcome']
    x = data[relevant_features]
    return x, y


def knn(
        x: npt.ArrayLike,
        y: npt.ArrayLike,
        k: int,
        scaler: MinMaxScaler | RobustScaler | StandardScaler
) -> tuple[float, float, dict[str, int], dict[str, float], npt.ArrayLike]:
    """Executa o algoritmo KNN para classificação binária.

    Args:
        x (npt.ArrayLike): Variáveis independentes
        y (npt.ArrayLike): Variável dependente
        k (int): Número de vizinhos

    Returns:
        tuple[float, float, npt.ArrayLike, dict | str]: Dados de saída

        accuracy: Acurácia
        cv_accuracy: Acurácia cross-validada
        conf_matrix: Matriz de confusão
        report: Relatório de classificação
    """
    x_train, x_test, y_train, y_test = train_test_split(
        x, y, test_size=0.3, train_size=0.7, random_state=42)

    x_train_scaled = scaler.fit_transform(x_train)
    x_test_scaled = scaler.transform(x_test)

    clf = KNeighborsClassifier(
        n_neighbors=k, weights='distance')

    clf.fit(x_train_scaled, y_train)

    y_pred = clf.predict(x_test_scaled)

    accuracy = accuracy_score(y_test, y_pred)

    cv_accuracy = cross_val_score(
        clf, x_train_scaled, y_train, cv=5, scoring='accuracy').mean()
    conf_matrix = confusion_matrix(y_test, y_pred)
    return (
        float(accuracy),
        cv_accuracy,
        get_metrics(conf_matrix),
        get_measures(conf_matrix),
        conf_matrix
    )


def test_knn(
        x: npt.ArrayLike,
        y: npt.ArrayLike,
        scaler: MinMaxScaler | RobustScaler | StandardScaler
) -> dict[int, tuple[float, float, dict[str, int], dict[str, float], npt.ArrayLike]]:
    """Testa o algoritmo KNN para diferentes valores de k.

    Args:
        x (npt.ArrayLike): Variáveis independentes
        y (npt.ArrayLike): Variável dependente

    Returns:
        dict[int, tuple[float, float, npt.ArrayLike, dict | str]]:
        Dicionário com os resultados para cada valor de k

        k -> (accuracy, cv_accuracy, conf_matrix, report)
    """
    # [3, 5, 7, 9, 11, 13, 15, 17, 19, 21]
    return {k: knn(x, y, k, scaler) for k in range(3, 102, 2)}


def main(k: int | None, threshold: float, scaler: MinMaxScaler | RobustScaler | StandardScaler):
    """Executa o algoritmo KNN para classificação binária de diabetes.

    Args:
        k (int | None, optional): Número de vizinhos utilizado no knn. Defaults to None.
    """
    # Load the data
    data = pd.read_csv('./../datasets/diabetes.csv')

    x, y = pre_process(data, threshold)
    if k:
        accuracy, cross_validation_accuracy, conf_matrix, metrics, matrix = knn(
            x, y, k, scaler)
        acuracies = f"{accuracy=}, {cross_validation_accuracy=}"
        ic(acuracies)
        ic(conf_matrix)
        ic(metrics)
        if input("Deseja plotar a matriz de confusão? (s/n): ") == 's':
            # Plot the confusion matrix as a heatmap gist_heat_r
            plt.matshow(matrix, alpha=0.7, cmap='gnuplot_r')
            plt.colorbar()
            plt.xlabel('Predicted label')
            plt.ylabel('True label')
            plt.xticks([0, 1], [0, 1])
            plt.yticks([0, 1], [0, 1])
            plt.title('Confusion Matrix')
            plt.show()

    else:
        results = test_knn(x, y, scaler)
        k_f_score: list[tuple[int, float]] = []
        for k, (accuracy, cross_validation_accuracy, conf_matrix, metrics, _) in results.items():
            k_f_score.append((k, metrics['f1_score']))

            acuracies = f"{accuracy=}, {cross_validation_accuracy=}"
            ic(k)
            ic(acuracies)
            ic(conf_matrix)
            ic(metrics)
            ic("---------------------------------------------------------")

        sorted_k_f_score = sorted(k_f_score, key=lambda x: x[1], reverse=True)
        ic("Melhores resultados:")
        ic(sorted_k_f_score[:5])

        if input("Deseja plotar a evolução do f_score: (s/n): ") == 's':
            k_values = [k for k, _ in k_f_score]
            f_scores = [f_score for _, f_score in k_f_score]
            plt.plot(k_values, f_scores)
            plt.xlabel('k')
            plt.ylabel('f1_score')
            plt.title('Evolução do f1_score')
            plt.show()


if __name__ == '__main__':
    parser = ArgumentParser(
        description='KNN para classificação binária de diabetes',
        epilog='Exemplo de uso: python main.py -k 3 -t 0.2 -s minmax',
        add_help=True
    )
    parser.add_argument(
        '-k', type=int,
        help='Número de vizinhos, se não definido irá mostrar todos resultados de 3 a 21',
        default=None)
    parser.add_argument(
        '-t', type=float,
        help='Threshold de correlação para selecionar as variáveis mais relevantes',
        default=0.2)
    parser.add_argument(
        '-s', type=str, choices=['minmax', 'robust', 'standard'],
        help='Tipo de scaler a ser utilizado', default='minmax')
    parser.add_argument(
        '--log-file', type=str, help='Arquivo de log', default=None)

    args = parser.parse_args()
    scalers: dict[str, MinMaxScaler | RobustScaler | StandardScaler] = {
        'minmax': MinMaxScaler(),
        'robust': RobustScaler(),
        'standard': StandardScaler()
    }

    assert args.k or args.k is None, "k deve ser um inteiro ou None"

    if args.log_file:
        ic.configureOutput(outputFunction=get_file_logger(args.log_file))

    main(args.k, args.t, scalers[args.s])
