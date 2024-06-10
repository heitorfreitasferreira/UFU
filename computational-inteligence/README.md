# Inteligencia computacional

> Adaptar IA para o mundo real onde a gente nao tem certeza de todos os detalhes de um problema 

Ia se divide em duas grandes areas

- simbolica
  - logica e representacao
    - pln
- inteligencia computacional
  - evolutiva
  - swarm
  - fuzzy
  - rede neural

## Aspectos Biologicos

### Redes neurais

Baseado no neuronio biologico

 Neuronios se conectam atraves das sinapses

sinais eletricos de outras celulas entram pelo dendrto

processados os snais, e o mesmo atingindo um certo limiar, o neuronio emite um sinal de saida

![perceptron](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQoYAV35AT1tOwbk2X1D9mogbGxq31kkfdyeQ&s)

$y = f(\sum_{i=1}^n w_i x_i)$

Onde f é a funcao de ativacao, ha varias funcoes como:

- Sigmoid
- ReLU
- Tanh


O problema e que tendo o somente uma camada de entrada e uma de saida, o modelo fica limitado

As criticas em geral  foram:

- resolve apenas problemas linearmente separaveis
- nao pondera a relevancia de cada neuronio  de entrada e saida
- utilizava apenas uma camada e funcao de ativacao degrau limiar

![perceptron and, or, xor](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRa55PzTy96qE_EpL7jYlLBDk9ydVkrLexvddH5HSgOEpPXj1m8p2dB7eY&s=10)

Solucao: adicionar camdas ate que a moral aumente!!

#### Classificacao de redes neurais

- Arquitetura: nro de camadas
- Conetictividade: parcialmente/completamente conectada
- Fluxo: sentido que e feito o processamento
- Tipo de treinamento

## Tipo de treinamento/aprendizagem

Consistem em apresentar exemplos a fim de modificar os pesos, calibrando a saida de acordo com as entradas do treino

Esse aprenizado pode ser:

- Supervisionado, onde a saida e conhecida e classificada
- Nao supervisionada, onde nao se conhece a classe, mas a rede agrupa as entradas
- Por reforco, recompensa a rede onde o desempenho e bom, analogo a adestrar pets


### Treinamento do perceptron

consiste em determinar cada peso da sua rede
![training rule](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR5ecmi4s_ob-cfOc3FHVjKtjCMP9ZsueFo4AeOfNj97-Izkw9DfQXQsbop&s=10)
- considerando o erro $\sigma$ que e a dif entre o valor desenhado e o obtido
- o valor do peso na proxima iteracao do treinamento sera $w_(i+1) = w_i + $
$$