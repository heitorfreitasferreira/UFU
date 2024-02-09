"""Algoritmo genético com cromossomos binários
"""

from typing import List, Tuple
from enum import Enum
import argparse

import numpy as np

ESTRATEGIAS_SELECAO = Enum('ESTRATEGIAS_SELECAO', ['TORNEIO',])

def sumario_populacao(pop: List[List[bool]])-> Tuple[float, float]:
    """Sumário de uma população

    Args:
        pop (List[List[bool]]): população

    Returns:
        Tuple[float, float]: Média, Desvio Padrão
    """
    fenotipos = get_fenotipo_populacao(pop)
    return ((sum(fenotipos)/len(fenotipos)), )

def get_populacao(pop_size:int = 10, cromossomo_size:int = 8)-> List[List[bool]]:
    """gera população

    Args:
        pop_size (int, optional): _description_. Defaults to 10.
        cromossomo_size (int, optional): _description_. Defaults to 8.

    Returns:
        List[List[bool]]: _description_
    """
    return np.random.rand(pop_size, cromossomo_size)

def get_fenotipo_populacao(pop: List[List[bool]])-> List[int]:
    """Gera o genotipo de uma população

    Args:
        pop (List[List[bool]]): população

    Returns:
        List[int]: fenótipos
    """
    def get_fenotipo(genotipo: List[bool])-> int:
        """gera o fenotipo a partir do genotipo

        Args:
            genotipo (List[bool]): 

        Returns:
            int: 
        """
        return sum(genotipo)
    return [get_fenotipo(genotipo) for genotipo in pop]


def gera_filhos(pais: List[List[bool]])-> List[List[bool]]:
    pass

def selecao_natural(
    pais: List[List[bool]],
    filhos: List[List[bool]],
    estrategia_selecao: ESTRATEGIAS_SELECAO = ESTRATEGIAS_SELECAO.TORNEIO
    ) -> List[List[bool]]:
    """Dada a população de pais e de filhos, gera uma nova população com o tamanho original

    Args:
        pais (List[List[bool]]): 
        filhos (List[List[bool]]): 
        estrategia_selecao (ESTRATEGIAS_SELECAO, optional): Forma que irei selecionar 
        os novos individuos dentre as populações. Defaults to ESTRATEGIAS_SELECAO.TORNEIO.

    Returns:
        List[List[bool]]: nova população
    """
    def torneio(pais: List[List[bool]], filhos: List[List[bool]]) -> List[List[bool]]:
        pass
    match estrategia_selecao:
        case ESTRATEGIAS_SELECAO.TORNEIO:
            torneio(pais, filhos)
        case _:
            raise NotImplementedError("Operação de seleção não suportada")


def main(tam_pop:int, tam_cromo:int, max_ger:int, prob_mult:float)-> None:
    pass

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Algoritmo genético")
    parser.add_argument("--pop_size", type=int, default=10, help="Tamanho da população")
    parser.add_argument("--cromossomo_size", type=int, default=8, help="Tamanho do cromossomo")
    parser.add_argument("--max_ger", type=int, default=10, help="Número máximo de gerações")
    parser.add_argument("--prob_mut", type=float, default=0.1, help="Probabilidade de mutação")
    main(**vars(parser.parse_args()))
