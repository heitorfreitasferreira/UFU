a :: Int -> Int -> [Int]
a x y
  | x == y || x + 1 == y -1 = [x]
  | x > y = []
  | otherwise = [(x + 1) .. (y -1)]

b :: Int -> Int -> [Int]
b x y
  | x > y || odd x = []
  | otherwise = [x, (x + 2) .. y]