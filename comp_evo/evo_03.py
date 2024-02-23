"""Algoritmo genético com cromossomos binários, o genótipo é representado por 
uma lista de booleanos indicando quais itens serão pegos da mochila no problema da mochila

Código base do professor em R:\n
onemax <- function(vet) {
  return(sum(vet))
}

## ALGORITMO GENETICO
# Primeira versao:
# Cria uma populacao aleatoria
# Seleciona apenas dois pais, de maneira aleatoria
# Cria dois filhos (crossover) e aplica mutacao
# Um dos filhos substitui o pior pai
## Parametros:
# - tamanho da populacao
# - tamanho do cromossomo
# - numero de geracoes
# - taxa de mutacao
ag_basico <- function(tam_pop = 10,
                      tam_crom = 8,
                      max_ger = 10,
                      prob_mut = 0.1) {
  
  # Fixa o valor da semente
  set.seed(1234)
  
  # PRIMEIRO PASSO:
  # Gerar a populacao inicial
  pop = matrix(sample(c(0,1), tam_pop*tam_crom, replace = TRUE),
               nrow = tam_pop, ncol = tam_crom)
  
  # SEGUNDO PASSO:
  # Avaliar a populacao inicial
  # Obs.: vamos considerar o valor da funcao objetivo
  #       como sendo o valor do fitness
  fitness = rep(0, tam_pop)  # cria um vetor de tam_pop elementos
  for (i in 1:tam_pop) {
    fitness[i] = onemax(pop[i,])
  }
  
  t = 0
  cat(t, "\t", max(fitness), mean(fitness), sd(fitness), "\n")
  
  # Cada passo eh uma GERACAO
  while (t <= max_ger) {
    
    t = t + 1
    
    # TERCEIRO PASSO:
    # Seleciona os pais
    # Nesta versao: seleciona dois pais e cruza
    # (depois vamos melhorar isso)
    ind_pais = sample(tam_pop, 2)
    
    # QUARTO PASSO:
    # Executa o cruzamento (crossover)
    # Seleciona o ponto de cruzamento
    p_cross = sample(tam_crom-1, 1)
    # Cruzamento dos pais
    # cria dois filhos: f1 e f2
    f1 = c(pop[ind_pais[1],1:p_cross],
           pop[ind_pais[2], (p_cross+1):tam_crom])
    f2 = c(pop[ind_pais[2],1:p_cross],
           pop[ind_pais[1], (p_cross+1):tam_crom])
    
    #print(pop[ind_pais[1],])
    #print(pop[ind_pais[2],])
    #print(f1)
    #print(onemax(pop[ind_pais[1],]))
    #print(onemax(pop[ind_pais[2],]))
    #print(onemax(f1))
    #print(onemax(f2))
    
    # QUINTO PASSO:
    # Aplica a mutacao em cada filho 
    #   com uma probabilidade prop_mut
    # Percorre o cromossomo e verifica se aplica mutacao
    for (i in 1:tam_crom) {
      if (runif(1) < prob_mut) {
        if (f1[i] == 0) f1[i] = 1
        else f1[i] = 0
      }
      
      if (runif(1) < prob_mut) {
        if (f2[i] == 0) f2[i] = 1
        else f2[i] = 0
      }
    }
    
    #print(onemax(f1))
    #print(onemax(f2))
    
    # SEXTO PASSO:
    # Insere os filhos na populacao
    if (fitness[ind_pais[1]] < fitness[ind_pais[2]]) pior = ind_pais[1]
    else pior = ind_pais[2]

    # Exercicio: fazer o *melhor* filho subsituir o *pior* pai    
    if (onemax(f1) > fitness[pior]) {
      pop[pior,] = f1
      fitness[pior] = onemax(f1)
    } else if (onemax(f2) > fitness[pior]) {
      pop[pior,] = f2
      fitness[pior] = onemax(f2)
    }
    cat(t, "\t", max(fitness), mean(fitness), sd(fitness), "\n")
  }
}
"""

