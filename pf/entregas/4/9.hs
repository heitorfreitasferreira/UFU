subListas :: [[Int]] -> [Int]

subListas x = [n|parcial<-x,n<-parcial]