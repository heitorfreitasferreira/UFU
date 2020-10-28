somaUm([],X).
somaUm([X|Xs],X):-X1 is +(X,1), somaUm([Xs],X1).