from typing import List, Tuple, Callable
from enum import Enum
import argparse
import numpy as np
from numpy.typing import ArrayLike as NpArray
from matplotlib import pyplot as plt

ESTRATEGIAS_SELECAO = Enum('ESTRATEGIAS_SELECAO', [
                           'TORNEIO', 'ROLETA', 'ELITISMO'])

Alelo = bool
Fenotipo = int

Cromossomo = List[Alelo]
Individuo = Cromossomo
Populacao = List[Individuo]


def sumario_populacao(fenotipos: List[float]) -> Tuple[float, float, float]:
    """Sumário de uma população

    Args:
        pop (Populacao): população

    Returns:
        Tuple[float, float]: Média, Desvio Padrão
    """
    return (float(np.mean(fenotipos)), float(np.std(fenotipos)), max(fenotipos))


def printa_sumario_populacao(fitness: List[float]) -> None:
    """Printa o sumário da população

    Args:
        fitness (List[Fenotipo]): fitness
    """
    s = sumario_populacao(fitness)
    print(
        f"Sumário da população: \nMédia: {s[0]:.2f}",
        f"Desvio Padrão: {s[1]:.2f} "
        f"Maior fitness: {s[2]:.2f}",
    )


def printa_populacao(
    pop: Populacao,
    fitness: List[Fenotipo],
    print_summary: bool = False
) -> None:
    """Printa a população

    Args:
        pop (Populacao): população
    """
    if print_summary:
        printa_sumario_populacao(fitness)
        print()

    for i, individuo in enumerate(pop):
        print(f"Individuo[{i}]", end=": ")
        for j, gene in enumerate(individuo):
            print(int(gene), end=","if j < len(individuo) -
                  1 else f"\tFitness: {fitness[i]}")
        print()


def get_populacao(pop_size: int, cromossomo_size: int) -> Populacao:
    """gera população

    Args:
        pop_size (int, optional): _description_. Defaults to 10.
        cromossomo_size (int, optional): _description_. Defaults to 8.

    Returns:
        Populacao: _description_
    """
    return [np.random.choice([True, False], size=cromossomo_size).tolist() for _ in range(pop_size)]

def generate_get_fenotipo(pesos:NpArray,valores: NpArray, capacidade_mochila) -> Callable:
    """Curry get fenotipo

    Args:
        pesos (NpArray): pesos das posições dos itens das mochilas
        valores (NpArray): valores das posições dos itens das mochilas
        capacidade_mochila (_type_): capacidade maxima da mochila

    Returns:
        Callable[Cromossomo, Fenotipo]: get_fenotipo
    """
    def get_fenotipo(posicao_itens_pegos:Cromossomo)-> Fenotipo:
        peso = np.inner(np.array(posicao_itens_pegos), pesos)
        valor = np.inner(np.array(posicao_itens_pegos), valores)
        return valor if peso < capacidade_mochila else -valor
    
    return get_fenotipo
# def get_fenotipo(genotipo: Cromossomo) -> Fenotipo:
#     """gera o fenotipo a partir do genotipo

#     Args:
#         genotipo (Cromossomo): 

#     Returns:
#         int: fenotipo
#     """
#     return sum(genotipo)



def generate_get_fenotipo_populacao(get_fenotipo:Callable) -> Callable:
    """Gera o genotipo de uma população

    Args:
        pop (Populacao): população

    Returns:
        List[Fenotipo]: fenótipos
    """
    def get_fenotipo_populacao(pop: Populacao) -> List[Fenotipo]:

        return [get_fenotipo(genotipo) for genotipo in pop]

    return get_fenotipo_populacao

