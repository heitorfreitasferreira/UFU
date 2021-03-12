type Data = (Int, Int, Int)

bissexto :: Data -> Bool
bissexto (dia, mes, ano)
  | mod ano 400 == 0 = True
  | mod ano 4 == 0 = True
  | otherwise = False

validaData :: Data -> Bool
validaData (dia, mes, ano)
  | dia < 1 || dia > 31 = False
  | mes < 1 || mes > 12 = False
  | dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11) = False
  | dia > 29 && mes == 2 = False
  | dia > 28 && mes == 2 && not (bissexto (dia, mes, ano)) = False
  | otherwise = True

precede :: Data -> Data -> Bool
precede (dia1, mes1, ano1) (dia2, mes2, ano2)
  | not (validaData (dia1, mes1, ano1)) || not (validaData (dia2, mes2, ano2)) = False
  | ano1 < ano2 = True
  | mes1 < mes2 && ano1 == ano2 = True
  | dia1 < dia2 && mes1 == mes2 && ano1 == ano2 = True
  | otherwise = False