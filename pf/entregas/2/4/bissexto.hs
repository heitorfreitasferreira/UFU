bissexto :: Integral a => a -> Bool
bissexto ano
  | mod ano 400 == 0 = True
  | mod ano 4 == 0 = True
  | otherwise = False

--seiji boiola