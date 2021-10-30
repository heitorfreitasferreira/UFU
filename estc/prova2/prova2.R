# Heitor Freitas Ferreira - 11921BCC026
#1
  #a
    papagaios = read.csv("papagaio.txt", header = TRUE, sep = ",")
    tail(papagaios)
    head(papagaios)
    str(papagaios)
    summary(papagaios)
  #b
    papagaios[ sample(nrow(papagaios)),]
  #c
    mean(papagaios[papagaios$especie == "corniculata",]$envergadura)
    mean(papagaios[papagaios$especie == "cirrhata",]$envergadura)
    mean(papagaios[papagaios$especie == "arctica",]$envergadura)
    #em média a envegadura se organiza em cirrhata>corniculata>arctica
    mean(papagaios[papagaios$especie == "corniculata",]$peso)
    mean(papagaios[papagaios$especie == "cirrhata",]$peso)
    mean(papagaios[papagaios$especie == "arctica",]$peso)
    #em média o peso se organiza em cirrhata>corniculata>arctica
    mean(papagaios[papagaios$especie == "corniculata",]$tamanho)
    mean(papagaios[papagaios$especie == "cirrhata",]$tamanho)
    mean(papagaios[papagaios$especie == "arctica",]$tamanho)
    #em média o tamanho se organiza em corniculata>cirrhata>arctica
    
    
    sd(papagaios[papagaios$especie == "corniculata",]$envergadura)
    sd(papagaios[papagaios$especie == "cirrhata",]$envergadura)
    sd(papagaios[papagaios$especie == "arctica",]$envergadura)
    #as articas são menos diversas com relação à envergadura, seguida pelas corniculatas e as mais diversas com relação à envegadura são as cirrhatas
    sd(papagaios[papagaios$especie == "corniculata",]$peso)
    sd(papagaios[papagaios$especie == "cirrhata",]$peso)
    sd(papagaios[papagaios$especie == "arctica",]$peso)
    #as articas são menos diversas com relação ao peso, seguida pelas corniculatas e as mais diversas com relação ao peso são as cirrhatas
    sd(papagaios[papagaios$especie == "corniculata",]$tamanho)
    sd(papagaios[papagaios$especie == "cirrhata",]$tamanho)
    sd(papagaios[papagaios$especie == "arctica",]$tamanho)
    #as articas são menos diversas com relação ao tamanho, seguida pelas cirrhata e as mais diversas com relação ao peso são corniculata
      par(mfrow = c(1, 3))
    boxplot(papagaios[papagaios$especie == "corniculata",]$peso, main = "Corniculta", ylim = c(min(papagaios$peso),max(papagaios$peso)))
    boxplot(papagaios[papagaios$especie == "cirrhata",]$peso, main = "Cirrhata", ylim = c(min(papagaios$peso),max(papagaios$peso)))
    boxplot(papagaios[papagaios$especie == "arctica",]$peso, main = "Arctica", ylim = c(min(papagaios$peso),max(papagaios$peso)))
    #as articas se testacam em peso, a mediana de seus pesos está próximo aos valores minimos das outras duas espècies, o mesmo vale para o valor max das articas, que está abaixo do primeiro quartil de cirrhata e próximo à mediana das cornicultas
    
  #d
    papagaios$especie = as.factor(papagaios$especie)
  #e
    treino = papagaios[1:floor(nrow(papagaios)*0.8),]
    teste = papagaios[ceiling(nrow(papagaios)*0.8):nrow(papagaios),]
  #f
    library(tree)
    library(rpart)
    library(rpart.plot)
    modelo_papagaios = rpart(especie~., data = treino)
    rpart.plot(modelo_papagaios, extra = 101)
    previsao = predict(modelo_papagaios, newdata = teste, type = "class")
  #g
    mean(previsao == teste$especie)
    table(teste$especie, previsao)



#2
  #a
    papagaios = read.csv("papagaio.txt", header = TRUE, sep = ",")
    corniculata = papagaios[papagaios$especie == "corniculata",]
    cirrhata = papagaios[papagaios$especie == "cirrhata",]
    arctica = papagaios[papagaios$especie == "arctica",]
    if(F){
      sum_prod_array = function(x,y){
        if(length(x)==0 || length(y == 0 )) return( 1);
        return (x[1,]*y[1,])+sum_prod_array(x[2:length(x)],y[2:length(y)])
      }
    }
  #b
    r = function(x,y){
      n = length(x)
      somatorio1 = sum(x*y)
      somatoriox2 = sum(x*x)
      somatorioy2 = sum(y*y)
      numer = somatorio1 - n*mean(x)*mean(y)
      denom = sqrt(somatoriox2-n*mean(x)*mean(x)) * sqrt(somatorioy2-n*mean(y)*mean(y))
      return (numer/denom)
    }
    r(corniculata$tamanho,corniculata$peso)# 0.9025978
    r(cirrhata$tamanho,cirrhata$peso)# 0.7143406
    r(arctica$tamanho,arctica$peso)# 0.6837219
    #mais correlacionado = corniculata
  #c
    r(corniculata$tamanho,corniculata$peso)
    r(cirrhata$tamanho,cirrhata$peso)
    r(arctica$tamanho,arctica$peso)
    
    lm(peso~tamanho, corniculata)
    
  #d
    peso_corniculata = function(tamanho){
      return (-300.59+tamanho*24.25)
    }
    peso_corniculata(10) - peso_corniculata(10.5) # diff = -12.125
  #e
    peso_corniculata = function(tamanho){
      if(tamanho<min(corniculata$tamanho) || tamanho>max(corniculata$tamanho))
        return ("Tamanho inválido")
      return (tamanho*24.25-300.59)
    }
    peso_corniculata(18)# "Tamanho inválido"
    peso_corniculata(41.01)# 693.9025
    