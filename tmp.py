# def sscml(prefixo, V):
#     if len(V) == 1:  # Falta so um elemento
#         if len(prefixo) == 0 or V[0] >= prefixo[len(prefixo)-1]:  # Compatível
#             return prefixo + V[0]  # Leva
#         return prefixo  # Não leva
#     x = V[0]  # Vou decidir sobre o primeiro elemento
#     sem = sscml(prefixo, V[1:])  # Não levo
#     if len(prefixo) == 0 or x >= prefixo[len(prefixo)-1]:
#         com = sscml(prefixo+x, V[1:])  # Levo
#         if len(com) > len(sem):
#             return com
#         return sem

def transformar(matriz):
    a = 1
    e = 1
    f = 1
    retorno = {}
    for lista in matriz[3]:
        for dicionario in lista:
            if "F"  in dicionario.keys():
                retorno["F"+str(f)] = dicionario["F"]
                f+=1
            if "E"  in dicionario.keys():
                retorno["E"+str(e)] = dicionario["E"]
                e+=1
            if "A"  in dicionario.keys():
                retorno["A"+str(a)] = dicionario["A"]
                a+=1
    print(retorno)
transformar([[[1.0, 3.0, 4.0], [2.0, 4.0, 6.0], [3.0, 5.0, 8.0]], ['<', '>', '='], [30.0, 12.0, 4.0], [[{'F': 1}, {'E': 0, 'A': 0}, {'A': 0}], [{'F': 0}, {'E': -1, 'A': 1}, {'A': 0}], [{'F': 0}, {'E': 0, 'A': 0}, {'A': 1}]]])