# import sys


# class Graph(object):
#     def __init__(self, nodes, init_graph):
#         self.nodes = nodes
#         self.graph = self.construct_graph(nodes, init_graph)

#     def construct_graph(self, nodes, init_graph):
#         '''
#         This method makes sure that the graph is symmetrical. In other words, if there's a path from node A to B with a value V, there needs to be a path from node B to node A with a value V.
#         '''
#         graph = {}
#         for node in nodes:
#             graph[node] = {}

#         graph.update(init_graph)

#         for node, edges in graph.items():
#             for adjacent_node, value in edges.items():
#                 if graph[adjacent_node].get(node, False) == False:
#                     graph[adjacent_node][node] = value

#         return graph

#     def get_nodes(self):
#         "Returns the nodes of the graph."
#         return self.nodes

#     def get_outgoing_edges(self, node):
#         "Returns the neighbors of a node."
#         connections = []
#         for out_node in self.nodes:
#             if self.graph[node].get(out_node, False) != False:
#                 connections.append(out_node)
#         return connections

#     def value(self, node1, node2):
#         "Returns the value of an edge between two nodes."
#         return self.graph[node1][node2]

#     def dijkstra(self, start_node):  # self is the graph
#         # FASE DE INICIALIZAÇÃO
#         unvisited_nodes = list(self.get_nodes())
#         shortest_path = {}  # DICIONÁRIO QUE GUARDA O CAMINHO MÍNIMO PARA OS NÓS
#         max_value = sys.maxsize  # infinito
#         for node in unvisited_nodes:
#             shortest_path[node] = max_value
#         shortest_path[start_node] = 0
#         # FASE DE RELAXAMENTO
#         while unvisited_nodes:
#             current_min_node = None
#             for node in unvisited_nodes:  # Iterate over the nodes
#                 if current_min_node == None:
#                     current_min_node = node
#                 elif shortest_path[node] < shortest_path[current_min_node]:
#                   # Aqui q ta o segredo
#                     current_min_node = node
#         return shortest_path  # dictioanry with the shortest path to each node
#         # O(Vertices* log(Vertices)+Edges)

#     def get_shortest_path(self, start_node, end_node):  # self is the graph
#         shortest_path = self.dijkstra(start_node)
#         path = []
#         while end_node != start_node:
#             path.append(end_node)
#             end_node = shortest_path[end_node]
#         path.append(start_node)
#         path.reverse()
#         return path


# lista = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# for x, y in lista:
#     print(x, y)


from re import I


class Item:
    def __init__(self, valor, peso):
        self.peso = peso
        self.valor = valor


class Mochila:

    def adiciona_item_DC(self, itens, capacidade):
        if len(itens) == 0 or capacidade == 0:
            return 0
        if itens[0].peso > capacidade:
            return self.adiciona_item_DC(itens[1:], capacidade)
        com_item = self.adiciona_item_DC(
            itens[1:], capacidade - itens[0].peso) + itens[0].valor
        sem_item = self.adiciona_item_DC(itens[1:], capacidade)
        return max(com_item, sem_item)

    def adiciona_item_topdown(self, itens, capacidade):
        memo = []
        for i in range(len(itens) + 1):
            memo.append([])
            for j in range(capacidade + 1):
                memo[i].append(None)
        for i in range(len(itens) + 1):
            memo[i][0] = 0
        for i in range(capacidade + 1):
            memo[0][i] = 0
        retorno = self.__topdown_aux(itens, capacidade, memo)
        print(memo)
        return retorno

    def __printa(self, memo):
        for i in range(len(memo)):
            for j in range(len(memo[i])):
                print(memo[i][j], end=" ")
            print("")
        print("-----------------")

    def __topdown_aux(self, itens, capacidade, memo):
        if memo[len(itens)][capacidade] is not None:
            return memo[len(itens)][capacidade]
        if itens[0].peso > capacidade:
            memo[len(itens)][capacidade] = self.__topdown_aux(
                itens[1:], capacidade, memo)
        else:
            com_item = self.__topdown_aux(
                itens[1:], capacidade - itens[0].peso, memo) + itens[0].valor
            sem_item = self.__topdown_aux(itens[1:], capacidade, memo)
            memo[len(itens)][capacidade] = max(com_item, sem_item)
        return memo[len(itens)][capacidade]

    def adiciona_item_bottomup(self, itens, capacidade):
        memo = []
        for i in range(len(itens) + 1):
            memo.append([])
            for j in range(capacidade + 1):
                memo[i].append(None)
        for i in range(len(itens) + 1):
            memo[i][0] = 0
        for i in range(capacidade + 1):
            memo[0][i] = 0
        self.__printa(memo)

        for j in range(1, capacidade):
            for x in range(len(itens)):
                if itens[j].peso > x:
                    memo[j][x] = memo[j - 1][x]
                else:
                    usa = memo[j-1][x-itens[j].peso] + itens[j].valor
                    nao_usa = memo[j-1][x]
                    memo[j][x] = max(usa, nao_usa)
                self.__printa(memo)

        return memo[len(itens)][capacidade]


mochila = Mochila()
itens = [Item(3, 4), Item(2, 3), Item(4, 2), Item(4, 3)]

# itens = [Item(60, 1), Item(150, 3), Item(120, 3), Item(
#   160, 4), Item(200, 5), Item(150, 5), Item(60, 5)]

print(mochila.adiciona_item_bottomup(itens, 6))


[
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, None, 60, 60],
    [0, 0, 0, 0, None, 150, 150],
    [0, 0, 0, 0, None, 200, 200],
    [0, None, 0, 0, None, 200, 200],
    [0, None, 0, 120, None, 200, 200],
    [0, None, None, None, None, 200, 270],
    [0, None, None, None, None, None, 270]
]

[
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 4, 4, None, 4],
    [0, None, 4, 4, None, None, 8],
    [0, None, 4, None, None, None, 8],
    [0, None, None, None, None, None, 8]
]
