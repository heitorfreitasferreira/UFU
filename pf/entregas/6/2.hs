type Data = (Int, Int, Int)
validaData :: Data -> Bool
validaData (dia, mes, ano)
  | dia < 1 || dia > 31 = False
  | mes < 1 || mes > 12 = False
  | dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11) = False
  | dia > 29 && mes == 2 = False
  | dia > 28 && mes == 2 && not (let bissexto ano = mod ano 400 == 0 || (mod ano 4 == 0 && mod ano 100 /=0) in bissexto ano) = False
  | otherwise = True


fatorial :: Int -> Int
fatorial n = 
  let _prodIntervalo m n
        | m == n = m
        | otherwise = m * _prodIntervalo (m + 1) n
  in 
    _prodIntervalo 1 n