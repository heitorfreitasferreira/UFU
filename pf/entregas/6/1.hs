type Data = (Int, Int, Int)

--            código  titulo  autor   editora ano
type Livro = (String, String, String, String, Int)

--            código  nome    email   telefone
type Aluno = (String, String, String, String)

--                 cod_lvr  cod_al  emp   dev   situação
type Emprestimo = (String, String, Data, Data, String)
---------------------------------------------------------
type ParFib = (Int, Int)

validaData :: Data -> Bool
validaData (dia, mes, ano)
  | dia < 1 || dia > 31 = False
  | mes < 1 || mes > 12 = False
  | dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11) = False
  | dia > 29 && mes == 2 = False
  | dia > 28 && mes == 2 && not (bissexto (dia, mes, ano)) = False
  | otherwise = True
  where 
    bissexto :: Data -> Bool
    bissexto (dia, mes, ano)
      | mod ano 400 == 0 = True
      | mod ano 4 == 0 = True
      | otherwise = False

anosBissextos::[Int]->[Int]
anosBissextos x = [n | n <- x, bissexto n]
  where
    bissexto :: Int -> Bool
    bissexto ano
      | mod ano 400 == 0 = True
      | mod ano 4 == 0 = True
      | otherwise = False



fibo2 :: Int -> Int
fibo2 n = fst (nPar n)
  where
    nPar :: Int -> ParFib
    nPar n = nParM (n, (1, 1))
      where
        nParM :: (Int, ParFib) -> ParFib
        nParM (n, par)
          | n == 1 = par
          | otherwise = nParM (n -1, proxPar par)
            where
              proxPar :: ParFib -> ParFib
              proxPar (x, y) = (y, x + y)

atrasados :: [Emprestimo] -> Data -> [Emprestimo]
atrasados lista hoje = [n | n <- lista, not(verificaEmprestimo n hoje)]
  where
    verificaEmprestimo :: Emprestimo -> Data -> Bool
    verificaEmprestimo (_, _, dataEmprestimo, dataDevolucao, situacao) hoje = 
      situacao == "fechado" || (hoje `precede` dataDevolucao && dataEmprestimo `poscede` hoje) || hoje == dataDevolucao
        where
          precede :: Data -> Data -> Bool
          precede (dia1, mes1, ano1) (dia2, mes2, ano2)
            | not (validaData (dia1, mes1, ano1)) || not (validaData (dia2, mes2, ano2)) = False
            | ano1 < ano2 = True
            | mes1 < mes2 && ano1 == ano2 = True
            | dia1 < dia2 && mes1 == mes2 && ano1 == ano2 = True
            | otherwise = False
          poscede :: Data -> Data -> Bool
          poscede (dia1, mes1, ano1) (dia2, mes2, ano2)
            | not (precede (dia1, mes1, ano1) (dia2, mes2, ano2)) && (dia1, mes1, ano1) /= (dia2, mes2, ano2) = True
            | otherwise = False

fatorial :: Int -> Int
fatorial n = prodIntervalo 1 n
  where
    prodIntervalo :: Int -> Int -> Int
    prodIntervalo m n
      | m < n = _prodIntervalo m n
      | m > n = _prodIntervalo n m
      | otherwise = m
        where
          _prodIntervalo :: Int -> Int -> Int
          _prodIntervalo m n
            | m == n = m
            | otherwise = m * _prodIntervalo (m + 1) n


