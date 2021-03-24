tabuada :: Int -> [Int]
tabuada x = [x * n | n <- [1 .. 10]]

tabuadaRecursiva :: Int -> [Int]
tabuadaRecursiva x = tabuadaRecursivaM [x] (10 * x)
tabuadaRecursivaM :: [Int]->Int->[Int]
tabuadaRecursivaM x:xs parada =
  if x < parada
    then tabuadaRecursivaM ((x + x):x:xs) parada: x :xs
    else x:xs