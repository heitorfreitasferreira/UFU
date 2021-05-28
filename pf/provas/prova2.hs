{-

  Nome: Heitor Freitas Ferreira
  Matricula: 11921BCC026

-}
{-RASCUNHO-}
-- quickSort3 :: (Ord a) => [a] -> ([a], Int)
-- quickSort3 [] = ([], 0)
-- quickSort3 [x] = ([x], 0)
-- quickSort3 (s : xs) = (quickSort3 lst1 ++ [s] ++ quickSort3 lst2, n)
--   where
--     (lst1, lst2) = divide1 s xs
--     (lista1, nEsq) = quickSort3 lst1
--     () = quickSort3 lst2

-- divide1 :: (Ord a) => a -> [a] -> ([a], [a])
-- divide1 p [] = ([], [])
-- divide1 p (x : xs) = if x > p then (x : l1, l2) else (l1, x : l2)
--   where
--     (l1, l2) = divide1 p xs

{-QUESTÃO 1-}
quickSort :: (Ord a) => [a] -> ([a], Int)
quickSort x = _quickSort x 0

_quickSort :: (Ord a) => [a] -> Int -> ([a], Int)
_quickSort [] _ = ([], 0)
_quickSort [x] n = ([x], 1)
_quickSort (s : xs) n = (listaEsq ++ [s] ++ listaDir, nDir + nEsq)
  where
    (lst1, lst2) = divide s xs
    (listaEsq, nEsq) = _quickSort lst1 (n + 1)
    (listaDir, nDir) = _quickSort lst2 (n + 1)

divide :: (Ord a) => a -> [a] -> ([a], [a])
divide p [] = ([], [])
divide p (x : xs) =
  if x > p
    then (x : l1, l2)
    else (l1, x : l2)
  where
    (l1, l2) = divide p xs

{-QUESTÃO 2-}
{-A-}
totaliza :: [Int] -> Int
totaliza lst = foldl (*) 1 (filter (\x -> x `mod` 2 == 0) lst)

{-B-}

addTriplas :: [(Integer, Integer, Integer)] -> [Integer]
addTriplas lst = filter (\x -> x `mod` 2 == 0) (map (\(x, y, z) -> x + y + z) lst)

{-QUESTÃO 3-}

data ArvoreBinInt = Nulo | No Int ArvoreBinInt ArvoreBinInt deriving (Show, Eq)

arvEx :: ArvoreBinInt
arvEx = No 7 (No 3 (No 6 Nulo Nulo) (No 1 (No 4 Nulo Nulo) Nulo)) (No 10 Nulo (No 14 Nulo Nulo))

buscaMult3 :: ArvoreBinInt -> String -> Int
buscaMult3 tree tipo
  | tipo == "sim" = buscaMult3Sim tree
  | tipo == "pre" = buscaMult3Pre tree
  | otherwise = -1
  where
    buscaMult3Sim :: ArvoreBinInt -> Int
    buscaMult3Pre :: ArvoreBinInt -> Int

    buscaMult3Pre Nulo = -1
    buscaMult3Pre (No x esq dir)
      | x `mod` 3 == 0 = x
      | buscaMult3Pre esq `mod` 3 == 0 = buscaMult3Pre esq
      | buscaMult3Pre dir `mod` 3 == 0 = buscaMult3Pre dir

    buscaMult3Sim Nulo = -1
    buscaMult3Sim (No x esq dir)
      | buscaMult3Sim esq `mod` 3 == 0 = buscaMult3Sim esq
      | x `mod` 3 == 0 = x
      | buscaMult3Sim dir `mod` 3 == 0 = buscaMult3Sim dir

{-QUESTÃO 4-}
data Horario = AntesMD Int Int Int | AposMD Int Int Int deriving (Show)

analisaHorario :: (Int, Int, Int) -> (Int, Int, Int) -> (Int, Int, Int)
analisaHorario (h1, m1, s1) (h2, m2, s2)
  | h1 > h2 = (h1, m1, s1)
  | h2 > h1 = (h2, m2, s2)
  | m1 > m2 = (h1, m1, s1)
  | m2 > m1 = (h2, m2, s2)
  | s1 > s2 = (h1, m1, s1)
  | s2 > s1 = (h2, m2, s2)
  | otherwise = (h1, m1, s1)

maisTarde :: Horario -> Horario -> Horario
-- Caso algum dos horários seja após o meio dia e o outro antes do meio dia que que é após o meio dia automaticamente é mais tarde
maisTarde (AntesMD hora1 min1 seg1) (AposMD hora2 min2 seg2) = AposMD hora2 min2 seg2
maisTarde (AposMD hora2 min2 seg2) (AntesMD hora1 min1 seg1) = AposMD hora2 min2 seg2
-- Caso de os dois horários serem ou antes ou após o meio dia temos que analisar os valores do tempo, isso é feito com a função aux analisaHorario
maisTarde (AntesMD hora1 min1 seg1) (AntesMD hora2 min2 seg2) = AntesMD horaR minR segR
  where
    (horaR, minR, segR) = analisaHorario (hora1, min1, seg1) (hora2, min2, seg2)
maisTarde (AposMD hora1 min1 seg1) (AposMD hora2 min2 seg2) = AposMD horaR minR segR
  where
    (horaR, minR, segR) = analisaHorario (hora1, min1, seg1) (hora2, min2, seg2)