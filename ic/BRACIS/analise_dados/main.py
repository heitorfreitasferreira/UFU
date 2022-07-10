medias_execucao = []
def apagou_fogo(reticulado):
    for i in range(len(reticulado)):
        for j in range(len(reticulado[i])):
            if int(reticulado[i][j]) > 0 and int(reticulado[i][j]) < 4:
                return True
    return False
def tem_fogo(reticulado):
    not apagou_fogo(reticulado)
f = open("data\\base_3_20_37_.txt")
qnt_focos_esquerda = 0
qnt_focos_direita = 0
def detecta_novo_foco(reticulado,passado):
    for i in range(len(reticulado)):
        for j in range(len(reticulado[i])):
            estado_atual = int(reticulado[i][j])
            estado_passado = int(passado[i][j])
            if estado_atual > 0 and estado_atual < 4:
                if  estado_passado > 4 and estado_passado < 7:
                    print("pegou fogo")
                    if i < len(reticulado) / 2:
                        qnt_focos_esquerda += 1
                    else:
                        qnt_focos_direita += 1

execucoes = []
reticulado_tmp = []
for linha in f:
    if linha.strip() != "-":
        listRes = list(linha.strip().split(" "))
        reticulado_tmp.append(listRes)
    else:
        execucoes.append(reticulado_tmp)
        reticulado_tmp = []
f.close()
for i in range(1,100):
    reticulado = execucoes[i]
    passado = execucoes[i-1]
    detecta_novo_foco(reticulado,passado)

print(qnt_focos_esquerda,qnt_focos_direita)