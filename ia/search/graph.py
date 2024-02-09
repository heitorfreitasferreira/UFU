"""Módulo com a implementação do grafo e do algoritmo A* para encontrar o menor 
caminho entre duas cidades\n

Raises:
    KeyError: Tenta acessar um vértice que não existe
    KeyError: Tentativa de acessar um vértice que não existe pelo nome
    ValueError: Tentativa de acessar um vértice com um tipo de dado inválido
"""
from typing import List, Set, Dict


class Vertex:
    """Classe que representa um vértice do grafo
    """

    def __init__(self, vertex_id: int, name: str, lat: float, long: float):
        """Construtor da classe Vertex

        Args:
            vertex_id (int): identificador ÚNICO do vértice, fica a 
            resposabilidade do usuário garantir a unicidade
            name (str): Nome do vértice, normalmente cidade
            lat (float): Latitude da cidade para ser usado na heurística do 
            algoritmo A*
            long (float): Longitude da cidade para ser usado na heurística do 
            algoritmo A*
        """
        self.id = vertex_id
        self.name = name
        self.lat = lat
        self.long = long
        self.neighbors: List[Vertex] = []

    def add_neighbor(self, neighbor: 'Vertex') -> None:
        """Adiciona um vizinho ao vértice

        Args:
            neighbor (Vertex): Vizinho a ser adicionado
        """
        if neighbor not in self.neighbors:
            self.neighbors.append(neighbor)

    def get_euclidian_distance(self, vertex: 'Vertex') -> float:
        """Calcula a distância euclidiana entre dois vértices

        Args:
            vertex (Vertex): Vértice para calcular a distância

        Returns:
            float: distância euclidiana entre os vértices
        """
        return ((self.lat - vertex.lat) ** 2 + (self.long - vertex.long) ** 2) ** 0.5

    def __str__(self):
        return self.name


