figura :: Int -> Int -> Int -> String
figura a b c
  | a == 90 || b == 90 || c == 90 = "retangulo"
  | a > 90 || b > 90 || c > 90 = "obtuso"
  | a == b && b == c = "equilatero"
  | otherwise = "simples"

seleciona :: [[Int]] -> [[Int]]
seleciona lista = [ns | (n : ns) <- lista, n < 4 || (n : ns) == []]

-- [[1,2,3],[7],[3,6,7,8],[2],[9,1,3,4,5],[8,8]]