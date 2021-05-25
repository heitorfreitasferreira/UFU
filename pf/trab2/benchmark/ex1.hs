import Control.DeepSeq (force)
import Control.Exception (evaluate)
import Data.List ()

-- import qualified Criterion
-- import qualified Criterion.Main

l1, l2, l3, l4, l5, l6, l7 :: [Int]
l1 = [1 .. 2000]
l2 = [2000, 1999 .. 1]
l3 = l1 ++ [0]
l4 = 0 : l2
l5 = l1 ++ [0] ++ l2
l6 = l2 ++ [0] ++ l1
l7 = l2 ++ [0] ++ l2

x1, x2, x3, x4, x5, x6, x7 :: [Int]
x1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
x2 = [20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
x3 = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
x4 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11]
x5 = [11, 12, 13, 14, 15, 5, 4, 3, 2, 1, 16, 17, 18, 19, 20, 10, 9, 8, 7, 6]
x6 = [1, 12, 3, 14, 5, 15, 4, 13, 2, 11, 6, 17, 8, 19, 20, 10, 9, 18, 7, 16]
x7 = [20, 8, 2, 11, 13, 3, 7, 18, 14, 4, 16, 10, 15, 1, 9, 17, 19, 12, 5, 6]

{-Original-}
bolhaOri :: Ord a => [a] -> ([a], Int)
bolhaOri [] = ([], 0)
bolhaOri lista = bolhaOrdOri lista (length lista)

bolhaOrdOri :: Ord a => [a] -> Int -> ([a], Int)
bolhaOrdOri lista 0 = (lista, 0)
bolhaOrdOri lista n = (bolhaOrd, j + cont)
  where
    (lst, j) = trocaOri lista
    (bolhaOrd, cont) = bolhaOrdOri lst (n - 1)

trocaOri :: Ord a => [a] -> ([a], Int)
trocaOri [x] = ([x], 0)
trocaOri (x : y : zs)
  | x > y = (y : l1, c1 + 1)
  | otherwise = (x : l2, c2)
  where
    (l1, c1) = trocaOri (x : zs)
    (l2, c2) = trocaOri (y : zs)

{-Variação 1-}
bolhaV1 :: Ord a => [a] -> ([a], Int)
bolhaV1 [] = ([], 0)
bolhaV1 lista = bolhaOrdV1 lista (length lista)

bolhaOrdV1 :: Ord a => [a] -> Int -> ([a], Int)
bolhaOrdV1 lista 0 = (lista, 0)
bolhaOrdV1 lista n = (bolhaOrd, j + cont)
  where
    (lst, j) = trocaV1 lista
    (bolhaOrd, cont) = if j == 0 then (lst, j) else bolhaOrdV1 lst (n - 1)

trocaV1 :: Ord a => [a] -> ([a], Int)
trocaV1 [x] = ([x], 0)
trocaV1 (x : y : zs)
  | x > y = (y : l1, c1 + 1)
  | otherwise = (x : l2, c2)
  where
    (l1, c1) = trocaV1 (x : zs)
    (l2, c2) = trocaV1 (y : zs)

{-Variação 2-}
bolhaV2 :: Ord a => [a] -> ([a], Int)
bolhaV2 [] = ([], 0)
bolhaV2 lista = bolhaOrdV2 lista (length lista)

bolhaOrdV2 :: Ord a => [a] -> Int -> ([a], Int)
bolhaOrdV2 lista 0 = (lista, 0)
bolhaOrdV2 lista n = (bolhaOrd, j + cont)
  where
    (lst, j) = trocaV2 lista n
    {- (lst, j) = trocaV2 (take n lista) -}
    (bolhaOrd, cont) = if j == 0 then (lst, j) else bolhaOrdV2 lst (n - 1)

trocaV2 :: Ord a => [a] -> Int -> ([a], Int)
trocaV2 [x] _ = ([x], 0)
trocaV2 lis 0 = (lis, 0)
trocaV2 (x : y : zs) n
  | x > y = (y : l1, c1 + 1)
  | otherwise = (x : l2, c2)
  where
    (l1, c1) = trocaV2 (x : zs) n
    (l2, c2) = trocaV2 (y : zs) n

