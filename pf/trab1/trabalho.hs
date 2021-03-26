-- 7

fatores :: Int -> [Int]
fatores n = [x | x <- [1 .. n], mod n x == 0]

fatoresTrio :: Int -> Int ->Int ->[(Int,Int,Int)]

fatoresTrio x y z = [(a, b, c) | a <- fatores x, b <- fatores y, c <- fatores z]

mdc :: Int -> Int-> Int-> Int 
fatoresTrioIguais :: [(Int, Int, Int)] -> [Int]
fatoresTrioIguais x = [a|(a,b,c)<-x,a==b &&b==c && a/=1]

mdc x y z = minimum (fatoresTrioIguais (fatoresTrio x y z))

--4A
gera1 :: [Int] -> [Int]
gera1 x = [n * n * n | n <- x, even n, n >= 3, n <= 11]

--4B
gera2 :: [Int] -> [(Int, Int)]
gera2 x = [(n, m) | n <- x, n <= 5, m <- [n .. n * 3]]

--4C
-- gera3M :: [Int] -> [[Int]]
-- gera3M x = [[1 .. n] | n <- x]
gera3 :: [Int] -> [Int]
gera3 x = [n|parcial<-y,n<-parcial]
  where y = [[1 .. n] | n <- x]
--4D
gera4 ::[(Int,Int)]
gera4 = [(n,n+1)|n<-[1..10],even n]
--4E
gera5 :: [Int]
gera5 = [fst n + snd n|n<-gera4]

