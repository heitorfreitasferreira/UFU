def sscml(prefixo, V):
    if len(V) == 1:  # Falta so um elemento
        if len(prefixo) == 0 or V[0] >= prefixo[len(prefixo)-1]:  # Compatível
            return prefixo + V[0]  # Leva
        return prefixo  # Não leva
    x = V[0]  # Vou decidir sobre o primeiro elemento
    sem = sscml(prefixo, V[1:])  # Não levo
    if len(prefixo) == 0 or x >= prefixo[len(prefixo)-1]:
        com = sscml(prefixo+x, V[1:])  # Levo
        if len(com) > len(sem):
            return com
        return sem
