---------------------------------------------------------------------------------------
-- 1a
or1 :: Bool -> Bool -> Bool
or1 False False = False
or1 _ _ = True

or2 :: Bool -> Bool -> Bool
or2 True _ = True
or2 _ True = True
or2 False False = False

or3 :: Bool -> Bool -> Bool
or3 True True = True
or3 True False = True
or3 False True = True
or3 False False = False

--1b
ou2 :: Bool -> Bool -> Bool
ou2 x y
  | x = True
  | y = True
  | otherwise = False

ou1 :: Bool -> Bool -> Bool
ou1 a b
  | not a && not b = False
  | otherwise = True

---------------------------------------------------------------------------------------
-- 2
distancia :: Floating a => (a, a) -> (a, a) -> a
distancia (xa, xb) (ya, yb) = sqrt ((xa - xb) ** 2 + (ya - yb) ** 2)

---------------------------------------------------------------------------------------
-- 3
fact :: (Eq p, Num p) => p -> p
fact 0 = 1
fact n = n * fact (n -1)

factG :: (Eq p, Num p) => p -> p
factG n
  | n == 0 = 1
  | otherwise = n * fact (n -1)

fat :: Int -> Int
fat n
  | n < 0 = -1
  | otherwise = fact n

---------------------------------------------------------------------------------------
-- 4
fib :: (Eq a, Num a, Num p) => a -> p
fib n
  | n == 1 = 1
  | n == 2 = 1
  | otherwise = fib (n -1) + fib (n -2)

fibP 1 = 1
fibP 2 = 1
fibP n = fibP (n -1) + fibP (n -2)

---------------------------------------------------------------------------------------
-- 5
numTri :: (Ord p, Num p) => p -> p
numTri n
  | n < 0 = -1
  | otherwise = numTriM n

numTriM :: (Eq p, Num p) => p -> p
numTriM 0 = 0
numTriM n = n + numTriM (n -1)

---------------------------------------------------------------------------------------
-- 6
pot2 :: Float -> Float
pot2 n
  | n == 0 = 1
  | n < 0 = pot2N n
  | otherwise = pot2P n

pot2P :: (Eq t, Num t, Num p) => t -> p
pot2P 0 = 1
pot2P n = 2 * pot2P (n -1)

pot2N :: Float -> Float
pot2N 0 = 1
pot2N n = 0.5 * pot2N (n + 1)

---------------------------------------------------------------------------------------
-- 7a
prodIntervalo :: Int -> Int -> Int
prodIntervalo m n
  | m < n = prodIntervaloM m n
  | m > n = prodIntervaloM n m
  | otherwise = m

prodIntervaloM :: Int -> Int -> Int
prodIntervaloM m n
  | m == n = m
  | otherwise = m * prodIntervaloM (m + 1) n

-- 7b
fatIntervalo :: Int -> Int
fatIntervalo 0 = 1
fatIntervalo n = prodIntervaloM 1 n

---------------------------------------------------------------------------------------
-- 8
resto :: (Ord t, Num t) => t -> t -> t
resto m n
  | n > m = m
  | otherwise = resto (m - n) n

quociente :: (Ord t, Num p, Num t) => t -> t -> p
quociente m n
  | m - n < n = 1
  | otherwise = 1 + quociente (m - n) n

---------------------------------------------------------------------------------------
-- 9
mdc :: (Int, Int) -> Int
mdc (m, n)
  | n == 0 = m
  | n > 0 = mdc (n, mod m n)

mdcP :: (Int, Int) -> Int
mdcP (m, 0) = m
mdcP (m, n) = if n > 0 then mdcP (n, mod m n) else -1

---------------------------------------------------------------------------------------
--10
binomial :: (Int, Int) -> Int
binomial (_, 0) = 1
binomial (n, k)
  | k == n = 1
  | n > k && k > 0 = binomial (n -1, k) + binomial (n -1, k -1)
  | otherwise = -1

binomialG :: (Int, Int) -> Int
binomialG (n, k)
  | k == 0 || k == n = 1
  | n > k && k > 0 = binomialG (n - 1, k) + binomialG (n - 1, k - 1)
  | otherwise = - 1

---------------------------------------------------------------------------------------
--11a
-- seq: (1, 1) (2, 3) (5, 8) (13, 21) (34, 55) (89,144)
-- passo: (1,1) => (1,2) => (2,3) => (3,5) => (5, 8) => (8, 13)
type ParFib = (Int, Int)

--11b
proxPar :: ParFib -> ParFib
proxPar (x, y) = (y, x + y)

--11c
nPar :: Int -> ParFib
nPar n = nParM (n, (1, 1))

nParM :: (Int, ParFib) -> ParFib
nParM (n, par)
  | n == 1 = par
  | otherwise = nParM (n -1, proxPar par)

--11d
fibLobo :: Int -> Int
fibLobo n = fst (nPar n)