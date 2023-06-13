# Classification model performance analysis for League of Legends team matches using KNN and Decision Tree algorithms

## Abstract

The following work aims to study and analyse classical data mining techniques to predict the result of League of Legends matches, allowing games that have not been classified before to have their label automatically defined. In order to achieve this goal, classical algorithms like KNN and Decision Tree algorithms were used, and the results were compared by generated metrics.

- more

## Introdução

O League of Legends (LoL) é um jogo eletrônico extremamente popular que cativou milhões de jogadores ao redor do mundo. Desenvolvido pela Riot Games e lançado em 2009, o League of Legends rapidamente se tornou um fenômeno global, revolucionando o gênero de jogos online multiplayer de arena de batalha (MOBA, na sigla em inglês).

No jogo, jogadores assumem o papel de "invocadores", que controlam poderosos personagens fictícios em confrontos emocionantes e estratégicos. O objetivo principal é destruir a base inimiga enquanto defende a própria base dos ataques inimigos.

Os jogadores podem escolher entre mais de 140 personagens, cada um com habilidades únicas e estilos de jogo distintos. Os campeões são divididos em seis classes principais: Assassino, Lutador, Mago, Atirador, Suporte e Tanque. Cada classe possui um papel específico dentro do jogo, e os jogadores devem escolher campeões que se complementem para formar uma equipe equilibrada e capaz de vencer a partida.

Durante a partida, os jogadores acumulam ouro e experiência ao derrotar inimigos e monstros. O ouro pode ser utilizado para comprar itens que melhoram as habilidades do campeão, enquanto a experiência permite que o campeão evolua e desbloqueie novas habilidades. Os jogadores também podem utilizar runas e talentos para personalizar ainda mais o campeão, permitindo que ele se adapte a diferentes situações e estratégias.

O jogo se destaca pela sua cena competitiva, com torneios profissionais emocionantes e de alto nível. As ligas regionais e os campeonatos mundiais atraem milhões de espectadores online e presenciais, transformando jogadores habilidosos em ídolos e celebridades no mundo dos esports.

### Definição do problema

O problema em questão é encontrar maneiras de prever os resultados de partidas de League of Legends em vitória ou derrota, utilizando os dados dos times de cada partida. A classificação é feita com base nos dados dos jogadores e campeões de cada partida, e o resultado da partida é definido como vitória ou derrota.

### Tarefas de mineração escolhidas

A tarefa de mineração utilizada é a classificação, a qual será responsável por classificar partidas em vitória ou derrota.

### Técnicas de pré-processamento usadas

E no processo de pre técnicas utilizadas no pre-processamento dos dados foram: normalização por média e desvio, seleção/remoção de atributos e seleção de amostras.

### Técnicas de mineração usadas

Sendo que após os pre-processamentos aplicados anteriormente, foram utilizadas as técnicas de mineração KNN e Decision Tree para a classificação das partidas.

### Técnicas de pós-processamento usadas

Finalmente, após a classificação das partidas, foram utilizadas as matrizes de confusão com estatísticas de Sensitividade e Especificidade para avaliar o desempenho dos modelos.

## Desenvolvimento

Inicialmente, temos um dataset com informações de players em partidas de League of Legends, com 123 atributos e 149232 amostras

### Características das técnicas usadas

### Medidas de avaliação

### Possíveis melhorias de desempenho

## Conclusão

Ambos os modelos tiveram resultados satisfatórios com relação à classificação da partida em vitória ou derrota usando os top 15 atributos mais relacionados com a variável alvo (resultado da partida), futuramente em outra pesquisa o grupo pretende usar a mesma base para agrupar os jogadores conforme seus dados individuais ao longo de todas as ligas e realizar a classificação para prever o resultado com os dados coletados no meio da partida (15 minutos de jogo).


## Referências