def gera_filhos(
    pais: Populacao,
    get_fenotipo:Callable,
    prob_cruzamento: float = 1.0,
    quantidade_filhos: int = 2,
    k: int = 2
) -> Tuple[Populacao, List[Tuple[int, int]]]:
    """Gera filhos a partir dos pais usando o método da roleta

    Args:
        pais (Populacao): pais
        quantidade_filhos (int): quantidade de filhos a serem gerados
        k (int): quantidade de potenciais pais do torneio

    Returns:
        Tuple[Populacao, List[Tuple[int, int]]]: filhos gerados, e posição dos pais 
        na população original
    """
    filhos = []
    pais_index: List[Tuple[int, int]] = []
    for _ in range(quantidade_filhos):
        if np.random.rand() > prob_cruzamento:
            continue
        # Seleciona dois pais por torneio

        pai_index =  -1 # np.random.choice(range(len(pais)))
        mae_index = -1 # np.random.choice(range(len(pais)))
        for _ in range(k):
            idx = np.random.choice(range(len(pais)))
            if pai_index == -1 or get_fenotipo(pais[idx]) > get_fenotipo(pais[pai_index]):
                pai_index = idx
        for _ in range(k):
            idx = np.random.choice(range(len(pais)))
            if mae_index == -1 or get_fenotipo(pais[idx]) > get_fenotipo(pais[mae_index]):
                mae_index = idx
        pai: Cromossomo = pais[pai_index]
        mae: Cromossomo = pais[mae_index]
        pais_index.append((pai_index, mae_index))
        # Seleciona um ponto de corte no cromossomo
        pos_corte: int = np.random.choice(range(len(pais[0])))

        filho: Cromossomo = pai[:pos_corte] + mae[pos_corte:]
        filhos.append(filho)
    return (filhos, pais_index)


def muta_populacao(
    pop: Populacao,
    prob_mut: float,
    prob_gene_flip: float = .1
) -> Populacao:
    """Gera uma nova população com alguns individuos mutados

    Args:
        pop (Populacao): população
        prob_mut (float): probabilidade de um individuo sofrer mutação
        prob_gene_flip (float, optional): probabilidade de um gene de um 
        individuo selecionado para ser mutado ser alterado. Defaults to .1.

    Returns:
        Populacao: População com alguns individuos mutados
    """

    def fabrica_mutacao(prob_gene_flip: float) -> Callable:
        """Binda os argumentos de probabilidades de mutação e de gene flip à uma função de mutação

        Args:
            prob_mut (float): probabilidade de um individuo sofrer mutação
            prob_gene_flip (float): probabilidade de um gene sofrer mutação

        Returns:
            Callable: Função que irá retornar um individuo mutante
        """
        def muta_cromossomo(
            individuo: Cromossomo,
            prob_gene_flip: float
        ) -> Cromossomo:
            """Mutação de um cromossomo\n

            Args:
                individuo (Cromossomo): cromossomo
                prob_mut (float): probabilidade de um individuo sofrer mutação
                prob_gene_flip (float, optional): probabilidade de um gene 
                sofrer mutação. Defaults to .1.

            Returns:
                Cromossomo: cromossomo mutado
            """
            quant_genes_a_mutar = int(prob_gene_flip * len(individuo))
            alelos_a_flipar = np.random.choice(
                range(len(individuo)), size=quant_genes_a_mutar, replace=False)
            for idx in alelos_a_flipar:
                individuo[idx] = not individuo[idx]
            return [not gene if i in alelos_a_flipar else gene for i, gene in enumerate(individuo)]
        return lambda individuo: muta_cromossomo(individuo, prob_gene_flip)

    muta = fabrica_mutacao(prob_gene_flip)

    return [muta(individuo) if prob_mut < np.random.random() else individuo for individuo in pop]


