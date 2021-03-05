dobro x = x * 2

quadruplicar x = dobro (dobro x)

hipotenusa a b = sqrt (a ** 2 + b ** 2)

distancia xa xb ya yb = sqrt ((xa - xb) ** 2 + (ya - yb) ** 2)

main :: IO ()
main = do
  putStrLn "Que numero devo dobrar"
  x <- readLn
  print (dobro x)

  putStrLn "Que numero devo quadruplicar"
  x <- readLn
  print (quadruplicar x)

  putStrLn "Insira o tamanho do cateto adjacente"
  x <- readLn
  putStrLn "Insira o tamanho do cateto oposto"
  y <- readLn
  print (hipotenusa x y)

  putStrLn "Insira a coordenada X do primeiro ponto"
  xa <- readLn
  putStrLn "Insira a coordenada Y do primeiro ponto"
  ya <- readLn
  putStrLn "Insira a coordenada X do segundo ponto"
  xb <- readLn
  putStrLn "Insira a coordenada Y do segundo ponto"
  yb <- readLn
  print (distancia xa xb ya yb)