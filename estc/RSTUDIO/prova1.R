#Nome: Heitor Freitas Ferreira
#Matricula: 11921BCC026

# 1
  library(dslabs)
  data(heights)
  heights
  # a
    heights$alt.cm <- (2.54 * heights[, 'height'])
  # b
    qnt_homens = sum(heights[, 'sex'] == "Male")
    qnt_mulheres = sum(heights[, 'sex'] == "Female")
    proporcao_homens = qnt_homens/(qnt_homens+qnt_mulheres)
    proporcao_homens
  # c
    maior_altura = max(heights[, 'height'])
    maior_altura_i = which(heights[, 'height'] == maior_altura)
    homem_ou_mulher_max = heights$sex[maior_altura_i]
  # d
    menor_altura = min(heights[, 'height'])
    menor_altura_i = which(heights[, 'height'] == menor_altura)
    homem_ou_mulhe_min = heights$sex[menor_altura_i]
    # Empate entre um homem e uma mulher, mulher da posição 1032 e hoeme na posição 1045
  # e
    media = mean(heights[, 'height'])
    desvio_padrao = sd(heights[, 'height'])
  # f
    homens = heights[heights$sex == "Male",]
    mean(homens$height)
    sd(homens$height)
    
    mulheres = heights[heights$sex == "Female",]
    mean(mulheres$height)
    sd(mulheres$height)
  # g
    boxplot(homens$alt.cm,mulheres$alt.cm, names = c("Homens","Mulheres"))
    # Em média os homens são maiores, 75% dos homens são maiores que as 75% das mulhores
    
# 2
    
  jujuWin = 0
  for (i in 1:100000) {
    juju = 18
    jorel = 7
    repeat{
      moeda = sample(x = 0:1,size = 1)
      if(moeda == 0){
        juju = juju+1
        jorel = jorel-1
      }
      else{
        juju = juju-1
        jorel = jorel+1
      }
      
      if( jorel == 0){
        break
      }
      else if(juju == 0){
        jujuWin = jujuWin + 1
        break
      }
    }
  }
    jujuWin/100000
    
# 3
    P = function(i){
      if(i<1/6)
      {
        return (1)
      }
      if(i<2/6)
      {
        return (2)
      }
      if(i<3/6)
      {
        return (3)
      }
      if(i<4/6)
      {
        return (4)
      }
      if(i<5/6)
      {
        return (5)
      }
      else
      {
        return (6)
      }
    }
    gerador = function(size){
      
      u = runif(size, min = 0, max = 1)
      
      result = c()
      
      for(i in 1:size){
        if(u[i]<1/6)
        {
          result[i] = 1
        }
        else if(u[i]<2/6)
        {
          result[i] = 2
        }
        else if(u[i]<3/6)
        {
          result[i] = 3
        }
        else if(u[i]<4/6)
        {
          result[i] = 4
        }
        else if(u[i]<5/6)
        {
          result[i] = 5
        }
        else
        {
          result[i] = 6
        }
      }
      result
    }
    
    
    som_suss = 0
    for (i in 1:100000) {
      fracasso = 0
      sucesso = 0
      repeat{
        dado = gerador(1)
        if(dado == 6){
          fracasso = fracasso + 1
        }
        else{
          sucesso = sucesso + 1
        }
        if(fracasso == 2 ){
          break
        }
      }
      som_suss = som_suss + sucesso
    }
    som_suss/100000
    
    