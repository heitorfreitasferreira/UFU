bissextoM :: Integral a => a -> Bool
bissextoM ano
  | mod ano 400 == 0 = True
  | mod ano 4 == 0 && mod ano 100 /= 0 = True
  | otherwise = False

bissextos :: [Int] -> [Int]
bissextos x = [n|n<-x,bissextoM n]