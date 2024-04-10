import argparse
from typing import Literal

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score

def pre_process(df: pd.DataFrame)-> tuple[pd.DataFrame, np.ndarray]:
    """Remove rows with 'season' < 3, drop columns: 'event', 'team', 'season',
    replace missing values with the mean of each column in: 'damage',
    'damage/min' and 3 other columns, drop columns: 'wins', 'loses'
    and 4 other columns

    Args:
        df (pd.DataFrame): dataframe

    Returns:
        tuple[pd.DataFrame, np.ndarray]: dataframe cleaned and player_id_name relation
    """
    # Drop where 'season' is < 3
    df = df[df["season"] >= 3]

    # Drop columns: 'event', 'team', 'season'
    df = df.drop(columns=["event", "team", "season"])

    # Replace missing values with the mean of each column in: 'damage',
    # 'damage/min' and 3 other columns
    df = df.fillna(
        {
            "damage": df["damage"].mean(),
            "damage/min": df["damage/min"].mean(),
            "kill_participation": df["kill_participation"].mean(),
            "kill_share": df["kill_share"].mean(),
            "gold_share": df["gold_share"].mean(),
        }
    )

    # Drop columns: 'wins', 'loses' and 4 other columns
    df = df.drop(
        columns=[
            "wins",
            "loses",
            "kill_death_assist_ratio",
            "creep_score",
            "gold",
            "damage",
        ]
    )
    df['player_id'] = pd.Series(range(1, len(df) + 1))
    # create an 2xlen(df) array with the player_id column and player name
    player_id = df["player_id"]
    player_name = df["player"]
    player_id_name = np.array([player_id, player_name])

    df = df.drop('player', axis=1)
    return (df, player_id_name)

def test(df):
    wcss = []
    for k in range(2, 11):
        kmeans = KMeans(n_clusters=k, algorithm='lloyd', n_init=10).fit(df)
        wcss.append(kmeans.inertia_)

    plt.plot(range(2, 11), wcss, marker='o')
    plt.xlabel('Number of Clusters (k)')
    plt.ylabel('WCSS')
    plt.title('Elbow Method')
    plt.show()

def main(*, k: int = -1, algorithm: Literal['lloyd', 'elkan', 'auto', 'full'], n_init: Literal["auto"] | int):
    df, player_id_name = pre_process(pd.read_csv("./data/players_stats.csv"))
    df.dropna(inplace=True)
    if k == -1:
        test(df)
    else:
        kmeans = KMeans(n_clusters=k, algorithm= algorithm, n_init=n_init).fit(df)
        sil_coeff = silhouette_score(df.drop("labels", axis=1), df["labels"])
        print("Silhouette Coefficient:", round(sil_coeff, 3))

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-k', type=int, default=-1)
    parser.add_argument('-a', type=str, default='lloyd', choices=['lloyd', 'elkan'])
    parser.add_argument('-n', type=int, default=300)
    args = parser.parse_args()
    main(k=args.k, algorithm=args.a, n_init=300)
