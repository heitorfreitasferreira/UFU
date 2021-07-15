conta :: [t] -> Int
conta x = _conta x 0
  where
    _conta :: [t] -> Int -> Int
    _conta [] a = a
    _conta (x : xs) a = _conta xs (a + 1)

contaCh :: [Char] -> Int
contaCh x = _contaCh x 0
  where
    _contaCh :: [Char] -> Int -> Int
    _contaCh [] a = a
    _contaCh (x : xs) a = _contaCh xs (a + 1)

maior :: (Ord t) => [t] -> t
maior (x : xs) = _maior xs x
  where
    _maior :: (Ord t) => [t] -> t -> t
    _maior [] r = r
    _maior (x : xs) maior =
      if x > maior
        then _maior xs x
        else _maior xs maior

primeiros :: [t] -> Int -> [t]
primeiros _ 0 = []
primeiros [] _ = []
primeiros (x : xs) n = x : primeiros xs (n -1)

uniaoR :: Eq t => [t] -> [t] -> [t]
uniaoR [] l = l
uniaoR (x : xs) l =
  if contem x l
    then uniaoR xs l
    else uniaoR xs (x : l)
  where
    contem :: (Eq a) => a -> [a] -> Bool
    contem _ [] = False
    contem a (x : xs) = x == a || contem a xs

nPares :: [Int] -> Int
nPares x = _nPares x 0
  where
    _nPares :: [Int] -> Int -> Int
    _nPares [] n = n
    _nPares (x : xs) n =
      if x `mod` 2 == 0
        then _nPares xs (n + 1)
        else _nPares xs n

produto :: [Int] -> Int
produto x = _produto x 1
  where
    _produto :: [Int] -> Int -> Int
    _produto [] n = n
    _produto (x : xs) n = _produto xs (n * x)

tamanho :: [Int] -> Int
tamanho x = _tamanho x 0
  where
    _tamanho :: [Int] -> Int -> Int
    _tamanho [] n = n
    _tamanho (x : xs) n = _tamanho xs (n + 1)

comprime :: [[a]] -> [a]
comprime [[]] = []
comprime ([] : xs) = comprime xs
comprime ((y : ys) : xs) = y : comprime (ys : xs)

uniaoR2 :: Eq t => [t] -> [t] -> [t]
uniaoR2 l [] = l
uniaoR2 l (x : xs) =
  if contem x l
    then uniaoR2 l xs
    else uniaoR2 (l ++ [x]) xs
  where
    contem :: (Eq a) => a -> [a] -> Bool
    contem _ [] = False
    contem a (x : xs) = x == a || contem a xs