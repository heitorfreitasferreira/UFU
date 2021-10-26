#1
mat_dist = rbind(c(0, 9, 3, 6, 11), c(9, 0, 7, 5, 10), c(3, 7, 0, 9, 2), c(6, 5, 9, 0, 8), c(11, 10, 2, 8, 0))

mat_dist = as.dist(mat_dist)
  #a
  cluster = hclust(mat_dist, method = "complete")
  plot(cluster)
  #b
  
  cluster = hclust(mat_dist, method = "single")
  plot(cluster)
  #c
  cluster = hclust(mat_dist, method = "complete")
  plot(cluster)
  rect.hclust(cluster, k = 2)
    # 3-5 / 1-2-4
  #d
  cluster = hclust(mat_dist, method = "single")
  plot(cluster)
  rect.hclust(cluster, k = 2)
    #1-3-5/2-4
#2
#2
library(tree)
library(rpart)
library(rpart.plot)
patients = read.csv("heart.txt", header = TRUE, sep = ",");
patients = patients[, -1]
cor(patients[1:4])
patients = patients[sample(nrow(patients)), ]
summary(patients)
#a
  patients$sex = as.factor(patients$sex)
  patients$chest_pain = as.factor(patients$chest_pain)
  patients$smokes = as.factor(patients$smokes)
  patients$exercises = as.factor(patients$exercises)
  patients$heart_attack = as.factor(patients$heart_attack)
  
  treino = patients[1:4, ]
  teste = patients[5:6, ]
  doente = patients[patients$heart_attack == "yes", ]
  saudaveis = patients[patients$heart_attack == "no", ]
  summary(doente)
  summary(saudaveis)
  classificador <- rpart(formula = heart_attack ~.,data = treino, parms = list(split = "gini"))
  print(classificador)
  rpart.plot(classificador)

