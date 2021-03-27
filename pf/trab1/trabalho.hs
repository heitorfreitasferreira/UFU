-- 7

multiplos :: Int -> [Int]
multiplos m = [n * m | n <- [2, 3 .. 1000]]

comparaListas :: [Int] -> [Int] -> [Int] -> Int
comparaListas (a : as) (b : bs) (c : cs)
  | a == b && c == b = a
  | otherwise = comparaListas as (dropWhile (< a) (b : bs)) (dropWhile (< a) (c : cs))

mmc :: Int -> Int -> Int -> Int
mmc a b c = comparaListas (multiplos a) (multiplos b) (multiplos c)


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

-- 9
fizzbuzzM :: Int -> [String]
fizzbuzzM 1 = ["No"]
fizzbuzzM x
  | x `mod` 6 == 0 = "FizzBuzz" : fizzbuzzM (x -1)
  | even x = "Fizz" : fizzbuzzM (x -1)
  | x `mod` 3 == 0 = "Buzz" : fizzbuzzM (x -1)
  | otherwise = "No" : fizzbuzzM (x -1)

fizzbuzz :: Int -> [String]
fizzbuzz n = reverse (fizzbuzzM n)

-- 10
selMultiplos :: Int -> [Int] -> [Int]
selMultiplos n xs = [x|x<-xs,x `mod` n ==0]
--11
unica_ocorrencia :: Int -> [Int] -> Bool
unica_ocorrencia a xs = length xs == length ([n|n<- xs,n /=a]) + 1 

--12
intercala :: [a] -> [a] -> [a]
intercala [] [] = []
intercala xs [] = xs
intercala [] ys = ys
intercala (x : xs) (y : ys) = x : y : intercala xs ys


--13
zipar :: [Int] -> [Int] -> [[Int]]
zipar _ [] = []
zipar [] _ = []
zipar (x : xs) (y : ys) = [x, y] : zipar xs ys

-- 14
type Endereco = (String, Int, String)

type Contato = (String, Endereco, String, [Char {-(nome, (rua,numero,bairro),telefone,email)-}])

recoverNameFromEmail :: Contato -> String
recoverNameFromEmail (_, _, _, email) = takeWhile ('@' /=) email

-- 15

type Pessoa = (String, Float, Int, Char)

pessoas :: [Pessoa]
pessoas = [("Rosa", 1.66, 27, 'C'), ("João", 1.85, 26, 'C'), ("Maria", 1.55, 62, 'S'), ("Jose", 1.78, 42, 'C'), ("Paulo", 1.93, 25, 'S'), ("Clara", 1.70, 33, 'C'), ("Bob", 1.45, 21, 'C'), ("Rosana", 1.58, 39, 'S'), ("Daniel", 1.74, 72, 'S'), ("Jocileide", 1.69, 18, 'S')]

sumAlturas :: [Pessoa] -> Float
sumAlturas [] = 0
sumAlturas ((_, altura, _, _) : xs) = altura + sumAlturas xs

mediaAlturas :: [Pessoa] -> Float
mediaAlturas listPessoa = sumAlturas listPessoa / fromIntegral (length listPessoa)

idadeMin :: [Pessoa] -> Int
idadeMin [(_, _, idade, _)] = idade
idadeMin ((n1, a1, idade1, e1) : (n2, a2, idade2, e2) : resto) =
  if idade1 < idade2
    then idadeMin ((n1, a1, idade1, e1) : resto)
    else idadeMin ((n2, a2, idade2, e2) : resto)

maisVelho :: [Pessoa] -> Pessoa
maisVelho [(nome, altura, idade, estadoCivil)] = (nome, altura, idade, estadoCivil)
maisVelho ((n1, a1, idade1, e1) : (n2, a2, idade2, e2) : resto) =
  if idade1 > idade2
    then maisVelho ((n1, a1, idade1, e1) : resto)
    else maisVelho ((n2, a2, idade2, e2) : resto)

boomers :: [Pessoa] -> [Pessoa]
boomers [] = []
boomers ((n, a, idade, e) : resto) =
  if idade >= 50
    then (n, a, idade, e) : boomers resto
    else boomers resto

milfsCasadas :: Int -> [Pessoa] -> [Pessoa]
milfsCasadas _ [] = []
milfsCasadas i ((n, a, idade, estadoCivil) : resto) =
  if idade >= i && estadoCivil == 'C'
    then (n, a, idade, estadoCivil) : milfsCasadas i resto
    else milfsCasadas i resto
--16
insereOrd :: Integral a => a -> [a] -> [a]
insereOrd a [] = [a]
insereOrd a (x : xs)
  | a <= x = a : x : xs
  | otherwise = x : insereOrd a xs

--17
reverte :: [a] -> [a]
reverte l = _reverte l []
  where
    _reverte :: [a] -> [a] -> [a]
    _reverte [] l = l
    _reverte (x : xs) l = _reverte xs (x : l)

-- 18
contem :: (Eq a) => a -> [a] -> Bool
contem _ [] = False
contem a (x : xs) = x == a || contem a xs

elimina_repet :: (Eq a) => [a] -> [a]
elimina_repet [] = []
elimina_repet (x : xs) =
  if contem x xs
    then elimina_repet xs
    else x : elimina_repet xs