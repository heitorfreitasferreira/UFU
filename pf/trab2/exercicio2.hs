l1 = [1 .. 2000]

l2 = [2000, 1999 .. 1]

l3 = l1 ++ [0]

l4 = 0 : l2

l5 = l1 ++ [0] ++ l2

l6 = l2 ++ [0] ++ l1

l7 = l2 ++ [0] ++ l2

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
selectionSortOri xs = (fst x : fst (selectionSortOri (delElemOri (fst x) xs)), snd (selectionSortOri (delElemOri (fst x) xs)) + snd x)
  where
    x = minimoOri xs 0

delElemOri :: (Ord a) => a -> [a] -> [a]
delElemOri _ [] = []
delElemOri a (x : xs)
  | a == x = xs
  | otherwise = x : delElemOri a xs

minimoOri :: (Ord a) => [a] -> Int -> (a, Int)
minimoOri [] _ = undefined
minimoOri [x] num = (x, num)
minimoOri (x : y : xs) num
  | x < y = minimoOri (x : xs) (num + 1)
  | otherwise = minimoOri (y : xs) num

{-Variação 1-}
selectionSortV1 :: (Ord a) => [a] -> ([a], Int)
selectionSortV1 [] = ([], 0)
selectionSortV1 lista = (menor : fst (selectionSortV1 resto), contador + snd (selectionSortV1 resto))
  where
    (resto, menor, contador) = removeMenorV1 lista

removeMenorV1 :: (Ord a, Num b) => [a] -> ([a], a, b)
removeMenorV1 l = _removeMenorV1 l ([], 0)
  where
    _removeMenorV1 [x] (lis, c) = (lis, x, c)
    _removeMenorV1 (x : y : zs) (l, c)
      | x < y = _removeMenorV1 (x : zs) (l ++ [y], c + 1)
      | otherwise = _removeMenorV1 (y : zs) (l ++ [x], c)