# Operações básicas
# Selecionar as linhas que quero que rode e Ctrl+Enter
2+3 # Soma
2-3 # Subtração
2*3 # Multiplicação
2**3 # Exponenciação
2^3 # Exponenciação
13%%2 # Resto

exp(2)
log(x = 2,base = 10)

# Variáveis e atribuição de valores

soma1 <- 2+3
5+2 -> soma2
soma3 = 1+1

# Operações lógicas

3<2
2==2
2!=1
2<=3

# Criando vetores no R; c()

vetor1 <- c(1,2,3)
vetor2 <- c("a","b","c")
vetor3 <- c(4,5,6)
vetor4<- c(vetor1,vetor3)
vetor5 <- 32:99
vetor6 <- seq(from = 2,  by = 2, to = 100)
vetor7 <- seq(from = 2,  by = 2, length.out = 10)
vetor6
vetor6+100


numeros <- rnorm(n = 1000, mean = 0, sd = 1) # gera uma distri norm
hist(numeros) # gera um histograma a partir de um vetor
length(numeros)# Tamanho de um vetor
numeros<(0.5) # gera um vetor de bool  que será verdadeiro na posição em que a condição for verdadeira
numeros[numeros<0.5] # Gera um vetor com somente os indices que derem TRUE no gerador entre os colchetes
sum(numeros<0.5) # quantidade de dados que satisfazem a operação


dado1 <- sample(1:6, size = 70000, replace = TRUE) # Gerar um vetor de tamanho 12, a partir do vetor 1:6, com repetição
dado2 <- sample(1:6, size = 70000, replace = TRUE)

soma <- dado1+dado2
deu12 <- soma==12

sum(deu12)/70000

# Matrizes

A <- matrix(c(1,2,3,4,5,6),ncol = 3,byrow = T)
A
A[,2] # Apenas a coluna 2
A[1,] # Apenas a linha 1

# dataframe

# Precisando instalar um pacote de data frame

install.packages(dslabs)
library(dslabs)
data(murders) #acessando o conjunto de dados
murders
head(murders)
tail(murders)
estados <- murders$state
estados
sum(murders$total)
order(murders$total)
murders[5,] # Estados com mais mortes flat
rate <-100000*murders$total/murders$population
rate
indices <-order(rate)
indices
murders[indices[length(indices)],]$state # Estados com mais morte/qnt_populacao
murders <- cbind(murders,rate)# Add coluna com o rate
murders
# outra maneira de add coluna no conjunto de addos
murders$rate <- rate
plot(x= murders$total,y=murders$rate)
