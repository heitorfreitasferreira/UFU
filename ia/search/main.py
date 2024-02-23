"""Main module

"""
#!/usr/bin/env python3
import argparse
import sys
from typing import List
from csv import reader as csv_reader
from graph import Graph, Vertex


def print_path(path: List[Vertex]):
    """Printa o caminho a ser tomado e a distância total

    Args:
        path (List[Vertex]): Lista de nós que representam as cidades
    """
    if not path or len(path) < 1:
        print("Não há caminho entre as cidades")
        return
    print("Caminho a ser tomado: " +
          " -> ".join([vertex.name for vertex in path]))

    print("Distância total: " +
          str(sum([path[i].get_euclidian_distance(path[i+1]) for i in range(len(path)-1)]))+"km\n")


def read_cities_from_file(file_path: str):
    """lê o arquivo csv com as cidades, identificador e suas coordenadas\n
    formato esperado do cabeçalho e das linhas do arquivo csv:\n
    ID,Name,Latitude,Longitude\n
    1,Uberlândia,-18.9128,-48.2755\n
    2,Uberaba,-19.7474,-47.9381\n


    Args:
        file_path (str): caminho do arquivo csv 

    Returns:
        _type_: List[Tuple[int, str, float, float]
    """
    cities_info_parsed = []
    try:
        with open(file_path, mode='r', encoding='utf-8') as file:
            reader = csv_reader(file)
            next(reader)
            for row in reader:
                cities_info_parsed.append(
                    (int(row[0]), row[1], float(row[2]), float(row[3])))
    except FileNotFoundError:
        print(f"Arquivo {file_path} com os dados das cidades não encontrado")
        sys.exit(1)
    return cities_info_parsed


def read_edges_from_file(file_path: str):
    """lê o arquivo csv com as arestas entre as cidades\n
    formato esperado do cabeçalho e das linhas do arquivo csv:\n
    City1,City2\n
    1,2\n
    1,3\n

    Args:
        file_path (str): caminho do arquivo csv

    Returns:
        List[Tuple[int, int]: Lista de tuplas com as arestas entre as cidades
    """
    edges_parsed = []
    try:
        with open(file_path, mode='r', encoding='utf-8') as file:
            reader = csv_reader(file)
            next(reader)  # Pula o cabeçalho
            for row in reader:
                city1_id = int(row[0])
                city2_id = int(row[1])
                edges_parsed.append((city1_id, city2_id))
    except FileNotFoundError:
        print(
            f"Arquivo {file_path} com as arestas entre as cidades não encontrado")
        sys.exit(1)
    return edges_parsed


def main(
        starting_city: int,
        view_trace: bool,
        end_city: int,
        cities_filepath: str,
        edges_filepath: str,
        algorithm
):
    """Função principal que lê os arquivos csv com as cidades e as arestas
    entre elas, instância o grafo e executa o algoritmo A* para encontrar 
    o menor caminho entre as cidades

    Args:
        starting_city (int): id da cidade de origem
        view_trace (bool): indica se deve ser mostrada a árvore de vértices visitados
        end_city (int): id da cidade de destino
        cities_filepath (str): caminho do arquivo csv com a informação das 
        cidades como id, nome e coordenadas
        edges_filepath (str): caminho do arquivo csv com as arestas entre as cidades
    """

    # Instanciando o grafo
    g = Graph()

    # Lista de cidades com identificador, nome e coordenadas aproximadas (latitude, longitude)
    cities_info = read_cities_from_file(cities_filepath)

    # Adicionando vértices ao grafo
    for city in cities_info:
        g.add_vertex(Vertex(*city))

    edges = read_edges_from_file(edges_filepath)

    for edge in edges:
        g.add_edge(*edge)
    if end_city != -1:
        print(
            f"De {g.get_vertex(starting_city).name} para {g.get_vertex(end_city).name}")
        path = g.get_path(starting_city, end_city, algorithm, view_trace=view_trace)
        print_path(path)
        return
    for i in range(1, 30):
        if i == starting_city:
            continue
        print(
            f"De {g.get_vertex(starting_city).name} para {g.get_vertex_by_id(i).name}")
        path = g.get_path(starting_city, i, algorithm, view_trace=view_trace)
        print_path(path)


if __name__ == "__main__":
    parser = argparse.ArgumentParser("A* Search Algorithm")

    parser.add_argument("-s", "--starting_city",
                        help="Starting city", type=int, default=1)
    parser.add_argument(
        "--view_trace", help="View all vertex visited in the search", action="store_true")
    parser.add_argument("-e", "--end_city",
                        help="End city", type=int, default=-1)
    parser.add_argument("-f", "--cities_filepath",
                        help="Path to a csv file containing the cities data", default="cities.csv")
    parser.add_argument("--edges_filepath", help="Path to a csv file containing the edges data",
                        default="edges.csv")
    parser.add_argument("--algorithm", help="Algorithm to be used [a_star, bfs, dfs]",
                        default="a_star")


    main(**vars(parser.parse_args()))
