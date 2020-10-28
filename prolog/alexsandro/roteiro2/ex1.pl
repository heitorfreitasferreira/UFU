sobre(topo,meio).
sobre(meio,baixo).

acima_de(A,B):-sobre(A,B);(sobre(A,C),sobre(C,B)).

% acima_de(topo,baixo).