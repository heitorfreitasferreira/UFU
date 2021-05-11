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
bolhaOri :: Ord a => [a] -> ([a], Int)
bolhaOri [] = ([], 0)
bolhaOri lista = bolhaOrdOri (lista, 0) (length lista)

bolhaOrdOri :: (Eq t, Num t, Ord a) => ([a], Int) -> t -> ([a], Int)
bolhaOrdOri (lista, m) 0 = (lista, m)
bolhaOrdOri (lista, m) n = bolhaOrdOri (fst trocas, snd trocas + m) (n - 1)
  where
    trocas = trocaOri lista

trocaOri :: (Ord a, Num b) => [a] -> ([a], b)
trocaOri l = _trocaOri l ([], 0)
  where
    _trocaOri [x] (lis, c) = (lis ++ [x], c)
    _trocaOri (x : y : zs) (l, c)
      | x > y = _trocaOri (x : zs) (l ++ [y], c + 1)
      | otherwise = _trocaOri (y : zs) (l ++ [x], c)

{-Variação 1-}
bolhaV1 :: Ord a => [a] -> ([a], Int)
bolhaV1 [] = ([], 0)
bolhaV1 lista = bolhaOrdV1 (lista, 0) (length lista)

bolhaOrdV1 :: (Eq t, Num t, Ord a) => ([a], Int) -> t -> ([a], Int)
bolhaOrdV1 (lista, m) 0 = (lista, m)
bolhaOrdV1 (lista, m) n
  | snd trocas == 0 = (lista, m)
  | otherwise = bolhaOrdV1 (fst trocas, snd trocas + m) (n - 1)
  where
    trocas = trocaV1 lista

trocaV1 :: (Ord a, Num b) => [a] -> ([a], b)
trocaV1 l = _trocaV1 l ([], 0)
  where
    _trocaV1 [x] (lis, c) = (lis ++ [x], c)
    _trocaV1 (x : y : zs) (l, c)
      | x > y = _trocaV1 (x : zs) (l ++ [y], c + 1)
      | otherwise = _trocaV1 (y : zs) (l ++ [x], c)

{-Variação 2-}
bolhaV2 :: Ord a => [a] -> ([a], Int)
bolhaV2 [] = ([], 0)
bolhaV2 lista = bolhaOrdV2 (lista, 0) (length lista)

bolhaOrdV2 :: (Eq t, Num t, Ord a) => ([a], Int) -> t -> ([a], Int)
bolhaOrdV2 (lista, m) 0 = (lista, m)
bolhaOrdV2 (lista, m) n
  | snd trocas == 0 = (lista, m)
  | otherwise = bolhaOrdV2 (fst trocas, snd trocas + m) (n - 1)
  where
    trocas = trocaV2 lista

trocaV2 :: (Ord a, Num b) => [a] -> ([a], b)
trocaV2 l = _trocaV2 l ([], 0)
  where
    _trocaV2 [x] (lis, c) = (lis ++ [x], c)
    _trocaV2 (x : y : zs) (l, c)
      | x > y = _trocaV2 (x : zs) (l ++ [y], c + 1)
      | otherwise = _trocaV2 (y : zs) (l ++ [x], c)
