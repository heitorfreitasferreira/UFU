# Classificação de vitória de times baseado em todas partidas competitivas de League of Legends em 2022

## Pre processamento

- [Dataset](https://www.kaggle.com/datasets/arthur1511/lol-esports-2022)

- Utilizando o dataset com 149232 amostras com dados estatísticos de players e de times
  - selecionamos as amostras com apenas informações estatísticas dos times, totalizando 24872 amostras
  - selecionando as amostras que apresentam informações completas (existe uma coluna que diz isso), temos 21232 amostras
  - realizando a seleção dos atributos temos 96 colunas, sendo as colunas removidas:
    - 'datacompleteness',
    - 'year',
    - 'position',
    - 'gameid',
    - 'url',
    - 'date',
    - 'playerid',
    - 'split',
    - 'playoffs',
    - 'patch',
    - 'participantid',
    - 'playername',
    - 'teamid',
    - 'champion',
    - 'firstbloodkill',
    - 'firstbloodassist',
    - 'firstbloodvictim',
    - 'dragons (type unknown)',
    - 'damageshare',
    - 'earnedgold',
    - 'earned gpm',
    - 'earnedgoldshare',
    - 'goldspent',
    - 'gspd',
    - 'total cs',
    - 'monsterkillsownjungle',
    - 'monsterkillsenemyjungle'
  - selecionando times de ligas expressivas, temos 12480 amostras
  - totalgold, minionkills, monsterkill vão ser utilizados para gerar as novas colunas com valores por minuto