o_l1, o_l2, o_l3, o_l4, o_l5, o_l6, o_l7 :: ([Int], Int)
o_l1 = bolhaOri l1
o_l2 = bolhaOri l2
o_l3 = bolhaOri l3
o_l4 = bolhaOri l4
o_l5 = bolhaOri l5
o_l6 = bolhaOri l6
o_l7 = bolhaOri l7

o_x1, o_x2, o_x3, o_x4, o_x5, o_x6, o_x7 :: ([Int], Int)
o_x1 = bolhaOri x1
o_x2 = bolhaOri x2
o_x3 = bolhaOri x3
o_x4 = bolhaOri x4
o_x5 = bolhaOri x5
o_x6 = bolhaOri x6
o_x7 = bolhaOri x7

v1_l1, v1_l2, v1_l3, v1_l4, v1_l5, v1_l6, v1_l7 :: ([Int], Int)
v1_l1 = bolhaV1 l1
v1_l2 = bolhaV1 l2
v1_l3 = bolhaV1 l3
v1_l4 = bolhaV1 l4
v1_l5 = bolhaV1 l5
v1_l6 = bolhaV1 l6
v1_l7 = bolhaV1 l7

v1_x1, v1_x2, v1_x3, v1_x4, v1_x5, v1_x6, v1_x7 :: ([Int], Int)
v1_x1 = bolhaV1 x1
v1_x2 = bolhaV1 x2
v1_x3 = bolhaV1 x3
v1_x4 = bolhaV1 x4
v1_x5 = bolhaV1 x5
v1_x6 = bolhaV1 x6
v1_x7 = bolhaV1 x7

v2_l1, v2_l2, v2_l3, v2_l4, v2_l5, v2_l6, v2_l7 :: ([Int], Int)
v2_l1 = bolhaV2 l1
v2_l2 = bolhaV2 l2
v2_l3 = bolhaV2 l3
v2_l4 = bolhaV2 l4
v2_l5 = bolhaV2 l5
v2_l6 = bolhaV2 l6
v2_l7 = bolhaV2 l7

v2_x1, v2_x2, v2_x3, v2_x4, v2_x5, v2_x6, v2_x7 :: ([Int], Int)
v2_x1 = bolhaV2 x1
v2_x2 = bolhaV2 x2
v2_x3 = bolhaV2 x3
v2_x4 = bolhaV2 x4
v2_x5 = bolhaV2 x5
v2_x6 = bolhaV2 x6
v2_x7 = bolhaV2 x7

main :: IO ()
main = do
  evaluate $ force l1
  evaluate $ force l2
  evaluate $ force l3
  evaluate $ force l4
  evaluate $ force l5
  evaluate $ force l6
  evaluate $ force l7
  evaluate $ force x1
  evaluate $ force x2
  evaluate $ force x3
  evaluate $ force x4
  evaluate $ force x5
  evaluate $ force x6

  putStrLn $ show (snd o_l1)
  putStrLn $ show o_l1
  putStrLn $ show o_l2
  putStrLn $ show o_l3
  putStrLn $ show o_l4
  putStrLn $ show o_l5
  putStrLn $ show o_l6
  putStrLn $ show o_l7
  putStrLn $ show o_x1
  putStrLn $ show o_x2
  putStrLn $ show o_x3
  putStrLn $ show o_x4
  putStrLn $ show o_x5
  putStrLn $ show o_x6

  putStrLn $ show v1_l1
  putStrLn $ show v1_l1
  putStrLn $ show v1_l2
  putStrLn $ show v1_l3
  putStrLn $ show v1_l4
  putStrLn $ show v1_l5
  putStrLn $ show v1_l6
  putStrLn $ show v1_l7
  putStrLn $ show v1_x1
  putStrLn $ show v1_x2
  putStrLn $ show v1_x3
  putStrLn $ show v1_x4
  putStrLn $ show v1_x5
  putStrLn $ show v1_x6

  putStrLn $ show v2_l1
  putStrLn $ show v2_l1
  putStrLn $ show v2_l2
  putStrLn $ show v2_l3
  putStrLn $ show v2_l4
  putStrLn $ show v2_l5
  putStrLn $ show v2_l6
  putStrLn $ show v2_l7
  putStrLn $ show v2_x1
  putStrLn $ show v2_x2
  putStrLn $ show v2_x3
  putStrLn $ show v2_x4
  putStrLn $ show v2_x5
  putStrLn $ show v2_x6