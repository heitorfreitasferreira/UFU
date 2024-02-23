# Algoritmo de busca A*

Este é um projeto de implementação do algoritmo A* em Python para um trabalho da disciplina de Inteligência Artificial.

## Objetivos do projeto

- Desenvolver um CLI (Command Line Interface) em Python utilizando a biblioteca argparser.
- Implementar uma inteligência artificial de busca baseada em heurística (A*).
- Organizar as entradas dos grafos em arquivos separados.
- Utilizar o linter pylint para garantir a qualidade do código Python.
- Documentar corretamente o código Python.

## Dependências

Não há dependencias para este projeto além de alguma versão do Python acima da 3.10

## Como Executar

```python3 ./main.py -s [STARTING_INDEX] -e [DESTINY_INDEX] --cities_filepath cities_info.csv --edges_filepath edges.csv```

Caso queira inserir outra base de dados basta trocar os arquivos --cities_filepath e --edges_filepath, cuidado para não repetir os indexes
