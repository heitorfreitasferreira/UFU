xLst :: [Float]
xLst = [10, 11, 12, 13, 14, 15]

yLst :: [Float]
yLst = [100, 112, 119, 130, 139, 142]

tamanho :: Num p => [a] -> p
tamanho = foldr (\x -> (+) 1) 0

media :: [Float] -> Float
media lst = sum lst / tamanho lst

numerador :: [Float] -> [Float] -> Float -> Float -> Float
numerador [] [] _ _ = 0
numerador (x : xs) (y : ys) mediaX mediaY = (x - mediaX) * (y - mediaY) + numerador xs ys mediaX mediaY

sumBaixo :: [Float] -> Float -> Float
sumBaixo [] _ = 0
sumBaixo (x : xs) media = (x - media) * (x - media) + sumBaixo xs media

denominador :: [Float] -> [Float] -> Float
denominador x y = sumBaixo x (media x) * sumBaixo y (media y)

r :: [Float] -> [Float] -> Float
r x y = numerador x y (media x) (media y) / sqrt (denominador x y)

b :: Float
b = numerador xLst yLst (media xLst) (media yLst) / sumBaixo xLst (media xLst)

a :: Float
a = media yLst - b * media xLst

fx :: Float -> Float
fx x = a + b * x

tc :: Float -> Float
tc sizeList = erre / sqrt ((1 - erre * erre) / (sizeList -2))
  where
    erre = r xLst yLst

sqTotal :: Float
sqTotal = sumBaixo yLst (media yLst)

sqRegressao :: Float
sqRegressao = b * b * sumBaixo xLst (media xLst)

sqErro :: Float
sqErro = sqTotal - sqRegressao

qmRegressao :: Float
qmRegressao = sqRegressao

qmErro :: Float
qmErro = sqErro / (tamanho yLst -2)

r2 :: Float
r2 = sqRegressao / sqTotal