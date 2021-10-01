#Ex1
a1 <- c(1:20)
b1 <- c(20:1)
c1 <- c(a1,b1)
d1 <- c()
j = 3
i=1
k = 1
while(k<=11) {
  d1[k] = (0.1^j) * (0.2^i)
  j=j+3
  i=i+3
  k = k+1
}
tmp = c(4,6,3)
e1 = rep(x = tmp,times = 10)
f1 = c(e1,4)

#Ex2
param = function(x) {
  exp(x)*cos(x)
}
entrada = seq(from = 3,to = 6,by = 0.1)
final = param(entrada)
final

#Ex3

somaAcum = function(start, end, funct){
  acum = 0
  while(start<=end){
    acum = acum + funct(start)
    start=start+1
  }
  return (acum)
}

a3 = somaAcum(10,100,function(i){i^3 + 4*(i^2)})
b3 = somaAcum(10,25,function(i){2^i/i + 3^i/i^2})

# eX 4


xVec <- sample(0:999, 250, replace=T)
yVec <- sample(0:999, 250, replace=T)

xImpar <- c()
for(i in xVec){
  if(i%%2 ==1){
    xImpar <- c(xImpar,i)
  }
}
xImpar


sumbYX = yVec[-1] - xVec[-length(xVec)]


senDivCos <- c()
for(i in 2:250){
  senDivCos <- c(senDivCos,sin(yVec[i])/cos(xVec[i-1]))
}
senDivCos

e = c()
for(i in 1:249){
  cima = exp(-(xVec[i]))
  baixo = xVec[i]+10
  e = c(e,cima/baixo)
}

# Ex 5
sorted = sort(xVec)
ordered = order(xVec)
ordered
media = mean(xVec)
media
raizQuadrada = sqrt(xVec)
raizQuadrada
soma = sum(xVec)
soma
absolut = abs(xVec)
absolut
which(xVec)
a = which(yVec>600)
b = yVec[a]
c = xVec[which(yVec %in% b)]
d = (abs(xVec- mean(xVec)))**(1/2)
e = sum(max(yVec) - yVec <= 200)
f = sum(xVec%%2)
h = c()
for (i in 1:length(xVec)){
  if((i-1)%%3==0) h = c(h,xVec[i])
}


#ex 6 

num.impar = function(vet){
  som = 0
  for (i in vet) {
    if(i%%2==1) som = som + 1
  }
  som
}
num.impar2 = function(vet){
  if(!length(vet)) {return (0)}
  return ((!(vet[1]%%2)) + num.impar2(vet[-1]))
}
# a questão pedia pra não usar laço e eu não usei rsrs


#ex 7

fibonacci = function(n){
  fib = c(1,1)
  for(i in 3:n){
    fib[i] = fib[i-1] + fib[i-2]
  }
  fib
}
# ex 8


tamanho.seq = function(prob){
  i = 1
  repeat{
    moeda = sample(x = c("cara","coroa"), prob = c(prob,1-prob),size = 1)
    if(moeda == "coroa") break
    i = i+1
  }
  i
}
lancamentos = c()
for(i in 1:10000){
  lancamentos[i] = tamanho.seq(0.5)
}
max(lancamentos)




# ex 9

rogger = function(n,k){
  coelhos = c(1,1)
  i = 3
  while(i<=n){
    coelhos[i] = coelhos[i-1]+coelhos[i-2]*k
    i = i+1
  }
  coelhos[n]
}
roggerRecM = function(n,k,list){
  if(length(list)==n) return (list[n])
  return (roggerRecM(n,k,c(list,list[length(list)]+list[length(list)-1]*k)))
}
# Esse faz a mesma coisa mas recursivamente
roggerRec = function(n,k){
  roggerRecM(n,k,c(1,1))
}


#ex10
install.packages(dslabs)
library(dslabs)
data(murders)
x <- murders[, 'population']
mean(x)
murders[which.max(x), 'state']
murders[which.min(x), 'state']


murders$taxa <- (10000 * murders[, 'total']) / murders[, 'population']

murders[order(murders$taxa), 'state']

murders[taxa <= 0.05,]$state
murders[taxa >= 0.5,]$state

murders[which.max(murders[, 'taxa']), 'state']
murders[which.min(murders[, 'taxa']), 'state']

w <- murders[murders$region == 'West',]
ne <- murders[murders$region == 'Northeast',]
nc <- murders[murders$region == 'North Central',]
s <- murders[murders$region == 'South',]

mw <- mean(w$taxa)
mne <- mean(ne$taxa)
mnc <- mean(nc$taxa)
ms <- mean(s$taxa)

dw <- sd(w$taxa)
dne <- sd(ne$taxa)
dnc <- sd(nc$taxa)
ds <- sd(s$taxa)

regionsData <- c(w, ne, nc, s)
regions <- c("Oeste", "Nordeste", "Centro Norte", "Sul")
avgs <- c(mw, mne, mnc, ms)
sds <- c(dw, dne, dnc, ds)

regions[which.max(avgs)]
regions[which.min(avgs)]

boxplot(w$taxa, ne$taxa, nc$taxa, s$taxa, names = regions)

# Com os dados acima podemos concluir que a região mais perigosa em questão de assassinatos é o Sul nos Estados Unidos, em contra pardida, o oeste e o nordeste em média são melhores em relação a essa métrica