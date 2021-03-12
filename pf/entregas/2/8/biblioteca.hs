type Data = (Int, Int, Int)

--            código  titulo  autor   editora ano
type Livro = (String, String, String, String, Int)

--            código  nome    email   telefone
type Aluno = (String, String, String, String)

--                 cod_lvr  cod_al  emp   dev   situação
type Emprestimo = (String, String, Data, Data, String)