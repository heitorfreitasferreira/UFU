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
        for i in range(len(lista)):
            dicionario = lista[i]
            if "F"  in dicionario.keys():
                if ("F"+str(i+1)) in retorno:
                    retorno["F"+str(i+1)].append(dicionario["F"])
                else:
                    retorno["F"+str(i+1)] = [dicionario["F"]]
            if "E"  in dicionario.keys():
                if ("E"+str(i+1)) in retorno:
                    retorno["E"+str(i+1)].append(dicionario["E"])
                else:
                    retorno["E"+str(i+1)] = [dicionario["E"]]
            if "A"  in dicionario.keys():
                if "A"+str(i+1) in retorno:
                    retorno["A"+str(i+1)].append(dicionario["A"])
                else:
                    retorno["A"+str(i+1)] = [dicionario["A"]]
    print(retorno)
# transformar([[[1.0, 3.0, 4.0], [2.0, 4.0, 6.0], [3.0, 5.0, 8.0]], ['<', '>', '='], [30.0, 12.0, 4.0], [[{'F': 1}, {'E': 0, 'A': 0}, {'A': 0}], [{'F': 0}, {'E': -1, 'A': 1}, {'A': 0}], [{'F': 0}, {'E': 0, 'A': 0}, {'A': 1}]]])

# list with random ints
# import random
# lista = [random.randint(0, 100) for i in range(10)]

# for item in lista: print (item)


# print("--------------------")
# funcaoDobra = lambda x: x%2 == 0




# for item in lista: print (funcaoDobra(item))

from threading import Thread
from time import sleep




def dekker(arg, time, tID):
    flag[tID] = True
    while flag[not tID]:
        if turno == (not tID):
            flag[tID] = False
            while turno == (not tID):
                # Executar nada
                print(f"Thread {tID} bloqueada pela thread {not tID}")
            flag[tID] = True

            # Região critica
            print(f"Thread {tID} Mexendo na variavel")
            turno = not turno

            flag[tID] = False
        



def f1(arg, time, tID):
    for i in range(arg):
        print(f"Thread: {tID} = {i+1}")
        sleep(time)

def peterson(tID):
    while True:
        flag[tID] = True
        turno = tID
        while flag[not tID] and turno == (not tID):
            print(f"Thread {tID} bloqueada de entrar na região critica")
        # Região critica
        print(f"Thread {tID} EXECUTANDO REGIÃO CRITICA")
        sleep(1)
        # Fim da região critica
        flag[tID] = False


# flag = [0,0]
# dados = f"Heitor"
# turno = 0
# thread1 = Thread(target = peterson, args = (0,))
# thread2 = Thread(target = peterson, args = (1,))
# thread1.start()
# thread2.start()
# thread2.join()
# thread1.join()
# print("thread finished...exiting")

acum = 0

for i in range(64):
    acum += 2**i
print(acum)