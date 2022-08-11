import sys


class Graph(object):
    def __init__(self, nodes, init_graph):
        self.nodes = nodes
        self.graph = self.construct_graph(nodes, init_graph)

    def construct_graph(self, nodes, init_graph):
        '''
        This method makes sure that the graph is symmetrical. In other words, if there's a path from node A to B with a value V, there needs to be a path from node B to node A with a value V.
        '''
        graph = {}
        for node in nodes:
            graph[node] = {}

        graph.update(init_graph)

        for node, edges in graph.items():
            for adjacent_node, value in edges.items():
                if graph[adjacent_node].get(node, False) == False:
                    graph[adjacent_node][node] = value

        return graph

    def get_nodes(self):
        "Returns the nodes of the graph."
        return self.nodes

    def get_outgoing_edges(self, node):
        "Returns the neighbors of a node."
        connections = []
        for out_node in self.nodes:
            if self.graph[node].get(out_node, False) != False:
                connections.append(out_node)
        return connections

    def value(self, node1, node2):
        "Returns the value of an edge between two nodes."
        return self.graph[node1][node2]

    def dijkstra(self, start_node):  # self is the graph
        # FASE DE INICIALIZAÇÃO
        unvisited_nodes = list(self.get_nodes())
        shortest_path = {}  # DICIONÁRIO QUE GUARDA O CAMINHO MÍNIMO PARA OS NÓS
        max_value = sys.maxsize  # infinito
        for node in unvisited_nodes:
            shortest_path[node] = max_value
        shortest_path[start_node] = 0
        # FASE DE RELAXAMENTO
        while unvisited_nodes:
            current_min_node = None
            for node in unvisited_nodes:  # Iterate over the nodes
                if current_min_node == None:
                    current_min_node = node
                elif shortest_path[node] < shortest_path[current_min_node]:
                  # Aqui q ta o segredo
                    current_min_node = node
        return shortest_path  # dictioanry with the shortest path to each node
        # O(Vertices* log(Vertices)+Edges)

    def get_shortest_path(self, start_node, end_node):  # self is the graph
        shortest_path = self.dijkstra(start_node)
        path = []
        while end_node != start_node:
            path.append(end_node)
            end_node = shortest_path[end_node]
        path.append(start_node)
        path.reverse()
        return path
