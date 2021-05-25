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
selectionSortOri :: (Ord a) => [a] -> ([a], Int)
selectionSortOri [] = ([], 0)
selectionSortOri xs = (x : resto, contTrocas + trocasResto)
  where
    (x, contTrocas) = minimoOri xs
    (resto, trocasResto) = selectionSortOri (delElemOri x xs)
    delElemOri :: (Ord a) => a -> [a] -> [a]
    delElemOri _ [] = []
    delElemOri a (x : xs)
      | a == x = xs
      | otherwise = x : delElemOri a xs

    minimoOri :: (Ord a) => [a] -> (a, Int)
    minimoOri [x] = (x, 0)
    minimoOri (x : y : xs)
      | x < y = (menor1, cont1)
      | otherwise = (menor2, cont2 + 1)
      where
        (menor1, cont1) = minimoOri (x : xs)
        (menor2, cont2) = minimoOri (y : xs)

{-Variação 1-}
selectionSortV1 :: (Ord a) => [a] -> ([a], Int)
selectionSortV1 [] = ([], 0)
selectionSortV1 xs = (x : resto, trocas + trocasResto)
  where
    (semMenor, x, trocas) = removeMenorV1 xs
    (resto, trocasResto) = selectionSortV1 semMenor
    removeMenorV1 :: (Ord a, Num b) => [a] -> ([a], a, b)
    removeMenorV1 l = _removeMenorV1 l ([], 0)
      where
        _removeMenorV1 [x] (lis, c) = (reverse lis, x, c)
        _removeMenorV1 (x : y : zs) (l, c)
          | x < y = _removeMenorV1 (x : zs) (y : l, c + 1)
          | otherwise = _removeMenorV1 (y : zs) (x : l, c)

{-Variação 2-}
selectionSortV2 :: (Ord a) => [a] -> ([a], Int)
selectionSortV2 [] = ([], 0)
selectionSortV2 (h : xs) = (x : resto, contTrocas + trocasResto)
  where
    (x, contTrocas) = foldl minimoV1 (h, 0) xs
    (resto, trocasResto) = selectionSortV2 (delElemV1 x (h : xs))

    delElemV1 :: (Ord a) => a -> [a] -> [a]
    delElemV1 _ [] = []
    delElemV1 a (x : xs)
      | a == x = xs
      | otherwise = x : delElemV1 a xs

    minimoV1 :: (Ord a) => (a, Int) -> a -> (a, Int)
    minimoV1 (x, c) y
      | x < y = (x, c)
      | otherwise = (y, c + 1)

o_l1, o_l2, o_l3, o_l4, o_l5, o_l6, o_l7 :: ([Int], Int)
o_l1 = selectionSortOri l1
o_l2 = selectionSortOri l2
o_l3 = selectionSortOri l3
o_l4 = selectionSortOri l4
o_l5 = selectionSortOri l5
o_l6 = selectionSortOri l6
o_l7 = selectionSortOri l7

o_x1, o_x2, o_x3, o_x4, o_x5, o_x6, o_x7 :: ([Int], Int)
o_x1 = selectionSortOri x1
o_x2 = selectionSortOri x2
o_x3 = selectionSortOri x3
o_x4 = selectionSortOri x4
o_x5 = selectionSortOri x5
o_x6 = selectionSortOri x6
o_x7 = selectionSortOri x7

v1_l1, v1_l2, v1_l3, v1_l4, v1_l5, v1_l6, v1_l7 :: ([Int], Int)
v1_l1 = selectionSortV1 l1
v1_l2 = selectionSortV1 l2
v1_l3 = selectionSortV1 l3
v1_l4 = selectionSortV1 l4
v1_l5 = selectionSortV1 l5
v1_l6 = selectionSortV1 l6
v1_l7 = selectionSortV1 l7

v1_x1, v1_x2, v1_x3, v1_x4, v1_x5, v1_x6, v1_x7 :: ([Int], Int)
v1_x1 = selectionSortV1 x1
v1_x2 = selectionSortV1 x2
v1_x3 = selectionSortV1 x3
v1_x4 = selectionSortV1 x4
v1_x5 = selectionSortV1 x5
v1_x6 = selectionSortV1 x6
v1_x7 = selectionSortV1 x7

v2_l1, v2_l2, v2_l3, v2_l4, v2_l5, v2_l6, v2_l7 :: ([Int], Int)
v2_l1 = selectionSortV2 l1
v2_l2 = selectionSortV2 l2
v2_l3 = selectionSortV2 l3
v2_l4 = selectionSortV2 l4
v2_l5 = selectionSortV2 l5
v2_l6 = selectionSortV2 l6
v2_l7 = selectionSortV2 l7

v2_x1, v2_x2, v2_x3, v2_x4, v2_x5, v2_x6, v2_x7 :: ([Int], Int)
v2_x1 = selectionSortV2 x1
v2_x2 = selectionSortV2 x2
v2_x3 = selectionSortV2 x3
v2_x4 = selectionSortV2 x4
v2_x5 = selectionSortV2 x5
v2_x6 = selectionSortV2 x6
v2_x7 = selectionSortV2 x7

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

  putStrLn $ show o_l1
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