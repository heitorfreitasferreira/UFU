uniaoNRec :: [Int] -> [Int] -> [Int]
uniaoNRec x y = x++[n|n<-y, n `notElem` x]