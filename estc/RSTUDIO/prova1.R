#1
  library(dslabs)
  data(heights)
  heights
  # a
    heights$alt.cm <- (2.54 * heights[, 'height'])
  # b
    qnt_homens = sum(heights[, 'sex'] == "Male")
    qnt_mulheres = sum(heights[, 'sex'] == "Female")
    proporcao_homens = qnt_homens/(qnt_homens+qnt_mulheres)
    proporcao_homens
  # c
    maior_altura = which(max(heights[, 'height']))
    maior_altura
    