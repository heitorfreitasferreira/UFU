# Ex1
qnt = 0
for (i in 1:100000) {
  dados = sample(x = 1:6, size = 2,replace = T)
  if(sum(dados) == 7 || sum(dados)==11){
    qnt=qnt+1
  }
}
qnt/100000

#Ex2
qnt = 0
balde1 = c(rep("p", 8), rep("b", 3), rep("v", 4))
balde2 = c(rep("p", 3), rep("b", 5), rep("v", 7))
balde3 = c(rep("p", 4), rep("b", 3), rep("v", 2))
balde4 = c(rep("p", 2), rep("b", 1), rep("v", 8))
for (i in 1:100000) {
  dados = sample(x = 1:6, size = 2,replace = T)
  
  
  if(sum(dados)<4){
    escolha = sample(x = balde1, size = 1)
    if(escolha=="v"){
      qnt = qnt +1
    }
  }
  else if(sum(dados)>=4 & sum(dados)<7){
    escolha = sample(x = balde2, size = 1)
    if(escolha=="v"){
      qnt = qnt +1
    }
  }
  else if(sum(dados)==7){
    escolha = sample(x = balde3, size = 1)
    if(escolha=="v"){
      qnt = qnt +1
    }
  }
  else {
    escolha = sample(x = balde4, size = 1)
    if(escolha=="v"){
      qnt = qnt +1
    }
  }
}
qnt/100000

#Ex3

ganhou = 0
for (i in 1:100000){
  
  dados = sample(x = 1:6, size = 2,replace = T)
  if(sum(dados)==7 || sum(dados)==11){
    ganhou = ganhou +1 
  }
  else if(sum(dados)==2 || sum(dados)==3|| sum(dados)==12){
    ganhou = ganhou + 0 
  }
  else{
    somaInicial = sum(dados)
    repeat{
      dados = sample(x = 1:6, size = 2,replace = T)
      if(sum(dados)==7 ){
        ganhou = ganhou + 0
        break;
      }
      else if(sum(dados)==somaInicial){
        ganhou = ganhou + 1
        break;
      }
    }
  }
}

ganhou/100000




#Ex 4

jim = c(0,0,1)
dwight = c(0,1,0)
jimWin = 0

for (i in 1:100000){
  moedas = sample(x = 0:1, size = 3,replace = T)
  if(identical(jim,moedas)){
    jimWin = jimWin + 1
  }
  else if(identical(dwight,moedas)){
    jimWin = jimWin + 0
  }
  else{
    repeat{
      moedas = c(moedas,sample(x = c(0,1), size = 1,replace = T))
      if(identical(tail(moedas,3), jim)){
        jimWin = jimWin+1
        break
      }
      else if(identical(tail(moedas,3), dwight)){
        jimWin = jimWin+0
        break
      }
    }
  }
  
}
jimWin/100000


passos = 20# Mudar para 4, 6, 10 e 20 para os testes
lukeZerado = 0
for (i in 1:100000){
  luke = 0
  for (j in 1:passos) {
    luke = luke + sample(x = c(-1,1), size = 1,replace = T)
  }
  if(luke == 0){
    lukeZerado = lukeZerado+1
  }
}
lukeZerado/100000
# Ex 5
# a
N = 20
lukePosLprec = function(l) {
  caiu = c()
  # takes too long
  for(cases in 1:10000) {
    pos = l;
    repeat {
      pos = pos + sample(c(-1, 1), size = 1)
      if(pos == 0 || pos == N) break; 
    }
    caiu[cases] = (pos == 0)
  }
  return(mean(caiu))
}

#b
estims = unlist(Map(lukePosLprec, 1:19))
plot(1:19, estims, main = 'Resultado', type = 'l')

#ex7

f1 = function(x) {
  (1/sqrt(2*pi))*exp(-x^2/2)
}
3*mean(f1(runif(1000000, min = -1, max = 2)))


f2 = function(x) {
  cos(x)^2
}

pi*mean(f2(runif(1000000, min = 0, max = pi)))

# Ex8

nVal = function(n) {
  valores = c()
  for(i in 1:n) {
    val = runif(1)
    if(val < 1/7) {
      valores[i] = 1
    } else if(val < 3/7) {
      valores[i] = 5
    } else {
      valores[i] = 10
    }
    
  }
  return(valores)
}
mean(nVal(100) == 5)
mean(nVal(1000) == 5)
mean(nVal(10000) == 5)


#Ex9

gera_r = function(c) {
  #delta > 0 === 1-4c > 0 -> c < 1/4
  if(c < 1/4) {
    delta = 1-4*c
    x1 = (-1+sqrt(delta))/2
    x2 = (-1-sqrt(delta))/2
    return(c(x1,x2))
  }
}
ex9 = function(n) {
  vals = runif(n)
  xs = c()
  for(i in 1:n) {
    rs = gera_r(-2*vals[i])
    if(rs[1] >= 0 && rs[1] <= 1) {
      xs[i] = rs[1]
    } else if(rs[2] >= 0 && rs[2] <= 1) {
      xs[i] = rs[2]
    }
  }
  xs
}
estims = ex9(10000)
mean(estims < 0.7)
mean(estims)
