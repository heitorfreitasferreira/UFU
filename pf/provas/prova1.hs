figura :: Int -> Int -> Int -> String
figura a b c
  | a == 90 || b == 90 || c == 90 = "retangulo"
  | a > 90 || b > 90 || c > 90 = "obtuso"
  | a == b && b == c = "equilatero"
  | otherwise = "simples"

seleciona :: [[Int]] -> [[Int]]
seleciona lista = [ns | (n : ns) <- lista, n < 4 || null (n : ns)]

-- [[1,2,3],[7],[3,6,7,8],[2],[9,1,3,4,5],[8,8]]
removeElem :: Eq t => t -> [t] -> [t]
removeElem x [] = []
removeElem x (y : ys) =
  if x == y
    then removeElem x ys
    else y : removeElem x ys

removeVarios :: Eq t => [t] -> [t] -> [t]
removeVarios l [] = l
removeVarios (x : xs) (y : ys) = removeVarios (removeElem y (x : xs)) ys

seque :: Eq a => [a] -> [a] -> Bool
seque _ [] = True
seque (x : xs) (y : ys) = (y == x) && seque xs ys

-- removeVogais :: [String] -> [String]
-- removeVogais [] = []
-- removeVogais (x : xs) = (removeVogal x) : removeVogais xs

representa :: [String] -> String -> [String]
representa x y = [n | n <- x, removeVogal n == y]
  where
    removeVogal :: String -> String
    removeVogal [] = []
    removeVogal (x : xs) =
      if x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'
        then removeVogal xs
        else x : removeVogal xs
