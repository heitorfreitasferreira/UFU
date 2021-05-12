l1 = [1 .. 2000]

l2=[2000,1999..1]

l3=l1++[0]

l4=[0]++l2

l5=l1++[0]++l2

l6=l2++[0]++l1

l7=l2++[0]++l2

x1=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]

x2=[20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1]

x3=[11,12,13,14,15,16,17,18,19,20,1,2,3,4,5,6,7,8,9,10]

x4=[10,9,8,7,6,5,4,3,2,1,20,19,18,17,16,15,14,13,12,11]

x5=[11,12,13,14,15,5,4,3,2,1,16,17,18,19,20,10,9,8,7,6]

x6=[1,12,3,14,5,15,4,13,2,11,6,17,8,19,20,10,9,18,7,16]

x7 = [20,8,2,11,13,3,7,18,14,4,16,10,15,1,9,17,19,12,5,6]


{-Original-}
quickSortOri :: (Ord a) => [a] -> ([a], Int)
quickSortOri [] = ([], 0)
quickSortOri (p : xs) = 
  let (esq, cont_esq) = filtrarCont (< p) xs 
      (dir, cont_dir) = filtrarCont (>= p) xs
      (ordEsq, n_esq) = quickSortOri esq
      (ordDir, n_dir) = quickSortOri dir
  in (ordEsq ++ [p] ++ ordDir, cont_esq + cont_dir + n_dir + n_esq)
  where
    filtrarCont :: (a -> Bool) -> [a] -> ([a], Int)
    filtrarCont f l = _filtrarCont f l ([], 0)
      where 
        _filtrarCont :: (a -> Bool) -> [a] -> ([a], Int) -> ([a], Int)
        _filtrarCont _ [] (lis, c) = (lis, c)
        _filtrarCont f (x : xs) (lis, c) 
          | f x = _filtrarCont f xs (lis ++ [x], c + 1)
          | otherwise = _filtrarCont f xs (lis, c + 1)      

{-Variação 1-}
quickSortV1 :: (Ord a) => [a] -> ([a], Int)
quickSortV1 [] = ([], 0)
quickSortV1 (p : xs) = 
  let (esq, dir, contComp) = divide p xs 
      (ordEsq, n_esq) = quickSortV1 esq
      (ordDir, n_dir) = quickSortV1 dir
  in (ordEsq ++ [p] ++ ordDir, contComp + n_dir + n_esq)
  where
    divide :: (Ord a) => a -> [a] -> ([a], [a], Int)
    divide p xs = seleciona p xs ([], [], 0)
      where
        seleciona :: (Ord a) => a -> [a] -> ([a], [a], Int) -> ([a], [a], Int)
        seleciona pivo [] (menores, maiores, c) = (menores, maiores, c)
        seleciona pivo (h:hs) (menores, maiores, c) 
          | h < pivo = seleciona pivo hs (menores ++ [h], maiores, c + 1)
          | otherwise = seleciona pivo hs (menores, maiores ++ [h], c + 1) 


{-Variação 2-}


-- quickSortV2 :: (Ord a) => [a] -> ([a], Int)
-- quickSortV2 [] = ([], 0)
-- quickSortV2 (p : xs) = 
--   let (esq, dir, contComp) = divide p xs 
--       (ordEsq, n_esq) = quickSortV2 esq
--       (ordDir, n_dir) = quickSortV2 dir
--   in (ordEsq ++ [p] ++ ordDir, contComp + n_dir + n_esq)
--   where
--     divide :: (Ord a) => a -> [a] -> ([a], [a], Int)
--     divide p xs = seleciona p xs ([], [], 0)
--       where
--         seleciona :: (Ord a) => a -> [a] -> ([a], [a], Int) -> ([a], [a], Int)
--         seleciona pivo [] (menores, maiores, c) = (menores, maiores, c)
--         seleciona pivo (h:hs) (menores, maiores, c) 
--           | h < pivo = seleciona pivo hs (menores ++ [h], maiores, c + 1)
--           | otherwise = seleciona pivo hs (menores, maiores ++ [h], c + 1) 
  