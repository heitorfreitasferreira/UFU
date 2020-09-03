elfo_domestico(dobby).
bruxo(hermione).
bruxo('McGonagall').
bruxo(rita_skeeter).
magico(X):- elfo_domestico(X).
% magico(X):- feiticeiro(X).
magico(X):- bruxo(X).
% ex.6
  % ?- feiticeiro(harry)
  % |    .
  % ERROR: Unknown procedure: feiticeiro/1 (DWIM could not correct goal)