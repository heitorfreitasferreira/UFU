{-# OPTIONS_GHC -Wno-deferred-type-errors #-}

contem :: (Eq a) => a -> [a] -> Bool
contem _ [] = False
contem a (x : xs) = x == a || contem a xs

removeDuplicata :: (Eq a) => [a] -> [a]
removeDuplicata [] = []
removeDuplicata (x : xs) =
  if contem x xs
    then removeDuplicata xs
    else x : removeDuplicata xs

crescente :: [Int] -> Bool
crescente [] = True
crescente [x] = True
crescente (x1 : x2 : xs)
  | x1 <= x2 = crescente (x2 : xs)
  | otherwise = False

hasPath :: [(Int, Int)] -> Int -> Int -> Bool
hasPath [] x y = x == y
hasPath xs i f
  | i == f = True
  | otherwise =
    let xs' = [(n, m) | (n, m) <- xs, n /= i]
     in or [hasPath xs' m f | (n, m) <- xs, n == i]
