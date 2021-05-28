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

isort :: Ord a => [a] -> [a]
isort lista = insertOrd lista []
  where
    insertOrd [] x = x
    insertOrd (x : y : xs) res =
      if x > y
        then insertOrd (y : xs) (x : res)
        else insertOrd (x : xs) (y : res)

{-Original-}
insertionOri :: (Ord a) => [a] -> ([a], Int)
insertionOri [] = ([], 0)
insertionOri (x : xs) = (res, cont + contInsert)
  where
    (list, cont) = insertionOri xs
    (res, contInsert) = insertOrdOri x list

insertOrdOri :: (Ord a) => a -> [a] -> ([a], Int)
insertOrdOri x [] = ([x], 0)
insertOrdOri x (y : ys)
  | x <= y = (x : y : ys, 1)
  | otherwise = (y : res, cont + 1)
  where
    (res, cont) = insertOrdOri x ys

{-Variação 1-}
--TODO
insertionV1 :: (Ord a) => [a] -> ([a], Int)
insertionV1 [] = ([], 0)
insertionV1 lis = foldl insertOrdV1 ([], 0) lis
  where
    insertOrdV1 :: (Ord a) => ([a], Int) -> a -> ([a], Int)
    insertOrdV1 ([], c) x = ([x], c)
    insertOrdV1 (y : ys, c) x
      | x <= y = (x : y : ys, c + 1)
      | otherwise = (y : res, cont + 1)
      where
        (res, cont) = insertOrdV1 (ys, c) x

o_l1, o_l2, o_l3, o_l4, o_l5, o_l6, o_l7 :: ([Int], Int)
o_l1 = insertionOri l1
o_l2 = insertionOri l2
o_l3 = insertionOri l3
o_l4 = insertionOri l4
o_l5 = insertionOri l5
o_l6 = insertionOri l6
o_l7 = insertionOri l7

o_x1, o_x2, o_x3, o_x4, o_x5, o_x6, o_x7 :: ([Int], Int)
o_x1 = insertionOri x1
o_x2 = insertionOri x2
o_x3 = insertionOri x3
o_x4 = insertionOri x4
o_x5 = insertionOri x5
o_x6 = insertionOri x6
o_x7 = insertionOri x7

v1_l1, v1_l2, v1_l3, v1_l4, v1_l5, v1_l6, v1_l7 :: ([Int], Int)
v1_l1 = insertionV1 l1
v1_l2 = insertionV1 l2
v1_l3 = insertionV1 l3
v1_l4 = insertionV1 l4
v1_l5 = insertionV1 l5
v1_l6 = insertionV1 l6
v1_l7 = insertionV1 l7

v1_x1, v1_x2, v1_x3, v1_x4, v1_x5, v1_x6, v1_x7 :: ([Int], Int)
v1_x1 = insertionV1 x1
v1_x2 = insertionV1 x2
v1_x3 = insertionV1 x3
v1_x4 = insertionV1 x4
v1_x5 = insertionV1 x5
v1_x6 = insertionV1 x6
v1_x7 = insertionV1 x7

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
  evaluate $ force x7

  putStrLn $ show (snd o_l1)
  putStrLn $ show (snd o_l2)
  putStrLn $ show (snd o_l3)
  putStrLn $ show (snd o_l4)
  putStrLn $ show (snd o_l5)
  putStrLn $ show (snd o_l6)
  putStrLn $ show (snd o_l7)
  putStrLn $ show (snd o_x1)
  putStrLn $ show (snd o_x2)
  putStrLn $ show (snd o_x3)
  putStrLn $ show (snd o_x4)
  putStrLn $ show (snd o_x5)
  putStrLn $ show (snd o_x6)
  putStrLn $ show (snd o_x7)
  putStrLn $ ""
  putStrLn $ show (snd v1_l1)
  putStrLn $ show (snd v1_l2)
  putStrLn $ show (snd v1_l3)
  putStrLn $ show (snd v1_l4)
  putStrLn $ show (snd v1_l5)
  putStrLn $ show (snd v1_l6)
  putStrLn $ show (snd v1_l7)
  putStrLn $ show (snd v1_x1)
  putStrLn $ show (snd v1_x2)
  putStrLn $ show (snd v1_x3)
  putStrLn $ show (snd v1_x4)
  putStrLn $ show (snd v1_x5)
  putStrLn $ show (snd v1_x6)
  putStrLn $ show (snd v1_x7)