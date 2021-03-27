-- disponiveis :: [Int]
-- disponiveis = [1, 2, 5, 10, 20, 50, 100]

-- -- solve :: Int -> [[Int]]
-- -- solve 0 = [[]]
-- -- solve valor = [{--} | nota <- disponiveis, nota <= valor]

-- zipy :: [Int] -> [[Int]] -> [[Int]]
-- zipy notasPossiveis resultado = [n : x | n <- notasPossiveis, m <- resultado, x <- m]

-- main :: IO ()
-- main = do
--   putStrLn "What's your name?"
--   name <- getLine
--   putStrLn ("Hey, " ++ name)

teste :: Int -> Int -> [Int]
teste x y = [x, y]
disponiveis = [1,2,5,10,20,50,100]

zipa nums results = [ (n:r) | n <- nums, r <- results]

pegaDisponiveis valor = [ x | x <- disponiveis, x<=valor ]

solve 0 = [[]]
solve valor = zipa (pegaDisponiveis valor) (solve valor-n)


fora valor = [      | n <- pegaDisponiveis valor ]