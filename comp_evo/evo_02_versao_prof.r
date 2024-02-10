onemax <- function(vet) {
  return(sum(vet))
}

## ALGORITMO GENETICO
# Primeira versao:
# Cria uma populacao aleatoria
# Seleciona apenas dois pais, de maneira aleatoria
# Cria dois filhos (crossover) e aplica mutacao
# Um dos filhos substitui o pior pai
## Parametros:
# - tamanho da populacao
# - tamanho do cromossomo
# - numero de geracoes
# - taxa de mutacao
ag_basico <- function(tam_pop = 10,
                      tam_crom = 8,
                      max_ger = 10,
                      prob_mut = 0.1) {
  
  # Fixa o valor da semente
  set.seed(1234)
  
  # PRIMEIRO PASSO:
  # Gerar a populacao inicial
  pop = matrix(sample(c(0,1), tam_pop*tam_crom, replace = TRUE),
               nrow = tam_pop, ncol = tam_crom)
  
  # SEGUNDO PASSO:
  # Avaliar a populacao inicial
  # Obs.: vamos considerar o valor da funcao objetivo
  #       como sendo o valor do fitness
  fitness = rep(0, tam_pop)  # cria um vetor de tam_pop elementos
  for (i in 1:tam_pop) {
    fitness[i] = onemax(pop[i,])
  }
  
  t = 0
  cat(t, "\t", max(fitness), mean(fitness), sd(fitness), "\n")
  
  # Cada passo eh uma GERACAO
  while (t <= max_ger) {
    
    t = t + 1
    
    # TERCEIRO PASSO:
    # Seleciona os pais
    # Nesta versao: seleciona dois pais e cruza
    # (depois vamos melhorar isso)
    ind_pais = sample(tam_pop, 2)
    
    # QUARTO PASSO:
    # Executa o cruzamento (crossover)
    # Seleciona o ponto de cruzamento
    p_cross = sample(tam_crom-1, 1)
    # Cruzamento dos pais
    # cria dois filhos: f1 e f2
    f1 = c(pop[ind_pais[1],1:p_cross],
           pop[ind_pais[2], (p_cross+1):tam_crom])
    f2 = c(pop[ind_pais[2],1:p_cross],
           pop[ind_pais[1], (p_cross+1):tam_crom])
    
    #print(pop[ind_pais[1],])
    #print(pop[ind_pais[2],])
    #print(f1)
    #print(onemax(pop[ind_pais[1],]))
    #print(onemax(pop[ind_pais[2],]))
    #print(onemax(f1))
    #print(onemax(f2))
    
    # QUINTO PASSO:
    # Aplica a mutacao em cada filho 
    #   com uma probabilidade prop_mut
    # Percorre o cromossomo e verifica se aplica mutacao
    for (i in 1:tam_crom) {
      if (runif(1) < prob_mut) {
        if (f1[i] == 0) f1[i] = 1
        else f1[i] = 0
      }
      
      if (runif(1) < prob_mut) {
        if (f2[i] == 0) f2[i] = 1
        else f2[i] = 0
      }
    }
    
    #print(onemax(f1))
    #print(onemax(f2))
    
    # SEXTO PASSO:
    # Insere os filhos na populacao
    if (fitness[ind_pais[1]] < fitness[ind_pais[2]]) pior = ind_pais[1]
    else pior = ind_pais[2]

    # Exercicio: fazer o *melhor* filho subsituir o *pior* pai    
    if (onemax(f1) > fitness[pior]) {
      pop[pior,] = f1
      fitness[pior] = onemax(f1)
    } else if (onemax(f2) > fitness[pior]) {
      pop[pior,] = f2
      fitness[pior] = onemax(f2)
    }
    
    
    cat(t, "\t", max(fitness), mean(fitness), sd(fitness), "\n")
  }
  
  
  
  
}

