fatores :: Int -> [Int]
fatores n = [x | x <- [1 .. n], mod n x == 0]

fatoresTrio :: Int -> Int ->Int ->[(Int,Int,Int)]

fatoresTrio x y z = [(a, b, c) | a <- fatores x, b <- fatores y, c <- fatores z]
fatoresTrioIguais :: [(Int, Int, Int)] -> [Int]
fatoresTrioIguais x = [a|(a,b,c)<-x,a==b &&b==c && a/=1]

mdc :: Int -> Int-> Int-> Int 
mdc x y z = minimum (fatoresTrioIguais (fatoresTrio x y z))