class Graph:
    """Classe que representa um grafo não direcionado
    """

    def __init__(self):
        self.vertices: Dict[int, Vertex] = {}

    def add_vertex(self, vertex: Vertex):
        """Adiciona um vértice ao grafo

        Args:
            vertex (Vertex): Vértice a ser adicionado

        Returns:
            boolean: True se o vértice foi adicionado, False caso contrário
        """
        if isinstance(vertex, Vertex) and vertex.id not in self.vertices:
            self.vertices[vertex.id] = vertex
            return True
        return False

    def add_edge(self, v1: int, v2: int):
        """Adiciona uma aresta entre dois vértices consideraqndo que o grafo é não direcionado

        Args:
            v1 (int): identificador do vértice 1
            v2 (int): identificador do vértice 2

        Returns:
            boolean: True se a aresta foi adicionada, False caso contrário
        """
        if v1 in self.vertices and v2 in self.vertices:
            self.vertices[v1].add_neighbor(self.vertices[v2])
            self.vertices[v2].add_neighbor(self.vertices[v1])
            return True
        return False

    def get_vertices(self):
        """Retorna os vértices do grafo

        Returns:
            List[Vertex]: Lista de vértices do grafo
        """
        return self.vertices.keys()

    def get_vertex_by_id(self, vertex_id: int) -> Vertex:
        """Retorna um vértice pelo identificador

        Args:
            vertex_id (int): identificador do vértice

        Raises:
            KeyError: Não encontrou o vértice

        Returns:
            Vertex: Vértice encontrado
        """
        if vertex_id in self.vertices:
            return self.vertices[vertex_id]
        raise KeyError(f"Vertex {vertex_id} not found")

    def get_vertex_by_name(self, name: str) -> Vertex:
        """Retorna um vértice pelo nome, preferir usar a busca pelo 
        identificador que é mais performática

        Args:
            name (str): nome do vértice

        Raises:
            KeyError: Não encontrou o vértice

        Returns:
            Vertex: Vértice encontrado
        """
        for vertex in self.vertices.values():
            if vertex.name == name:
                return vertex
        raise KeyError(f"Vertex {name} not found")

    def get_vertex(self, key) -> Vertex:
        """Retorna um vértice pelo identificador ou pelo nome

        Args:
            key (str|int): identificador ou nome do vértice

        Raises:
            ValueError: Tipo de busca não suportada

        Returns:
            Vertex: Vértice encontrado
        """
        if isinstance(key, int):
            return self.get_vertex_by_id(key)
        if isinstance(key, str):
            return self.get_vertex_by_name(key)
        raise ValueError("Key must be an integer or a string")

    def a_star(self, start_id: int, end_id: int, view_trace=False):
        """Executa o algoritmo A* para encontrar o menor caminho entre dois vértices

        Args:
            start_id (int): identificador do vértice de origem
            end_id (int): identificador do vértice de destino
            view_trace (bool, optional): Flag indicando se deverá imprimir na 
            tela o caminho percorrido pelo algoritmo até encontrar o menor 
            caminho. Defaults to False.

        Returns:
            List[Vertex]: Menor caminho entre os vértices de origem e destino
        """
        if start_id == end_id:
            return [self.get_vertex_by_id(start_id)]
        start = self.get_vertex_by_id(start_id)
        end = self.get_vertex_by_id(end_id)

        # Cidades a serem avaliadas
        cidades_a_avaliar: Set[Vertex] = {start}
        # Cidades já avaliadas
        cidades_ja_avaliadas: Set[Vertex] = set()
        came_from: Dict[Vertex, Vertex] = {}
        # Distância do início até cada vértice
        g_score: Dict[Vertex, float] = {vertex: float(
            'inf') for vertex in self.vertices.values()}
        # Distância do início até o início é 0
        g_score[start] = 0
        # Distância do início até o final passando por cada vértice
        f_score: Dict[Vertex, float] = {vertex: float(
            'inf') for vertex in self.vertices.values()}
        # Distância em linha reta do vértice até o final
        # (a solução ótima tenta minimizar até essa distância)
        f_score[start] = start.get_euclidian_distance(end)
        # Enquanto houver cidades a serem avaliadas
        while cidades_a_avaliar:
            # Define a cidade a ser avaliada como a cidade com menor distância até o final
            onde_estou: Vertex = min(cidades_a_avaliar,
                                     key=lambda vertex: f_score[vertex])
            # Se chegou ao fim, constrói o caminho e o retorna
            if onde_estou == end:
                path = [onde_estou]
                while onde_estou in came_from:
                    onde_estou = came_from[onde_estou]
                    path.append(onde_estou)
                return path[::-1]
            # Remove a cidade a ser avaliada do conjunto de cidades a serem
            # avaliadas e adiciona ao conjunto de cidades já avaliadas
            cidades_a_avaliar.remove(onde_estou)
            cidades_ja_avaliadas.add(onde_estou)
            # Para cada vizinho da cidade a ser avaliada
            for neighbor in onde_estou.neighbors:
                # Se o vizinho já foi avaliado, pula para o próximo
                if neighbor in cidades_ja_avaliadas:
                    continue
                # Calcula a distância do início até o vizinho passando pela cidade a ser avaliada
                tentative_g_score = g_score[onde_estou] + \
                    onde_estou.get_euclidian_distance(neighbor)
                # Se a cidade a ser avaliada não está no conjunto de cidades
                # a serem avaliadas a adiciona
                if neighbor not in cidades_a_avaliar:
                    cidades_a_avaliar.add(neighbor)

                # Se estiver, mas a distância do início até o vizinho passando
                # pela cidade a ser avaliada for maior que a distância já
                #  calculada, pula para o próximo
                elif tentative_g_score >= g_score[neighbor]:
                    continue
                # Se chegou até aqui, é porque a distância do início até o
                # vizinho passando pela cidade a ser avaliada é menor que a
                # distância já calculada
                came_from[neighbor] = onde_estou
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + \
                    neighbor.get_euclidian_distance(end)
                if view_trace:
                    print(f"{onde_estou.name} -> {neighbor.name} \t\t\t "
                          f"g({neighbor.name})={g_score[neighbor]}, "
                          f"h({neighbor.name})={neighbor.get_euclidian_distance(end)}, "
                          f"f({neighbor.name})={f_score[neighbor]}")
        # Não há caminho entre o início e o fim
        if view_trace:
            print(f"Não há caminho entre {start.name} e {end.name}")
        return []
