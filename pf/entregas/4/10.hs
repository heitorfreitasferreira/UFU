{-# OPTIONS_GHC -Wno-deferred-type-errors #-}

type Data = (Int, Int, Int)

type Emprestimo = (String, String, Data, Data, String)

type Emprestimos = [Emprestimo]

bdEmprestimo :: Emprestimos
bdEmprestimo =
  [ ("H123C9", "BSI945", (12, 9, 2009), (20, 09, 2009), "aberto"),
    ("L433C5", "BCC021", (01, 9, 2009), (10, 09, 2009), "encerrado"),
    ("M654C3", "BCC008", (04, 9, 2009), (15, 09, 2009), "aberto")
  ]

bissexto :: Integral a => a -> Bool
bissexto ano
  | mod ano 400 == 0 = True
  | mod ano 4 == 0 && mod ano 100 /= 0 = True
  | otherwise = False

valida :: Data -> Bool
valida (dia, mes, ano)
  | (dia < 1 || dia > 31) || (mes < 1 || mes > 12) = False {- Tira mes e dia com valores inválidos -}
  | dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11) = False
  | mes == 2 && dia > 29 = False
  | mes == 2 && dia > 28 && not (bissexto ano) = False
  | otherwise = True

precede :: Data -> Data -> Bool
precede (dia1, mes1, ano1) (dia2, mes2, ano2)
  | not (valida (dia1, mes1, ano1)) || not (valida (dia2, mes2, ano2)) = False
  | ano1 < ano2 = True
  | ano1 == ano2 && mes1 < mes2 = True
  | ano1 == ano2 && mes1 == mes2 && dia1 < dia2 = True
  | otherwise = False

atrasados :: Emprestimos -> Data -> [Emprestimo]
atrasados lista dataAtual = [(x, y, z, dtDev, w) | (x, y, z, dtDev, w) <- lista, precede dtDev dataAtual]