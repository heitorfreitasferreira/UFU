ou1 :: Bool -> Bool -> Bool
ou1 a b
  | not a && not b = False
  | otherwise = True

ou2 :: Bool -> Bool -> Bool
ou2 a b =
  not (not a && not b)

ou4 :: Bool -> Bool -> Bool
ou4 a b =
  not (not a && not b)

or1 :: Bool -> Bool -> Bool
or1 False False = False
or1 _ _ = True

distance :: (Float, Float, Float) -> (Float, Float, Float) -> Float
distance (x1, y1, z1) (x2, y2, z2) = sqrt ((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2)

qst5 :: (Int, (Int, Int)) -> Int
qst5 (x, (y, z))
  | x == 1 = y + z
  | x == 2 = y - z
  | otherwise = 0