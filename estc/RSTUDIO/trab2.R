qnt <-0
for (i in 1:100000) {
  
  balde1<- c("p","p","p","p","p","p","b","b","b","v","v","v","v","v")
  balde2<- c("p","p","p","p","b","b","b","b","v","v")
  balde3<- c("p","p","p","p","b","b","v","v","v","v","v","v","v")
  dado <- sample(x=1:6,size= 1)
  if(dado==5){
    escolha <- sample(x = 1:length(balde1),size = 1 )
    if(balde1[escolha] == "v"){
      qnt = qnt +1
    }
  }
  if(dado==1 || dado == 4){
    escolha <- sample(x = 1:length(balde2),size = 1 )
    if(balde2[escolha] == "v"){
      qnt = qnt +1
    }
  }
  if(dado==2 || dado == 3 || dado == 6){
    escolha <- sample(x = 1:length(balde3),size = 1 )
    if(balde3[escolha] == "v"){
      qnt = qnt +1
    }
  }
}
qnt/100000
