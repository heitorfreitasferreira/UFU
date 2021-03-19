--------------------------------------------------------------------------------------------------------
type ParFib = (Int, Int)
proxPar :: ParFib -> ParFib
proxPar (x, y) = (y, x + y)
nPar :: Int -> ParFib
nPar n = nParM (n, (1, 1))
nParM :: (Int, ParFib) -> ParFib
nParM (n, par)
  | n == 1 = par
  | otherwise = nParM (n -1, proxPar par)
fib :: Int -> Int
fib n = fst (nPar n)
--------------------------------------------------------------------------------------------------------
--
type ParFib = (Int, Int)
proxPar :: ParFib -> ParFib
nPar :: Int -> ParFib
nParM :: (Int, ParFib) -> ParFib


fibWhere :: Int -> Int
fib n = fst (nPar n)
  where
    nPar n = nParM (n, (1, 1))
    where
      nParM (n, par)
        | n == 1 = par
        | otherwise = nParM (n -1, proxPar par)
        where
          proxPar (x, y) = (y, x + y)
--------------------------------------------------------------------------------------------------------