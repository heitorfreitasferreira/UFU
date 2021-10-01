data(iris)
iris

summary(iris)
plot(iris$Petal.Length, iris$Petal.Width,pch = 16,type = "p")
iris$Species == "setosa"
setosa <- iris[iris$Species == "setosa",]
virginica <- iris[iris$Species == "virginica",]
versicolor <- iris[iris$Species == "versicolor",]

summary(setosa)
summary(versicolor)
summary(virginica)

i <- sample(1:150, size = 150, replace = F)
iris <- iris[i,]

#TEM ERRO AQUI PRA BAIXO
treino <- iris[1:120,]
teste <- iris[121:150,]
table(treino$Species)
teste[1,1:4]
sum((treino[1,1:4]-teste[1,1:4])^2)
sqrt(sum((treino[1,3:4]-teste[1,3:4])^2))
distancias <- c()

for(j in 1:120){
  distancias[j] <- sqrt(sum((treino[j,3:4]-teste[1,3:4])^2))
}
distancias
order(distancias)
treino[12,5]
teste[1,5]
classificacao <- c()
for (j in 1:30) {
  distancias <- c()
  for (i in 1:120) {
    distancias[i] <- sqrt(sum((treino[i,1:4] - teste[j,1:4])^2))
  }
  classificacao[j] <- order(distancias)[1]
}
classificacao
mean(treino[classificacao,5] == teste[,5])

## LISTA 1

#ex1
qnt <- 0
for (i in 1:1000000) {
  x <- sample(x = 1:6, size = 1,replace = T)
  y <- sample(x = 1:6, size = 1,replace = T)
  if(((x+y)%%2 == 0 ) & (y ==5 ||x==5)){ qnt <- qnt +1}
}
qnt/1000000


#ex2 tentativa 1
positivo = 0
for (i in 1:1000000) {
  contraiu <- sample(x = 1:1000, size = 1)
  if (contraiu <= 4){
    teste <- sample(x = 1:100, size = 1)
    if(teste>=94){
      positivo <- positivo + 1
    }
  }
  else{
    teste <- sample(x = 1:1000, size = 1)
    if(teste == 1){
      positivo <- positivo + 1
    }
  }
  
}
positivo/1000000
#ex2 tentativa 2
