def selecao_natural(
    pais: Populacao,
    filhos: Populacao,
    get_fenotipo_populacao:Callable,
    estrategia_selecao: ESTRATEGIAS_SELECAO = ESTRATEGIAS_SELECAO.ELITISMO
) -> Populacao:
    """Dada a população de pais e de filhos, gera uma nova população com o tamanho original

    Args:
        pais (Populacao): 
        filhos (Populacao): 
        estrategia_selecao (ESTRATEGIAS_SELECAO, optional): Forma que irei selecionar 
        os novos individuos dentre as populações. Defaults to ESTRATEGIAS_SELECAO.TORNEIO.

    Returns:
        Populacao: nova população
    """
    def torneio(
            pais: Populacao,
            filhos: Populacao
    ) -> Populacao:
        raise NotImplementedError("Operação de seleção não suportada")

    def roleta(
            pais: Populacao,
            filhos: Populacao
    ) -> Populacao:
        raise NotImplementedError("Operação de seleção não suportada")

    def remove_worst(
            pais: Populacao,
            filhos: Populacao,
    ) -> Populacao:
        # Int default to 0,
        # Bool default to False
        for filho in filhos:
            idx_pior_pai = np.argmin(get_fenotipo_populacao(pais))
            pais[idx_pior_pai] = filho
        return pais

    match estrategia_selecao:
        case ESTRATEGIAS_SELECAO.TORNEIO:
            return torneio(pais, filhos)
        case ESTRATEGIAS_SELECAO.ELITISMO:
            return remove_worst(pais, filhos)
        case ESTRATEGIAS_SELECAO.ROLETA:
            return roleta(pais, filhos)
        case _:
            raise NotImplementedError("Operação de seleção não suportada")


def main(
    pop_size: int,
    cromossomo_size: int,
    max_ger: int,
    prob_mut: float,
    prob_cruzamento: float
) -> None:
    """Função principal com o loop de geracoes

    Args:
        pop_size (int): tamanho da população inicial
        cromossomo_size (int): tamanho do cromossomo
        max_ger (int): limite de quantidade de gerações
        prob_mut (float): probabilidade de um individuo sofrer mutação
        prob_cruzamento (float): probabilidade de cruzamento
    """

    get_fenotipo = generate_get_fenotipo(
        pesos= np.array([2, 1, 4, 1, 12]),
        valores=np.array([2, 1, 10, 2, 4]),
        capacidade_mochila=15
    )
    get_fenotipo_populacao = generate_get_fenotipo_populacao(get_fenotipo)
    # Passo 1: Gera população inicial
    pop = get_populacao(pop_size, cromossomo_size)

    # Passo 2: Avalia população
    fitness = get_fenotipo_populacao(pop)
    sumarios = [sumario_populacao([f/cromossomo_size for f in fitness])]

    print("População Inicial")
    printa_populacao(pop, fitness, print_summary=True)
    print()
    for _ in range(max_ger):
        # Passo 3: Gera filhos
        filhos, _ = gera_filhos(
            pop, prob_cruzamento=prob_cruzamento,
            quantidade_filhos=2,
            get_fenotipo=get_fenotipo,
            k=2
        )
        # Passo 4: Aplica mutação
        filhos_mutados = muta_populacao(filhos, prob_mut)
        # Passo 5: Seleciona os individuos mais aptos
        pop = selecao_natural(pop, filhos_mutados, get_fenotipo_populacao)
        fitness = get_fenotipo_populacao(pop)
        # print(f"Geração {i}: ", end="")

        sumarios.append(sumario_populacao(
            [f/cromossomo_size for f in fitness]))
        # printa_populacao(pop, fitness, print_summary=True)
    # Plotar gráfico do sumário
    print("População final")
    printa_populacao(pop, fitness, print_summary=True)
    sumarios = np.array(sumarios)
    plt.plot(sumarios[:, 0], label="Média")
    plt.plot(sumarios[:, 1], label="Desvio Padrão")
    plt.plot(sumarios[:, 2], label="Maior fitness")

    # Add legend x and y labels
    plt.xlabel("Gerações")
    plt.ylabel("Fitness")

    plt.legend()
    plt.show()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Algoritmo genético")
    parser.add_argument("--pop_size", type=int, default=10,
                        help="Tamanho da população")
    parser.add_argument("--cromossomo_size", type=int,
                        default=5, help="Tamanho do cromossomo")
    parser.add_argument("--max_ger", type=int, default=50,
                        help="Número máximo de gerações")
    parser.add_argument("--prob_mut", type=float, default=0.5,
                        help="Probabilidade de mutação")
    parser.add_argument("--prob_cruzamento", type=float, default=0.5,
                        help="Probabilidade de cruzamento")

    main(**vars(parser.parse_args()))
