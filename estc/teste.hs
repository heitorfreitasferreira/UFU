somaAcum [] _ = 0
somaAcum (x : xs) function = function x + function

--somaAcum [10 .. 100] (\i -> ((i ^ 3) + (4 * i ^ 2)))