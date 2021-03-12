conversao :: Fractional c => c -> (c, c, c)
conversao real = (real, real * 3.96, real * 4.45)