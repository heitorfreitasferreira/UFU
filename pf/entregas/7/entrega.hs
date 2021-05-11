paridade :: [Int] -> [Bool]
paridade = map even

prefix :: [String] -> [String]
prefix = map _prefix
  where
    _prefix :: String -> String
    _prefix (x : y : z : _) = x : y : [z]

saudacao :: [String] -> [String]
saudacao = map _saudacao
  where
    _saudacao :: String -> String
    _saudacao n = "Oi " ++ n

filtrar :: (a -> Bool) -> [a] -> [a]
filtrar f [] = []
filtrar f (x : xs) = if f x then x : filtrar f xs else filtrar f xs

pares :: [Int] -> [Int]
pares = filter even

solucoes :: [Int] -> [Int]
solucoes = filter (\x -> 5 * x + 6 < x * x)

maior :: [Int] -> Int
maior = maximum

menor_min10 :: [Int] -> Int
menor_min10 x = if minimum x > 10 then minimum x else 10

junta_silabas_plural :: [String] -> String
junta_silabas_plural = foldr (++) "s"

menores10_itens :: [Int] -> ([Int], Int)
menores10_itens lst = _min10 lst [] 0
  where
    _min10 :: [Int] -> [Int] -> Int -> ([Int], Int)
    _min10 list result qnt
      | qnt == 10 || list == [] = (result, qnt)
      | otherwise = _min10 (removeItem (minimum list) list) (minimum list : result) (qnt + 1)
      where
        removeItem :: Int -> [Int] -> [Int]
        removeItem _ [] = []
        removeItem x (y : ys)
          | x == y = removeItem x ys
          | otherwise = y : removeItem x ys

menores10 :: [Int] -> ([Int], Int)
menores10 lst = _min10 lst [] 0
  where
    _min10 :: [Int] -> [Int] -> Int -> ([Int], Int)
    _min10 [] result qnt = (result, qnt)
    _min10 (x : xs) result qnt =
      if x < 10
        then _min10 xs (x : result) (qnt + 1)
        else _min10 xs result qnt

buscaElem :: (Eq t1, Num t2) => t1 -> [t1] -> (Bool, t2)
buscaElem x list = _buscaElem x list 0
  where
    _buscaElem n [] qnt = (False, qnt)
    _buscaElem n (x : xs) qnt =
      if n == x
        then (True, qnt + 1)
        else _buscaElem n xs (qnt + 1)