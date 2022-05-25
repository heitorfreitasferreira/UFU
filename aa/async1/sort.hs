-- merge :: Ord a => [a] -> [a] -> ([a], Int)


-- merge xs [] = (xs, 0)
-- merge [] ys = (ys, 0)
-- merge (x : xs) (y : ys)
--   | x <= y = (x : l1, cont1 + 1)
--   | otherwise = (y : l2, cont2 + 1)
--   where
--     (l1, cont1) = merge xs (y : ys)
--     (l2, cont2) = merge (x : xs) ys

-- mergeSort :: Ord a => [a] -> ([a], Int)
-- mergeSort [] = ([], 0)
-- mergeSort [x] = ([x], 0)
-- mergeSort list = (merged, cont + contEsq + contDir)
--   where
--     (esq, dir) = separaListas list
--     (newEsq, contEsq) = mergeSort esq
--     (newDir, contDir) = mergeSort dir


insertion_sort :: Ord a => [a] -> [a]
insertion_sort [] = []
insertion_sort [x] = [x]
insertion_sort (x : xs) = insert x (insertion_sort xs)

insert :: Ord a => a -> [a] -> [a]
insert x [] = [x]
insert x (y : ys)
  | x <= y = x : y : ys
  | otherwise = y : insert x ys


merge_sort :: Ord a => [a] -> [a]
merge_sort [] = []
merge_sort [x] = [x]
merge_sort xs = merge (merge_sort left)(merge_sort right) where
  pivo = (length xs) `div` 2 -- Ponto mediano
  left = take pivot xs -- Metade esquerda da lista
  right = drop pivot xs -- Metade direita da lista


merge :: Ord a => [a] -> [a] -> [a]
merge [] right = right
merge left [] = left
merge (x : xs) (y : ys)
  | x <= y = x : merge xs (y : ys)
  | otherwise = y : merge (x : xs) ys